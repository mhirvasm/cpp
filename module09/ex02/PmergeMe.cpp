#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cerrno>
#include <sys/time.h>
#include <algorithm>

// default constructor
PmergeMe::PmergeMe() : _time_vector(0), _time_deque(0) {}

// copy constructor
PmergeMe::PmergeMe(const PmergeMe& other) 
    : _vector(other._vector), _deque(other._deque), 
      _time_vector(other._time_vector), _time_deque(other._time_deque) {}

// assignment operator
PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
    if (this != &rhs) {
        _vector = rhs._vector;
        _deque = rhs._deque;
        _time_vector = rhs._time_vector;
        _time_deque = rhs._time_deque;
    }
    return *this;
}

// destructor
PmergeMe::~PmergeMe() {}

// retrieves current time in microseconds
double PmergeMe::_getTimeMicroseconds() const {
    struct timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000000.0) + time.tv_usec;
}

// prints up to a limited number of elements
void PmergeMe::_printSequence(const std::string& prefix, const std::vector<int>& arr) const {
    std::cout << prefix;
    size_t limit = arr.size() > 10 ? 10 : arr.size(); // limit output so terminal doesn't flood
    for (size_t i = 0; i < limit; ++i) {
        std::cout << arr[i] << " ";
    }
    if (arr.size() > 10) {
        std::cout << "[...]";
    }
    std::cout << "\n";
}

// generates jacobsthal numbers to optimize binary search insertion
std::vector<size_t> PmergeMe::_generateJacobsthal(size_t n) const {
    std::vector<size_t> seq;
    if (n == 0) return seq;
    
    seq.push_back(1);
    if (n == 1) return seq;
    
    seq.push_back(3);
    for (size_t i = 2; ; ++i) {
        size_t next = seq[i - 1] + 2 * seq[i - 2];
        seq.push_back(next);
        if (next >= n) break; // generate just enough for our pend size
    }
    return seq;
}

// simple recursive sort for the pairs based on the larger element (first)
void PmergeMe::_sortPairsVector(std::vector<std::pair<int, int> >& pairs) {
    if (pairs.size() <= 1) return;
    
    // using a simple insertion sort for the pairs array to avoid generic std::sort
    for (size_t i = 1; i < pairs.size(); ++i) {
        std::pair<int, int> key = pairs[i];
        int j = i - 1;
        while (j >= 0 && pairs[j].first > key.first) {
            pairs[j + 1] = pairs[j];
            j--;
        }
        pairs[j + 1] = key;
    }
}

// ford-johnson logic for std::vector
void PmergeMe::_sortVector(std::vector<int>& arr) {
    if (arr.size() <= 1) return;

    // 1. handle odd element
    int straggler = -1;
    if (arr.size() % 2 != 0) {
        straggler = arr.back();
        arr.pop_back();
    }

    // 2. group into pairs, sort internally (larger goes to 'first')
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    // 3. sort pairs by their larger elements
    _sortPairsVector(pairs);

    // 4. split into main chain and pend
    std::vector<int> main_chain;
    std::vector<int> pend;
    for (size_t i = 0; i < pairs.size(); ++i) {
        main_chain.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }

    // 5. insert pend[0] automatically at the start of main_chain (it's always the smallest)
    main_chain.insert(main_chain.begin(), pend[0]);

    // 6. insert remaining pend elements using jacobsthal gaps
    std::vector<size_t> jacob = _generateJacobsthal(pend.size());
    size_t prev_j = 1;

    for (size_t i = 1; i < jacob.size(); ++i) {
        size_t current_j = jacob[i];
        size_t limit = current_j > pend.size() ? pend.size() : current_j;

        // insert in reverse order within the batch
        for (size_t k = limit; k > prev_j; --k) {
            size_t pend_idx = k - 1;
            // binary search the main_chain for the optimal insertion point
            std::vector<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), pend[pend_idx]);
            main_chain.insert(it, pend[pend_idx]);
        }
        prev_j = current_j;
        if (prev_j >= pend.size()) break;
    }

    // 7. insert the odd straggler if it exists
    if (straggler != -1) {
        std::vector<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), straggler);
        main_chain.insert(it, straggler);
    }

    arr = main_chain;
}

// -----------------------------------------------------------------------------
// deque implementation (identitical logic, separate container type)
// -----------------------------------------------------------------------------

void PmergeMe::_sortPairsDeque(std::deque<std::pair<int, int> >& pairs) {
    if (pairs.size() <= 1) return;
    
    for (size_t i = 1; i < pairs.size(); ++i) {
        std::pair<int, int> key = pairs[i];
        int j = i - 1;
        while (j >= 0 && pairs[j].first > key.first) {
            pairs[j + 1] = pairs[j];
            j--;
        }
        pairs[j + 1] = key;
    }
}

void PmergeMe::_sortDeque(std::deque<int>& arr) {
    if (arr.size() <= 1) return;

    int straggler = -1;
    if (arr.size() % 2 != 0) {
        straggler = arr.back();
        arr.pop_back();
    }

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    _sortPairsDeque(pairs);

    std::deque<int> main_chain;
    std::deque<int> pend;
    for (size_t i = 0; i < pairs.size(); ++i) {
        main_chain.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }

    main_chain.insert(main_chain.begin(), pend[0]);

    std::vector<size_t> jacob = _generateJacobsthal(pend.size());
    size_t prev_j = 1;

    for (size_t i = 1; i < jacob.size(); ++i) {
        size_t current_j = jacob[i];
        size_t limit = current_j > pend.size() ? pend.size() : current_j;

        for (size_t k = limit; k > prev_j; --k) {
            size_t pend_idx = k - 1;
            std::deque<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), pend[pend_idx]);
            main_chain.insert(it, pend[pend_idx]);
        }
        prev_j = current_j;
        if (prev_j >= pend.size()) break;
    }

    if (straggler != -1) {
        std::deque<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), straggler);
        main_chain.insert(it, straggler);
    }

    arr = main_chain;
}

// parsing and master execution
void PmergeMe::parseAndSort(int argc, char** argv) {
    // 1. parse arguments
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        
        // reject empty strings
        if (arg.empty()) throw InvalidInputException();
        
        // reject non-digit characters (allow optional + at start)
        for (size_t j = 0; j < arg.length(); ++j) {
            if (j == 0 && arg[j] == '+') continue;
            if (!std::isdigit(arg[j])) throw InvalidInputException();
        }

        // convert and check integer limits
        char* endptr;
        errno = 0;
        long val = std::strtol(arg.c_str(), &endptr, 10);
        
        if (errno == ERANGE || val < 0 || val > INT_MAX || *endptr != '\0') {
            throw InvalidInputException();
        }

        _vector.push_back(static_cast<int>(val));
        _deque.push_back(static_cast<int>(val));
    }

    if (_vector.empty()) return;

    // print unsorted sequence
    _printSequence("Before: ", _vector);

    // time and sort vector
    double start_v = _getTimeMicroseconds();
    _sortVector(_vector);
    double end_v = _getTimeMicroseconds();
    _time_vector = end_v - start_v;

    // time and sort deque
    double start_d = _getTimeMicroseconds();
    _sortDeque(_deque);
    double end_d = _getTimeMicroseconds();
    _time_deque = end_d - start_d;

    // print sorted sequence
    _printSequence("After:  ", _vector);

    // print timing results based on exact subject format
    std::cout << "Time to process a range of " << _vector.size() 
              << " elements with std::vector : " << _time_vector << " us\n";
    std::cout << "Time to process a range of " << _deque.size() 
              << " elements with std::deque  : " << _time_deque << " us\n";
}

const char* PmergeMe::InvalidInputException::what() const noexcept {
    return "Error";
}
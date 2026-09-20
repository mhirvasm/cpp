#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <exception>
#include <utility>

class PmergeMe {
private:
    std::vector<int> _vector;
    std::deque<int> _deque;

    // timers
    double _time_vector;
    double _time_deque;

    // private logic for vector (ford-johnson)
    void _sortVector(std::vector<int>& arr);
    void _sortPairsVector(std::vector<std::pair<int, int> >& pairs);
    std::vector<size_t> _generateJacobsthal(size_t n) const;

    // private logic for deque (ford-johnson)
    void _sortDeque(std::deque<int>& arr);
    void _sortPairsDeque(std::deque<std::pair<int, int> >& pairs);

    // utilities
    void _printSequence(const std::string& prefix, const std::vector<int>& arr) const;
    double _getTimeMicroseconds() const;

public:
    // orthodox canonical form
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& rhs);
    ~PmergeMe();

    // core execution
    void parseAndSort(int argc, char** argv);

    // exception
    class InvalidInputException : public std::exception {
    public:
        virtual const char* what() const noexcept override;
    };
};

#endif
#include <iostream>
#include <vector>
#include <list>
#include "Easyfind.hpp"

int main() {
    std::cout << "--- test 1: std::vector ---\n";
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    try {
        // search for an existing value
        std::vector<int>::iterator it1 = easyfind(vec, 20);
        std::cout << "vector found value: " << *it1 << "\n";

        // search for a non-existing value
        std::vector<int>::iterator it2 = easyfind(vec, 99);
        std::cout << "vector found value: " << *it2 << "\n";
    } catch (const std::exception& e) {
        std::cerr << "exception caught (vector): " << e.what() << "\n";
    }

    std::cout << "\n--- test 2: std::list ---\n";
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    try {
        // search for an existing value
        std::list<int>::iterator it3 = easyfind(lst, 3);
        std::cout << "list found value: " << *it3 << "\n";

        // search for a non-existing value
        easyfind(lst, 42); 
    } catch (const std::exception& e) {
        std::cerr << "exception caught (list): " << e.what() << "\n";
    }

    return 0;
}
#ifndef WHATEVER_HPP
#define WHATEVER_HPP

// Template declaration. 'T' becomes a placeholder for ANY data type.
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Returns the smallest value. If equal, returns the second one (b).
template <typename T>
const T& min(const T& a, const T& b) {
    // If b is less than or equal to a, return b. Otherwise, return a.
    return (b <= a) ? b : a;
}

// Returns the greatest value. If equal, returns the second one (b).
template <typename T>
const T& max(const T& a, const T& b) {
    // If b is greater than or equal to a, return b. Otherwise, return a.
    return (b >= a) ? b : a;
}

#endif
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// Randomly instantiate A, B, or C
Base* generate(void) {
    int r = std::rand() % 3;
    if (r == 0) return new A();
    if (r == 1) return new B();
    return new C();
}

// Identify via pointer
void identify(Base* p) {
    // dynamic_cast with pointers returns nullptr if the cast fails
    if (dynamic_cast<A*>(p)) {
        std::cout << "A\n";
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B\n";
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C\n";
    }
}

// Identify via reference
void identify(Base& p) {
    // dynamic_cast with references throws an exception if the cast fails
    // Using pointers inside this function is explicitly forbidden
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
        return;
    } catch (...) {}
    
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B\n";
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C\n";
        return;
    } catch (...) {}
}

//For testing if want 
//class D : public Base {};

int main() {
   {
	std::srand(std::time(NULL));
		// Test random objects with pointers.
		// Verifies dynamic_cast returns nullptr on failure.
		std::cout << "TEST 1 with Base pointers\n\n";
		for (int i = 0; i < 10; ++i) {
			Base *base = generate(); // Allocate dynamically
			std::cout << i + 1 << ": ";
			identify(base);
			delete base; // Free memory to prevent leaks
		}
		std::cout << "____________________\n\n";
	}
	{
		// Test random objects with references.
		// Verifies try-catch blocks handle std::bad_cast.
		std::cout << "TEST 2 with Base reference\n\n";
		for (int i = 0; i < 10; ++i) {
			Base *base = generate();
			std::cout << i + 1 << ": ";
			identify(*base); // Dereference pointer for reference parameter
			delete base;
		}
		std::cout << "____________________\n\n";
	}
	{
		// Test explicit pointers without randomness.
		// Tests implicit upcasting (e.g. A* to Base*).
		std::cout << "TEST 3 with explicit Base pointers\n\n";
		A *a = new A;
		B *b = new B;
		C *c = new C;
		identify(a);
		identify(b);
		identify(c);
		delete a;
		delete b;
		delete c;
		std::cout << "____________________\n\n";
	}
	{
		// Test stack-allocated objects with references.
		// No new keyword, memory is managed automatically.
		std::cout << "TEST 4 with explicit Base reference\n\n";
		A a;
		B b;
		C c;
		identify(a); // Implicit upcast (A& to Base&)
		identify(b);
		identify(c);
		std::cout << "____________________\n\n";
	}

    /*
    {
        std::cout << "TEST 5 with unknown class D (Pointer)\n\n";
        Base* unknown_ptr = new D();
        
        // dynamic_cast<A*>, <B*>, and <C*> will all return nullptr.
        // The function will finish without printing anything.
        identify(unknown_ptr);
        
        delete unknown_ptr;
        std::cout << "____________________\n\n";
    }

    {
        std::cout << "TEST 6 with unknown class D (Reference)\n\n";
        D unknown_ref;
        
        // dynamic_cast<A&>, <B&>, and <C&> will all throw std::bad_cast.
        // Your empty catch(...) blocks will swallow all of them.
        // The function will finish without printing anything.
        identify(unknown_ref);
        
        std::cout << "____________________\n\n";
    }
        */
	
	return 0;
}
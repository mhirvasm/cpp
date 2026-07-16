#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"




int main()
{
    // ---------------------------------------------------------
    // TEST 1: Form Instantiation Exceptions
    // ---------------------------------------------------------
    std::cout << "--- Testing Form Bounds ---" << std::endl;
    
    try 
    {
        // Attempt to create a form with a signGrade of 0 (Too High)
        // This should throw Form::GradeTooHighException
        Form invalidFormHigh("Classified", 0, 50); 
    }
    catch (std::exception & e) 
    {
        // Catch the exception and print the what() message
        std::cerr << "Caught expected error: " << e.what() << std::endl;
    }

    try 
    {
        // Attempt to create a form with an execGrade of 151 (Too Low)
        // This should throw Form::GradeTooLowException
        Form invalidFormLow("Useless", 50, 151); 
    }
    catch (std::exception & e) 
    {
        // Catch the exception and print the what() message
        std::cerr << "Caught expected error: " << e.what() << std::endl;
    }

    // ---------------------------------------------------------
    // TEST 2: Valid Form Instantiation & Output
    // ---------------------------------------------------------
    std::cout << "\n--- Testing Valid Form ---" << std::endl;
    try 
    {
        Form validForm("Tax Return", 50, 50);
        std::cout << validForm;
    }
    catch (std::exception & e) 
    {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    // ---------------------------------------------------------
    // TEST 3: Successful Signature
    // ---------------------------------------------------------
    std::cout << "\n--- Testing Successful Signature ---" << std::endl;
    try 
    {
        Bureaucrat highRanker("Alice", 10);
        Form easyForm("Form 101", 20, 20);
        
        highRanker.signForm(easyForm);
        std::cout << "State after signature attempt:\n" << easyForm;
    }
    catch (std::exception & e) 
    {
        std::cerr << "Unexpected error in test execution: " << e.what() << std::endl;
    }

    // ---------------------------------------------------------
    // TEST 4: Failed Signature
    // ---------------------------------------------------------
    std::cout << "\n--- Testing Failed Signature ---" << std::endl;
    try 
    {
        Bureaucrat lowRanker("Bob", 100);
        Form hardForm("Classified Document", 10, 10);
        
        lowRanker.signForm(hardForm);
        std::cout << "State after signature attempt:\n" << hardForm;
    }
    catch (std::exception & e) 
    {
        std::cerr << "Unexpected error in test execution: " << e.what() << std::endl;
    }
}
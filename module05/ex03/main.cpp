#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Intern.hpp"


    int main()
{
    // Seed the random number generator for RobotomyRequestForm probability
    std::srand(std::time(NULL));

    Intern intern;

    std::cout << "--- 1. Testing ShrubberyCreationForm (Sign 145, Exec 137) ---" << std::endl;
    try
    {
        Bureaucrat low("Intern", 150);
        Bureaucrat mid("Manager", 138);
        Bureaucrat high("CEO", 1);
        ShrubberyCreationForm tree("Home");

        // Intern attempts to sign (grade 150 > 145). Should fail.
        low.signForm(tree);

        // Manager attempts to sign (grade 138 <= 145). Should succeed.
        mid.signForm(tree);

        // Manager attempts to execute (grade 138 > 137). Should fail.
        mid.executeForm(tree);

        // CEO attempts to execute (grade 1 <= 137). Should succeed and create file.
        high.executeForm(tree);
    }
    catch (std::exception & e)
    {
        std::cerr << "Unexpected exception in Shrubbery test: " << e.what() << std::endl;
    }
    
    // ---------------------------------------------------------
    // 2. Testing RobotomyRequestForm (Sign 72, Exec 45)
    // ---------------------------------------------------------
    std::cout << "\n--- 2. Testing RobotomyRequestForm (Sign 72, Exec 45) ---" << std::endl;
    try
    {
        // Manager grade 40 is sufficient to both sign (72) and execute (45).
        Bureaucrat mid("Manager", 40);
        RobotomyRequestForm robot("Bender");

        // Form must be signed before execution.
        mid.signForm(robot);

        // Execute in a loop to observe the 50% probability output.
        for (int i = 0; i < 5; ++i)
        {
            mid.executeForm(robot);
        }
    }
    catch (std::exception & e)
    {
        std::cerr << "Unexpected exception in Robotomy test: " << e.what() << std::endl;
    }

    // ---------------------------------------------------------
    // 3. Testing PresidentialPardonForm (Sign 25, Exec 5)
    // ---------------------------------------------------------
    std::cout << "\n--- 3. Testing PresidentialPardonForm (Sign 25, Exec 5) ---" << std::endl;
    try
    {
        // CEO grade 1 is the highest and clears all requirements.
        Bureaucrat high("CEO", 1);
        PresidentialPardonForm pardon("Arthur Dent");

        // Bureaucrat signs and executes the form.
        high.signForm(pardon);
        high.executeForm(pardon);
    }
    catch (std::exception & e)
    {
        std::cerr << "Unexpected exception in Presidential test: " << e.what() << std::endl;
    }

    // ---------------------------------------------------------
    // 4. Testing Unsigned Execution Exception
    // ---------------------------------------------------------
    std::cout << "\n--- 4. Testing Unsigned Execution Exception ---" << std::endl;
    try
    {
        // Bureaucrat has sufficient grade to execute.
        Bureaucrat high("CEO", 1);
        ShrubberyCreationForm unsignedTree("Nowhere");

        // Bureaucrat attempts execution without signing the form first.
        // checkExecutionRequirements will throw AForm::NotSignedException.
        // executeForm will catch it and print the failure message.
        high.executeForm(unsignedTree);
    }
    catch (std::exception & e)
    {
        std::cerr << "Unexpected exception in Unsigned test: " << e.what() << std::endl;
    }

    {
		std::cout << "----------TEST 5----------\n\n";
		Intern bob(intern);
		AForm *form = bob.makeForm("shrubbery creation", "Back yard");
		delete form;

		Intern steve = bob;
		form = steve.makeForm("robotomy request", "Bjorn");
		delete form;
        
		Intern mike;
		mike = steve;
		form = mike.makeForm("presidential pardon", "Hans");
		delete form;
	}
    
    return 0;
}
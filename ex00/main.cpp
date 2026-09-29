#include "Bureaucrat.hpp"

int main() 
{
    std::cout << "Basic construction:\n";
	try {
		Bureaucrat a("A", 1);
		std::cout << a << "\n";
		Bureaucrat b("B", 150);
		std::cout << b << "\n";
	} catch (const std::exception& e) {
		std::cout << "Construction failed: " << e.what() << "\n";
	}

	std::cout << "\nInvalid construction:\n";
	try {
		Bureaucrat bad1("BadLow", 0);
		std::cout << bad1 << "\n";
	} catch (const std::exception& e) {
		std::cout << "Caught (grade 0): " << e.what() << "\n";
	}
	try {
		Bureaucrat bad2("BadHigh", 151);
		std::cout << bad2 << "\n";
	} catch (const std::exception& e) {
		std::cout << "Caught (grade 151): " << e.what() << "\n";
	}

	std::cout << "\nIncrement / decrement boundaries:\n";
	try {
		Bureaucrat top("Top", 1);
		std::cout << top << " -> increment\n";
		top.incrementGrade();
	} catch (const std::exception& e) {
		std::cout << "Increment at 1 threw: " << e.what() << "\n";
	}
	try {
		Bureaucrat bottom("Bottom", 150);
		std::cout << bottom << " -> decrement\n";
		bottom.decrementGrade();
	} catch (const std::exception& e) {
		std::cout << "Decrement at 150 threw: " << e.what() << "\n";
	}
	std::cout << "\nNormal moves:\n";
	try {
		Bureaucrat mid("Mid", 42);
		std::cout << mid << "\n";
		mid.incrementGrade();
		std::cout << "After increment: " << mid << "\n";
		mid.decrementGrade();
		std::cout << "After decrement: " << mid << "\n";
	} catch (const std::exception& e) {
		std::cout << "Mid ops failed: " << e.what() << "\n";
	}
	return 0;
}
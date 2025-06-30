#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    std::cout << "=== FORM AND BUREAUCRAT TESTING ===" << std::endl;
    
    // Test 1: Form creation and basic functionality
    std::cout << "\n1. Creating forms with valid grades:" << std::endl;
    try {
        Form tax("Tax Return", 50, 25);
        Form passport("Passport Application", 20, 10);
        Form permit("Building Permit", 100, 75);
        
        std::cout << tax << std::endl;
        std::cout << passport << std::endl;
        std::cout << permit << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test 2: Form creation with invalid grades (too high)
    std::cout << "\n2. Testing form creation with grade too high (0):" << std::endl;
    try {
        Form invalid("Invalid Form", 0, 50);
        std::cout << invalid << std::endl;
    } catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    // Test 3: Form creation with invalid grades (too low)
    std::cout << "\n3. Testing form creation with grade too low (151):" << std::endl;
    try {
        Form invalid("Invalid Form", 50, 151);
        std::cout << invalid << std::endl;
    } catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    // Test 4: Successful form signing
    std::cout << "\n4. Testing successful form signing:" << std::endl;
    try {
        Bureaucrat alice("Alice", 25);
        Form contract("Contract", 30, 20);
        
        std::cout << "Before signing: " << contract << std::endl;
        std::cout << "Bureaucrat: " << alice << std::endl;
        
        alice.signForm(contract);
        std::cout << "After signing: " << contract << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test 5: Failed form signing (grade too low)
    std::cout << "\n5. Testing failed form signing (bureaucrat grade too low):" << std::endl;
    try {
        Bureaucrat bob("Bob", 80);
        Form secureDoc("Top Secret Document", 20, 10);
        
        std::cout << "Before signing attempt: " << secureDoc << std::endl;
        std::cout << "Bureaucrat: " << bob << std::endl;
        
        bob.signForm(secureDoc);
        std::cout << "After signing attempt: " << secureDoc << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test 6: Edge case - exact grade match
    std::cout << "\n6. Testing exact grade match:" << std::endl;
    try {
        Bureaucrat charlie("Charlie", 42);
        Form report("Monthly Report", 42, 30);
        
        std::cout << "Before signing: " << report << std::endl;
        std::cout << "Bureaucrat: " << charlie << std::endl;
        
        charlie.signForm(report);
        std::cout << "After signing: " << report << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test 7: High-grade bureaucrat signing multiple forms
    std::cout << "\n7. Testing high-grade bureaucrat signing multiple forms:" << std::endl;
    try {
        Bureaucrat director("Director", 1);
        Form form1("Application A", 50, 25);
        Form form2("Application B", 10, 5);
        Form form3("Application C", 100, 75);
        
        std::cout << "Bureaucrat: " << director << std::endl;
        std::cout << "\nSigning multiple forms:" << std::endl;
        
        director.signForm(form1);
        director.signForm(form2);
        director.signForm(form3);
        
        std::cout << "\nFinal status:" << std::endl;
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;
        std::cout << form3 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test 8: Form copy and assignment
    std::cout << "\n8. Testing form copy constructor and assignment:" << std::endl;
    try {
        Form original("Original Form", 50, 30);
        Bureaucrat signer("Signer", 25);
        
        std::cout << "Original before signing: " << original << std::endl;
        signer.signForm(original);
        std::cout << "Original after signing: " << original << std::endl;
        
        Form copy(original);
        std::cout << "Copy: " << copy << std::endl;
        
        Form assigned("Temp Form", 100, 80);
        std::cout << "Before assignment: " << assigned << std::endl;
        assigned = original;
        std::cout << "After assignment: " << assigned << std::endl;
        // Note: name and grades should remain the same since they're const
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test 9: Testing grade increments/decrements affecting signing ability
    std::cout << "\n9. Testing grade changes affecting signing ability:" << std::endl;
    try {
        Bureaucrat employee("Employee", 51);
        Form document("Important Document", 50, 25);
        
        std::cout << "Initial state:" << std::endl;
        std::cout << "Bureaucrat: " << employee << std::endl;
        std::cout << "Form: " << document << std::endl;
        
        std::cout << "\nTrying to sign with grade 51 (should fail):" << std::endl;
        employee.signForm(document);
        
        std::cout << "\nIncrementing grade to 50:" << std::endl;
        employee.incrementGrade();
        std::cout << "Bureaucrat after increment: " << employee << std::endl;
        
        std::cout << "\nTrying to sign with grade 50 (should succeed):" << std::endl;
        employee.signForm(document);
        std::cout << "Final form state: " << document << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== END OF TESTING ===" << std::endl;
    return 0;
}

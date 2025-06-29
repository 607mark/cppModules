#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    std::cout << "=== Bureaucrat Testing ===" << std::endl;
    
    // Test 1: Valid bureaucrat creation
    std::cout << "\n1. Creating valid bureaucrats:" << std::endl;
    try {
        Bureaucrat bob("Bob", 75);
        Bureaucrat alice("Alice", 1);
        Bureaucrat charlie("Charlie", 150);
        
        std::cout << bob << std::endl;
        std::cout << alice << std::endl;
        std::cout << charlie << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test 2: Invalid grade (too high)
    std::cout << "\n2. Testing grade too high (0):" << std::endl;
    try {
        Bureaucrat invalid("Invalid", 0);
        std::cout << invalid << std::endl;
    } catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    // Test 3: Invalid grade (too low)
    std::cout << "\n3. Testing grade too low (151):" << std::endl;
    try {
        Bureaucrat invalid("Invalid", 151);
        std::cout << invalid << std::endl;
    } catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    // Test 4: Increment grade
    std::cout << "\n4. Testing grade increment:" << std::endl;
    try {
        Bureaucrat worker("Worker", 50);
        std::cout << "Before increment: " << worker << std::endl;
        worker.incrementGrade();
        std::cout << "After increment: " << worker << std::endl;
        worker.incrementGrade();
        std::cout << "After second increment: " << worker << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test 5: Decrement grade
    std::cout << "\n5. Testing grade decrement:" << std::endl;
    try {
        Bureaucrat manager("Manager", 10);
        std::cout << "Before decrement: " << manager << std::endl;
        manager.decrementGrade();
        std::cout << "After decrement: " << manager << std::endl;
        manager.decrementGrade();
        std::cout << "After second decrement: " << manager << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test 6: Increment at highest grade (should throw exception)
    std::cout << "\n6. Testing increment at highest grade (1):" << std::endl;
    try {
        Bureaucrat top("TopBoss", 1);
        std::cout << "Before increment: " << top << std::endl;
        top.incrementGrade();
        std::cout << "After increment: " << top << std::endl;
    } catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    // Test 7: Decrement at lowest grade (should throw exception)
    std::cout << "\n7. Testing decrement at lowest grade (150):" << std::endl;
    try {
        Bureaucrat bottom("BottomWorker", 150);
        std::cout << "Before decrement: " << bottom << std::endl;
        bottom.decrementGrade();
        std::cout << "After decrement: " << bottom << std::endl;
    } catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    // Test 8: Copy constructor and assignment
    std::cout << "\n8. Testing copy constructor and assignment:" << std::endl;
    try {
        Bureaucrat original("Original", 42);
        std::cout << "Original: " << original << std::endl;
        
        Bureaucrat copy(original);
        std::cout << "Copy: " << copy << std::endl;
        
        Bureaucrat assigned("Temp", 100);
        std::cout << "Before assignment: " << assigned << std::endl;
        assigned = original;
        std::cout << "After assignment: " << assigned << std::endl;
        
        // Note: name should remain "Temp" since it's const
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== End of testing ===" << std::endl;
    return 0;
}

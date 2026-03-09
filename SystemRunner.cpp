#include "MenuManager.h"
#include <iostream>

using namespace std;

int main() {
    Restaurant system;
    int userChoice;

    cout << "Welcome to the ITM Restaurant Order Management System" << endl;

    do {
        // Requirement 2: Order Operations menu
        cout << "\n1. Place Order" << endl;
        cout << "2. Modify Order" << endl;
        cout << "3. Generate Bill" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> userChoice;

        switch (userChoice) {
            case 1: 
                system.placeOrder(); 
                break;
            case 2: 
                system.modifyOrder(); 
                break;
            case 3: 
                system.generateBill(); 
                break;
            case 4: 
                cout << "Exiting system. Have a great day!" << endl; 
                break;
            default: 
                cout << "Invalid choice. Please select from 1-4." << endl;
        }
    } while (userChoice != 4);

    return 0;
}
#include "MenuManager.h"
#include <iostream>

using namespace std;

Restaurant::Restaurant() {
    // Initializing the menu with sample items and prices
    menu = {
        {"Burger", 150.0}, 
        {"Pizza", 450.0}, 
        {"Pasta", 300.0}, 
        {"Cold Coffee", 180.0}
    };
}

void Restaurant::showMenu() {
    cout << "\n--- RESTAURANT MENU ---" << endl;
    for (size_t i = 0; i < menu.size(); i++) {
        cout << i + 1 << ". " << menu[i].name << " - Rs." << menu[i].price << endl;
    }
}

void Restaurant::placeOrder() {
    int choice;
    showMenu();
    cout << "\nEnter Item Number to add to your order (Press 0 to finish): ";
    
    while (cin >> choice && choice != 0) {
        if (choice > 0 && choice <= menu.size()) {
            currentOrder.push_back(menu[choice - 1]);
            cout << ">> " << menu[choice - 1].name << " added." << endl;
        } else {
            cout << "Invalid item number. Try again." << endl;
        }
        cout << "Add another item? (Press 0 to finish): ";
    }
    // Matches the required "Example Output" from your case study
    cout << "\nOrder Placed Successfully" << endl; 
}

void Restaurant::modifyOrder() {
    if (currentOrder.empty()) {
        cout << "\nYour order is currently empty!" << endl;
        return;
    }
    
    cout << "\n--- Your Current Order ---" << endl;
    for (size_t i = 0; i < currentOrder.size(); i++) {
        cout << i + 1 << ". " << currentOrder[i].name << " (Rs." << currentOrder[i].price << ")" << endl;
    }
    
    cout << "Enter Item Number to remove from order (Press 0 to cancel): ";
    int idx;
    cin >> idx;
    
    if (idx > 0 && idx <= currentOrder.size()) {
        currentOrder.erase(currentOrder.begin() + (idx - 1));
        cout << "Item removed successfully." << endl;
    } else if (idx != 0) {
        cout << "Invalid selection." << endl;
    }
}

void Restaurant::generateBill() {
    if (currentOrder.empty()) {
        cout << "\nNo items ordered yet." << endl;
        return;
    }

    double total = 0;
    cout << "\n========================" << endl;
    cout << "       FINAL BILL       " << endl;
    cout << "========================" << endl;
    
    for (const auto& item : currentOrder) {
        cout << item.name << " \t\t Rs." << item.price << endl;
        total += item.price;
    }
    
    cout << "------------------------" << endl;
    // Matches the required "Example Output"
    cout << "Total Bill: \t Rs." << total << endl; 
    cout << "========================\n" << endl;
    
    // Clear the order for the next customer
    currentOrder.clear(); 
}
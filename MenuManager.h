#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include <string>
#include <vector>

// Requirement 1: Menu Details (Item name, Item price)
struct MenuItem {
    std::string name;
    double price;
};

class Restaurant {
private:
    std::vector<MenuItem> menu;
    std::vector<MenuItem> currentOrder;

public:
    Restaurant(); 
    void showMenu();
    void placeOrder();
    void modifyOrder();
    void generateBill();
};

#endif
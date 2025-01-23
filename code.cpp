#include <iostream>
#include <vector>
#include <string>

class FoodItem {
public:
    std::string name;
    double price;

    FoodItem(std::string name, double price) : name(name), price(price) {}
};
//FUNCTION
class Order {
public:
    std::vector<FoodItem> items;
    double totalPrice;

    Order() : totalPrice(0.0) {}

    void addItem(const FoodItem& item) {
        items.push_back(item);
        totalPrice += item.price;
    }

    void showOrder() {
        std::cout << "Order Details:" << std::endl;
        for (const auto& item : items) {
            std::cout << item.name << " - " << item.price << " PKR" << std::endl;
        }
        std::cout << "Total Price: " << totalPrice << " PKR" << std::endl;
    }
};

int main() {
    std::vector<FoodItem> menu = {
        FoodItem("Burger", 250.0),
        FoodItem("Pizza", 500.0),
        FoodItem("Pasta", 300.0),
        FoodItem("Salad", 150.0)
    };

    Order myOrder;

    int choice = 0;
    std::cout << "Welcome to the Food Delivery System!" << std::endl;
    while (choice != -1) {
        std::cout << "Menu:" << std::endl;
        for (int i = 0; i < menu.size(); ++i) {
            std::cout << i + 1 << ". " << menu[i].name << " - " << menu[i].price << " PKR" << std::endl;
        }
        std::cout << "Enter the number of the item to add to your order (-1 to finish): ";
        std::cin >> choice;

        if (choice > 0 && choice <= menu.size()) {
            myOrder.addItem(menu[choice - 1]);
        } else if (choice != -1) {
            std::cout << "Invalid choice, please try again." << std::endl;
        }
    }

    myOrder.showOrder();
    return 0;
}

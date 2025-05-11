#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SanskritiCanteen {
private:
    struct MenuItem {
        int id;
        string name;
        double price;
    };

    struct Order {
        int orderId;
        string studentName;
        vector<int> itemIds;
        double netAmount;
    };

    vector<MenuItem> menu;
    vector<Order> orders;

    // Unique IDs for next menu item and/or order
    int nextMenuId = 1;
    int nextOrderId = 1;

public:
    void addMenuItem() {
        string name;
        double price;
        cout << "Enter item name: ";
        // Clear input buffer
        cin.ignore();  
        getline(cin, name);
        cout << "Enter item price: ";
        cin >> price;

        menu.push_back({nextMenuId++, name, price});
        cout << "Menu item added successfully!\n";
    }

    void displayMenu() const {
        cout << "\nMenu:\n";
        for (const auto& item : menu) {
            cout << "ID: " << item.id << ", Name: " << item.name << ", Price: Rs" << item.price << '\n';
        }
    }

    void placeOrder() {
        string studentName;
        int itemCount, itemId;

        cout << "Dear student, please enter your name: ";
        cin.ignore();
        getline(cin, studentName);

        cout << "How many items do you want to order? ";
        cin >> itemCount;

        if (itemCount <= 0) {
            cout << "Invalid item count.\n";
            return;
        }

        vector<int> chosenItems;
        for (int i = 0; i < itemCount; ++i) {
            cout << "Enter item ID #" << (i + 1) << ": ";
            cin >> itemId;
            chosenItems.push_back(itemId);
        }

        double total = 0.0;
        vector<int> validItems;
        for (int id : chosenItems) {
            bool found = false;
            for (const auto& item : menu) {
                if (item.id == id) {
                    total += item.price;
                    validItems.push_back(id);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Invalid item ID: " << id << " (ignored)\n";
            }
        }

        if (!validItems.empty()) {
            orders.push_back({nextOrderId++, studentName, validItems, total});
            cout << "Order placed! Total: Rs" << total << '\n';
        } else {
            cout << "No valid items in the order. Nothing was placed.\n";
        }
    }

    void displayOrders() const {
        cout << "\nAll Orders:\n";
        for (const auto& order : orders) {
            cout << "Order ID: " << order.orderId
                 << ", Customer: " << order.studentName
                 << ", Total: Rs" << order.netAmount << '\n';
        }
    }
};

int main() {
    SanskritiCanteen canteen;
    int choice;

    do {
        cout << "\n--- Sanskriti Canteen System! ---\n";
        cout << "1. Add Menu Item\n";
        cout << "2. Display Menu\n";
        cout << "3. Place Order\n";
        cout << "4. Display Orders\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;


        // utilizing switch-case for menu options
        switch (choice) { 
            case 1:
                canteen.addMenuItem();
                break;
            case 2:
                canteen.displayMenu();
                break;
            case 3:
                canteen.displayMenu();
                canteen.placeOrder();
                break;
            case 4:
                canteen.displayOrders();
                break;
            case 5:
                cout << "Thank you! Visit again.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

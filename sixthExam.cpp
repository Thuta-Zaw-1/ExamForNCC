#include "iostream"
using namespace std;

class Food {
private:

    string foodName;
    int foodPrice=0;

public:

    Food(string name, int price) {

        foodName = name;
        foodPrice = price;
    }

    string getFoodName() {
        return foodName;
    }

    int getFoodPrice() {
        return foodPrice;
    }

};


class Main {
public:

    Food foodList[5] = {Food("Steak", 100),
                       Food("FriedChicken", 60),
                       Food("Crisp", 30),
                       Food("Sandwich", 50),
                       Food("hamburger", 60)
    };

    string orderedFood[100];
    int locate=0;
    int mainMenu();
    void showFoodList();
    void orderFood();
    void showBill();
};

void Main::showFoodList() {

    int size = sizeof(foodList) / sizeof(foodList[0]);

    cout << "************* Food List ************" << endl;
    for(int i=0; i<size; i++) {

        cout << " | name: " << foodList[i].getFoodName();
        cout << " |price: " << foodList[i].getFoodPrice();
        cout << endl;
    }
}

int Main::mainMenu() {

    int option = 0;
    string choosedName;

    while (true) {

        cout << "Press1 to Food: ";
        cin >> option;

        if (option == 1) {
            showFoodList();
            orderFood();

        } else {
            cout << "Please enter only press1 and press2!" << endl;
        }

    }
    return 0;
}

void Main::orderFood() {

    int optionOrder = 0;
    cout << "************ To Order Food ************" << endl;
    while (true) {

        int orderOption=0;
        cout << "Press1 to order Steak" << endl;
        cout << "Press2 to order FriedChicken" << endl;
        cout << "Press3 to order Crisp" << endl;
        cout << "Press4 to order Sandwich" << endl;
        cout << "Press5 to order Hamburger : ";
        cin >> orderOption;
        if (orderOption == 1) {
            orderedFood[locate] = "Steak";
        } else if (orderOption == 2) {
            orderedFood[locate] = "FriedChicken";
        } else if (orderOption == 3) {
            orderedFood[locate] = "Crisp";
        } else if (orderOption == 4) {
            orderedFood[locate] = "Sandwich";
        } else if (orderOption == 5) {
            orderedFood[locate] = "Hamburger";
        } else {
            cout << "Invalid Number!" << endl;
        }
        locate++;

        cout << "Press1 to order again\nPress2 to stop orders: ";
        cin >> optionOrder;
        if (optionOrder == 1) {
            continue;
        } else {
            showBill();
            break;
        }

    }
}

void Main::showBill() {
    cout << "************ Bill ***********" << endl;

    int total=0;

    for(int a=0; a<locate; a++) {
        cout << orderedFood[a] << endl;
    }

    int foodSize = sizeof(foodList) / sizeof(foodList[0]);

    for (int i=0; i<locate; i++) {
        int ii=0;
        while (ii<foodSize) {
            if (orderedFood[i] == foodList[ii].getFoodName()) {
                cout << orderedFood[i] << "->" << foodList[ii].getFoodPrice() << endl;
                total += foodList[ii].getFoodPrice();
            }
            ii++;
        }
    }
    cout << "total is " << total << endl;

}


int main() {
    Main m;
    m.mainMenu();

    return 0;
}

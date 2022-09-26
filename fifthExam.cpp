#include "iostream"
using namespace std;

class User {
private:
    int id;
    string name;
    int amount;

public:
    User(int id, string name, int amount) {
        this->id = id;
        this->name = name;
        this->amount = amount;
    }

    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    int getAmount() {
        return amount;
    }

};

void insertData(User user) {
    FILE *fptr;
    fptr = fopen("user.txt", "a");
    if (fptr == NULL) {
        cout << "File can't open!" << endl;
        exit(1);
    }
    fprintf(fptr, "%d  %s  %d\n", user.getId(), user.getName().c_str(), user.getAmount());
    fclose(fptr);

}

void findDataByName(int findId){

    FILE *fptr;
    if ((fptr = fopen("user.txt", "r")) == NULL) {
        printf("File is empty!");
        exit(1);
    }

    int id = 0;
    int amount = 0;
    string name;

    while ((fscanf(fptr, "%d  %s  %d\n", &id, name.c_str(), &amount)) != EOF) {
        if(findId == id) {
            printf("%d  %s  %d\n", id, name.c_str(), amount);
            break;
        }

    }

    fclose(fptr);
};

int main() {

    int id = 0;
    string name;
    int amount = 0;
    int b = 0;

    while (true) {
        int press = 0;
        cout << "Press1 to insert Data\nPress2 to find Data : ";
        cin >> press;
        if (press == 1) {
            cout << "Please enter id to insert data :";
            cin >> id;

            cout << "Please enter name to insert data :";
            cin >> name;

            cout << "Please enter amount to insert data :";
            cin >> amount;

            User user(id, name, amount);

            insertData(user);

            while (true) {
                int option = 0;
                cout << "Option1 to handle data more\nOption2 to exit : ";
                cin >> option;
                if (option == 1) {
                    break;
                } else if (option == 2) {
                    exit(1);
                } else {
                    cout << "Please choose only option1 and option2!" << endl;
                }
            }

        } else if (press == 2) {
            cout << "Please enter name to find data : ";
            cin >> id;

            findDataByName(id);
            while (true) {
                int option = 0;
                cout << "Option1 to handle data more\nOption2 to exit : ";
                cin >> option;
                if (option == 1) {
                    break;
                } else if (option == 2) {
                    exit(1);
                } else {
                    cout << "Please choose only option1 and option2!" << endl;
                }
            }
        } else {
            cout << "Please enter only press 1 and press2!" << endl;
        }
    }

}

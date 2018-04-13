#include <iostream>
#include <stdlib.h>
#include <string>
#include <limits>
#include "sortedtype.cpp"
using namespace std;

int main_menu_choice = 0;
int actions_menu_choice = 5;
static SortedType<string, long int, string, string> st;

void insertUser(){
    if(st.IsFull()){
        cout << "Oops, ran out of memory" << endl;
    }else{
        int exit = 0;
        do{
                cout<< "Enter Name: ";
                string name;
                cin.ignore();
                getline(cin, name);
                bool foundName;
                st.CheckForSimilarName(name, foundName);
                if(!foundName){
                    cout<< "Enter Contact Number: ";
                    long int num;
                    cin >> num;
                    while(!cin){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout<< "Not a Number!\n";
                        cout<< "Enter Contact Number: ";
                        cin >> num;
                    }
                    bool found;
                    st.CheckForSimilarNumber(num, found);
                    if(!found){
                        cout<< "Enter Email: ";
                        string email;
                        cin.ignore();
                        getline(cin, email);
                        cout<< "Enter Address: ";
                        string address;
                        cin.ignore();
                        getline(cin, address);
                        cout<< "Mark as Favorite (y/n): ";
                        char important;
                        cin >> important;

                        st.InsertItem(name, num, email, address, important);
                        if(foundName)
                            cout << "This Name already exists!" << endl;
                    } else {
                        cout << "This Number already exists!" << endl;
                    }
                }  else {
                    cout << "This Name already exists!" << endl;
                }

            cout << endl;
            cout << "Enter '1' to go back" << endl;
            cin >> exit;
        }while(exit != 1);
    }
}

void deleteUser(){
    int exit = 0;
    do{
        cout<< "Enter Contact Number to Delete: ";
        long int num = 0;
        cin >> num;
        st.DeleteItem(num);
        cout << endl;
        cout << "Enter '1' to go back" << endl;
        cin >> exit;
    }while(exit != 1);
}

void clearPhonebook(){
    int exit = 0;
    do{
        st.MakeEmpty();
        cout<< "Phonebook is Empty.\n";
        cout << endl;
        cout << "Enter '1' to go back" << endl;
        cin >> exit;
    }while(exit != 1);
}

void searchUser(){
    int exit = 0;
    do{
        cout << "Enter Search Input: ";
        string searchInput;
        cin.ignore();
        getline(cin, searchInput);
        st.RetrieveItem(searchInput);
        cout << endl;
        cout << "Enter '1' to go back" << endl;
        cin >> exit;
    }while(exit != 1);
}

void viewAll(){
    int exit = 0;
    do{
        st.PrintList();
        cout << "Enter '1' to go back" << endl;
        cin >> exit;
    }while(exit != 1);
}

void viewFavorite(){
    int exit = 0;
    do{
        cout << "Favorite Contacts\n";
        cout << "---------------------------------------\n";
        st.PrintFavoriteList();
        cout << endl;
        cout << "Enter '1' to go back" << endl;
        cin >> exit;
    }while(exit != 1);
}

void actions() {
    actions_menu_choice = 0;
    do {
        system("cls");
        cout << "\t\t\t\tPHONE BOOK\n";
        cout << "===============================================================================\n";
        cout << "Actions Menu\n";
        cout << "---------------------------------------\n";
        cout << "1 - Insert Contact\n";
        cout << "2 - Delete Contact\n";
        cout << "3 - Clear PhoneBook\n";
        cout << "4 - Search Contacts\n";
        cout << "5 - Back\n";
        cout << "Choose Option Number: ";
        cin >> actions_menu_choice;
        switch(actions_menu_choice){
            case 1:
                system("cls");
                cout << "\t\t\t\tPHONE BOOK\n";
                cout << "===============================================================================\n";
                insertUser();
                break;
            case 2:
                system("cls");
                cout << "\t\t\t\tPHONE BOOK\n";
                cout << "===============================================================================\n";
                deleteUser();
                break;
            case 3:
                system("cls");
                cout << "\t\t\t\tPHONE BOOK\n";
                cout << "===============================================================================\n";
                clearPhonebook();
                break;
            case 4:
                system("cls");
                cout << "\t\t\t\tPHONE BOOK\n";
                cout << "===============================================================================\n";
                searchUser();
                break;
            case 5:
                break;

        }
    } while(actions_menu_choice != 5);
}

int main()
{
    do{
        system("cls");
        cout << "\t\t\t\tPHONE BOOK\n";
        cout << "===============================================================================\n";
        cout << "1 - View All Contacts\n";
        cout << "2 - View Favorite Contacts\n";
        cout << "3 - Actions\n";
        cout << "4 - Exit\n";
        cout << "Choose Option Number: ";
        cin >> main_menu_choice;
        switch(main_menu_choice) {
            case 1:
                system("cls");// Windows system("cls");
                cout << "\t\t\t\tPHONE BOOK\n";
                cout << "===============================================================================\n";
                cout << "All " << st.LengthIs() <<" Users\n";
                viewAll();
                break;
            case 2:
                system("cls");
                cout << "\t\t\t\tPHONE BOOK\n";
                cout << "===============================================================================\n";
                viewFavorite();
                break;
            case 3:
                system("cls");
                cout << "\t\t\t\tPHONE BOOK\n";
                cout << "===============================================================================\n";
                actions();
                break;
            case 4:
                return 0;
        }
    } while(main_menu_choice != 4);
    return 0;
}

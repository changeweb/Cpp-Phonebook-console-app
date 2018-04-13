#include "sortedtype.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

template <class ItemType, class ItemType2, class ItemType3, class ItemType4>
SortedType<ItemType, ItemType2, ItemType3, ItemType4>::SortedType(){
    length = 0;
    listData = NULL;
    currentPos = NULL;
}
template <class ItemType, class ItemType2, class ItemType3, class ItemType4>
int SortedType<ItemType, ItemType2, ItemType3, ItemType4>::LengthIs(){
   return length;
}
template <class ItemType, class ItemType2, class ItemType3, class ItemType4>
bool SortedType<ItemType, ItemType2, ItemType3, ItemType4>::IsFull(){
    NodeType* location;
    try{
        location = new NodeType;
        delete location;
        return false;
    }catch(bad_alloc& exception){
        return true;
    }
}

template <class ItemType, class ItemType2, class ItemType3, class ItemType4>
void SortedType<ItemType, ItemType2, ItemType3, ItemType4>::InsertItem(ItemType item, ItemType2 item2, ItemType3 item3, ItemType4 item4, char important){
    NodeType* newNode;
    NodeType* predLoc;
    NodeType* location;
    bool moreToSearch;

    location = listData;
    predLoc = NULL;
    moreToSearch = (location != NULL);
    string origName = item;
    while(moreToSearch){
        string fullName = location->name;
        if(fullName.erase(remove(fullName.begin(),fullName.end(),' '),fullName.end()) < item.erase(remove(item.begin(),item.end(),' '),item.end())){
            predLoc = location;
            location = location->next;
            moreToSearch = (location != NULL);
        } else {
            moreToSearch = false;
        }
    }
    newNode = new NodeType;
    newNode->name = origName;
    newNode->phone = item2;
    newNode->email = item3;
    newNode->address = item4;
    newNode->important = (important == 'y')?'y':'n';

    if(predLoc == NULL){
        newNode->next = listData;
        listData = newNode;
    } else {
        newNode->next = location;
        predLoc->next = newNode;
    }
    length++;
}
template <class ItemType, class ItemType2, class ItemType3, class ItemType4>
void SortedType<ItemType, ItemType2, ItemType3, ItemType4>::DeleteItem(ItemType2 item){
    NodeType* location = listData;
    NodeType* tempLocation;
    if(item == listData->phone){
        tempLocation = location;
        listData = listData->next;
    } else {
        while(!(item == (location->next)->phone))
            location = location->next;
        tempLocation = location->next;
        location->next = (location->next)->next;
    }
    delete tempLocation;
    length--;
}
template <class ItemType, class ItemType2, class ItemType3, class ItemType4>
void SortedType<ItemType, ItemType2, ItemType3, ItemType4>::RetrieveItem(ItemType item){
    int count = 0;
    string buf;
    stringstream ss(item); // Insert the string into a stream

    vector<string> tokens;

    while (ss >> buf)
        tokens.push_back(buf);
    for(int i = 0; i < tokens.size(); i++){
        NodeType* location = listData;
        bool moreToSearch = (location != NULL);
        while(moreToSearch){
            string buf2;
            stringstream ss2(location->name); // Insert the string into a stream

            vector<string> tokens2;

            while (ss2 >> buf2)
                tokens2.push_back(buf2);
            for(int j = 0; j < tokens2.size(); j++){
                if(tokens2[j] == tokens[i]){
                    count++;
                    if(location->important == 'y')
                        cout << "Marked as Important!" << endl;
                    cout << "Name:    | " << location->name << endl;
                    cout << "Phone:   | " << location->phone << endl;
                    cout << "Email:   | " << location->email << endl;
                    cout << "Address: | " << location->address << endl;
                    cout << "---------------------------------------------------" << endl;
                    location = location->next;
                    moreToSearch = (location != NULL);
                    break;
                } else if(tokens[i] < tokens2[j]){
                    location = location->next;
                    moreToSearch = (location != NULL);
                } else {
                    moreToSearch = false;
                }
            }
        }
    }

    NodeType* location2 = listData;
    bool moreToSearch2 = (location2 != NULL);
    while(moreToSearch2 && count < length){

        if(atoi(item.c_str()) == location2->phone || item == location2->email || item == location2->address){
            if(location2->important == 'y')
                cout << "Marked as Important!" << endl;
            cout << "Name:    | " << location2->name << endl;
            cout << "Phone:   | " << location2->phone << endl;
            cout << "Email:   | " << location2->email << endl;
            cout << "Address: | " << location2->address << endl;
            cout << "---------------------------------------------------" << endl;
            if(atoi(item.c_str()) == location2->phone){
                moreToSearch2 = false;
            } else {
                location2 = location2->next;
                moreToSearch2 = (location2 != NULL);
                count++;
            }
        }else if(atoi(item.c_str()) < location2->phone || item < location2->email || item < location2->address){
            location2 = location2->next;
            moreToSearch2 = (location2 != NULL);
        } else {
            moreToSearch2 = false;
        }
    }
    if(count > 0){
        cout << count << " Match found." << endl;
    }
}
template <class ItemType, class ItemType2, class ItemType3, class ItemType4>
void SortedType<ItemType, ItemType2, ItemType3, ItemType4>::CheckForSimilarName(ItemType name, bool& found){
    NodeType* location = listData;
    bool moreToSearch = (location != NULL);
    found = false;
    while(moreToSearch && !found){
        if(name == location->name){
            found = true;
        }else if(name < location->name){
            location = location->next;
            moreToSearch = (location != NULL);
        } else {
            moreToSearch = false;
        }
    }
}
template <class ItemType, class ItemType2, class ItemType3, class ItemType4>
void SortedType<ItemType, ItemType2, ItemType3, ItemType4>::CheckForSimilarNumber(ItemType2 number, bool& found){
    NodeType* location = listData;
    bool moreToSearch = (location != NULL);
    found = false;
    while(moreToSearch && !found){
        if(number == location->phone){
            found = true;
        }else if(number < location->phone){
            location = location->next;
            moreToSearch = (location != NULL);
        } else {
            moreToSearch = false;
        }
    }
}
template <class ItemType, class ItemType2, class ItemType3, class ItemType4>
void SortedType<ItemType, ItemType2, ItemType3, ItemType4>::MakeEmpty(){
    NodeType* tempPtr;
    while(listData != NULL){
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}
template <class ItemType, class ItemType2, class ItemType3, class ItemType4>
SortedType<ItemType, ItemType2, ItemType3, ItemType4>::~SortedType(){
    MakeEmpty();
}
template <class ItemType, class ItemType2, class ItemType3, class ItemType4>
void SortedType<ItemType, ItemType2, ItemType3, ItemType4>::ResetList(){
    currentPos = NULL;
}
template <class ItemType, class ItemType2, class ItemType3, class ItemType4>
void SortedType<ItemType, ItemType2, ItemType3, ItemType4>::GetNextItem(ItemType& item, ItemType2& item2, ItemType3& item3, ItemType4& item4, char& important){
    if(currentPos == NULL)
        currentPos = listData;
    else
        currentPos = currentPos->next;
    item = currentPos->name;
    item2 = currentPos->phone;
    item3 = currentPos->email;
    item4 = currentPos->address;
    important = currentPos->important;
}
template <class ItemType, class ItemType2, class ItemType3, class ItemType4>
void SortedType<ItemType, ItemType2, ItemType3, ItemType4>::PrintFavoriteList(){
    int i = 0;
    int count = 0;
    while(i < length){
        ItemType name;
        ItemType2 phone;
        ItemType3 email;
        ItemType4 address;
        char important;
        GetNextItem(name, phone, email, address, important);
        if(important == 'y'){
            cout << "| Name:    | " << name << endl;
            cout << "| Phone:   | " << phone << endl;
            cout << "| Email:   | " << email << endl;
            cout << "| Address: | " << address << endl;
            cout << "---------------------------------------------------" << endl;
            count++;
        }
        i++;
    }
    currentPos = NULL;
    if(count == 0){
        cout << "No Favorite Contact Found!" << endl;
    }
}
template <class ItemType, class ItemType2, class ItemType3, class ItemType4>
void SortedType<ItemType, ItemType2, ItemType3, ItemType4>::PrintList(){
    int i = 0;
    while(i < length){
        ItemType name;
        ItemType2 phone;
        ItemType3 email;
        ItemType4 address;
        char important;
        GetNextItem(name, phone, email, address, important);
        if(important == 'y')
                cout << "Marked as Important!" << endl;
        cout << "| Name:    | " << name << endl;
        cout << "| Phone:   | " << phone << endl;
        cout << "| Email:   | " << email << endl;
        cout << "| Address: | " << address << endl;
        cout << "---------------------------------------------------" << endl;
        i++;
    }
    currentPos = NULL;
}

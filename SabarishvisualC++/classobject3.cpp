#include <iostream> 
#include <string> 
using namespace std; 

class List { 
private: 
    string items[10]; 
    bool bought[10]; 
    int count; 
public: 
    void initialize() { 
        count = 0; 
        for (int i = 0; i < 10; ++i) { 
            bought[i] = false; 
        } 
    } 

    void addItem(const string& name) { 
        if (count < 10) { 
            items[count] = name; 
            bought[count] = false; 
            count++; 
        } else { 
            cout << "List is full." << endl; 
        } 
    } 

    void display() { 
        for (int i = 0; i < count; ++i) { 
            cout << items[i] << (bought[i] ? " (Bought)" : " (Not Bought)") << endl; 
        } 
    } 

    int getCount() const { 
        return count; 
    } 

    friend void markAsBought(List& list, const string& name); 
}; 

void markAsBought(List& list, const string& name) { 
    for (int i = 0; i < list.count; ++i) { 
        if (list.items[i] == name) { 
            list.bought[i] = true;  
            break; 
        } 
    } 
} 

int main() { 
    List myList; 
    myList.initialize(); 
    string name; 
    cout << "Enter items for the list (max 10 items):" << endl; 
    while (myList.getCount() < 10) { 
        cout << "Enter item name (or 'done' to finish): "; 
        getline(cin, name); 
        if (name == "done") { 
            break; 
        } 
        myList.addItem(name); 
    } 
    cout << "List before processing:" << endl; 
    myList.display(); 
    while (true) { 
        cout << "Enter the name of an item to mark as bought (or 'done' to finish): "; 
        getline(cin, name); 
        if (name == "done") { 
            break; 
        } 
        markAsBought(myList, name); 
    } 
    cout << "List after processing:" << endl; 
    myList.display(); 
    return 0; 
}

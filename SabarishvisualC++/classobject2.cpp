#include <iostream>
#include <string>
using namespace std;

class SMgr {
public:
    string uID[100]; // Array for user IDs
    string sData[100]; // Array for session data
    static int cnt; // Static member for session count

    void createS(const string& id, const string& data) {
        if (cnt < 100) {
            uID[cnt] = id;
            sData[cnt] = data;
            cnt++;
            cout << "Session created for user: " << id << endl;
        } else {
            cout << "Session storage is full!" << endl;
        }
    }

    string getSData(const string& id) {
        for (int i = 0; i < cnt; ++i) {
            if (uID[i] == id) {
                return sData[i];
            }
        }
        return "Session not found for user: " + id;
    }

    void delS(const string& id) {
        bool found = false;
        for (int i = 0; i < cnt; ++i) {
            if (uID[i] == id) {
                found = true;
                for (int j = i; j < cnt - 1; ++j) {
                    uID[j] = uID[j + 1];
                    sData[j] = sData[j + 1];
                }
                cnt--;
                cout << "Session deleted for user: " << id << endl;
                break;
            }
        }
        if (!found) {
            cout << "No session found for user: " << id << endl;
        }
    }

    static void printS(const SMgr& mgr) {
        if (mgr.cnt == 0) {
            cout << "No sessions available." << endl;
        } else {
            cout << "Current Sessions:" << endl;
            for (int i = 0; i < mgr.cnt; ++i) {
                cout << "User: " << mgr.uID[i] << ", Data: " << mgr.sData[i] << endl;
            }
        }
    }
};

int SMgr::cnt = 0;

int main() {
    int ch;
    string id, data;
    SMgr mgr;

    do {
        cout << "\nSession Manager System\n";
        cout << "1. Create Session\n";
        cout << "2. Get Session Data\n";
        cout << "3. Delete Session\n";
        cout << "4. Print All Sessions\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        cin.ignore();

        switch (ch) {
            case 1:
                cout << "Enter User ID: ";
                getline(cin, id);
                cout << "Enter Session Data: ";
                getline(cin, data);
                mgr.createS(id, data);
                break;
            case 2:
                cout << "Enter User ID: ";
                getline(cin, id);
                cout << "Session Data: " << mgr.getSData(id) << endl;
                break;
            case 3:
                cout << "Enter User ID: ";
                getline(cin, id);
                mgr.delS(id);
                break;
            case 4:
                SMgr::printS(mgr);
                break;
            case 5:
                cout << "Exiting the system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    } while (ch != 5);

    return 0;
}

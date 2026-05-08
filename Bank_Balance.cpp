#include <iostream>
#include <map>
using namespace std;

class Bank {
private:
    map<int, int> accounts; // userID -> balance

public:
    bool CREATE(int userID, int amount) {
        if (accounts.count(userID)) {
            accounts[userID] += amount;
            return false;
        }
        accounts[userID] = amount;
        return true;
    }

    bool DEBIT(int userID, int amount) {
        if (!accounts.count(userID) || accounts[userID] < amount)
            return false;
        accounts[userID] -= amount;
        return true;
    }

    bool CREDIT(int userID, int amount) {
        if (!accounts.count(userID))
            return false;
        accounts[userID] += amount;
        return true;
    }

    int BALANCE(int userID) {
        if (!accounts.count(userID))
            return -1;
        return accounts[userID];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Bank bank;
    int Q;
    cin >> Q;

    while (Q--) {
        string query;
        cin >> query;

        if (query == "CREATE") {
            int x, y; cin >> x >> y;
            cout << (bank.CREATE(x, y) ? "true" : "false") << "\n";
        } else if (query == "DEBIT") {
            int x, y; cin >> x >> y;
            cout << (bank.DEBIT(x, y) ? "true" : "false") << "\n";
        } else if (query == "CREDIT") {
            int x, y; cin >> x >> y;
            cout << (bank.CREDIT(x, y) ? "true" : "false") << "\n";
        } else if (query == "BALANCE") {
            int x; cin >> x;
            cout << bank.BALANCE(x) << "\n";
        }
    }

    return 0;
}

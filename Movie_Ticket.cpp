#include <iostream>
#include <map>
#include <set>
using namespace std;

class MovieTicket {
private:
    map<int, set<int>> bookings; // movieID -> set of customerIDs who booked it
    const int MAX_SLOTS = 100;

public:
    bool BOOK(int customerID, int movieID) {
        set<int>& customers = bookings[movieID];
        if (customers.count(customerID) || (int)customers.size() >= MAX_SLOTS)
            return false;
        customers.insert(customerID);
        return true;
    }

    bool CANCEL(int customerID, int movieID) {
        if (!bookings.count(movieID) || !bookings[movieID].count(customerID))
            return false;
        bookings[movieID].erase(customerID);
        return true;
    }

    bool IS_BOOKED(int customerID, int movieID) {
        return bookings.count(movieID) && bookings[movieID].count(customerID);
    }

    int AVAILABLE_TICKETS(int movieID) {
        return MAX_SLOTS - (int)bookings[movieID].size();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    MovieTicket system;
    int Q;
    cin >> Q;

    while (Q--) {
        string query;
        cin >> query;

        if (query == "BOOK") {
            int x, y; cin >> x >> y;
            cout << (system.BOOK(x, y) ? "true" : "false") << "\n";
        } else if (query == "CANCEL") {
            int x, y; cin >> x >> y;
            cout << (system.CANCEL(x, y) ? "true" : "false") << "\n";
        } else if (query == "IS_BOOKED") {
            int x, y; cin >> x >> y;
            cout << (system.IS_BOOKED(x, y) ? "true" : "false") << "\n";
        } else if (query == "AVAILABLE_TICKETS") {
            int y; cin >> y;
            cout << system.AVAILABLE_TICKETS(y) << "\n";
        }
    }
    return 0;
}

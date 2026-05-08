#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    string name;

    // Keep asking until user enters a non-empty name
    do {
        cout << "Enter your name: ";
        getline(cin, name);

        if (name.empty()) {
            cout << "Invalid input! Please enter a valid name.\n\n";
        }

    } while (name.empty());

    // Seed random generator
    srand(time(0));

    // Roast templates
    vector<string> roasts = {
        "Hey " + name + ", you are not stupid, you just have bad luck thinking.",
        name + ", if laziness were a sport, you would come second because you would not try hard enough to win.",
        "I would explain it to you, " + name + ", but I left my crayons at home.",
        name + ", your brain is like a web browser with too many tabs open and none of them useful.",
        "Hey " + name + ", you bring everyone so much joy when you leave the room.",
        name + ", you are proof that even evolution takes a break sometimes.",
        "If I had a dollar for every smart thing you said, " + name + ", I would be broke.",
        name + ", you are not useless, you could be used as a bad example.",
        "Somewhere out there, " + name + ", a tree is working hard to replace the oxygen you waste.",
        name + ", you have something on your chin, no, the third one down."
    };

    // Random selection
    int randomIndex = rand() % roasts.size();

    // Output roast
    cout << "\nYour Roast:\n";
    cout << roasts[randomIndex] << endl;

    return 0;
}

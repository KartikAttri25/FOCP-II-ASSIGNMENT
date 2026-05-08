#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    string name;

    // Input validation (no empty name)
    do {
        cout << "Enter your name: ";
        getline(cin, name);

        if (name.empty()) {
            cout << "Invalid input! Please enter a valid name.\n\n";
        }

    } while (name.empty());

    // Seed random generator
    srand(time(0));

    // Excuse templates (10)
    vector<string> excuses = {
        "Sorry teacher, I am " + name + " and my internet stopped working right when I was about to submit.",
        "Hello, this is " + name + ". My dog accidentally deleted my homework.",
        name + " could not complete the assignment because there was a power cut all night.",
        "I am " + name + ", and I was helping my family with an emergency, so I could not finish the work.",
        name + " tried to do the homework, but the file got corrupted somehow.",
        "Sorry, I am " + name + ". I misunderstood the deadline and thought it was tomorrow.",
        name + " was not feeling well yesterday, so the homework could not be completed.",
        "I am " + name + ", and my laptop suddenly stopped working while I was doing the assignment.",
        name + " could not submit the work because the internet connection was very unstable.",
        "Hello teacher, " + name + " had to attend an urgent family function and could not complete the task."
    };

    // Random selection
    int randomIndex = rand() % excuses.size();

    // Output
    cout << "\nYour Excuse:\n";
    cout << excuses[randomIndex] << endl;

    return 0;
}

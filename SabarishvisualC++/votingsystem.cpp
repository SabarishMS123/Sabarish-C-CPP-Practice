#include <iostream>
using namespace std;

class Candidate {
private:
    string name;
    int votes;

public:
    // Function to read candidate details
    void read() {
        cout << "Enter candidate's name: ";
        cin >> name;
        cout << "Enter votes received: ";
        cin >> votes;
    }

    // Function to display candidate details
    void display(int totalVotes) const {
        float percentage = (votes * 100.0) / totalVotes; // Manual percentage calculation
        cout << "Name: " << name << ", Votes: " << votes
             << ", Percentage: " << percentage << "%" << endl;
    }

    // Getter for votes
    int getVotes() const {
        return votes;
    }

    // Getter for name
    string getName() const {
        return name;
    }

    // Setter for votes
    void setVotes(int v) {
        votes = v;
    }

    // Setter for name
    void setName(string n) {
        name = n;
    }
};

int main() {
    int n;
    cout << "Enter the number of candidates: ";
    cin >> n;

    Candidate candidates[100]; // Assuming a maximum of 100 candidates
    int totalVotes = 0;

    // Reading data for each candidate
    for (int i = 0; i < n; ++i) {
        string tempName;
        int tempVotes;
        cout << "\nCandidate " << i + 1 << ":\n";
        cout << "Enter candidate's name: ";
        cin >> tempName;
        cout << "Enter votes received: ";
        cin >> tempVotes;

        candidates[i].setName(tempName);
        candidates[i].setVotes(tempVotes);

        totalVotes += candidates[i].getVotes(); // Summing up total votes manually
    }

    // Displaying the results and finding the winner
    cout << "\nElection Results:\n";
    int maxVotes = 0;
    string winnerName;

    for (int i = 0; i < n; ++i) {
        candidates[i].display(totalVotes);

        // Finding the candidate with the highest votes
        if (candidates[i].getVotes() > maxVotes) {
            maxVotes = candidates[i].getVotes();
            winnerName = candidates[i].getName();
        }
    }

    // Displaying the winner
    cout << "\nWinner of the election is: " << winnerName << " with " << maxVotes << " votes!" << endl;

    return 0;
}

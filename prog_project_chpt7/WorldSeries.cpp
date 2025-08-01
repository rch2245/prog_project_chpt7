// ===============================================
// World Series Champions Program - Analysis & Design
// ===============================================

// Types of Input:
// - File input: Teams.txt (team names) and WorldSeriesWinners.txt (historical winners)

// Program Output:
// - Display list of all teams that have won a World Series
// - Prompt for team name
// - Output number of wins or error message if not found

// Algorithm / Tasks:
// 1. Load teams and winner list into vectors
// 2. Display all available teams
// 3. Prompt user for team name until 'quit'
// 4. If team exists:
//    - Count and display wins
//    Else:
//    - Show error message

// Hierarchy Chart:
// runWorldSeriesLookup()
// - getTeams()
// - teamExists()
// - findWinner()

// Pseudocode:
// getTeams("Teams.txt", teams)
// getTeams("WorldSeriesWinners.txt", winners)
// display teams
// loop:
//     prompt for team
//     if teamExists:
//         count = findWinner(team, winners)
//         display count
//     else:
//         display error


#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void getTeams(const string& filename, vector<string>& vec) {
    ifstream file(filename);
    if (!file) {
        cerr << "Failed to open " << filename << endl;
        exit(1);
    }
    string name;
    while (getline(file, name)) vec.push_back(name);
    file.close();
}

int findWinner(const string& team, const vector<string>& winners) {
    int count = 0;
    for (const string& win : winners)
        if (win == team) count++;
    return count;
}

bool teamExists(const string& team, const vector<string>& teamList) {
    return find(teamList.begin(), teamList.end(), team) != teamList.end();
}

void runWorldSeriesLookup() {
    vector<string> teams, winners;
    getTeams("Teams.txt", teams);
    getTeams("WorldSeriesWinners.txt", winners);

    string teamName;
    cout << "\nWorld Series Winners Lookup\n";
    for (const string& team : teams)
        cout << team << endl;

    cout << "\nEnter the name of a team exactly as it appears in the list above (or 'quit' to exit): ";
    while (getline(cin >> ws, teamName) && teamName != "quit") {
        if (teamExists(teamName, teams)) {
            int wins = findWinner(teamName, winners);
            cout << teamName << " won the World Series " << wins << " times.\n";
        }
        else {
            cout << "Error: '" << teamName << "' does not exist in the list. Please try again.\n";
        }
        cout << "Enter another team name (or 'quit'): ";
    }
}

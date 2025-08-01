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

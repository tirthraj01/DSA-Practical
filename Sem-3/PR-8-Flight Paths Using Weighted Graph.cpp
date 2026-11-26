
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string city[20];
    vector<pair<int, int>> adj[20];

    int n, m;

    cout << "Enter number of cities: ";
    cin >> n;

    // Enter city names
    for (int i = 0; i < n; i++) {
        cout << "Enter city " << i + 1 << ": ";
        cin >> city[i];
    }

    cout << "Enter number of flights: ";
    cin >> m;

    // Add flight connections
    for (int i = 0; i < m; i++) {
        int from, to, cost;

        cout << "Enter source, destination and cost: ";
        cin >> from >> to >> cost;

        adj[from - 1].push_back({to - 1, cost});
    }

    // Display adjacency list
    cout << "\nFlight Connections:\n";

    for (int i = 0; i < n; i++) {
        cout << city[i] << " -> ";

        for (int j = 0; j < adj[i].size(); j++) {
            int destination = adj[i][j].first;
            int cost = adj[i][j].second;

            cout << city[destination]
                 << " (" << cost << " hours) ";
        }

        cout << endl;
    }

    return 0;
}


5. Algorithm
1. Start.
2. Read the number of cities.
3. Enter the names of all cities.
4. Create an empty adjacency list.
5. Read the number of flights.
6. For each flight:
   - Read source city.
   - Read destination city.
   - Read flight cost.
   - Store destination and cost in the source city's adjacency list.
7. Display all cities with their connected flights and costs.
8. Stop.

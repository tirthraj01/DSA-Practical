
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 8;

// Names of landmarks
string place[N] = {
    "AISSMS COE",
    "AISSMS IOIT",
    "AISSMS Pharmacy",
    "AISSMS IOM",
    "AISSMS Ground",
    "RTO Metro Station",
    "Pune Railway Station",
    "Sassoon Hospital"
};

// Adjacency matrix
int adjMatrix[N][N] = {0};

// Adjacency list
vector<int> adjList[N];

// Add connection between two nodes
void addEdge(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;

    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

// DFS using adjacency matrix
void DFS(int start, bool visited[]) {
    visited[start] = true;
    cout << place[start] << " ";

    for (int i = 0; i < N; i++) {
        if (adjMatrix[start][i] == 1 && !visited[i]) {
            DFS(i, visited);
        }
    }
}

// BFS using adjacency list
void BFS(int start) {
    bool visited[N] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << place[current] << " ";

        for (int x : adjList[current]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

int main() {

    // Add connections between landmarks
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(0, 4);
    addEdge(0, 5);
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(5, 6);
    addEdge(6, 7);

    bool visited[N] = {false};

    cout << "DFS Traversal:\n";
    DFS(0, visited);

    cout << "\n\nBFS Traversal:\n";
    BFS(0);

    return 0;
}

4. Algorithm
1. Start.
2. Create vertices representing the nearby landmarks.
3. Create an adjacency matrix and adjacency list.
4. Add connections between the landmarks.
5. Perform DFS:
   - Start from the college node.
   - Mark the node as visited.
   - Display the node.
   - Visit an unvisited adjacent node recursively.
6. Perform BFS:
   - Create an empty queue.
   - Insert the starting node into the queue.
   - Mark it as visited.
   - Remove a node from the queue and display it.
   - Insert all its unvisited adjacent nodes into the queue.
   - Repeat until the queue is empty.
7. Stop.

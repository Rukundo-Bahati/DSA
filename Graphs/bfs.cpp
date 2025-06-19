#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform BFS on a graph
void BFS(int startNode, vector<vector<int>>& graph, vector<bool>& visited) {
    // Create a queue for BFS
    queue<int> q;

    // Mark the starting node as visited and enqueue it
    visited[startNode] = true;
    q.push(startNode);

    // Traverse the graph
    while (!q.empty()) {
        // Dequeue a vertex from the queue
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " "; // Process the node (e.g., print it)

        // Visit all adjacent nodes of the current node
        for (int neighbor : graph[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true; // Mark the neighbor as visited
                q.push(neighbor);         // Enqueue the neighbor
            }
        }
    }
}

int main() {
    // Example graph represented as an adjacency list
    int numNodes = 6; // Number of nodes in the graph
    vector<vector<int>> graph(numNodes);

    // Add edges to the graph
    graph[0] = {1, 2};       // Node 0 is connected to nodes 1 and 2
    graph[1] = {0, 3, 4};    // Node 1 is connected to nodes 0, 3, and 4
    graph[2] = {0, 4};       // Node 2 is connected to nodes 0 and 4
    graph[3] = {1, 5};       // Node 3 is connected to nodes 1 and 5
    graph[4] = {1, 2, 5};    // Node 4 is connected to nodes 1, 2, and 5
    graph[5] = {3, 4};       // Node 5 is connected to nodes 3 and 4

    // Vector to keep track of visited nodes
    vector<bool> visited(numNodes, false);

    // Perform BFS starting from node 0
    cout << "BFS Traversal: ";
    BFS(0, graph, visited);

    return 0;
}
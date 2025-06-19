#include <iostream>
#include <vector>

using namespace std;

void printDFS(const vector<vector<int>> &graph, int sv, vector<bool> &visited) {
    cout << sv << " ";
    visited[sv] = true;
    int n = graph.size();
    for (int i = 0; i < n; i++) {
        if (graph[sv][i] == 1 && !visited[i]) {
            printDFS(graph, i, visited);
        }
    }
}

int main() {
    int n, e;
    
    // Prompt for number of nodes and edges
    cout << "Enter number of nodes: ";
    cin >> n;
    
    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> matrix(n, vector<int>(n, 0));

    cout << "\nEnter " << e << " edges (format: node1 node2):\n";
    for (int i = 0; i < e; i++) {  
        int fv, sv;
        cin >> fv >> sv;

        // Edge validation check
        if (fv >= 0 && fv < n && sv >= 0 && sv < n) {
            matrix[fv][sv] = 1;
            matrix[sv][fv] = 1;
        } else {
            cout << "❌ Invalid edge: (" << fv << ", " << sv << "). Please enter valid nodes.\n";
            i--;  // Re-enter invalid input
        }
    }

    // Display adjacency matrix
    cout << "\nAdjacency Matrix:\n";
    for (const auto &row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Let user choose starting node for DFS
    int startNode;
    cout << "\nEnter starting node for DFS: ";
    cin >> startNode;
    
    if (startNode < 0 || startNode >= n) {
        cout << "❌ Invalid starting node. Defaulting to node 0.\n";
        startNode = 0;
    }

    // Perform DFS
    cout << "\nDFS Traversal starting from node " << startNode << ": ";
    vector<bool> visited(n, false);
    printDFS(matrix, startNode, visited);
    cout << endl;

    return 0;
}

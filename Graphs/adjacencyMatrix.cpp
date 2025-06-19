#include <iostream>

using namespace std;

class AdjacencyMatrix {
private:
    int n;
    int **adj;

public:
    AdjacencyMatrix(int n) {
        this->n = n;
        adj = new int *[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new int[n];
            for (int j = 0; j < n; j++) {  // Fix increment
                adj[i][j] = 0;
            }
        }
    }

    void add_edge(int origin, int destin) {
        if (origin > n || destin > n || origin <= 0 || destin <= 0) {
            cout << "Invalid Edge number" << endl;
            return;
        }
        adj[origin - 1][destin - 1] = 1; // Fix array indexing
    }

    void delete_edge(int origin, int destin) {
        if (origin > n || destin > n || origin <= 0 || destin <= 0) {
            cout << "Invalid Edge number" << endl;
            return;
        }
        adj[origin - 1][destin - 1] = 0;
    }

    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {  // Fix incorrect loop condition
                cout << adj[i][j] << " ";
            }
            cout << endl;  // Move endl outside loop
        }
    }

    ~AdjacencyMatrix() {
        for (int i = 0; i < n; i++) {
            delete[] adj[i];
        }
        delete[] adj;
    }
};

int main() {
    int nodes, max_edges, origin, destin;
    
    cout << "Enter number of nodes: ";
    cin >> nodes;
    
    AdjacencyMatrix am(nodes);
    max_edges = nodes * nodes;

    for (int i = 0; i < max_edges; i++) {
        cout << "Edges number: " << i + 1 << endl;
        cout << "Enter edge (-1 -1 to exit):" << endl;
        cout << "Enter Origin and Destination vertices: ";
        cin >> origin >> destin; // Fix incorrect cin syntax

        if (origin == -1 || destin == -1)
            break;

        am.add_edge(origin, destin); // Fix missing semicolon
    }

    cout << "\nAdjacency Matrix:\n";
    am.display();

    return 0;
}

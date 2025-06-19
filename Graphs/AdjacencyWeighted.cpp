#include <iostream>
#include <vector>
#include <limits>

class WeightedGraph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjacencyMatrix;
    const int INF = std::numeric_limits<int>::max();

public:
    // Constructor
    WeightedGraph(int vertices) : numVertices(vertices) {
        // Initialize adjacency matrix with all INF (representing no edge)
        adjacencyMatrix.resize(numVertices, std::vector<int>(numVertices, INF));
        
        // Set diagonal to 0 (distance from vertex to itself)
        for (int i = 0; i < numVertices; ++i) {
            adjacencyMatrix[i][i] = 0;
        }
    }

    // Add edge with weight
    void addEdge(int from, int to, int weight) {
        if (from >= 0 && from < numVertices && to >= 0 && to < numVertices) {
            adjacencyMatrix[from][to] = weight;
        } else {
            std::cout << "Invalid vertices. Edge not added.\n";
        }
    }

    // Add bidirectional edge with weight
    void addBidirectionalEdge(int v1, int v2, int weight) {
        addEdge(v1, v2, weight);
        addEdge(v2, v1, weight);
    }

    // Remove edge
    void removeEdge(int from, int to) {
        if (from >= 0 && from < numVertices && to >= 0 && to < numVertices) {
            adjacencyMatrix[from][to] = INF;
        } else {
            std::cout << "Invalid vertices. No edge removed.\n";
        }
    }

    // Check if edge exists
    bool hasEdge(int from, int to) {
        if (from >= 0 && from < numVertices && to >= 0 && to < numVertices) {
            return adjacencyMatrix[from][to] != INF;
        }
        return false;
    }

    // Get edge weight
    int getWeight(int from, int to) {
        if (from >= 0 && from < numVertices && to >= 0 && to < numVertices) {
            return adjacencyMatrix[from][to];
        }
        return INF;
    }

    // Display adjacency matrix
    void displayMatrix() {
        std::cout << "Adjacency Matrix:\n";
        std::cout << "    ";
        for (int i = 0; i < numVertices; ++i) {
            std::cout << i << "   ";
        }
        std::cout << "\n";
        
        for (int i = 0; i < numVertices; ++i) {
            std::cout << i << " | ";
            for (int j = 0; j < numVertices; ++j) {
                if (adjacencyMatrix[i][j] == INF) {
                    std::cout << "INF ";
                } else {
                    std::cout << adjacencyMatrix[i][j] << "   ";
                }
            }
            std::cout << "\n";
        }
    }
};

// Clear input buffer
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int numVertices;
    int choice;
    
    std::cout << "Enter the number of vertices in the graph: ";
    std::cin >> numVertices;
    
    if (numVertices <= 0) {
        std::cout << "Invalid number of vertices. Exiting program.\n";
        return 1;
    }
    
    WeightedGraph graph(numVertices);
    
    while (true) {
        std::cout << "\n==== Weighted Graph - Adjacency Matrix ====\n";
        std::cout << "1. Add an edge\n";
        std::cout << "2. Add a bidirectional edge\n";
        std::cout << "3. Remove an edge\n";
        std::cout << "4. Check if edge exists\n";
        std::cout << "5. Get edge weight\n";
        std::cout << "6. Display adjacency matrix\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        if (choice == 0) {
            break;
        }
        
        switch (choice) {
            case 1: {
                int from, to, weight;
                std::cout << "Enter source vertex: ";
                std::cin >> from;
                std::cout << "Enter destination vertex: ";
                std::cin >> to;
                std::cout << "Enter weight: ";
                std::cin >> weight;
                graph.addEdge(from, to, weight);
                break;
            }
            case 2: {
                int v1, v2, weight;
                std::cout << "Enter first vertex: ";
                std::cin >> v1;
                std::cout << "Enter second vertex: ";
                std::cin >> v2;
                std::cout << "Enter weight: ";
                std::cin >> weight;
                graph.addBidirectionalEdge(v1, v2, weight);
                break;
            }
            case 3: {
                int from, to;
                std::cout << "Enter source vertex: ";
                std::cin >> from;
                std::cout << "Enter destination vertex: ";
                std::cin >> to;
                graph.removeEdge(from, to);
                break;
            }
            case 4: {
                int from, to;
                std::cout << "Enter source vertex: ";
                std::cin >> from;
                std::cout << "Enter destination vertex: ";
                std::cin >> to;
                if (graph.hasEdge(from, to)) {
                    std::cout << "Edge exists from " << from << " to " << to << "\n";
                } else {
                    std::cout << "No edge exists from " << from << " to " << to << "\n";
                }
                break;
            }
            case 5: {
                int from, to;
                std::cout << "Enter source vertex: ";
                std::cin >> from;
                std::cout << "Enter destination vertex: ";
                std::cin >> to;
                int weight = graph.getWeight(from, to);
                if (weight != std::numeric_limits<int>::max()) {
                    std::cout << "Weight of edge from " << from << " to " << to << " is " << weight << "\n";
                } else {
                    std::cout << "No edge exists from " << from << " to " << to << "\n";
                }
                break;
            }
            case 6:
                graph.displayMatrix();
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
        
        clearInputBuffer();
    }
    
    return 0;
}
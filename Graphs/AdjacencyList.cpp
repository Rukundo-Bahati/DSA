#include <iostream>
#include <vector>
#include <list>
#include <utility> // for std::pair
#include <limits>

class WeightedGraph {
private:
    int numVertices;
    // Vector of lists containing pairs of vertex and weight
    std::vector<std::list<std::pair<int, int>>> adjacencyList;

public:
    // Constructor
    WeightedGraph(int vertices) : numVertices(vertices) {
        adjacencyList.resize(numVertices);
    }

    // Add edge with weight
    void addEdge(int from, int to, int weight) {
        if (from >= 0 && from < numVertices && to >= 0 && to < numVertices) {
            // Check if edge already exists
            for (auto& edge : adjacencyList[from]) {
                if (edge.first == to) {
                    std::cout << "Edge already exists. Updating weight.\n";
                    edge.second = weight;
                    return;
                }
            }
            // Add edge (to, weight) to the list of vertex 'from'
            adjacencyList[from].push_back(std::make_pair(to, weight));
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
            // Store original size
            size_t originalSize = adjacencyList[from].size();
            
            // Remove all edges from 'from' to 'to'
            adjacencyList[from].remove_if([to](const std::pair<int, int>& edge) {
                return edge.first == to;
            });
            
            // Check if any edge was removed
            if (adjacencyList[from].size() < originalSize) {
                std::cout << "Edge removed successfully.\n";
            } else {
                std::cout << "No edge exists from " << from << " to " << to << ".\n";
            }
        } else {
            std::cout << "Invalid vertices. No edge removed.\n";
        }
    }

    // Check if edge exists
    bool hasEdge(int from, int to) {
        if (from >= 0 && from < numVertices && to >= 0 && to < numVertices) {
            for (const auto& edge : adjacencyList[from]) {
                if (edge.first == to) {
                    return true;
                }
            }
        }
        return false;
    }

    // Get edge weight
    int getWeight(int from, int to) {
        if (from >= 0 && from < numVertices && to >= 0 && to < numVertices) {
            for (const auto& edge : adjacencyList[from]) {
                if (edge.first == to) {
                    return edge.second;
                }
            }
        }
        return -1; // Edge doesn't exist
    }

    // Display adjacency list
    void displayList() {
        std::cout << "Adjacency List:\n";
        for (int i = 0; i < numVertices; ++i) {
            std::cout << "Vertex " << i << " -> ";
            if (adjacencyList[i].empty()) {
                std::cout << "No outgoing edges";
            } else {
                for (const auto& edge : adjacencyList[i]) {
                    std::cout << "(" << edge.first << ", " << edge.second << ") ";
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
        std::cout << "\n==== Weighted Graph - Adjacency List ====\n";
        std::cout << "1. Add an edge\n";
        std::cout << "2. Add a bidirectional edge\n";
        std::cout << "3. Remove an edge\n";
        std::cout << "4. Check if edge exists\n";
        std::cout << "5. Get edge weight\n";
        std::cout << "6. Display adjacency list\n";
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
                if (weight != -1) {
                    std::cout << "Weight of edge from " << from << " to " << to << " is " << weight << "\n";
                } else {
                    std::cout << "No edge exists from " << from << " to " << to << "\n";
                }
                break;
            }
            case 6:
                graph.displayList();
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
        
        clearInputBuffer();
    }
    
    return 0;
}
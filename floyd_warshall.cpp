#include <iostream>
#include <climits>

int main() {
    int V;
    std::cout << "Enter the number of vertices: ";
    std::cin >> V;

    int graph[V][V];

    std::cout << "Enter the adjacency matrix:" << std::endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            std::cin >> graph[i][j];
            if (graph[i][j] == 0 && i != j) {
                graph[i][j] = INT_MAX;
            }
        }
    }

    std::cout << "\nOriginal graph:" << std::endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            std::cout << graph[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (graph[i][k] + graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }

    std::cout << "\nShortest distances between all pairs of vertices:" << std::endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            std::cout << graph[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}


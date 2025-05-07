#include <iostream>

using namespace std;

#define MAX_NODES 10

class Graph {
    int adjMatrix[MAX_NODES][MAX_NODES];
    string nodes[MAX_NODES];
    bool visited[MAX_NODES];
    int nodeCount;

public:
    Graph(int n) {
        nodeCount = n;
        for (int i = 0; i < MAX_NODES; i++) {
            for (int j = 0; j < MAX_NODES; j++) {
                adjMatrix[i][j] = 0;
            }
            visited[i] = false;
        }
    }

    void addNode(int index, string name) {
        if (index < MAX_NODES)
            nodes[index] = name;
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    void printAdjMatrix() {
        cout << "\nAdjacency Matrix:" << endl;
        for (int i = 0; i < nodeCount; i++) {
            for (int j = 0; j < nodeCount; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void DFS(int start) {
        cout << nodes[start] << " ";
        visited[start] = true;

        for (int i = 0; i < nodeCount; i++) {
            if (adjMatrix[start][i] == 1 && !visited[i]) {
                DFS(i);
            }
        }
    }

    void BFS(int start) {
        int queue[MAX_NODES], front = 0, rear = 0;
        bool visited[MAX_NODES] = {false};

        queue[rear++] = start;
        visited[start] = true;

        while (front < rear) {
            int node = queue[front++];
            cout << nodes[node] << " ";
            
            for (int i = 0; i < nodeCount; i++) {
                if (adjMatrix[node][i] == 1 && !visited[i]) {
                    queue[rear++] = i;
                    visited[i] = true;
                }
            }
        }
    }
};

int main() {
    Graph g(5);
    g.addNode(0, "College");
    g.addNode(1, "Library");
    g.addNode(2, "Cafeteria");
    g.addNode(3, "Auditorium");
    g.addNode(4, "Hostel");
    
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    
    g.printAdjMatrix();
    
    cout << "\nDFS Traversal:" << endl;
    g.DFS(0);
    
    cout << "\n\nBFS Traversal:" << endl;
    g.BFS(0);
    
    return 0;
}

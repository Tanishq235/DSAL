#include <iostream>
using namespace std;

#define k 10

class Graph {
    int g[10][10];         // Adjacency matrix
    int visited[10];       // Visited nodes
    string landmark[k];    // Names of landmarks
    int n;                 // Number of landmarks

public:
    Graph() {
        for (int i = 0; i < 10; i++) {
            visited[i] = 0;
            for (int j = 0; j < 10; j++) {
                g[i][j] = 0;
            }
        }
    }

    void adj_mat_readgraph();
    void display_DFS(int t);
    void printLandmarks();
    int getN() { return n; }
};

void Graph::adj_mat_readgraph() {
    cout << "\nEnter the total number of landmarks: ";
    cin >> n;

    cout << "Enter the names of the landmarks:\n";
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        cin >> landmark[i];
    }

    cout << "\nEnter the adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Is there a connection from " << landmark[i]
                 << " to " << landmark[j] << "? (1/0): ";
            cin >> g[i][j];
        }
    }
}

void Graph::display_DFS(int t) {
    cout << landmark[t] << " ";
    visited[t] = 1;

    for (int i = 0; i < n; i++) {
        if (g[t][i] == 1 && visited[i] == 0) {
            display_DFS(i);
        }
    }
}

void Graph::printLandmarks() {
    for (int i = 0; i < n; i++) {
        cout << i << ": " << landmark[i] << endl;
    }
}

int main() {
    Graph g;
    g.adj_mat_readgraph();

    int startNode;
    cout << "\nChoose the starting node for DFS traversal:\n";
    g.printLandmarks();
    cin >> startNode;

    cout << "\nDFS Traversal: ";
    g.display_DFS(startNode);
    cout << endl;

    return 0;
}

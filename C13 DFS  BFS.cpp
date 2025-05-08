
// Represent a given graph using adjacency matrix/list to perform DFS and using adjacency
// list to perform BFS. Use the map of the area around the college as the graph. Identify
// the prominent land marks as nodes and perform DFS and BFS on that.

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue {
    int arr[10];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int x) {
        if (rear == 9) return; 
        if (isEmpty())
            front = 0;
        arr[++rear] = x;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int temp = arr[front];
        if (front == rear)
            front = rear = -1;
        else
            front++;
        return temp;
    }
};

class Graph {
    int matrix[6][6];
    Node* list[6];
    int visitedDFS[6];
    int visitedBFS[6];

public:
    string landmark[6] = {
        "Main Gate", "Playground", "Cafe", "HOD CABIN", "Playground", "CITP HALL"
    };

    Graph() {
        for (int i = 0; i < 6; i++) {
            visitedDFS[i] = visitedBFS[i] = 0;
            list[i] = NULL;
            for (int j = 0; j < 6; j++)
                matrix[i][j] = 0;
        }

        addEdge(0, 1); 
        addEdge(0, 2); 
        addEdge(1, 5); 
        addEdge(2, 3); 
        addEdge(3, 4);
        addEdge(4, 5); 
    }

    void addEdge(int u, int v) {
        matrix[u][v] = matrix[v][u] = 1;

        Node* node1 = new Node(v);
        node1->next = list[u];
        list[u] = node1;

        Node* node2 = new Node(u);
        node2->next = list[v];
        list[v] = node2;
    }

    void dfs(int v) {
        visitedDFS[v] = 1;
        cout << landmark[v] << " -> ";
        for (int i = 0; i < 6; i++) {
            if (matrix[v][i] == 1 && !visitedDFS[i])
                dfs(i);
        }
    }

    void bfs(int start) {
        Queue q;
        q.enqueue(start);
        visitedBFS[start] = 1;

        while (!q.isEmpty()) {
            int node = q.dequeue();
            cout << landmark[node] << " -> ";
            Node* temp = list[node];
            while (temp != NULL) {
                if (!visitedBFS[temp->data]) {
                    q.enqueue(temp->data);
                    visitedBFS[temp->data] = 1;
                }
                temp = temp->next;
            }
        }
    }
};

int main() {
    Graph g;

    cout << "DFS Traversal (Starting from Main Gate):\n";
    g.dfs(0);
    cout << "END\n\n";

    cout << "BFS Traversal (Starting from Main Gate):\n";
    g.bfs(0);
    cout << "END\n";

    return 0;
}

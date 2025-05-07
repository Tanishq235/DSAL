#include <iostream>
#include <climits>  
using namespace std;

class graph {
public:
    int distance[4][4];

    graph() {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                distance[i][j] = 0;
    }

    void printgraph() {
        string cities[4] = {"SATARA", "PUNE", "KARAD", "DUBAI"};

        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                cout << "Enter the distance between " << cities[i] << " and " << cities[j] << ": ";
                cin >> distance[i][j];
                distance[j][i] = distance[i][j];
            }
        }

        cout << "\nDistance matrix:\n";
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << distance[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void prims() {
        int outmtr[4][4] = {0};
        int n = 4;
        bool visited[4] = {false};
        int dist[4];
        int from[4];
        int sum = 0;

        for (int i = 0; i < n; i++) {
            dist[i] = INT_MAX;
            from[i] = -1;
        }

        dist[0] = 0;

        for (int count = 0; count < n - 1; count++) {
            int min = INT_MAX, u = -1;

            for (int i = 0; i < n; i++) {
                if (!visited[i] && dist[i] < min) {
                    min = dist[i];
                    u = i;
                }
            }

            visited[u] = true;
            sum += min;

            for (int v = 0; v < n; v++) {
                if (!visited[v] && distance[u][v] && distance[u][v] < dist[v]) {
                    dist[v] = distance[u][v];
                    from[v] = u;
                }
            }
        }

        cout << "\nMinimum Spanning Tree:\n";
        for (int i = 1; i < n; i++) {
            outmtr[from[i]][i] = distance[from[i]][i];
            outmtr[i][from[i]] = distance[from[i]][i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << outmtr[i][j] << "\t";
            }
            cout << endl;
        }

        cout << "Total weight is: " << sum << endl;
    }
};

int main() {
    graph g;
    g.printgraph();
    g.prims();
    return 0;
}

#include <iostream>
#include <cstring>
using namespace std;

#define MAX 10

int w[MAX][MAX], c[MAX][MAX], r[MAX][MAX];
float p[MAX], q[MAX];
char idnt[MAX][10];
int n;

// Function to find the root with minimum cost
int find(int i, int j) {
    int min = 2000, l = -1;
    for (int m = r[i][j - 1]; m <= r[i + 1][j]; m++) {  // Knuth's optimization
        int cost = c[i][m - 1] + c[m][j];
        if (cost < min) {
            min = cost;
            l = m;
        }
    }
    return l;
}

// Function to print the OBST structure
void print(int i, int j) {
    if (i < j) {
        cout << idnt[r[i][j]] << " ";
        print(i, r[i][j] - 1);
        print(r[i][j], j);
    }
}

int main() {
    cout << "\nEnter the number of identifiers: ";
    cin >> n;

    cout << "\nEnter identifiers:\n";
    for (int i = 1; i <= n; i++) {
        cout << "Identifier no " << i << ": ";
        cin >> idnt[i];
    }

    cout << "\nEnter success probabilities for identifiers:\n";
    for (int i = 1; i <= n; i++) {
        cout << "p[" << i << "]: ";
        cin >> p[i];
    }

    cout << "\nEnter failure probabilities:\n";
    for (int i = 0; i <= n; i++) {
        cout << "q[" << i << "]: ";
        cin >> q[i];
    }

    for (int i = 0; i <= n; i++) {
        w[i][i] = q[i];
        c[i][i] = r[i][i] = 0;

        if (i < n) {
            w[i][i + 1] = q[i] + p[i + 1] + q[i + 1];
            c[i][i + 1] = w[i][i + 1];
            r[i][i + 1] = i + 1;
        }
    }

    for (int m = 2; m <= n; m++) {
        for (int i = 0; i <= n - m; i++) {
            int j = i + m;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            int k = find(i, j);
            r[i][j] = k;
            c[i][j] = w[i][j] + c[i][k - 1] + c[k][j];
        }
    }

    cout << "\nRoot of this OBST: " << r[0][n] << " which is " << idnt[r[0][n]];
    cout << "\nCost of this OBST: " << c[0][n] << "\n";

    cout << "\nPre-order traversal of OBST:\n";
    print(0, n);
    cout << "\n";

    return 0;
}

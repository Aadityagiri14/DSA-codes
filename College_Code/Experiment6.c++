#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void takeInput(vector<vector<int>>& ary, int& n) {
    int i, j;
    cout << "Enter the number of villages: ";
    cin >> n;
    ary.resize(n, vector<int>(n, 0)); // Initialize 2D vector with zeros
    cout << "\nEnter the Cost Matrix\n";
    for (i = 0; i < n; ++i) {
        cout << "\nEnter Elements of Row: " << i + 1 << endl;
        for (j = 0; j < n; ++j) {
            cin >> ary[i][j];
        }
    }
}

void displayMatrix(const vector<vector<int>>& ary, int n) {
    cout << "\nCost Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ary[i][j] << "\t";
        }
        cout << endl;
    }
}


int least(const vector<vector<int>>& ary, const vector<int>& completed, int c, int n) {
    int minCost = INT_MAX;
    int minIndex = -1;
    for (int i = 0; i < n; ++i) {
        if (ary[c][i] < minCost && !completed[i]) {
            minCost = ary[c][i];
            minIndex = i;
        }
    }
    return minIndex;
}

void mincost(vector<vector<int>>& ary, vector<int>& completed, int city, int& cost, int n) {
    completed[city] = 1;
    cout << city + 1 << " --> ";
    int ncity = least(ary, completed, city, n);
    if (ncity != -1) {
        cost += ary[city][ncity];
        mincost(ary, completed, ncity, cost, n);
    }
}

int main() {
    vector<vector<int>> ary;
    int n, cost = 0;
    takeInput(ary, n);
    displayMatrix(ary, n);
    vector<int> completed(n, 0);

    cout << "\n\nThe Path is:\n";
    mincost(ary, completed, 0, cost, n); // Pass 0 for starting vertex

    cout << "\n\nMinimum cost is " << cost << endl;
    return 0;
}

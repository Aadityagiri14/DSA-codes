#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    char id;
    int value;
    int weight;
    double ratio;
};


struct Node {
    int level;
    int profit;
    int weight;
    double bound;
};

double bound(Node u, int W, vector<Item>& items) {
    if (u.weight >= W) {
        return 0;
    }
    double bound = u.profit;
    int j = u.level + 1;
    int totalWeight = u.weight;
    while (j < items.size() && totalWeight + items[j].weight <= W) {
        bound += items[j].value;
        totalWeight += items[j].weight;
        j++;
    }
    if (j < items.size()) {
        bound += (W - totalWeight) * items[j].ratio;
    }
    return bound;
}

int knapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.ratio > b.ratio;
    });

    vector<Node> Q;
    Node u, v;

    u.level = -1;
    u.profit = u.weight = 0;
    Q.push_back(u);

    int maxProfit = 0;

    while (!Q.empty()) {
        u = Q.back();
        Q.pop_back();

        if (u.level == -1) {
            v.level = 0;
        } else if (u.level == items.size() - 1) {
            continue;
        } else {
            v.level = u.level + 1;
        }

        v.weight = u.weight + items[v.level].weight;
        v.profit = u.profit + items[v.level].value;

        if (v.weight <= W && v.profit > maxProfit) {
            maxProfit = v.profit;
        }

        v.bound = bound(v, W, items);
        if (v.bound > maxProfit) {
            Q.push_back(v);
        }

        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, W, items);
        if (v.bound > maxProfit) {
            Q.push_back(v);
        }
    }

    return maxProfit;
}

int main() {
    vector<Item> items = {
        {'A', 2, 1},
        {'B', 4, 3},
        {'C', 7, 5}, 
        {'D', 10, 7} 
    };
    for (auto& item : items) {
        item.ratio = (double)item.value / item.weight;
    }
    int W = 10;
    int maxProfit = knapsack(W, items);
    cout << "Item\t";
    for (const auto& item : items) {
        cout << item.id << '\t';
    }
    cout << endl << "Profit\t";
    for (const auto& item : items) {
        cout << item.value << '\t';
    }
    cout << endl << "Weight\t";
    for (const auto& item : items) {
        cout << item.weight << '\t';
    }
    cout << endl;
    cout << "Maximum profit: " << maxProfit << endl;
    return 0;
}

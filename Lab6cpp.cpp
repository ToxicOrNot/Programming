#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

vector<vector<int>> createGraph(int N, vector<int>& prices, vector<vector<int>>& Routes) {
    vector<vector<int>> graph(N, vector<int>(N, -1));

    for (const auto& route : Routes) {
        int u = route[0] - 1;
        int v = route[1] - 1;
        graph[u][v] = prices[u];
        graph[v][u] = prices[v];
    }

    return graph;
}

int priceCheck(int N, int start, int end, vector<vector<int>>& graph) {
    vector<int> cost(N, numeric_limits<int>::max());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> priority_road;
    priority_road.push({0, start});
    cost[start] = 0;

    while (!priority_road.empty()) {
        int current_price = priority_road.top().first;
        int current_city = priority_road.top().second;
        priority_road.pop();

        if (current_city == end) {
            return current_price;
        }

        if (current_price > cost[current_city]) {
            continue;
        }

        for (int neighbour = 0; neighbour < N; ++neighbour) {
            int price = graph[current_city][neighbour];
            if (price != -1) {
                int temp_price = current_price + price;
                if (temp_price < cost[neighbour]) {
                    cost[neighbour] = temp_price;
                    priority_road.push({temp_price, neighbour});
                }
            }
        }
    }

    return cost[end];
}

int main() {
    int N = 5;
    vector<int> prices = {5, 10, 3, 7, 4};
    vector<vector<int>> Routes = {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5},
        {1, 5}
    };

    vector<vector<int>> graph = createGraph(N, prices, Routes);
    int result = priceCheck(N, 0, N - 1, graph);

    cout << result << endl;

    return 0;
}

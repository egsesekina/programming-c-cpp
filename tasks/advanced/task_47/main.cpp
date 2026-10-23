/*
 * Задание 47. Найти кратчайшие расстояния алгоритмом Дейкстры.
 * Ввод: N M, M рёбер u v w и исходная вершина; веса неотрицательны.
 * Вывод: расстояние до каждой вершины или unreachable.
 * Пример: 3 2 / 0 1 4 / 1 2 5 / 0 -> 0:0, 1:4, 2:9.
 */
#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int n, m;
    if (!(cin >> n >> m) || n <= 0 || n > 100000 ||
        m < 0 || m > 300000) {
        cerr << "Error\n";
        return 1;
    }

    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        if (!(cin >> u >> v >> w) ||
            u < 0 || u >= n || v < 0 || v >= n || w < 0 || w > 1000000000) {
            cerr << "Error\n";
            return 1;
        }
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int source;
    if (!(cin >> source) || source < 0 || source >= n) {
        cerr << "Error\n";
        return 1;
    }

    const long long INF = numeric_limits<long long>::max() / 4;
    vector<long long> dist(n, INF);
    using State = pair<long long, int>;
    priority_queue<State, vector<State>, greater<State>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [currentDist, u] = pq.top();
        pq.pop();
        if (currentDist != dist[u]) continue; // Устаревшая запись.

        for (auto [v, weight] : graph[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) cout << i << ": unreachable\n";
        else cout << i << ": " << dist[i] << '\n';
    }
    return 0;
}

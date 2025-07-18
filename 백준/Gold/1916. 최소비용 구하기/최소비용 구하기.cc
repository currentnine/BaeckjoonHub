#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;
int n, m;
vector<pair<int, int>> graph[1001]; // graph[u] = {{v1, cost1}, {v2, cost2}, ...}
int dist[1001];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        auto [cost, now] = pq.top(); pq.pop();
        if (dist[now] < cost) continue;

        for (auto [next, nextCost] : graph[now]) {
            if (dist[next] > dist[now] + nextCost) {
                dist[next] = dist[now] + nextCost;
                pq.push({dist[next], next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        dist[i] = INF;

    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }

    int start, end; cin >> start >> end;
    dijkstra(start);
    cout << dist[end] << '\n';
}

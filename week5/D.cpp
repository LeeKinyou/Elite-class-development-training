#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
int n, m, s;
vector<int>dis, vis;
vector<vector<pair<int, int>>>G;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
void init() {
    G.resize(n + 1);
    dis.resize(n + 1, 0x7f7f7f);
    vis.resize(n + 1, 0);
}

void dij() {
    dis[s] = 0;
    q.push({0, s});
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        // cout << "vis: " << vis[u] << endl;
        for (auto next : G[u]) {
            int v = next.first, w = next.second;
            // cout << "v: " << v << endl;
            // cout << "w: " << w << endl;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
    return;
}

int main() {
    // ios::sync_with_stdio(false);
    cin >> n >> m >> s;
    init();
    for (int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back(make_pair(v, w));
    }
    // cout << "G: " << endl;
    // for (int i = 1; i <= n; i++) {
    //     for (int k = 0; k < G[i].size(); k++) {
    //         cout << i << " " <<  G[i][k].first << " " << G[i][k].second << endl;
    //     }
    //     cout << "----------" << endl;
    // }
    dij();
    for (int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }
    return 0;
}
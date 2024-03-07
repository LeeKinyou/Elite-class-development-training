#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, u, v, ans;
vector<vector<int>> G;
vector<int> vis, dis;

void dfs(int u) {
    vis[u] = 1;
    for (int v : G[u]) {
        if (!vis[v]) {
            dis[v] = dis[u] + 1;
            vis[v] = 1;
            dfs(v);
        }
    }
}

void init() {
    G.resize(n + 1);
    vis.resize(n + 1, 0);
    dis.resize(n + 1, 0);
}

int main() {
    cin >> n >> m;
    init();
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        if (dis[i] <= m) {
            ans++;
        }
        // cout << dis[i] << " ";
    }
    cout << ans - 1<< endl;
    return 0;
}
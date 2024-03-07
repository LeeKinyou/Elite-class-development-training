#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <ctime>
#define eps 1e-8

using namespace std;

int n, m, s;
vector<vector<int>> G;
vector<int> vis;
void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    cout << u << " ";
    for (int v : G[u]) {
        dfs(v);
    }
}

int main() {
    cin >> n >> m >> s;
    G.resize(n + 1);
    vis.resize(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        G[x].push_back(y);
    }
    dfs(s);
    return 0;
}

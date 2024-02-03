#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int t, n, m, node[1010];
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    unordered_map<int, int> mp;
    while (t--) {
        cin >> n >> m;
        mp.clear();
        memset(node, 0, sizeof(node));
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            node[u]++;
            node[v]++;
        }
        for (int i= 1; i <= n; i++) {
            mp[node[i]]++;
            // cout << node[i] << " ";
        }
        int num_leaf = 0, num_node = 0x7f7f7f;
        if (mp.size() == 2) {
            for (auto i : mp) {
                num_leaf = max(i.second, num_leaf);
                num_node = min(i.second - 1, num_node);
            }
            cout << num_node << " " << num_leaf / num_node << endl;
        } else {
            num_leaf = mp[1];
            num_node = 0;
            mp.erase(1);
            for (auto i : mp) {
                num_node = max(num_node, i.second);
            }
            cout << num_node << " " << num_leaf / num_node << endl;
        }
    }
    return 0;
}
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n, m, cnt;
int nex[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
string mp[101];
bool vis[101][101];
void dfs(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int xx = x + nex[i][0];
        int yy = y + nex[i][1];
        if (xx < 0 || xx >= n || yy < 0 || yy >= m || mp[xx][yy] != 'W' || vis[xx][yy]) {
            continue;
        }
        vis[xx][yy] = true;
        dfs(xx, yy);
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> mp[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && mp[i][j] == 'W') {
                vis[i][j] = true;
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
#include <cstdio>  
#include <vector>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
  
int t, n, m, cnt;  
int a[1001][1001];  
bool vis[1001][1001];  
int nex[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};  

int dfs(int x, int y) {  
    int sum = a[x][y];
    vis[x][y] = true;  
    for (int i = 0; i < 4; i++) {  
        int xx = x + nex[i][0];  
        int yy = y + nex[i][1];  
        if (xx < 1 || xx > n || yy < 1 || yy > m || vis[xx][yy] || a[xx][yy] == 0)   
            continue;  
        sum += dfs(xx, yy); 
    }  
    return sum;  
}  
  
int main() {  
    ios::sync_with_stdio(false);  
    cin >> t;  
    vector<int> blockSums;
    while (t--) {  
        cin >> n >> m;  
        memset(vis, 0, sizeof(vis));  
        cnt = 0;
        for (int i = 1; i <= n; i++) {  
            for (int j = 1; j <= m; j++) {  
                cin >> a[i][j];  
            }  
        }
        for (int i = 1; i <= n; i++) {  
            for (int j = 1; j <= m; j++) {  
                if (!vis[i][j] && a[i][j]) {  
                    int blockSum = dfs(i, j);
                    cnt = max(cnt, blockSum);
                }  
            }  
        }
        cout << cnt << endl;  
    }  
    return 0;  
}
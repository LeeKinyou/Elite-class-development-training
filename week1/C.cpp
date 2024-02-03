#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int t, n, fin, tim, vis[1010];
struct node {
    int l, r;
}rem[1010];
bool cmp (node a, node b) {
    return a.l == b.l ? a.r < b.r : a.l < b.l;
}
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) {
            cin >> rem[i].l >> rem[i].r;
            if (rem[i].l > rem[i].r) {
                swap(rem[i].l, rem[i].r);
            }
            rem[i].l = (rem[i].l + 1) / 2;
            rem[i].r = (rem[i].r + 1) / 2;
        }
        tim = 0;
        // cout << fin << endl;
        // while (fin < n) {
        //     int now = -1;
        //     for (int i = 1; i <= n; i++) {
        //         // cout << fin <<endl;
        //         if (vis[i] == 1)
        //             continue;
        //         if (now == -1) {
        //             fin++;
        //             now = i;
        //             vis[i] = 1;
        //         } else if (rem[i].l > rem[now].r) {
        //             now = i;
        //             fin++;
        //             vis[i] = 1;
        //         }    
        //     }
        //     tim++;
        // }
        for (int i = 1; i <= n; i++) {
            for (int j = rem[i].l; j <= rem[i].r; j++) {
                vis[j]++;
            }
        }
        for (int i = 0; i <= 1000; i++) {
            tim = max(tim, vis[i]);
        }
        cout << tim * 10 << endl;
    }
    return 0;
}


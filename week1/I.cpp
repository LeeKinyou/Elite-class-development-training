#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int t, n, m, k, fl;
struct node {
    int x, y;
};
int main() {
    cin >> t;
    node vika, friends;
    while (t--) {
        fl = 0;
        cin >> n >> m >> k;
        cin >> vika.x >> vika.y;
        for (int i = 1; i <= k; i++) {
            cin >> friends.x >> friends.y;
            int dis = abs(vika.x - friends.x) + abs(vika.y - friends.y);
            if (dis % 2 == 0) {
                fl = 1;
            }
        }
        if (fl == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
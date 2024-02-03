#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
int ans = 100;
char mp[10][10];
int dir[5][2] = {{0, 0}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool inspection_matrix() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (mp[i][j] != '-') {
                return false;
            }
        }
    }
    return true;
}
char get_change(char ch) {
    if (ch == '+')
        return '-';
    else
        return '+';
}

void swap_matrix(int x, int y) {
    for (int i = 0; i < 4; i++) {
        mp[x][i] = get_change(mp[x][i]);
    }
    for (int i = 0; i < 4; i++) {
        mp[i][y] = get_change(mp[i][y]);
    }
    mp[x][y] = get_change(mp[x][y]);
}
void dfs(int x, int y, int step) {
    if (step > 16) {
        return;
    }
    if (inspection_matrix()) {
        ans = min(ans, step);
        return;
    }
    if (y >= 4) {
        x += 1;
        y = 0;
        if (x >= 4) {
            return;
        }
    }
    swap_matrix(x, y);

    dfs(x, y + 1, step + 1);
    swap_matrix(x, y);

    dfs(x, y + 1, step);
}
int main() {
    for (int i = 0; i < 4; i++) {
        scanf("%s", mp[i]);
    }
    dfs(0, 0, 0);
    if (ans <= 16) {
        cout << ans << endl;
    } else {
        cout << "Impossible" << endl;
    }
    return 0;
}
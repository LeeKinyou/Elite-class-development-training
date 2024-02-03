#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int t, n, m, fl;
void is_ok(int num, int goal) {
    if (num % 3 != 0) {
        return;
    } else {
        int tmp = num / 3;
        if (tmp == goal || tmp * 2 == goal) {
            fl = 1;
            return;
        } else {
            if (tmp * 2 > goal) {
                is_ok(tmp * 2, goal);
            }
            if (tmp > goal) {
                is_ok(tmp, goal);
            }
        }
    }
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        fl = 0;
        if (n == m) {
            fl = 1;
        }
        else {
            is_ok(n, m);
        } 
        if (fl == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
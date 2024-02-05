#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n, m, x;
vector<int> a;
int main() {
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> x;
        int pos = lower_bound(a.begin(), a.end(), x) - a.begin();
        if (a[pos] != x)
            cout << -1 << " ";
        else
            cout << pos + 1 << " ";
    }
    return 0;
}
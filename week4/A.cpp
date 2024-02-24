#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int main() {
    int n, m, k;
    vector<int> a;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        a.push_back(k);
    }
    for (int i = 1; i <= m; i++) {
        cin >> k;
        cout << a[k - 1] << endl;   
    }
    return 0;
}
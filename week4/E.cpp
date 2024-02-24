#include <iostream>
#include <cstring>
using namespace std;
int a[100010];
int main() {
    int n, minn, ans;
    cin >> n;
    cin >> a[0];
    ans = a[0];
    minn = a[0];
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        ans += abs(a[i] - minn);
        minn = min(minn, a[i]);
    }
    cout << ans << endl;
    return 0;
}
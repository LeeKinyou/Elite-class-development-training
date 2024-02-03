#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int t;
string str[10];
int main() {
    cin >> t;
    while (t--) {
        string ans = "";
        for (int i = 0; i < 8; i++) {
            cin >> str[i];
        }
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < str[i].length(); j++) {
                if (str[i][j] != '.') {
                    ans += str[i][j];
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
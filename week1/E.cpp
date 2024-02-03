#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
string str;
int main() {
    while (getline(cin, str)) {
        int sum = 0;
        if (str[0] == '#' && str.size() == 1) {
            break;
        }
        for (int i = 0; i < str.size(); i++) {
            sum += (str[i] == ' ' ? 0 : str[i] - 'A' + 1) * (i + 1);
        }
        cout << sum << endl;
    }
    return 0;
}
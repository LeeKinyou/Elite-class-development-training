#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int get_num(char c) {
    return c - 'A';
}
int main() {
    int fl = 0;
    string str;
    cin >> str;
    for (int i = 2; i < str.size(); i++) {
        if (get_num(str[i]) != (get_num(str[i - 1]) + get_num(str[i - 2])) % 26) {
            fl = 1;
            break;
        }
    }
    if (fl) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}
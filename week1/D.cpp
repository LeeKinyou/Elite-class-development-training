#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a, d, n, cnt, pri_num; 
bool is_prime(int num){
    if(num < 2)
        return false;
    for(int i = 2; i * i <= num; i++)
        if(num % i == 0)
            return false;
    return true;
}
int main() {
    while(cin >> a >> d >> n) {
        if(a == 0 && d == 0 && n == 0)
            break;
        cnt = 0;
        pri_num = 0;
        while(cnt < n) {
            if(is_prime(a)) {
                cnt++;
                pri_num = a;
            }
            a += d;
        }
        cout << pri_num << endl;
    }
    return 0;
}
 
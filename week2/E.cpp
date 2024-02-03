#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int t, n;
int main() {
    ios::sync_with_stdio(false);    
    cin >> t;
    while(t--){
        cin >> n;
        if(n == 1){
        	cout << 1 << endl;
		} else if(n % 2 == 1) {
            cout << -1 << endl;
        } else {
            for(int i = 1; i <= n; i++) {
                if (i % 2 == 1){
                    cout << i + 1 << " ";
                } else {
                    cout << i - 1 << " ";
                }
            }
            cout << endl;
        }
    }
    return 0; 
}
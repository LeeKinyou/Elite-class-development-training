#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int n, m, s = 0;
    vector<int>visit;
    cin >> n >> m;
    visit.resize(n+1);
    for (int k = 0; k < n; k++) {
        for(int i = 0; i < m; i++){
            if( ++s > n) s = 1;
            if(visit[s]) i--;
        }
        cout << s << " ";
        visit[s]=true;
    }
    return 0;
}
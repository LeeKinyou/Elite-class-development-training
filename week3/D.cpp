#include<cstdio>
#include<iomanip>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n, m;
bool a[30]; 
using namespace std;
int main(){
    cin >> n >> m;
    for (int i = m + 1; i <= n; i++)
        a[i] = 1;
    do {
        for(int i = 1; i <= n; i++)
            if(!a[i]) 
                cout << setw(3) << i;
        cout << endl;
    } while(next_permutation(a + 1, a + n + 1));
    return 0;
}
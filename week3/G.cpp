#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
long long n, ans;
struct node {
    long long val, id;
} people[10010];
int main() {
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> people[i].val;
        people[i].id = i;
    }
    sort(people + 1, people + n + 1, [](node a, node b) {
        return a.val < b.val;
    });
    for (int i = 1; i <= n; i++) {
        cout << people[i].id << " ";
    }
    cout << endl;
    for(int i = 2; i <= n; i++)
		for(int j = 1; j < i; j++) ans += people[j].val;
    printf("%.2lf", ans * 1.0 / n);
    return 0;
}
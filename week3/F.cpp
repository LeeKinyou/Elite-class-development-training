#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n, p[20];
void init() {
    p[0] = 1;
    for (int i = 1; i < 20; i++) {
        p[i] = p[i - 1] * 2;
    }
}
vector<int> get_index(int x) {
    vector<int> ans;
    for (int i = 19; i >= 0; i--) {
        if (x >= p[i]) {
            x -= p[i];
            ans.push_back(i);
        }
    }
    return ans;
}
void print(int x) {
    vector<int> index = get_index(x);
    // for (int i: index) {
    //     printf("%d ", i);
    // }
    // cout << endl;
    for (int i = 0; i < index.size() - 1; i++) {
        if (index[i] > 2) {
            printf("2(");
            print(index[i]);
            printf(")+");
        } else if (index[i] == 2){
            printf("2(2)+");
        } else if (index[i] == 1){
            printf("2+");
        } else if (index[i] == 0){
            printf("2(0)+");
        }
    }
    if (index[index.size() - 1] > 2) {
        printf("2(");
        print(index[index.size() - 1]);
        printf(")");
    }  else if (index[index.size() - 1] == 2){
        printf("2(2)");
    } else if (index[index.size() - 1] == 1){
        printf("2");
    } else if (index[index.size() - 1] == 0){
        printf("2(0)");
    }
}
int main() {
    init();
    cin >> n;
    print(n);
    return 0;
}
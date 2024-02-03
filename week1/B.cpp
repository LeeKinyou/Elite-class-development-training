// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <cstring>
// #include <algorithm>
// #define N 10000
// using namespace std;
// int num, sum, now, time, prime[N + 10], vis[N + 10];
// void get_prime() {
//     for(int i=2; i <= N; i++){
//         if(!vis[i])
//             prime[++now] = i;
//         for(int j = 1; j <= now && prime[j] * i <= N;j++){
//             vis[prime[j] * i] = 1;
//             if(i % prime[j] == 0)
//                 break;
//         }
//     }
// }

// int main () {
//     get_prime();
//     while (cin >> num) {
//         if (num == 0) {
//             break;
//         }
//         time = 0;
//         for (int i = 1; i <= now; i++) {
//             if (prime[i] > num) {
//                 break;
//             }
//             sum = 0;
//             for (int j = i; j <= now; j++) {
//                 sum += prime[j];
//                 if (sum == num) {
//                     time++;
//                     break;
//                 } else if (sum > num) {
//                     break;
//                 }
//             }
//         }
//         cout << time << endl;
//     }
//     return 0;
// }


#include<stdio.h>
#include<math.h>
int Prime(int num){
    int i;
    for (i=2;i<=sqrt(num);i++){
        if (num%i==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int i;
    int j=0;
    int end=0;
    int a[10010];
    int x;
    for (i=2;i<=10000;i++){
        if(Prime(i)){
            a[j]=i;
            j=j+1;
        }
    }
    end=j;
    /* for (i=0;i<=end;i++){
        printf("%d\n",a[i]);
    }
    printf("%d\n",end); */
    

    while(scanf("%d",&x)==1 && x!=0){
        int num=0;
        int total=0;
        for (i=0;i<end;i++){
            if(x<a[i]){
                num=i;
                break;
            }
        }
        for (i=0;i<num;i++){
            int sum=0;
            for (j=i;j<num;j++){
                sum+=a[j];
                if (sum==x){
                    total+=1;
                    printf("i j %d %d\n",i,j);
                    break;
                }
            }
        }
        printf("%d\n",total);
    }
    return 0;
}
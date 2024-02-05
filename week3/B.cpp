#include <cmath>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int p, f[1001], res[1001], sav[1001];
void result1(){
	memset(sav, 0, sizeof(sav));
	for(int i = 1; i <= 500; i++){
		for(int j = 1; j <= 500; j++){
			sav[i + j - 1] += res[i] * f[j];
		}
	}
	for(int i = 1; i <= 500; i++){
		sav[i+1] += sav[i] / 10;
		sav[i] %= 10;
	}
    memcpy(res, sav, sizeof(res));
}
void result2(){
	memset(sav, 0, sizeof(sav));
	for(int i = 1; i <= 500; i++){
		for(int j = 1; j <= 500; j++){
			sav[i + j - 1] += f[i] * f[j];
		}
	}
	for(int i = 1; i <= 500; i++){
		sav[i + 1] += sav[i] / 10;
		sav[i] %= 10;
	}
	memcpy(f, sav, sizeof(f)); 
}
int main(){
	cin >> p;
	cout << (int)(log10(2) * p + 1) << endl;
	res[1] = 1;
	f[1] = 2;
	while (p != 0) {
		if(p %2 == 1){
			result1();
		}
		p /= 2;
		result2();
	}
	res[1] -= 1;
	for(int i = 500; i >= 1; i--){
		if(i != 500 && i % 50 == 0){
			cout << endl;
			cout << res[i];
		}
		else{
			cout << res[i];
		}
	}
	return 0;
}
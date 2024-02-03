#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
    char first_char, second_char;
    float first_num, second_num, tmp, dep, hex;
    while (cin >> first_char) {
        if (first_char == 'E') {
            break;
        }
        tmp = hex = dep = 0x7f7f;
        cin >> first_num >> second_char >> second_num;
        if (first_char == 'T') {
            tmp = first_num;
        } else if (first_char == 'D') {
            dep = first_num;
        } else if (first_char == 'H') {
            hex = first_num;
        }
        if (second_char == 'T') {
            tmp = second_num;
        } else if (second_char == 'D') {
            dep = second_num;
        } else if (second_char == 'H') {
            hex = second_num;
        }
        if(hex == 0x7f7f) {
            hex = tmp + 0.5555 * (6.11 * exp(5417.7530 * (1 / 273.16 - 1 / (dep + 273.16))) - 10);
        } else if(tmp == 0x7f7f) {
            tmp = hex - 0.5555 * (6.11 * exp(5417.7530 * (1 / 273.16 - 1 / (dep + 273.16))) - 10);
        } else if(dep == 0x7f7f) {
            dep = 1 / (( 1 / 273.16) - ((log((((hex - tmp) / 0.5555) + 10.0) / 6.11)) / 5417.7530)) - 273.16;
        }
        printf("T %.1f D %.1f H %.1f\n", tmp, dep, hex);
    }
    return 0;
}
/*
humidex = temperature + h
h = (0.5555)× (e - 10.0)
e = 6.11 × exp [5417.7530 × ((1/273.16) - (1/(dewpoint+273.16)))]
*/
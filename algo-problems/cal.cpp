#include<bits/stdc++.h>
using namespace std;

int main(){

    int n = (3*3*77)%385;

    int m = (5*6*55)%385;
    
    int k = (7*6*35)%385;

    cout << n << ' ' << m  << ' ' << k << ' ' << (n+m+k)%385;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

long long arr[46] = {};

long long fib(long long n){

    if(n == 0)return 0;

    else if(n == 1)return 1;

    else if(arr[n] != 0)return arr[n];

    else{

        arr[n] = fib(n-1) + fib(n-2);

        return arr[n];

    }

}


int main(){

    long long n;

    arr[0] = 0;

    arr[1] = 1;

    cin >> n;

    cout << fib(n);

    return 0;
}
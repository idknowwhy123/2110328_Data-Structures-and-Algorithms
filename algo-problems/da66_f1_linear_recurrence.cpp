#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll R(int n, vector<ll> &a, vector<ll> &c, int k,vector<ll> &r){

    if(r[n] != 0){

        return r[n] % 32717;

    }else if(n < k){

        r[n] = a[n];

        return r[n] % 32717;

    }else if(n >= k){

        ll sum = 0;

        for(int i=1;i<=k;i++){

            sum += (c[i] * (R(n-i,a,c,k,r))) % 32717;

        }

        r[n] = sum;

        return r[n] % 32717;

    }

    return 0;

}

int main(){

    ll k,n;

    vector<ll> c;

    vector<ll> a;

    cin >> k >> n;  
    
    vector<ll> r(n*n, 0);

    c.push_back(0);

    for(int i=0;i<k;i++){

        int num;

        cin >> num;

        c.push_back(num);

    }

    for(int i=0;i<k;i++){

        int num;

        cin >> num;

        a.push_back(num);

    }

    cout  << R(n, a, c, k, r);
    
    return 0;
}
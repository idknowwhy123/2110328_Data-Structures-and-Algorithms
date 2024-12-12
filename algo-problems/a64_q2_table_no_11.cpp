#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll md = 100000007;

ll recur(vector<ll> &v, ll n){

    if(n == 0)return 1;

    else if(n == 1)return 3;

    else if(v[n] == 0){

        v[n] = ((2*recur(v,n-1)) + recur(v,n-2)) % md;

        return v[n];

    }else{

        return v[n];

    }

}

int main(){

    ll n;

    cin >> n;

    vector<ll> v(n+1,0);

    cout << recur(v,n);

    return 0;
}
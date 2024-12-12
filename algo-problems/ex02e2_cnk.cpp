#include<bits/stdc++.h>
using namespace std;

#define ll long long

map<pair<ll,ll>,ll> mp;

ll C(ll n, ll k){

    if(n == k || k == 0){

        return 1;

    }else if(mp.find({n,k}) == mp.end()){

        mp[{n,k}] = C(n-1,k-1) + C(n-1,k);

    }

    return mp[{n,k}];

}

int main(){

    ll n,k;

    cin >> n >> k;

    cout << C(n,k);
    
    return 0;
}
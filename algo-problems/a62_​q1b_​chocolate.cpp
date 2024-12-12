#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> ans(10010, 0);

ll recur(vector<ll> &v, ll n){

    if(n < 0)return 0;

    else if(n == 0)return 1;

    else if(ans[n] != 0)return ans[n];

    else{

        ll sum = 0;

        for(auto x : v){

            sum += recur(v,n-x);

        }

        ans[n] = sum;

        return ans[n];

    }
}

int main(){

    ll n,m;

    cin >> n >> m;

    vector<ll> v(1+n, 0);

    while(m--){

        ll num;

        cin >> num;

        v.push_back(num);

    }    

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll solve(vector<ll> &v, ll indx,ll cost,ll k){

    ll n = v.size();

    ll low = indx + 1, high = n - 1, best = indx;

    while (low <= high) {

        ll mid = (low + high) / 2;

        ll ct = (mid - indx) * k;

        if (v[mid] - v[indx] <= cost - ct) {

            best = mid;

            low = mid + 1;

        } else {

            high = mid - 1;

        }

    }

    return v[best] - v[indx];
}


int main(){

    ll n,m,k;

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m >> k;
    
    vector<ll> v(n+1 , 0);

    for(int i=1;i<=n;i++){

        ll num;

        cin >> num;

        v[i] = v[i-1] + num;

    }

    for(int i=0;i<m;i++){

        ll num,cost;

        cin >> num >> cost;

        cout << solve(v,num,cost,k) << '\n';

    }

    return 0;

}
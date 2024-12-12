#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

    ll n;

    ios_base::sync_with_stdio(0);cin.tie(NULL);

    cin >> n;
    
    vector<ll> v[2*n - 1];

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){

            ll num;

            cin >> num;
            
            int tmp = i - j + (n - 1);

            if(v[tmp].size()!=0)num += v[tmp][v[tmp].size()-1];

            v[tmp].push_back(num);

        }

    }
    ll mx = LLONG_MIN;

    for (auto &anti_diag : v) {

        for (int i = 0; i < anti_diag.size(); i++) {

            for (int j = i; j < anti_diag.size(); j++) {
                
                ll segment_sum = anti_diag[j];

                if (i > 0) {

                    segment_sum -= anti_diag[i - 1];

                }
                
                mx = max(mx, segment_sum); 
            }
        }
    }

    cout << mx << '\n';

    return 0;
}
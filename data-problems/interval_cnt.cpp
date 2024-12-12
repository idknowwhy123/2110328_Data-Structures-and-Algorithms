#include<bits/stdc++.h>
using namespace std;

vector<int> v;

int main(){

    int n,m,k;

    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    cin >> n >> m >> k;

    for(int i=0;i<n;i++){

        int tmp;

        cin >> tmp;

        v.push_back(tmp);

    }

    sort(v.begin(),v.end());

    for(int i=0;i<m;i++){

        int q,st,en;

        cin >> q;

        st = q-k;

        en = q+k;
        
        if(q-k < 0)st = 0;

        auto it1 = lower_bound(v.begin(), v.end(), st) - v.begin();

        auto it2 = upper_bound(v.begin(), v.end(), en) - v.begin();

        cout << it2 - it1 << ' ';
    }

    return 0;
}
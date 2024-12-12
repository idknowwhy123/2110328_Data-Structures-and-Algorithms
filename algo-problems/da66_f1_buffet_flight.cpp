#include<bits/stdc++.h>
using namespace std;

#define ll long long

struct edge{

    ll en,w;

    bool operator<(const edge &x)const{

        return w > x.w;

    }

};

vector<ll> STP(vector<vector<edge>> &v, vector<ll> &in, vector<ll> &out, ll n, ll st){

    vector<ll> dis(n, LLONG_MAX);

    priority_queue<edge> q;

    q.push({st, 0});

    while(!q.empty()){

        edge tmp = q.top();q.pop();

        if(dis[tmp.en] < tmp.w)continue;

        dis[tmp.en] = tmp.w;

        for(auto x : v[tmp.en]){

            if(dis[x.en] > tmp.w + x.w) q.push({x.en,tmp.w + x.w});

        }

    }

    return dis;

}



int main(){

    ll n,m;

    cin >> n >> m;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll> in;

    vector<ll> out; 

    vector<vector<edge>> v(n);

    for(ll i=0;i<n;i++){

        ll num;

        cin >> num;

        in.push_back(num);

    }

    for(ll i=0;i<n;i++){

        ll num;

        cin >> num;

        out.push_back(num);

    }

    for(ll i=0;i<m;i++){

        ll st,en;

        cin >> st >> en;

        v[st].push_back({en,out[st] + in[en]});

        v[en].push_back({en,out[en] + in[st]});

    }

    vector<ll> dis = STP(v, in, out, n, 0);

    for(auto x : dis){

        if(x == LLONG_MAX){

            cout << -1 << ' ';

            continue;

        }

        cout << x << ' ';

    }

    return 0;
}
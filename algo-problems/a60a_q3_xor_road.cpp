#include<bits/stdc++.h>
using namespace std;

struct edge{

    long long en,w;

    bool operator<(const edge &x)const{

        return w < x.w;

    }

};

long long prim(vector<vector<edge>> &v, long long st,long long n){

    vector<bool> chk(n, 0);

    priority_queue<edge> q;

    long long ans = 0;

    q.push({st,0});

    while(!q.empty()){

        edge tmp = q.top(); q.pop();

        if(chk[tmp.en])continue;

        chk[tmp.en] = 1;

        ans += tmp.w;

        for(auto x : v[tmp.en]){

            if(!chk[x.en])q.push({x.en,x.w});

        }

    }

    return ans;
}

int main(){

    long long n;

    cin >> n;

    long long arr[n];

    vector<vector<edge>> v(n);

    for(long long i=0;i<n;i++){

        cin >> arr[i];

    }

    for(long long i=0;i<n;i++){

        for(long long j=0;j<n;j++){

            long long x = arr[i] ^ arr[j];

            v[i].push_back({j,x});;

        }

    }

    cout << prim(v, 0, n);

    return 0;
}
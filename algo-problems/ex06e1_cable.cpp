#include<bits/stdc++.h>
using namespace std;

struct edge{

    long long en,w;

    bool operator<(const edge &x)const{

        return w > x.w;

    }

};

long long prim(vector<vector<edge>> &v, long long st, long long n){

    vector<bool> chk(n, 0);

    priority_queue<edge> q;

    q.push({st,0});

    long long ans = 0;

    while(!q.empty()){

        edge tmp = q.top();q.pop();

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

    vector<vector<edge>> v(n);

    for(int i=0;i<n-1;i++){

        for(int j=i+1;j<n;j++){

            long long num;

            cin >> num;

            v[i].push_back({j,num});

            v[j].push_back({i,num});

        }

    }

    cout << prim(v, 0, n);

    return 0;
}
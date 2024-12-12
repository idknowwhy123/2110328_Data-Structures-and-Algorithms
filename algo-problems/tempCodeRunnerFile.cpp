#include<bits/stdc++.h>
using namespace std;

struct edge{

    int st,en,w;

};

vector<int> bellman(int n, vector<edge> &v, int st, int m){

    vector<int> dis(n, INT_MAX);

    dis[st] = 0;

    for(int i=0;i<n;i++){

        for(auto x : v){

            if(dis[x.st] != INT_MAX && dis[x.st] + x.w < dis[x.en]){

                if(i == m-1)return {-1};

                dis[x.en] = dis[x.st] + x.w;

            }

        }

    }

    return dis;

}

int main(){

    int n,m,s;

    cin >> n >> m >> s;

    vector<edge> v;

    for(int i=0;i<m;i++){

        int st,en,w;

        cin >> st >> en >> w;

        v.push_back({st,en,w});

    }

    vector<int> ans = bellman(n, v, s, m);

    for(auto x : ans){

        cout << x << ' ';

    }

    return 0;
}
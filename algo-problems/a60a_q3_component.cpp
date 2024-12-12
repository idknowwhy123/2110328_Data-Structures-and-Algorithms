#include<bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int>> &v,vector<bool> &chk, int st){

    queue<int> q;

    q.push(st);

    while(!q.empty()){

        int curr = q.front();q.pop();

        if(chk[curr])continue;

        chk[curr] = 1;

        for(auto x : v[curr]){

            if(!chk[x])q.push(x);

        }

    }

    return 1;

}

int main(){

    int n,m;

    cin >> n >> m;

    vector<vector<int>> v(n+1);

    vector<bool> chk(n+1, 0);

    for(int i=0;i<m;i++){

        int st,en;

        cin >> st >> en;

        v[st].push_back(en);

        v[en].push_back(st);

    }

    int cnt = 0;

    for(int i=1;i<=n;i++){

        if(!chk[i])cnt += bfs(v, chk, i);

    }

    cout << cnt;

    return 0;
}
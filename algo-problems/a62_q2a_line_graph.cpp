#include<bits/stdc++.h>
using namespace std;

int check(vector<vector<int>> &v, vector<bool> &chk, int st, int n){

    queue<int> q;

    q.push(st);

    bool deg3 = 1,root = 0;

    while(!q.empty()){

        int tmp = q.front();
        
        q.pop();
        
        if(chk[tmp])continue;

        else chk[tmp] = 1;
        
        int deg = v[tmp].size();
        
        if (deg < 2)root = true;

        if (deg > 2)deg3 = false;
        
        for(auto x : v[tmp]){

            if(!chk[x]) q.push(x);

        }   

    }

    return deg3 && root;

}

int main(){

    int n,m;

    cin >> n >> m;

    vector<vector<int>> v(n);

    vector<bool> chk(n, 0);

    for(int i=0;i<m;i++){

        int st,en;

        cin >> st >> en;

        v[st].push_back(en);

        v[en].push_back(st);

    }

    int ans = 0;

    for(int i=0;i<n;i++){

        if(!chk[i]){
            
            ans += check(v,chk,i,n);

        }

    }

    cout << ans;

    return 0;
}
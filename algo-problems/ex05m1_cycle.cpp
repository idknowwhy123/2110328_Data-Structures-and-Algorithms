#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &v, vector<bool> &chk, int cur,int prev){

    chk[cur] = 1;

    for(auto x : v[cur]){

        if(!chk[x]){

            if(dfs(v, chk, x, cur)){

                return 1;

            }

        }else if(x != prev){

            return 1;

        }

    }

    return 0;

}

int main(){

    int t;

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> t;

    while(t--){

        int n,e;
        
        cin >> n >> e;
        
        vector<vector<int>> v(n);

        vector<bool> chk(n, 0);

        for(int i=0;i<e;i++){

            int st,en;

            cin >> st >> en;

            v[st].push_back(en);

            v[en].push_back(st);

        }

        bool cycle = false;

        for (int i = 0; i < n; i++) {

            if (!chk[i] && dfs(v, chk, i, -1)) {

                cycle = true;

                break;
                
            }
        }

        cout << (cycle ? "YES\n" : "NO\n");

    }

    return 0;
}
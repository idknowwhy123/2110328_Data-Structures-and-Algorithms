#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &v, vector<bool> &chk, int curr, int dept, int k,int &cnt, vector<bool> &dchk){

    if(dept > k) return; 

    //cout << curr << ' ' << dept << '\n';

    if(!dchk[curr]){

        dchk[curr] = 1;
        
        cnt++;

    }

    for(auto x : v[curr]){

        if(!chk[x]){
            
            chk[x] = 1;
            
            dfs(v, chk, x, dept+1, k, cnt, dchk);
            
            chk[x] = 0;

        }
        
    }

}

int main(){

    int n,m,k;

    cin >> n >> m >> k;

    vector<vector<int>> v(n);

    for(int i=0;i<m;i++){

        int st,en;

        cin >> st >> en;

        v[st].push_back(en);

        v[en].push_back(st);

    }

    

    int ans = INT_MIN;

    for (int i = 0; i < n; i++) {

        vector<bool> chk(n, 0);

        vector<bool> dchk(n, 0);

        int cnt = 0;
        
        dfs(v, chk, i, 0, k, cnt, dchk);

       // cout << '\n';

        ans = max(ans, cnt);

    }

    cout << ans;

    return 0;
}

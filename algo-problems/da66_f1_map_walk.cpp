#include<bits/stdc++.h>
using namespace std;  

int n,m;

void dfs(vector<vector<int>> &v, vector<vector<bool>> &chk, int st, int en, int gx, int gy, string tmp){

    if(st > n-1 || en > m-1 || st < 0 || en < 0 || v[st][en] == 1 || chk[st][en] == 1)return ;

    else if(st == gx && en == gy){

        cout << tmp << '\n';

        return;

    }else{

        chk[st][en] = 1;

        dfs(v, chk, st, en+1, gx, gy, tmp+"A");

        dfs(v, chk, st+1, en, gx, gy, tmp+"B");

        dfs(v, chk, st-1, en, gx, gy, tmp+"C");

        chk[st][en] = 0;

    }


}

int main(){

  

    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m,0));

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            int num;

            cin >> num;

            v[i][j] = num;

        }

    }

    vector<vector<bool>> chk(n, vector<bool>(m,0));

    dfs(v, chk, 0, 0, n-1, m-1, "");

    cout << "DONE";



    return 0;
}
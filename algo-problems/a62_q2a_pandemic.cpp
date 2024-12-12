#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> v(500, vector<int>(500));
//vector<vector<bool>> chk(500, vector<bool>(500,0));

void recur(int x, int y,int k,int n,int m,int t,int &cnt,vector<vector<bool>> &chk){

    if(x >= n || x < 0 || y >= m || y < 0 || v[x][y] == 2 || k >= t)return;

    if(v[x][y] == 0){

        v[x][y] = 1;

        cnt++;

    }

    recur(x+1, y, k+1,n,m,t,cnt,chk);

    recur(x, y+1, k+1,n,m,t,cnt,chk);

    recur(x-1, y, k+1,n,m,t,cnt,chk);

    recur(x, y-1, k+1,n,m,t,cnt,chk);

}

int main(){

    int n,m,t;

    cin >> n >> m >> t;

    vector<pair<int,int>> pos;

    for(int i =0;i<n;i++){

        for(int j=0;j<m;j++){

            int num;

            cin >> num;

            v[i][j] = num;

            if(num == 1)pos.push_back({i,j});

        }
        
    }
    
    int cnt = 0;

    for(auto &x : pos){

        cnt++;

        vector<vector<bool>> chk(500, vector<bool>(500, false));

        recur(x.first, x.second,-1,n,m,t,cnt,chk);

    }

    cout << cnt;

    return 0;
}

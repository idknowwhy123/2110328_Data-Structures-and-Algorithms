#include<bits/stdc++.h>
using namespace std;   

int r,c;

struct edge{

    int x,y,w;

};

int bfs(vector<vector<int>> &v, vector<pair<int,int>> &pos1, int n,int m){

    vector<vector<bool>> chk(n, vector<bool>(m,0));

    queue<edge> q;

    for(auto x : pos1){

        q.push({x.first,x.second,0});

    }

    while(!q.empty()){

        edge tmp = q.front();

        q.pop();

        int cx = tmp.x, cy = tmp.y;
        
        if(cx >= r || cx < 0 || cy >= c || cy < 0)continue;

        else if(chk[cx][cy] || v[cx][cy] == 3)continue;

        else if(v[cx][cy] == 2)return tmp.w+1;

        chk[cx][cy] = 1;

        q.push({cx,cy+1,tmp.w+1});

        q.push({cx+1,cy,tmp.w+1});

        q.push({cx,cy-1,tmp.w+1});

        q.push({cx-1,cy,tmp.w+1});

    }

    return INT_MAX;

}

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);

    cin >> r >> c;

    vector<vector<int>> v(r, vector<int>(c,0));

    vector<pair<int,int>> pos1;

    for(int i=0;i<r;i++){

        for(int j=0;j<c;j++){

            int num;

            cin >> num;

            v[i][j] = num;

            if(num == 1)pos1.push_back({i,j});

        }

    }

    cout << bfs(v,pos1,r,c);
    
    return 0;
}
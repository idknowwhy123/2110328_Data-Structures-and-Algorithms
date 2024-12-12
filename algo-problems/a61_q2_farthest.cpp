#include<bits/stdc++.h>
using namespace std;

struct edge{

    int en,w;

    bool operator<(const edge &x)const{

        return w > x.w;

    }

};

int STP(vector<vector<edge>> &v, vector<int> &dis, int st){

    priority_queue<edge> q;

    q.push({st,0});

    int ans = INT_MIN;

    while(!q.empty()){

        edge tmp = q.top();q.pop();

        if(dis[tmp.en] <= tmp.w)continue;

        dis[tmp.en] = tmp.w;

        ans = max(ans, tmp.w);

        for(auto x : v[tmp.en]){

            if(dis[x.en] > tmp.w + x.w) {

                q.push({x.en, x.w + tmp.w}); 

            }

        }

    }

    return ans;

}

int main(){

    int n;

    cin >> n;

    vector<vector<edge>> v(n);

    vector<int> dis(n, INT_MAX);

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){

            int num;

            cin >> num;

            if(num == -1)continue;

            v[i].push_back({j,num});

        }

    }

    STP(v, dis, 0);

    int mx = INT_MIN;

    for(auto x : dis){

        mx = max(mx, x);

        if(x == INT_MAX){

            cout << -1;

            return 0;

        }

    }

    cout << mx;

    return 0;
}
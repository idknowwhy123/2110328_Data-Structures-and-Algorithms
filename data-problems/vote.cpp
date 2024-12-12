#include<bits/stdc++.h>
using namespace std;

unordered_map<string,int> ump;

vector<int> v;

int main(){

    int n,m;

    cin >> n >> m;

    for(int i = 0;i<n;i++){

        string name;

        cin >> name;

        if(ump.find(name) != ump.end()){

            ump[name]++;

        }else{

            ump[name] = 1;

        }

    }

    for(auto x : ump){

        //if(x.second <= 0)continue;

        v.push_back(x.second);

    }

    sort(v.begin(),v.end(),greater<int>());

    int indx = 0,ans;

    for(int i=0; i<v.size(); i++){

        if(v[i+1] <= v[i])indx++;

        ans = v[i];

        //cout << v[i] << ' ' << indx << '\n';

        if(indx == m)break;
 
    }
    
    cout << ans;

    return 0;
}
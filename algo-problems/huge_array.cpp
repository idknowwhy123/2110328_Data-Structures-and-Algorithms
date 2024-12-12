#include<bits/stdc++.h>
using namespace std;

map<int,int> ump;

int main(){

    int n,m;

    int mx = INT_MIN;

    cin >> n >> m;

    for(int i=0;i<n;i++){

        int num1,num2;

        cin >> num1 >> num2;

        if(ump.find(num1) != ump.end()){

            ump[num1] += num2;

        }else{

            ump[num1] = num2;

        }

        mx = max(mx, num1);

    }
    
    set<pair<int,int>> s;

    int curr = 0;

    for(auto x : ump){

        curr += x.second;

        s.insert({curr,x.first});

    }

    for(int i=0;i<m;i++){

        int num;

        cin >> num;

        auto it = s.lower_bound({num,0});

        cout << (*it).second << '\n';

    }

    return 0;
}

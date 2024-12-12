#include<bits/stdc++.h>
using namespace std;

vector<int> v;

int n,m;

void res(int p){

    if(p >= n)return ;
    else {
        v.push_back(p);
        res(p*2+1);
        res(p*2+2);
    }
}

int main(){

    

    cin >> n >> m;

    //cout << m << ' ';

    res(m);

    //sort(v.begin(),v.end());

    for(auto x : v){

        cout << x << ' ';

    }


    return 0;
}
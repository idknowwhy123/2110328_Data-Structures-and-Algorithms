#include<bits/stdc++.h>
using namespace std;

vector<bool> chk(INT_MAX, 0);

void permu(vector<int> &v,int i, int n){

    if(i == n){

        for(auto x : v){

            cout << x << ' ';

        }

        cout << '\n';

    }else{

        for(int j=i;j<n;j++){

            swap(v[i], v[j]);
               
            permu(v,i+1,n);
            
            swap(v[i], v[j]);
            
        }

    }

}

int main(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n,m,k;

    cin >> n >> m;
    
    vector<int> v;

    for(int i=0;i<m;i++){

        int st,nd;

        cin >> st >> nd;

        chk[st] = 1;

        chk[nd] = 1;

    }

    for(int i=0;i<n;i++){

        v.push_back(i);

    }

    permu(v,0,n);

    return 0;
}
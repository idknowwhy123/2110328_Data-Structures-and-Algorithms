#include<bits/stdc++.h>
using namespace std;

int count(vector<int> &v, int num){

    int cnt = 0;

    for(int i=0;v[i] != num;i++){

        if(v[i] > num)cnt++;

    }
    
    return cnt;

}

int main(){

    vector<int> v;

    unordered_map<int,int> ump;

    int n,m;

    cin >> n >> m;

    for(int i=0;i<n;i++){

        int num;

        cin >> num;

        v.push_back(num);

    }

    for(int i=0;i<m;i++){

        int num;

        cin >> num;

        cout << count(v, num) << '\n';

    }
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int recur(set<long long> &s, int curr, int n){

    if(n <= curr){

        return 0;

    }else{

        s.insert(curr);

        recur(s, (2*curr) + 1, n);

        recur(s, (2*curr) + 2, n);

        return 0;

    }

}

int main(){

    long long n,m;

    cin >> n >> m;

    if(m == 0){

        cout << '0';

        return 0;
        
    }

    set<long long> s;

    recur(s, m, n);

    cout << n-s.size() << '\n';

    for(int i=0;i<n;i++){

        if(s.find(i) == s.end())cout << i << ' ';

    }

    return 0;

}
#include<bits/stdc++.h>
using namespace std;

multiset<int> s;

string res(int n){

    for(auto x : s){

        if(x < 0 || x > n || x == 0 || s.count(x) >= 2)return "NO";

    }

    return "YES";

}

int main(){

    int n;

    cin >> n;

    for(int i=0;i<n;i++){

        int num;

        cin >> num;

        s.insert(num);
        
    }

    cout << res(n);

    return 0;
}
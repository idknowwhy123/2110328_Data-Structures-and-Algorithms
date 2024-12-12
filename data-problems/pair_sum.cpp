#include<bits/stdc++.h>
using namespace std;

multiset<int> s;

string res(int num){

    for(auto x : s){

        if(s.find(num-x) != s.end()){

            if(num - x == num/2 && s.count(num/2) < 2)return "NO\n";

            return "YES\n";
            
        }

    }

    return "NO\n";

}


int main(){

    int n,m;

    cin >> n >> m;

    for(int i=0;i<n;i++){

        int num;

        cin >> num;

        s.insert(num);

    }

    for(int i=0;i<m;i++){

        int num;

        cin >> num;

        cout << res(num);

    }

    return 0;
}
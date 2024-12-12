#include<bits/stdc++.h>
using namespace std;

set<string> s;

void recur(string str,int indx,int n){

    if(indx >= n){

        s.insert(str);
        

    }else{

        for(int i = indx;i<n;i++){

            swap(str[i],str[indx]);

            if(s.find(str) == s.end()){

                 recur(str, indx+1, n);

            }

            swap(str[i],str[indx]);

        }

    }

}

int main(){

    int n,m;

    cin >> n >> m;

    string str = "";

    for(int i=0;i<m-n;i++){

        str += "0";
        
    }

    for(int i=0;i<n;i++){

        str += "1";

    }

    recur(str, 0, m);

    for(auto x : s){

        cout << x << '\n';

    }

    return 0;
}
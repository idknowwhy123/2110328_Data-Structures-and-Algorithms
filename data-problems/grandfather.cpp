#include<bits/stdc++.h>
using namespace std;

unordered_map<string,string> ump;

string grand(string a){

    if(ump.find(a)!=ump.end()){

        string f = ump[a];

        if(ump.find(f)!=ump.end()){

            return ump[f];

        }else{

            return "X";

        }

    }

    return "X";

}   

int main(){

    ios_base::sync_with_stdio(false); cin.tie(0);

    int n,m;

    cin >> n >> m;

    for(int i=0;i<n;i++){

        string f,s;

        cin >> f >> s;

        ump[s] = f;

    }
    
    for(int i=0;i<m;i++){

        string a,b;

        cin >> a >> b;

        string gf1 = grand(a);

        string gf2 = grand(b);

        if(a == b || gf1 == "X" || gf2 == "X" || gf1 != gf2)cout << "NO\n";

        else cout << "YES\n";

    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    set<pair<int,int>> s;

    int n;

    cin >> n;

    while(n--){

        int num;

        cin >> num;

        if(num == 1){

            int st,en;

            cin >> st >> en;

            auto it = s.lower_bound({st,en});

            if(!s.empty())it--;
            
            while(it != s.end() && en+1 >= it->first && st <= it->second+1){
                
                st = min(st, it->first);

                en = max(en, it->second);

                it  = s.erase(it);

            }
            
            s.insert({st,en});

        }else{

            cout << s.size() << '\n';

        }

    }

    return 0;
}
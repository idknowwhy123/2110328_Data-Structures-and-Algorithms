#include<bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    int n,mx = INT_MIN;

    cin >> n;

    int arr[n] = {};

    unordered_map<int,int> ump;

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){

            int num;

            cin >> num;

            if(j == 0){

                ump[i] = num;

            }else{

                ump[i] += num;

            }

            mx = max(mx, ump[i]);

        }

    }

    //vector<int> v;

    //int arr[n] = {}

    for(auto x : ump){
        
        arr[x.second] += 1;

    }

    for(int i=0;i<mx+1;i++){

        cout << arr[i] << ' ';

    }
    

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(){

    int T;

    cin >> T;

    while(T--){

        int n;

        cin >> n;

        float R[n][n];

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                cin >> R[i][j];

            }

        }

        bool chk = 0;

        for(int k=0;k<n;k++){

            for(int i=0;i<n;i++){

                for(int j=0;j<n;j++){

                    //cout << R[i][j] << ' ' << R[i][k] * R[k][j] << '\n';

                    R[i][j] = max(R[i][j], R[i][k] * R[k][j]);

                    if(R[j][j] > 1)chk = 1;
                }

                if(chk)break;
            }

            if(chk)break;
        }

        if(chk)cout << "YES\n";

        else cout << "NO\n";

    }

    return 0;
}
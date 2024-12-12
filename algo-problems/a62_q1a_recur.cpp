#include<bits/stdc++.h>
using namespace std;

void recur(vector<vector<int>> &v, int a, int b,int top,int bottom,int left,int right){

    if(a == 0){

        v[top][left] = b;

    }else{

        int midr = (top + bottom)/2;
        
        int midc = (right + left)/2;

        recur(v, a-1, b, top, midr, left, midc);

        recur(v, a-1, b-1, top, midr ,midc, right);

        recur(v, a-1, b+1, midr, bottom ,left ,midc);

        recur(v, a-1, b, midr , bottom, midc, right);
        
    }

}

int main(){

    //vector<vector<int>> v;

    int a,b;

    cin >> a >> b;

    int size = 1 << a;

    vector<vector<int>> v(size, vector<int>(size, 0));

    recur(v ,a ,b ,0 ,1 << a ,0 ,1 << a);

    for(int i=0;i<v.size();i++){

        for(auto x : v[i]){

            cout << x << ' ';

        }

        cout << '\n';

    }

    return 0;
}
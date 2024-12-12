#include<bits/stdc++.h>
using namespace std;

bool chk(vector<int> &v,int left,int right){

    if(right - left == 1){
        
        //cout << v[left] << ' ' << v[right] << '\n';

        return(v[left] == 0 && v[right] == 1);

    }else{

        int mid = (left + right)/2;

        bool lf = chk(v, left, mid);

        bool rt = chk(v, mid+1, right);

        reverse(v.begin() + left, v.begin() + mid + 1);

        bool lf_r = chk(v, left, mid);

        bool rt_r = chk(v, mid+1, right);

        reverse(v.begin() + left, v.begin() + mid + 1);

        return (lf && rt) || (lf_r && rt_r);

    }

}



int main(){

    int n,m;

    cin >> n >> m;

    int size = 1 << m;

    for(int i=0;i<n;i++){
        
        vector<int> v;

        for(int j=0;j<size;j++){

            int num;

            cin >> num;

            v.push_back(num);

        }

        if(chk(v, 0, size-1))cout << "yes\n";

        else cout << "no\n";
       
    }

    return 0;
}
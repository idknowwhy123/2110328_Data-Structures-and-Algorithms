#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll bsearch(vector<ll> &v, ll num,int left,int right){

    if(v[left] == num || v[right] == num)return num;

    else if(left >= right && v[left] > num)return -1;

    else if(left >= right && v[left] < num)return v[left];

    else{

        int mid = (left+right+1)/2;

        if(num < v[mid]){

            return bsearch(v, num, left, mid-1);

        }else{

            return bsearch(v, num, mid, right);

        }

    }

    return -1;


} 

int main(){

    ll n,m;

    cin >> n >> m;

    vector<ll> v;

    for(int i=0;i<n;i++){

        int num;

        cin >> num;

        v.push_back(num);

    }

    for(int i=0;i<m;i++){

        ll num;

        cin >> num;

        cout << bsearch(v,num,0,n-1) << '\n';

    }


    return 0;
}
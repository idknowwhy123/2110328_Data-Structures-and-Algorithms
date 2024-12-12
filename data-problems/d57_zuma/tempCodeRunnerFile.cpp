#include<bits/stdc++.h>
using namespace std;

vector<int>::iterator check(vector<int> &v, vector<int>::iterator it, int num){

    if (v.empty()) {
        return v.end();
    }

    auto left = it;
    auto right = it;

    while (left != v.begin() && *(left - 1) == num) {
        left--;
    }

    while (right + 1 != v.end() && *(right + 1) == num) {
        right++;
    }

    int count = distance(left, right) + 1;

    if (count >= 3) {

        it = v.erase(left, right + 1);

        return it;
    }

    return v.end(); 

}

vector<int> v;

int main(){

    int n,pos,color;

    cin >> n >> pos >> color;

    for(int i=0;i<n;i++){

        int num;

        cin >> num;

        v.push_back(num);

    }

    auto it = v.begin() + pos;

    v.insert(it, color);

    while (true) {

        it = check(v, it, *it); 
        
        if (it == v.end()) {
            break;
        }
    }

    for(auto &x : v){

        cout << x << ' ';

    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

list<int>::iterator check(list<int> &lst, list<int>::iterator it) {
    if (lst.empty()) {
        return lst.end();
    }

    int num = *it;
    auto left = it;
    auto right = it;

    while (left != lst.begin() && *prev(left) == num) {
        left--;
    }

    while (next(right) != lst.end() && *next(right) == num) {
        right++;
    }

    int count = distance(left, next(right));

    if (count >= 3) {
        it = lst.erase(left, next(right));
        return it;                           
    }

    return lst.end();
}

int main() {
    int n, pos, color;

    cin >> n >> pos >> color;

    list<int> lst;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        lst.push_back(num);
    }

    auto it = lst.begin();
     
    for(int i=0;i<pos;i++){
        it++;
    }

    it = lst.insert(it, color);

    while (true) {

        it = check(lst, it);  
        
        if (it == lst.end()) {
            break;
        }
        if (it != lst.end()) {
            it--;
        }
    }

    for(auto x : lst) {
        cout << x << " ";
    }

    return 0;
}

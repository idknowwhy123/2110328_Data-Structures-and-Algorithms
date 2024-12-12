#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int> &v,vector<int>::iterator a,vector<int>::iterator b) {

    auto en = b,it = a;

    en--;

    for(auto it = a;it != b;it++){

        int fst = it-v.begin(),snd = en-v.begin();

        swap(v[fst],v[snd]);

        if(fst == snd || snd - fst == 1)break;

        en--;

    } 

}
int main() {
 //read input
    int n,a,b;

    cin >> n;

    vector<int> v;

    for (int i = 0;i < n;i++) {

        int c;

        cin >> c;

        v.push_back(c);

    }
    cin >> a >> b;

 //call function
    reverse(v,v.begin()+a,v.begin()+b+1);

 //display content of the vector
    for (auto &x : v) {

        cout << x << " ";

    }

    cout << endl;

    return 0;
}
#include <iostream>
#include "map_bst.h"
using namespace std;

int main()
{
    CP::map_bst<int, int> m;

    int n;

    cin >> n;

    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        m[num] = 1;
    }
    m.print();
    std::cout<<m.getValueOfMostImbalanceNode()<<endl;
    return 0;
}

#include <iostream>
#include <vector>
#include "KSet.h"
using namespace std;

int main(){
    vector<int> vec1 {1, 10, 2, 1, 4, 3};
    KSet k1(vec1);
    cout << k1 << endl;
    cout << k1.size() << endl;
    k1.clear();
    cout << k1 << endl;
    return 0;

}

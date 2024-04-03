#include <iostream>
#include <vector>
#include "KSet.h"
#include "iter.h"
using namespace std;

int count(KSet &kset, int value) {
    Iter *iter = kset.CreateIter();
    int* last = iter->last();
    iter->first();
    while (iter->CurrentItem() != last)
    {
        if (*iter->CurrentItem() == value) {
            return 1;
        }
        iter->next();
    }
    if (*iter->last() != value)
    {
        return 0;
    }
    else {
        return 1;
    }
    
    
    
}

int main(){
    KSet k1;
    KSet k2;
    k1.push(3);
    k1.push(2);
    k1.push(4);
    k1.push(3);
    k1.push(5);
    k1.push(7);
    k1.push(3);
    k2.push(2);
    k2.push(3);
    k2.push(4);
    k2.push(1);
    k2.push(7);
    k2.push(4);
    k2.push(1);
    cout << count(k1, 1) << endl;
    cout << count(k2, 1) << endl;
    KSet k3;
    cout << "k1: " << k1 << endl << "k2: " << k2 << endl;
    k3 = k1 | k2;
    cout << "k1 | k2: " << k3 << endl;
    k3 = k1 / k2;
    cout << "k1 / k2: " << k3 << endl;
    k3 = k1 & k2;
    cout << "k1 & k2: " << k3 << endl;
    return 0;
    
}

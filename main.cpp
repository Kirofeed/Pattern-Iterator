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
    cout << count(k1, 0) << endl;
    return 0;
    
}

#include "KSet.h"


class Iter {
    int index;
    int* value = 0;
    const KSet* kset;
public:
    Iter(const KSet* kset);
    int* first();
    int* last();
    int* next();
    int* CurrentItem();
};
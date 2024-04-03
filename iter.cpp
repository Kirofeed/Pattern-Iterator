#include "iter.h"


Iter::Iter(const KSet* kset) {
    this->kset = kset;
    int index = 0;
}
int* Iter::first() {
    this->value = &kset->arr[0];
    index = 0;
    return this->value;
}
int* Iter::last() {
    if (this->kset->sz == -1) {
        return first();
    }
    this->value = &this->kset->arr[this->kset->sz];
    return this->value;
}
int* Iter::next() {
    this->index++;
    this->value = &this->kset->arr[this->index];
    return this->value;
}
int* Iter::CurrentItem() {
    return this->value;
}





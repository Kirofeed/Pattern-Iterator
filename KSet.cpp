#include "KSet.h"
#include "Iter.h"
#include <iostream>
#include <algorithm>

using namespace std;

KSet::KSet() {
    sz = -1;
}

int KSet::size() const {
    return this->sz + 1;
}

void KSet::push(int a) {
    arr[++sz] = a;
    processKSet();
}


void KSet::processKSet() {
    std::sort(arr, arr + size());
    auto end = std::unique(arr, arr + size());
    sz = std::distance(arr, end) - 1;
}

Iter* KSet::CreateIter() const {
    return new Iter(this);
}


KSet &KSet::operator=(const KSet &other) {
    this->sz = other.sz;
    for(int i = 0; i != other.size(); ++i) {
        this->arr[i] = other.arr[i];
    }
    return *this;
}

KSet& KSet::operator|(const KSet& other) {
    KSet* NewKSet = new KSet();
    for(int i = 0; i != this->size(); ++i) {
        NewKSet->push(arr[i]);
    }
    for(int i = 0; i != other.size(); ++i) {
        NewKSet->push(other.arr[i]);
    } 
    NewKSet->processKSet();
    return *NewKSet;
}

KSet &KSet::operator|=(const KSet &other) {
    for(int i = 0; i != other.size(); ++i) {
        this->push(other.arr[i]);
    }
    processKSet();
    return *this;
}

KSet& KSet::operator&(const KSet& other) {
    KSet* NewKSet = new KSet();
    int this_size = this->size(),  other_size = other.size();
    for(int i = 0; i != this_size; ++i) {
        for(int j = 0; j != other_size; ++j) {
            if(this->arr[i] == other.arr[j]) {
                NewKSet->push(this->arr[i]);
            }
        }
    }
    NewKSet->processKSet();
    return *NewKSet;
}

KSet& KSet::operator&=(const KSet& other) {
    vector<int> temp;
    for(int i = 0; i != this->size(); ++i) {
        for(int j = 0; j != other.size(); ++j) {
            if(this->arr[i] == other.arr[j]) {
                temp.push_back(this->arr[i]);
            }
        }
    }
    this->sz = temp.size();
    for (int i = 0; i != this->size(); ++i) {
        this->arr[i] = temp[i];
    }
    
    this->processKSet();
    return *this;
}

KSet& KSet::operator/(const KSet& other) {
    KSet* NewKSet = new KSet();
    for(int i = 0; i != this->size(); ++i) {
        bool flag = false;
        for(int j = 0; j != other.size(); ++j) {
            if(this->arr[i] == other.arr[j]) {
                flag = true;
                break;
            }
        }
        if(!flag) {
            NewKSet->push(this->arr[i]);
        }
    }
    NewKSet->processKSet();
    return *NewKSet;
}

KSet& KSet::operator/=(const KSet& other) {
    vector<int> temp;
    for(int i = 0; i != this->size(); ++i) {
        bool flag = false;
        for(int j = 0; j != other.size(); ++j) {
            if(this->arr[i] == other.arr[j]) {
                flag = true;
                break;
            }
        }
        if(!flag) {
            temp.push_back(this->arr[i]);
        }
    }
    this->sz = temp.size();
    for(int i = 0; i != this->size(); ++i) {
        this->arr[i] = temp[i];
    }
    this->processKSet();
    return *this;
}

ostream& operator<<(ostream& os, const KSet& kset) {
    for(int i = 0; i != kset.sz + 1; ++i) {
        os << kset.arr[i] << "\t";
    }
    return os;
}

void KSet::clear() {
    delete arr;
    this->sz = 0;
}

bool KSet::IsEmpty() {
    return this->sz == 0;
}

bool KSet::IsFull() {
    return this->sz == 10;
}










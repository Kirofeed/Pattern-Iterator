#include "KSet.h"
#include <iostream>

using namespace std;

void processKSet(vector<int>& vec) {
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
}


KSet::KSet(const vector<int>& a) {
    vec = a;
    processKSet(vec);
}

void KSet::display() {
    for (auto i : this->vec) {
        cout << i << "\t";
    }
}

KSet &KSet::operator=(const KSet &other) {
    return *this;
}

KSet& KSet::operator|(const KSet& other) {
    KSet* NewKSet = new KSet();
    for(auto i : this->vec) {
        NewKSet->vec.push_back(i);
    }
    for(auto i : other.vec) {
        NewKSet->vec.push_back(i);
    }
    processKSet(NewKSet->vec);
    return *NewKSet;
}

KSet &KSet::operator|=(const KSet &other) {
    for(auto i : other.vec) {
        this->vec.push_back(i);
    }
    processKSet(this->vec);
    return *this;
}

KSet& KSet::operator&(const KSet& other) {
    KSet* NewKSet = new KSet();
    for(auto i : this->vec) {
        for(auto j : other.vec) {
            if(i == j) {
                NewKSet->vec.push_back(i);
            }
        }
    }
    processKSet(NewKSet->vec);
    return *NewKSet;
}

KSet& KSet::operator&=(const KSet& other) {
    vector<int> temp;
    for(auto i : this->vec) {
        for(auto j : other.vec) {
            if(i == j) {
                temp.push_back(i);
            }
        }
    }
    this->vec = temp;
    processKSet(this->vec);
    return *this;
}

KSet& KSet::operator/(const KSet& other) {
    KSet* NewKSet = new KSet();
    for(auto i : this->vec) {
        bool flag = false;
        for(auto j : other.vec) {
            if(i == j) {
                flag = true;
                break;
            }
        }
        if(!flag) {
            NewKSet->vec.push_back(i);
        }
    }
    processKSet(NewKSet->vec);
    return *NewKSet;
}

KSet& KSet::operator/=(const KSet& other) {
    vector<int> temp;
    for(auto i : this->vec) {
        bool flag = false;
        for(auto j : other.vec) {
            if(i == j) {
                flag = true;
                break;
            }
        }
        if(!flag) {
            temp.push_back(i);
        }
    }
    this->vec = temp;
    processKSet(this->vec);
    return *this;
}

ostream& operator<<(ostream& os, const KSet& kset) {
    for(auto i : kset.vec) {
        os << i << "\t";
    }
    return os;
}

int KSet::size() {
    return this->vec.size();
}

void KSet::clear() {
    this->vec.clear();
}

bool KSet::IsEmpty() {
    return this->vec.empty();
}









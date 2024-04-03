#ifndef KSET_H
#define KSET_H

#include <vector>
#include <fstream>
using namespace std;



class KSet {
    friend ostream& operator<<(ostream& os, const KSet& kset);
    friend class Iter;
private:
    int *arr = new int[10];
    int sz;
public:
    KSet();
    void push(int a);
    Iter* CreateIter() const;
    KSet& operator=(const KSet& other);
    KSet& operator|(const KSet& other);
    KSet& operator|=(const KSet& other);
    KSet& operator&(const KSet& other);
    KSet& operator&=(const KSet& other);
    KSet& operator/(const KSet& other);
    KSet& operator/=(const KSet& other);
    int size() const;
    void clear();
    bool IsEmpty();
    bool IsFull();
    void processKSet();
};

#endif // KSET_H
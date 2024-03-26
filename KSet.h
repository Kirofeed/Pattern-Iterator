#include <vector>
using namespace std;


class KSet {
    friend ostream& operator<<(ostream& os, const KSet& kset);
private:
    vector<int> vec;
public:
    explicit KSet(const vector<int>& a);
    KSet() = default;
    KSet& operator=(const KSet& other);
    KSet& operator|(const KSet& other);
    KSet& operator|=(const KSet& other);
    KSet& operator&(const KSet& other);
    KSet& operator&=(const KSet& other);
    KSet& operator/(const KSet& other);
    KSet& operator/=(const KSet& other);
    int size();
    void clear();
    bool IsEmpty();
    void display();
};
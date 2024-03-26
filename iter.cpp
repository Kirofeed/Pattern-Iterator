#include "iter.h"

Iter::Iter() {
    value_ = 0;
}
Iter::Iter(const Iter& other) {
    value_ = other.value_;
}
Iter& Iter::operator=(const Iter& other) = default;
void Iter::next() {
    value_++;
}

[[maybe_unused]] bool Iter::equals(const Iter& other) const {
    return value_ == other.value_;
}
int Iter::value() const {
    return value_;
}
void Iter::setValue(int value) {
    value_ = value;
}

Iter::~Iter() = default;





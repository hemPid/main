#include "vect.h"


vect::vect()
{
    size_ = 0;
    allocated_ = def_size_;
    data_ = new i64[def_size_];
}

vect::vect(u64 size) {
    this->size_ = 0;
    data_ = new i64[size];
    allocated_ = size;
    for (size_t i = 0; i < size; i++)
    {
        data_[i] = 0;
    }
    
}

vect::~vect()
{
    delete [] data_;
}

vect::vect(const vect & a) {
    this->allocated_ = a.allocated_;
    this->size_ = a.size_;
    this->data_ = new i64[allocated_];
    for (int64_t i = 0; i < size_; i++)
    {
        data_[i] = a.data_[i];
    }
}

vect & vect::operator=(const vect & a) {
    if (&a == this)
    {
        return *this;
    }
    vect tmp(a);
    std::swap(this->allocated_, tmp.allocated_);
    return *this;
}

vect::vect(vect && a) {
    this->allocated_ = a.allocated_;
    this->size_ = a.size_;
    this->data_ = a.data_;
    a.~vect();
}


vect & vect::operator=(vect && a) {
    if (&a == this)
    {
        return *this;
    }
    vect tmp(a);
    std::swap(this->allocated_, tmp.allocated_);
    std::swap(this->size_, tmp.size_);
    std::swap(this->data_, tmp.data_);
    return *this;
}

void vect::alloc_at_least(u64 n) {
    if (n <= allocated_) return;
    i64 * tmp = new i64[2*allocated_];
    allocated_ *= 2;
    for (size_t i = 0; i < size_; i++)
    {
        tmp[i] = data_[i];
    }
    delete [] data_;
    data_ = tmp;
}

i64& vect::operator[](u64 n) {
    return data_[n];
}

void vect::push_back(i64 a) {
    alloc_at_least(size_+1);
    data_[size_] = a;
    ++size_;
}

i64 vect::pop_back() {
    --size_;
    return data_[size_];
}

u64 vect::size() const {
    return size_;
}
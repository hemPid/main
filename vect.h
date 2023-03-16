#ifndef vect_h
#define vect_h
#include <cstdint>
#include <algorithm>
using i64 = int64_t;
using u64 = uint64_t;

class vect
{
private:
    i64 * data_;
    u64 size_;
    u64 allocated_;
    const u64 def_size_ = 2;
public:
    vect();
    vect(u64 size);
    ~vect();
    vect(const vect & a);
    vect & operator=(const vect & a);
    vect(vect && a);
    vect & operator=(vect && a);
    i64 & operator[](u64 i);
    void alloc_at_least(u64 n);
    void push_back(i64 a);
    i64 pop_back();
    u64 size() const;
};



#endif
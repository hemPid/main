#ifndef queue_h
#define queue_h
#include <cstdint>
#include "vect.h"

using i64 = int64_t;
using u64 = uint64_t;

//default queue

struct q_el
{
    q_el * prev;
    q_el * next;
    i64 val;
};


class queue_l
{
private:
    q_el * begin_;
    q_el * end_;
public:
    queue_l();
    ~queue_l();
    queue_l(const queue_l & a);
    queue_l & operator=(const queue_l & a);
    queue_l(queue_l && a);
    queue_l & operator=(queue_l && a);
    void append_back(i64 e);
    i64 pop_front();
};

//queue on two vectors

class queue_d
{
private:
    vect * s1_;
    vect * s2_; 
public:
    queue_d(/* args */);
    ~queue_d();
    void append_back(i64 e);
    i64 pop_front();
};


//circle queue

class queue_c
{
private:
    vect * data_;
    u64 tail_;
    u64 head_;
    u64 size_;
    u64 len_;
public:
    queue_c(u64 size);
    ~queue_c();
    queue_c(const queue_c & a);
    queue_c & operator=(const queue_c & a);
    queue_c(queue_c && a);
    queue_c & operator=(queue_c && a);
    void append_back(i64 e);
    i64 pop_front();
};




#endif
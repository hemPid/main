#include "queue.h"
#include <iostream>


//default queue

queue_l::queue_l()
{
    begin_ = nullptr;
    end_ = nullptr;
}

queue_l::~queue_l() {
    while (begin_) {
        pop_front();
    }
}

queue_l::queue_l(const queue_l & a) {
    begin_ = nullptr;
    end_ = nullptr;
    q_el * now = a.begin_;
    while (now)
    {
        this->append_back(now->val);
        now = now->prev;
    }
}

queue_l & queue_l::operator=(const queue_l & a) {
    queue_l tmp(a);
    std::swap(tmp.begin_, this->begin_);
    std::swap(tmp.end_, this->end_);
    return *this;
}

queue_l::queue_l(queue_l && a) {
    this->begin_ = a.begin_;
    this->end_ = a.end_;
    a.begin_ = nullptr;
    a.end_ = nullptr;
}

queue_l & queue_l::operator=(queue_l && a) {
    if (&a == this)
    {
        return *this;
    }
    
    queue_l tmp(std::move(a));
    std::swap(tmp.begin_, this->begin_);
    std::swap(tmp.end_, this->end_);
    return *this;
}

void queue_l::append_back(i64 e) {
    q_el * tmp = new q_el;
    tmp->val = e;
    tmp->prev = nullptr;
    if (end_ == nullptr)
    {
        begin_ = tmp;
        end_ = tmp;
        tmp->next = nullptr;
    } else {
        tmp->next = end_;
        end_->prev = tmp;
        end_ = tmp;
    }
}

i64 queue_l::pop_front() {
    if (begin_ == nullptr) {
        std::cerr << "There are no elements\n";
        return 0;
    }
    i64 ret_val = begin_->val;
    q_el * tmp = begin_->prev;
    delete begin_;
    begin_ = tmp;
    if (begin_) {
        begin_->next = nullptr;
    }
    return ret_val;
}



//queue on two vectors 



queue_d::queue_d()
{
    s1_ = new vect;
    s2_ = new vect;
}

queue_d::~queue_d()
{
    delete s1_;
    delete s2_;
}

void queue_d::append_back(i64 e) {
    s1_->push_back(e);
}

i64 queue_d::pop_front() {
    if (s2_->size()) {
        return s2_->pop_back();
    }
    while (s1_->size())
    {
        s2_->push_back(s1_->pop_back());
    }
    if (!s2_->size())
    {
        std::cerr << "No elements\n";
        return 0;
    }
    
    return s2_->pop_back();
}


//circle queue

queue_c::queue_c(u64 size)
{
    data_ = new vect(size);
    head_ = 0;
    tail_ = 0;
    len_ = 0;
    size_ = size;
}

queue_c::~queue_c()
{
    delete data_;
}


queue_c::queue_c(const queue_c & a) {
    this->head_ = a.head_;
    this->len_ = a.len_;
    this->size_ = a.size_;
    this->tail_ = a.tail_;
    this->data_ = a.data_;
}

queue_c & queue_c::operator=(const queue_c & a) {
    this->head_ = a.head_;
    this->len_ = a.len_;
    this->size_ = a.size_;
    this->tail_ = a.tail_;
    this->data_ = a.data_;
    return *this;
}

queue_c::queue_c(queue_c && a) {
    std::swap(this->head_, a.head_);
    std::swap(this->len_, a.len_);
    std::swap(this->size_, a.size_);
    std::swap(this->tail_, a.tail_);
    std::swap(this->data_, a.data_);
    a.~queue_c();
}

queue_c & queue_c::operator=(queue_c && a) {
    if (&a == this)
    {
        return *this;
    }
    
    queue_c tmp(a);
    std::swap(this->head_, tmp.head_);
    std::swap(this->len_, tmp.len_);
    std::swap(this->size_, tmp.size_);
    std::swap(this->tail_, tmp.tail_);
    std::swap(this->data_, tmp.data_);
    return *this;
}

void queue_c::append_back(i64 e) {
    if (len_ == size_)
    {
        std::cerr << "Too many elements\n";
        return;
    }
    
    (*data_)[tail_] = e;
    tail_ = (tail_ + 1) % size_;
    ++len_;
}

i64 queue_c::pop_front() {
    if (!len_)
    {
        std::cerr << "Queue is empty\n";
        return 0;
    }
    i64 ret_val = (*data_)[head_];
    head_ = (head_ + 1)%size_;
    --len_;
    return ret_val;
}
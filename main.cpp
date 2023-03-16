#include <iostream>
#include "vect.h"
#include "queue.h"
#include <string>
#include <chrono>
#include <fstream>

void triple_append(queue_l * a, queue_d * b, queue_c * c, i64 val) {
    a->append_back(val);
    b->append_back(val);
    c->append_back(val);
}

void triple_pop(queue_l * a, queue_d * b, queue_c * c, std::string & r_a, std::string & r_b,  std::string & r_c) {
    
    r_a += std::to_string(a->pop_front())  + " ";
    r_b += std::to_string(b->pop_front()) + " ";
    r_c += std::to_string(c->pop_front()) + " ";
}



void test_queues() {
    //case 1
    queue_l a1;
    queue_d b1;
    queue_c c1(5);
    std::string a_res = "";
    std::string b_res = "";
    std::string c_res = "";
    std::cout << "case 1:\n";
    std::cout << "Correct: 10 9 8 7 6 5 4 3 2 1\n";
    triple_append(&a1, &b1, &c1, 10);
    triple_append(&a1, &b1, &c1, 9);
    triple_append(&a1, &b1, &c1, 8);
    triple_append(&a1, &b1, &c1, 7);
    triple_pop(&a1, &b1, &c1, a_res, b_res, c_res);
    triple_append(&a1, &b1, &c1, 6);
    triple_append(&a1, &b1, &c1, 5);
    triple_pop(&a1, &b1, &c1, a_res, b_res, c_res);
    triple_pop(&a1, &b1, &c1, a_res, b_res, c_res);
    triple_append(&a1, &b1, &c1, 4);
    triple_append(&a1, &b1, &c1, 3);
    triple_pop(&a1, &b1, &c1, a_res, b_res, c_res);
    triple_pop(&a1, &b1, &c1, a_res, b_res, c_res);
    triple_append(&a1, &b1, &c1, 2);
    triple_append(&a1, &b1, &c1, 1);
    triple_pop(&a1, &b1, &c1, a_res, b_res, c_res);
    triple_pop(&a1, &b1, &c1, a_res, b_res, c_res);
    triple_pop(&a1, &b1, &c1, a_res, b_res, c_res);
    triple_pop(&a1, &b1, &c1, a_res, b_res, c_res);
    triple_pop(&a1, &b1, &c1, a_res, b_res, c_res);
    std::cout << "linked list: " << a_res << "\n";
    std::cout << "double stack: " << b_res << "\n";
    std::cout << "circle buf: " << c_res << "\n";
    //case 2
    queue_l a2;
    queue_d b2;
    queue_c c2(10);
    a_res = "";
    b_res = "";
    c_res = "";
    std::cout << "case 2:\n";
    std::cout << "Correct: 10 9 8 7 6 5 4 3 2 1\n";
    triple_append(&a2, &b2, &c2, 10);
    triple_append(&a2, &b2, &c2, 9);
    triple_append(&a2, &b2, &c2, 8);
    triple_append(&a2, &b2, &c2, 7);
    triple_append(&a2, &b2, &c2, 6);
    triple_append(&a2, &b2, &c2, 5);
    triple_append(&a2, &b2, &c2, 4);
    triple_append(&a2, &b2, &c2, 3);
    triple_append(&a2, &b2, &c2, 2);
    triple_append(&a2, &b2, &c2, 1);
    triple_pop(&a2, &b2, &c2, a_res, b_res, c_res);
    triple_pop(&a2, &b2, &c2, a_res, b_res, c_res);
    triple_pop(&a2, &b2, &c2, a_res, b_res, c_res);
    triple_pop(&a2, &b2, &c2, a_res, b_res, c_res);
    triple_pop(&a2, &b2, &c2, a_res, b_res, c_res);
    triple_pop(&a2, &b2, &c2, a_res, b_res, c_res);
    triple_pop(&a2, &b2, &c2, a_res, b_res, c_res);
    triple_pop(&a2, &b2, &c2, a_res, b_res, c_res);
    triple_pop(&a2, &b2, &c2, a_res, b_res, c_res);
    triple_pop(&a2, &b2, &c2, a_res, b_res, c_res);
    std::cout << "linked list: " << a_res << "\n";
    std::cout << "double stack: " << b_res << "\n";
    std::cout << "circle buf: " << c_res << "\n";
}


void time_test() {
    u64 size = 100000000;
    u64 n_p = 100;
    u64 step = size / n_p;
    //queue_l
    queue_l a;
    auto begin = std::chrono::steady_clock::now();
    std::ofstream q_l_append;
    q_l_append.open("q_l_append.txt");
    for (i64 i = 1; i <= size; ++i)
    {
        a.append_back(i);
        if (!(i % (size/n_p)))
        {
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> t = end - begin;
            q_l_append << i << " : " << t.count()/step << "\n";    
            begin = std::chrono::steady_clock::now();
        }
    }
    q_l_append.close();
    std::ofstream q_l_pop;
    q_l_pop.open("q_l_pop.txt");
    auto begin2 = std::chrono::steady_clock::now();
    for (i64 i = 1; i <= size; ++i)
    {
        a.pop_front();
        if (!(i % (size/n_p)))
        {
            auto end2 = std::chrono::steady_clock::now();
            std::chrono::duration<double> t = end2 - begin2;
            q_l_pop << i << " : " << t.count()/step << "\n";    
            begin2 = std::chrono::steady_clock::now();
        }
    }
    q_l_pop.close();
    //q_d
    queue_d b;
    auto begin3 = std::chrono::steady_clock::now();
    std::ofstream q_d_append;
    q_d_append.open("q_d_append.txt");
    for (i64 i = 1; i <= size; ++i)
    {
        b.append_back(i);
        if (!(i % (size/n_p)))
        {
            auto end3 = std::chrono::steady_clock::now();
            std::chrono::duration<double> t = end3 - begin3;
            q_d_append << i << " : " << t.count()/step << "\n";    
            begin3 = std::chrono::steady_clock::now();
        }
    }
    q_d_append.close();
    std::ofstream q_d_pop;
    q_d_pop.open("q_d_pop.txt");
    auto begin4 = std::chrono::steady_clock::now();
    for (i64 i = 1; i <= size; ++i)
    {
        b.pop_front();
        if (!(i % (size/n_p)))
        {
            auto end4 = std::chrono::steady_clock::now();
            std::chrono::duration<double> t = end4 - begin4;
            q_d_pop << i << " : " << t.count()/step << "\n";    
            begin4 = std::chrono::steady_clock::now();
        }
    }
    q_d_pop.close();
    //q_c
    queue_c c(size);
    auto begin5 = std::chrono::steady_clock::now();
    std::ofstream q_c_append;
    q_c_append.open("q_c_append.txt");
    for (i64 i = 1; i <= size; ++i)
    {
        c.append_back(i);
        if (!(i % (size/n_p)))
        {
            auto end5 = std::chrono::steady_clock::now();
            std::chrono::duration<double> t = end5 - begin5;
            q_c_append << i << " : " << t.count()/step << "\n";    
            begin5 = std::chrono::steady_clock::now();
        }
    }
    q_c_append.close();
    std::ofstream q_c_pop;
    q_c_pop.open("q_c_pop.txt");
    auto begin6 = std::chrono::steady_clock::now();
    for (i64 i = 1; i <= size; ++i)
    {
        c.pop_front();
        if (!(i % (size/n_p)))
        {
            auto end6 = std::chrono::steady_clock::now();
            std::chrono::duration<double> t = end6 - begin6;
            q_c_pop << i << " : " << t.count()/step << "\n";    
            begin6 = std::chrono::steady_clock::now();
        }
    }
    q_d_pop.close();
}


int main() {
    //test_queues();
    time_test();
    return 0;
}
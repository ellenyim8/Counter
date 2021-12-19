#ifndef MCOUNTER_H
#define MCOUNTER_H
#include <iostream>
using namespace std;

class MCounter
{
public:
    MCounter();             // default constructor
    int add_1();
    int add_10();
    int add_100();
    int add_1000();
    int reset();
    int count() const;
    void display_count();
    // error handling:
    string error_description();
    int error();            // accessor
    void reset_error();     // mutator
private:
    int _count;
    int max_count;
    int _error;
    int check_error();
};

void test_MCounter();

#endif // MCOUNTER_H

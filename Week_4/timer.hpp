#ifndef timer_hpp
#define timer_hpp

#include <stdio.h>
#include <iostream>
class Timer {
public:
    Timer();
    Timer(unsigned int _hr);
    Timer(unsigned int _hr, unsigned int _min);
    Timer(unsigned int _hr, unsigned int _min, unsigned int _sec);
    
    Timer& operator+=(const Timer&);
    Timer& operator-=(const Timer&);
    Timer& operator++();
    Timer operator++(int);
    Timer& operator--();
    Timer operator--(int);
    
    operator size_t();

private:
    unsigned int hr;
    unsigned int min;
    unsigned int sec;

    void simplify();

    friend bool operator==(const Timer&, const Timer&);
    friend bool operator< (const Timer&, const Timer&);

    friend std::ostream& operator<<(std::ostream&, const Timer&);
};

std::istream& operator>>(std::istream&, Timer&);
Timer operator+(Timer, const Timer&);
Timer operator-(Timer, const Timer&);

bool operator> (const Timer&, const Timer&);
bool operator!=(const Timer&, const Timer&);
bool operator<=(const Timer&, const Timer&);
bool operator>=(const Timer&, const Timer&);
#endif /* timer_hpp */

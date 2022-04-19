//
//  timer.cpp
//  opovtest
//
//  Created by Tejas Viswanath on 4/14/22.
//

#include "timer.hpp"

Timer::Timer()                           : hr(   0), min(   0),sec(0) {}
Timer::Timer(unsigned int _hr)           : hr(   _hr), min(   0),sec(0) {}
Timer::Timer(unsigned int _hr, unsigned int _min) :  hr(   _hr), min(   _min),sec(0) {simplify();}
Timer::Timer(unsigned int _hr, unsigned int _min, unsigned int _sec) :  hr(   _hr), min(   _min),sec(_sec) {simplify();}

void Timer::simplify() {
    if (sec>=60){
        min+=(sec/60);
        sec=(sec%60);
    }
    if (min>=60){
        hr+=(min/60);
        min=(min%60);
    }
}

std::ostream& operator<<(std::ostream& os, const Timer& t){
    
    os << ((t.hr>9)? '\0' : '0') << t.hr << ':'
       << ((t.min>9)? '\0' : '0') << t.min << ':'
       << ((t.sec>9)? '\0' : '0') << t.sec << '\n';
    
    return os;
}

std::istream& operator>>(std::istream& in, Timer& r) {
    unsigned int hr;
    unsigned int min;
    unsigned int sec;

    char colon1,colon2;

    in >> hr >> colon1 >> min >> colon2 >> sec;

    if (colon1 != ':' || colon2 != ':' ) {
        in.setstate(std::ios_base::failbit);
    }
    if (in) {
        r = Timer(hr, min, sec);
    }

    return in;
}

Timer& Timer::operator+=(const Timer& t){
    hr+=t.hr;
    min+=t.min;
    sec+=t.sec;
    simplify();
    return *this;
}

Timer& Timer::operator-=(const Timer& t){
    assert(*this>t);
    if(t.sec>sec){
        min-=1;
        sec+=60;
    }
    sec-=t.sec;
    if(t.min>min){
        hr-=1;
        min+=60;
    }
    min-=t.min;
    hr-=t.hr;
    simplify();
    return *this;
}

Timer operator+(Timer t1, const Timer& t2){
    return t1 += t2;
}

Timer operator-(Timer t1, const Timer& t2){
    return t1 -= t2;
}

bool operator==(const Timer& t1, const Timer& t2){
    if((t1.hr==t2.hr)&&(t1.min==t2.min)&&(t1.sec==t2.sec)){
        return true;
    }
    return false;
}

bool operator< (const Timer& t1, const Timer& t2){
    if(t1.hr<t2.hr){
        return true;
    }
    else if (t1.hr==t2.hr){
        if(t1.min<t2.min){
            return true;
        }
        else if (t1.min==t2.min){
            if(t1.sec<t2.sec){
                return true;
            }
        }
    }
    return false;
}

bool operator> (const Timer& t1, const Timer& t2){
    return (t2 < t1);
}
bool operator!=(const Timer& t1, const Timer& t2){
    return !(t1 == t2);
}
bool operator<=(const Timer& t1, const Timer& t2){
    if ((t1<t2) || (t1==t2)) {
        return true;
    }
    return false;
}
bool operator>=(const Timer& t1, const Timer& t2){
    if ((t2<t1) || (t1==t2)) {
        return true;
    }
    return false;
}

Timer& Timer::operator++(){
    ++sec;
    return *this;
}
Timer Timer::operator++(int){
    Timer pre(*this);
    ++(*this);
    return pre;
}
Timer& Timer::operator--(){
    assert(*this!=Timer());
    --sec;
    return *this;
}
Timer Timer::operator--(int){
    Timer pre(*this);
    --(*this);
    return pre;
}

Timer::operator size_t(){
    return hr*3600+min*60+sec;
}

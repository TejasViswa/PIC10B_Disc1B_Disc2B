#include "timer.hpp"
#include <string.h>

Timer::Timer()                                                        : hr(0), min(0),sec(0) {}
Timer::Timer(unsigned int _hr)                                        : hr(_hr), min(0),sec(0) {}
Timer::Timer(unsigned int _hr, unsigned int _min)                     : hr(_hr), min(_min),sec(0) {}
Timer::Timer(unsigned int _hr, unsigned int _min, unsigned int _sec)  : hr(_hr), min(_min),sec(_sec) {}

std::ostream& operator<<(std::ostream& os, const Timer& t){
    
    \\ '\0' is a null character, it is similar to "" in this case
    \\ Here, we check if the variable is a double digit or not. If it are not, then a '0' is placed in front of it.
    os << ((t.hr>9)? '\0' : '0') << t.hr << ':'
       << ((t.min>9)? '\0' : '0') << t.min << ':'
       << ((t.sec>9)? '\0' : '0') << t.sec << '\n';   
    
    return os;
}


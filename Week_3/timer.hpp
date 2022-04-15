#define timer_hpp

#include <iostream>
class Timer {
public:
    Timer();
    Timer(unsigned int _hr);
    Timer(unsigned int _hr, unsigned int _min);
    Timer(unsigned int _hr, unsigned int _min, unsigned int _sec);

private:
    unsigned int hr;
    unsigned int min;
    unsigned int sec;

    //void simplify();

    friend std::ostream& operator<<(std::ostream&, const Timer&);
};

//std::istream& operator>>(std::istream&, Timer&);

#endif /* timer_hpp */

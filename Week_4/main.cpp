#include <iostream>
#include "timer.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    Timer a(8,500,150);
    Timer b(2,67);
    std::cout << "Part 1 "<< std::endl;
    std::cout << "a is: "<< a << std::endl;
    std::cout << "b is: "<< b << std::endl;
    Timer& t1 = (a += b);
    std::cout << t1 << std:: endl;
    Timer& t2 = (a -= b);
    std::cout << t2 << std:: endl;
    Timer& t3 = ++a;
    std::cout << t3 << std:: endl;
    
    std::cout << t1 << ' ' << t2 << ' ' << t3 << std::endl;

    Timer& t4 = --a;
    std::cout << t1 << ' ' << t2 << ' ' << t3 << ' ' << t4 << std::endl;
    
    std::cout << "Part 2 "<< std::endl;
    Timer v1 = a++; std::cout << v1 << ' ' << a << std::endl;
    Timer v2 = a--; std::cout << v2 << ' ' << a << std::endl;

    Timer c(1, 3);
    Timer d(1, 2);
    std::cout << "Part 3 "<< std::endl;
    std::cout << static_cast<size_t>(c) << ' ' << static_cast<size_t>(d) << std::endl;
    std::cout <<  c + d << ' ' << c - d  << std::endl;
    
    std::cout << "Part 4 "<< std::endl;
    std::cout << std::boolalpha;
    std::cout << (c == c) << ' ' << (c == d) << std::endl;
    std::cout << (c != c) << ' ' << (c != d) << std::endl;
    std::cout << (c <  c) << ' ' << (c <  d) << std::endl;
    std::cout << (c >  c) << ' ' << (c >  d) << std::endl;
    std::cout << (c <= c) << ' ' << (c <= d) << std::endl;
    std::cout << (c >= c) << ' ' << (c >= d) << std::endl;
    
    std::cout << "Part 5 "<< std::endl;
    Timer r;
    std::cout << "Type a Timer in the form hr:min:sec, and I'll say it back at you: ";
    std::cin  >> r;
    std::cout << "This is your Timer: " << r << std::endl;

    return 0;
}

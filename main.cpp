

#include <iostream>
#include <sstream>
#include <thread>
#include <unistd.h>

using namespace std;

void function( int a,  int b, int &result) {
    result = a + b;
    usleep(result);
    cout << "timer:" << (a + b)  << "is finished" << endl;
}

int main() {
    int result = 0;
    
    std::thread t1 (function, 0, 100, std::ref(result));
    std::thread t2 (function, 0, 1000, std::ref(result));
    std::thread t3 (function, 0, 10000, std::ref(result));
    std::thread t4 (function, 0, 100000, std::ref(result));
    t4.join();
    t3.join();
    t2.join();
    t1.join();  
    
}
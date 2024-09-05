#include <iostream>
#include <thread>
#include <chrono>

#include "Promise.h"

struct context {
    bool canRun = true;
};

void delay(int amt) {
    std::this_thread::sleep_for(std::chrono::milliseconds(amt));
}

void threadFoo(EmilyPromise::Promise<int>& p) {
    std::cout << "Thread waiting" << std::endl;
    delay(2000);

    std::cout << "Thread is setting the value" << std::endl;
    p.set(96);
}

int main() {

    EmilyPromise::Promise<int> p;

    std::cout << "Creating the thread" << std::endl;
    std::thread t(threadFoo, std::ref(p));

    std::cout << "Waiting for the future" << std::endl;
    int val = p.wait();

    std::cout << "The future is " << val << "!!" << std::endl;
    
    t.join();
    std::cout << "Done!" << std::endl;
    return 0;
}

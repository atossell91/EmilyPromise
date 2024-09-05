#pragma once

#include <mutex>
#include <condition_variable>

namespace EmilyPromise {
    template<typename T>
    class Promise {
    private:
        //  Private stuff here
        std::mutex mutex;
        std::condition_variable cv;

        T data;
        bool isSet = false;
    public:
        //  Public stuff here
        void set(T value) {
            {
                std::lock_guard<std::mutex> lg(mutex);
                data = value;
                isSet = true;
            }
            cv.notify_one();
        }

        void reset() {
            std::lock_guard<std::mutex> guard;
            isSet = false;
        }
        
        T wait() {
            std::unique_lock<std::mutex> lock(mutex);
            cv.wait(lock, []{ return isSet; });
            return std::move(data);
        }
    };
} // EmilyPromise

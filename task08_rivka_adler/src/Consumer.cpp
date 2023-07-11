#include "Consumer.h"

// init static : 
Lockers Consumer::_lockers;

// functions :
Consumer::Consumer(queue<Message>& global_queue, int millisecondsToWait) :
	_global_queue(global_queue), _millisecondsToWait(millisecondsToWait){}

void Consumer::operator() () {
    try
    {
        while (true)
        {
            unique_lock<mutex> lck(_lockers._mtx_global_queue);
            _lockers._cond_global_queue.wait(lck, []() {return !messages.empty(); });
            Message message = _global_queue.front();
            _global_queue.pop();
            if (message._isLast)
            {
                lock_guard<mutex> lck_cout(_lockers._mtx_cout);
                std::cout << message._id << " finished" << std::endl;
                terminationCount++;
            }
            else
            {
                lock_guard<mutex> lck_cout(_lockers._mtx_cout);
                std::cout << message._id << " :sent " << message._value << std::endl;
            }
            if (terminationCount == 2)
            {
                std::cout << "Consumer finished" << std::endl;
                return;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(_millisecondsToWait));
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Exception in consumer: " << e.what() << std::endl;
    }
}
#include "Producer.h" 

// init static : 
Lockers Producer::_lockers;

// functions :
Producer::Producer(queue<Message>& global_queue, int millisecondsToWait) :
	_global_queue(global_queue), _millisecondsToWait(millisecondsToWait) {}

void Producer::operator() () {
    try
    {
        double id = static_cast<double>(std::hash<std::thread::id>{}(std::this_thread::get_id()));
        double value = id;
        Message message{};
        while (!message._isLast)
        {
            {
                message._id = id;
                message._value = value;
                message._isLast = value ==0.0? true: false;
                lock_guard<mutex> lck_names(_lockers._mtx_global_queue);
                _global_queue.push(message);
                _lockers._cond_global_queue.notify_all();
                value /= 10.0;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(_millisecondsToWait));
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Exception in producer: " << e.what() << std::endl;
    }
}


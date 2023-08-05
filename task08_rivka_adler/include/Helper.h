#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <atomic>
#include "Message.h"

using namespace std;
using std::lock_guard;
using std::unique_lock;

extern queue<Message> messages; // Shared queue to store messages;
extern std::atomic<int> terminationCount;              // Atomic counter for termination count

class Lockers {
public:
	static mutex _mtx_global_queue;      //Mutex for signaling messages input\output
	static condition_variable _cond_global_queue; // Condition variable for signaling messages availability
};

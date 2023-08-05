#include "Helper.h"
queue<Message> messages;
std::atomic<int> terminationCount(0);

mutex Lockers::_mtx_global_queue;
condition_variable Lockers::_cond_global_queue;

#pragma once
#include "Helper.h"
/**
 * @class Consumer
 * @brief A class representing a consumer that processes messages from a global queue.
 *
 * The Consumer class processes messages from a global queue by waiting for a specified amount of time and then retrieving and processing the messages from the queue. It operates as a separate thread and continuously runs until the program terminates or explicitly stopped.
 */
class Consumer {

    // static, internal globals :
    static Lockers _lockers;

    // globals (by reference) :
    queue<Message>& _global_queue;

    // parameters :
    int _millisecondsToWait;

public:
    /**
 * @brief Constructs a Consumer object with the specified parameters.
 * @param global_queue A reference to the global queue from which the consumer retrieves messages.
 * @param millisecondsToWait The time in milliseconds to wait between retrieving messages from the queue.
 */
    Consumer(queue<Message>& global_queue, int millisecondsToWait);
    /**
 * @brief Overloaded function call operator.
 *
 * This operator is called when the Consumer object is invoked as a functor. It starts the processing of messages from the global queue.
 */
    void operator() ();
};



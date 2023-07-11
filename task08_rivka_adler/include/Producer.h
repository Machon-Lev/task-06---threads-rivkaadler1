#pragma once
#include "Helper.h"

/**
 * @class Producer
 * @brief A class representing a producer that adds messages to a global queue.
 *
 * The Producer class is responsible for producing messages and adding them to a global queue. It operates as a separate thread and continuously runs until the program terminates or explicitly stopped. Each producer adds messages to the shared global queue at a specified interval.
 */
class Producer {
	// static, internal globals :
	static Lockers _lockers;

	// globals (by reference) :
	queue<Message>& _global_queue;

	// parameters :
	int _millisecondsToWait;

public:
	/**
   * @brief Constructs a Producer object with the specified parameters.
   * @param global_queue A reference to the global queue where messages will be added.
   * @param millisecondsToWait The time in milliseconds to wait between adding messages to the queue.
   */
	Producer(queue<Message>& global_queue, int millisecondsToWait);

	/**
    * @brief Overloaded function call operator.
   *
   * This operator is called when the Producer object is invoked as a functor. It starts the production and addition of messages to the global queue.
   */
	void operator() ();
};

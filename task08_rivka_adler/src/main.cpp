#include "Helper.h"
#include "Producer.h"
#include "Consumer.h"


int main()
{

	try {
		Consumer consumer1(messages,50);
		Producer producer1(messages, 50);
		Producer producer2(messages, 50);
		// Create the consumer thread
		thread consumerThread(ref(consumer1));

		// Create the producer threads
		thread producerThread1(ref(producer1));
		thread producerThread2(ref(producer2));

		// Wait for the consumer and producer threads to finish
		consumerThread.join();
		producerThread1.join();
		producerThread2.join();
	}
	catch (const std::exception& e) {
		std::cerr << "Exception in main: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
#include <iostream>           
#include <thread>             
#include <mutex>              
#include <condition_variable> 

std::mutex mtx;
std::condition_variable condition;

int item = 0;

// creating the producer
void producer(int orderNumber) {
	
	std::unique_lock<std::mutex> lck(mtx);
	item++;
	condition.notify_one();
	std::cout << "producer" << std::endl;
}


// Creating the consumer
void consumer(int orderNumber) {
	std::unique_lock<std::mutex> lck(mtx);
	while (item == 0) 
	{ 
		condition.wait(lck);
	}
	std::cout << "iteration: ";
	std::cout << orderNumber + 1 << std::endl;
	std::cout << "Threads running concurrently: "  << item - 1 << std::endl;
	item--;
	std::cout << "consumer" << std::endl;

}


int main() {

	std::thread t1[900];
	std::thread t2[900];

	// Initialise the producer and consumer
	for (int order = 0; order < 900; order++) {
		t1[order] = std::thread(producer, order);
		t2[order] = std::thread(consumer, order);
	}

	//add to the threads
	for (int order = 0; order < 900; order++) {
		t1[order].join();
		t2[order].join();
	}

	system("Pause");
}
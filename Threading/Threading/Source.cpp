#include <iostream>
#include <vector>
#include <thread>

/// <summary>
/// Petersons
/// </summary>

int n = 25; // Amount
int in[] = { 0 }; //condition
int last[] = { 0 }; // last thread to be ran

void processOut(int i) 
{
	while (true)
	{

		//run throuh the number of threads
		for (int j = 0; j < n; j++)
		{
			in[i] = j; //condition i = current thread

			last[j] = i; //last = current

			//run through amount of threads
			for (int k = 0; k < n; k++)
			{
				if (i != k)
				{
					while (in[k] >= in[i] && last[j] == i);
				}
			}
		}
		//output of thread number
		std::cout << "P:" << i << "\n" << std::endl;
		in[i] = -1;
	}
}

int main() 
{
	std::vector<std::thread> threads;
	//threads being added to vector
	for (int i = 0; i < n; i++)
	{
		threads.push_back(std::thread(processOut, i));
	}

	//execution
	for (auto & thread : threads)
	{
		thread.join();
	}
	return 1;
}


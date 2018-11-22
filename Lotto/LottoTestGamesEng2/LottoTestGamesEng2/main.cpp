#include <vector>
#include <iostream>
#include <assert.h>

bool testNumbers(std::vector<int> & nums)
{
	if(nums.size() != 6)
	{
		return false;
	}
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums.at(i) >= 1 && nums.at(i) <= 46)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (nums.at(i) == nums.at(j))
				{
					return false;
				}
			}
		}
		else
		{
			return false;
		}		
	}
	return true;
}

int main()
{
	std::vector<int> nums;
	std::cout << "LOTTO CHECK" << std::endl;
	
	for (int i = 0; i < 6; i++)
	{
		std::cout << "Please Enter a digit" << std::endl;
		int number = 0;
		std::cin >> number;
		if (!std::cin)
		{
			std::cout << "bad value, not a number" << std::endl;
			i--;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			nums.push_back(number);
		}
	}


	if (testNumbers(nums))
	{
		std::cout << "valid" << std::endl;
		
	}
	else
	{
		std::cout << "eRROIC" << std::endl;
	}
	system("PAUSE");
	return 0;
}
#include<iostream>
#include<stdlib.h>
#include<time.h>

template<typename T>
void initArray(T array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		array[i] = (10 + rand() % 10) / 1.5;
	}
}

template<typename T>
void printArray(T array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl << std::endl;
}

template<typename T>
void sortArray(T array[], int length, int tmp = 1)
{
	if (tmp == 0)
	{
		for (int i = 0; i < length; i++)
		{
			for (int j = i; j > 0 && array[j - 1] > array[j]; j--)
			{
				T variable = array[j - 1];
				array[j - 1] = array[j];
				array[j] = variable;
			}
		}
	}
	else if (tmp == 1)
	{
		for (int i = 0; i < length; i++)
		{
			for (int j = i; j > 0 && array[j - 1] < array[j]; j--)
			{
				T variable = array[j - 1];
				array[j - 1] = array[j];
				array[j] = variable;
			}
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	const int LENGTH = 10;
	int array[LENGTH];

	initArray(array, LENGTH);
	printArray(array, LENGTH);

	sortArray(array, LENGTH);
	printArray(array, LENGTH);

	const int KEY = 0;
	sortArray(array, LENGTH, KEY);
	printArray(array, LENGTH);

	return 0;
}
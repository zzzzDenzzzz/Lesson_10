#include<iostream>
#include<stdlib.h>
#include<time.h>

void initArray(int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		array[i] = -20 + rand() % 40;
	}
}

void printArray(int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl << std::endl;
}

void sortArray(int array[], int first_element, int last_element)
{
	for (int i = first_element + 1; i < last_element; i++)
	{
		for (int j = i; j > (first_element + 1) && array[j - 1] > array[j]; j--)
		{
			int variable = array[j - 1];
			array[j - 1] = array[j];
			array[j] = variable;
		}
	}
}

int firstElement(int array[], int length)
{
	int first_element;

	for (int i = 0; i < length; i++)
	{
		if (array[i] < 0)
		{
			first_element = i;
			break;
		}
	}
	return first_element;
}

int lastElement(int array[], int length)
{
	int last_element;

	for (int i = length - 1; i >= 0; i--)
	{
		if (array[i] < 0)
		{
			last_element = i;
			break;
		}
	}
	return last_element;
}

int main()
{
	srand((unsigned int)time(NULL));
	const int LENGTH = 20;
	int array[LENGTH];

	initArray(array, LENGTH);
	printArray(array, LENGTH);

	int first_element = firstElement(array, LENGTH);
	int last_element = lastElement(array, LENGTH);

	sortArray(array, first_element, last_element);
	printArray(array, LENGTH);

	return 0;
}
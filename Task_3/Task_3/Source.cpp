#include<iostream>
#include<stdlib.h>
#include<time.h>

void printArray(int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl << std::endl;
}

void mixElementsArray(int array[], int length)
{
	int variable;
	for (int i = 0; i < length / 2; i++)
	{
		int index_1 = rand() % 10;
		int index_2 = 10 + rand() % 10;
		variable = array[index_1];
		array[index_1] = array[index_2];
		array[index_2] = variable;
	}
}

int randNumber()
{
	return (1 + rand() % 20);
}

int findPosition(int array[], int length, int number)
{
	int index_position;

	for (int i = 0; i < length; i++)
	{
		if (array[i] == number)
		{
			index_position = i;
			break;
		}
	}
	return index_position;
}

void sortArray(int array[], int length, int index_position)
{
	int i = 0;
	if (index_position != 0)
	{
		for (; i < index_position; i++)
		{
			for (int j = i; j > 0 && array[j - 1] < array[j]; j--)
			{
				int variable = array[j - 1];
				array[j - 1] = array[j];
				array[j] = variable;
			}
		}
	}

	i = index_position + 1;
	for (; i < length; i++)
	{
		for (int j = i; j > (index_position + 1) && array[j - 1] > array[j]; j--)
		{
			int variable = array[j - 1];
			array[j - 1] = array[j];
			array[j] = variable;
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	const int LENGTH = 20;
	int array[LENGTH]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

	mixElementsArray(array, LENGTH);
	printArray(array, LENGTH);

	int rand_number = randNumber();
	std::cout << "random number = " << rand_number << std::endl << std::endl;

	int index_position = findPosition(array, LENGTH, rand_number);
	std::cout << "index random number = " << index_position << std::endl << std::endl;

	sortArray(array, LENGTH, index_position);
	printArray(array, LENGTH);

	return 0;
}
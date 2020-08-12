/*CS 340 Assignment #3 - Part 2 - Question 1

Prajna Chakma  (Kevin)
200361931

Code References from: Mark Allen Weiss "DATA STRUCTUERS AND ALGORITHIM ANALYSIS IN C++ (FOURTH EDITION)" 

*/
#include <iostream>
#include <stdlib.h>

using namespace std;


// Partitioning the merge sort values from fron to last to middle.
void PartitionForMergeSort(int ARRAY[], int size, int x, int y)
{
	//Declaring the Int variables to for the first last and middle
	int a, b, c;

	//ALLOCATING THE ARRAY (Allocating memory to the heap)
	int XSize = x - size + 1;
	int YSize = y - x;

	//Creating a Dynamic array for both halves.
	int* leftHeap = new int [XSize];
	int* rightHeap = new int [YSize];
	

	for (a = 0; a < XSize; a++)
		leftHeap[a] = ARRAY[size + a];
	for (b = 0; b < YSize; b++)
		rightHeap[b] = ARRAY[x + 1 + b];


	// This will create values for the front and last, which c will follow the size integer
	a, b = 0;
	c = size;



	// The while loop is finding the front and last of the heap values
	while (a < XSize && b < YSize)
	{
		if (leftHeap[a] <= rightHeap[b])
		{
			ARRAY[c] = leftHeap[a];
			a++;
		}
		else 
		{
			ARRAY[c] = rightHeap[b];
			b++;
		}
		c++;
	}

	//If the value of front is less than the size climb up the array.
	while (a < XSize)
	{
		ARRAY[c] = leftHeap[a];
		a,c++;
	}

	//If the value of last is less than the size climb up the array.
	while (b < YSize)
	{
		ARRAY[c] = rightHeap[b];
		b,c++;	
	}


	//BC's a created a dynamic array, a have to delete the allocated memory.
	delete[] leftHeap, rightHeap;
}



//This void function is to create the math for when the Mergesort is called.
void AlgoMergeSort(int ARRAY[], int x, int y)
{
	if (x < y) {

		int value = x + (y - x) / 2;

		AlgoMergeSort(ARRAY, x, value);
		AlgoMergeSort(ARRAY, value + 1, y);

		PartitionForMergeSort(ARRAY, x, value, y);
	}
}


int main()
{

	//Creating a integer variable for the size of the array.
	int SizeOfArray;
	cout << "Please enter how large you would like the Array to be: ";
	cin >> SizeOfArray;


	//Creating dynamic array.
	int* ARRAY = new int[SizeOfArray];
	cout << "Please enter your values in the array: ";



	for (int i = 0; i<SizeOfArray; i++)
	{
		cin >> ARRAY[i];
	}
	AlgoMergeSort(ARRAY, 0, SizeOfArray - 1);

	// displays the mergesort values with spaces and formatting.
	cout << "\nHere is your Mergesort Array!: ";
	for (int i = 0; i < SizeOfArray; i++)
		cout << ARRAY[i] << " ";
	printf("\n");


	//Closing after dynamic array was created.
	delete[] ARRAY;
}
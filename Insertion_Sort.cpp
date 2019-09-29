/*
	TO DO: 
		Gather data for different array sizes and put those in a table 

*/
#include <iostream> 
#include <ctime>
using namespace std;


void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

// A utility function to print an array of size n  
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void copyArr(int arr[], int temp[] ,int size) {
	for (int x = 0; x < size; x++) {
		temp[x] = arr[x];
	}

}


int main()
{
	srand(time(NULL));
	static int size = 16;
	int arr[16];
	

	// Generate random numbers in the array 
	for (int x = 0; x < size; x++) {
		arr[x] = rand() % 100 + 1;
	}

	// Temp array to be sorted
	int temp[16];

	// Print unsorted array 
	printArray(arr, size);

	clock_t begin = clock();		// begin clock time

	// Loop to copy array into temp then call insertion sort
	for (int y = 0; y < 600000; y++) {
		copyArr(arr, temp, size);
		insertionSort(temp, size);
	}
	clock_t end = clock();			// end clock time 
	double time = double(end - begin) / CLOCKS_PER_SEC;

	cout << "Time: " << time << endl << endl;
	printArray(temp, size);

	return 0;
}

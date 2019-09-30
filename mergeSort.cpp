
#include <iostream>
#include <ctime>
using namespace std;

void merge2(int sortMe[], int &low, int &mid, int &high);

void mergeSort(int sortMe[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = low + (high - 1) / 2;

		// Sort first two halves 
		mergeSort(sortMe, low, mid);
		mergeSort(sortMe, mid + 1, high);
		merge2(sortMe, low, mid, high);
	}
}

// Pass in vector to be merged with 
void merge2(int sortMe[], int &low, int &mid, int &high) {
	int j = mid + 1;

	// If already sorted, then exit out
	if (sortMe[mid] <= sortMe[j]) {
		return;
	}

	while (low <= mid && j <= high) {
		// if first element is already sorted
		if (sortMe[low] <= sortMe[j])
			low++;

		else {
			int value = sortMe[j];
			int index = j;

			while (index != low) {
				sortMe[index] = sortMe[index - 1];
				index--;
			}
			sortMe[low] = value;

			low++;
			mid++;
			j++;
		}
	}
}


// Prints array on one line  
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Copy arr into temp array
void copyArr(int arr[], int temp[], int size) {
	for (int x = 0; x < size; x++) {
		temp[x] = arr[x];
	}

}

int main()
{
	srand(time(NULL));

	const int size = 8;
	int arr[size];

	// Temp array to be sorted
	int temp[size];

	// Generate random numbers in the array 
	for (int x = 0; x < size; x++) {
		arr[x] = rand() % 100 + 1;
	}


	// Print unsorted array 
	cout << "Unsorted array: ";
	printArray(arr, size);
	cout << endl;

	clock_t begin = clock();		// begin clock time

	// Loop to copy array into temp then call insertion sort
	for (int y = 0; y < 3; y++) {
		copyArr(arr, temp, size);
		mergeSort(temp, 0, size - 1);
	}
	clock_t end = clock();			// end clock time 
	double time = double(end - begin) / CLOCKS_PER_SEC;

	cout << "Time: " << time << endl;

	cout << "Sorted array: ";
	printArray(temp, size);

	return 0;
}



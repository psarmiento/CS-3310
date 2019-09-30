
#include <iostream>
#include <ctime>
using namespace std;

void merge(int arr[], int low, int mid, int end)
{
	int j = mid + 1;

	// If the direct merge is already sorted 
	if (arr[mid] <= arr[j]) {
		return;
	}

	// Two pointers to maintain start 
	// of both arrays to merge 
	while (low <= mid && j <= end) {

		// If element 1 is in right place 
		if (arr[low] <= arr[j]) {
			low++;
		}
		else {
			int value = arr[j];
			int index = j;

			// Shift all the elements between element 1 
			// element 2, right by 1. 
			while (index != low) {
				arr[index] = arr[index - 1];
				index--;
			}
			arr[low] = value;

			// Update all the pointers 
			low++;
			mid++;
			j++;
		}
	}
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int low, int high)
{
	if (low < high) {

		// Same as (l + r) / 2, but avoids overflow 
		// for large l and r 
		int mid = low + (high - low) / 2;

		// Sort first and second halves 
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);

		merge(arr, low, mid, high);
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

	const int size = 65536;
	int arr[size];

	// Temp array to be sorted
	int temp[size];

	// Generate random numbers in the array 
	for (int x = 0; x < size; x++) {
		arr[x] = rand() % 100 + 1;
	}


	// Print unsorted array 
	//cout << "Unsorted array: ";
	//printArray(arr, size);
	//cout << endl;

	clock_t begin = clock();		// begin clock time

	// Loop to copy array into temp then call insertion sort
	for (int y = 0; y < 10; y++) {
		copyArr(arr, temp, size);
		mergeSort(temp, 0, size - 1);
	}
	clock_t end = clock();			// end clock time 
	double time = double(end - begin) / CLOCKS_PER_SEC;

	cout << "Time: " << time << endl;

	//cout << "Sorted array: ";
	//printArray(temp, size);

	return 0;
}



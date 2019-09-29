

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


int main()
{

	srand(time(NULL));
	int num = rand() % 100 + 1;		// generates a number between 1 - 100
	clock_t begin = clock();		// begin clock time
	int sum = 0;
	for (int x = 0; x < 10; x++) {
		cout << num << endl;
		num = rand() %100 + 1;		// re generate random num
	}

	clock_t end = clock();			// end clock time 
	double time = double(end - begin) / CLOCKS_PER_SEC;

	cout << "Time: " << time << endl;

	int arr[] = { 12, 11, 13, 5, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, n);
	printArray(arr, n);

	return 0;
}

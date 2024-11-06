#include <bits/stdc++.h>

using namespace std;

// Step counters for deterministic and randomized QuickSort
int deterministicSteps = 0;
int randomizedSteps = 0;

// Deterministic Partition (always takes the first element as pivot)
int deterministicPartition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
            deterministicSteps++; // Count comparison steps
        }

        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
            deterministicSteps++; // Count comparison steps
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
            deterministicSteps++; // Count swap steps
        }
    }
    swap(arr[low], arr[j]);
    deterministicSteps++; // Count swap steps
    return j;
}

// Randomized Partition (chooses a random pivot)
int randomizedPartition(vector<int> &arr, int low, int high)
{
    int randomPivot = low + rand() % (high - low + 1);
    swap(arr[randomPivot], arr[high]); // Move random pivot to end
    randomizedSteps++;                 // Count swap for random pivot
    return deterministicPartition(arr, low, high);
}

// Deterministic Quick Sort
void deterministicQuickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = deterministicPartition(arr, low, high);
        deterministicQuickSort(arr, low, pi - 1);
        deterministicQuickSort(arr, pi + 1, high);
    }
}

// Randomized Quick Sort
void randomizedQuickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = randomizedPartition(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

int main()
{
    srand(time(0)); // Seed for random number generator

    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = arr1; // Copy for randomized sort

    cout << "Original Array: ";
    for (int i : arr1)
        cout << i << " ";
    cout << endl;

    // Deterministic Quick Sort
    deterministicQuickSort(arr1, 0, arr1.size() - 1);
    cout << "Sorted Array (Deterministic QuickSort): ";
    for (int i : arr1)
        cout << i << " ";
    cout << endl;
    cout << "Steps in Deterministic QuickSort: " << deterministicSteps << endl;

    // Randomized Quick Sort
    randomizedQuickSort(arr2, 0, arr2.size() - 1);
    cout << "Sorted Array (Randomized QuickSort): ";
    for (int i : arr2)
        cout << i << " ";
    cout << endl;
    cout << "Steps in Randomized QuickSort: " << randomizedSteps << endl;

    return 0;
}

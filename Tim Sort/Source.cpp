//-- Problem description --//
// 
// Given:      array of N numbers
// Required:   sort the array
// Case:       { 31, 41, 59, 26, 53, 58, 97, 93, 23, 84 }
// Soloution:  { 23, 26, 31, 41, 53, 58, 59, 84, 93, 97 }

#include <iostream>
#include <vector>
using namespace std;

const int RUN = 32;

int getMin(int A, int B)
{
    if (A < B)
        return A;

    return B;
}

void insertionSort(int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++) 
    {
        int pos = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > pos)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = pos;
    }
}

void merge(int arr[], int left, int mid, int right) 
{
    int lSize = mid - left + 1;
    int rSize = right - mid;

    int* leftArr;
    int* rightArr;
    leftArr = new int[lSize];
    rightArr = new int[rSize];

    for (int i = 0; i < lSize; i++)
        leftArr[i] = arr[left + i];

    for (int i = 0; i < rSize; i++)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < lSize && j < rSize)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else 
        {
            arr[k] = rightArr[j];
            j++;
        }

        k++;
    }

    while (i < lSize)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < rSize)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void timSort(int arr[], int size) 
{
    for (int i = 0; i < size; i += RUN)
        insertionSort(arr, i, getMin((i + RUN - 1), (size - 1)));

    for (int sizeMerged = RUN; sizeMerged < size; sizeMerged *= 2)
        for (int left = 0; left < size; left += 2 * sizeMerged) 
        {
            int mid = left + sizeMerged - 1;
            int right = getMin((left + 2 * sizeMerged - 1), (size - 1));
            merge(arr, left, mid, right);
        }
}

int main()
{
    int arr[] = { 31, 41, 59, 26, 53, 58, 97, 93, 23, 84 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Elements before sort: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << ", ";
    cout << endl;

    timSort(arr, size);

    cout << "Elements after sort : ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << ", ";
    cout << endl;

    return 0;
}
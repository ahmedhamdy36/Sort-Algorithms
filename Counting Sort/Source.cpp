//-- Problem description --//
// 
// Given:      array of N numbers
// Required:   sort the array
// Case:       { 31, 41, 59, 26, 53, 58, 97, 93, 23, 84 }
// Soloution:  { 23, 26, 31, 41, 53, 58, 59, 84, 93, 97 }

#include <iostream>
using namespace std;

int getMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; ++i)
        if (arr[i] > max)
            max = arr[i];

    return max;
}

void countingSort(int arr[], int size) 
{
    int max = getMax(arr, size);

    int* count;
    count = new int[max + 1];
    for (int i = 0; i < max + 1; i++)
        count[i] = 0;

    for (int i = 0; i < size; i++)
        count[arr[i]]++;

    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    int* output;
    output = new int[size];
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}

int main() 
{
    int arr[] = { 31, 41, 59, 26, 53, 58, 97, 93, 23, 84 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Elements before sort: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << ", ";
    cout << endl;

    countingSort(arr, size);

    cout << "Elements after sort : ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << ", ";
    cout << endl;

    return 0;
}
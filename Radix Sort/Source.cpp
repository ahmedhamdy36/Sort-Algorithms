#include <iostream>
using namespace std;

int getMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
}

void countingSort(int arr[], int size, int exp)
{
    const int radix = 10;
    int* output;
    output = new int[size];
    int count[radix] = { 0 };

    for (int i = 0; i < size; i++) 
    {
        int digit = (arr[i] / exp) % radix;
        count[digit]++;
    }

    for (int i = 1; i < radix; ++i)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--) 
    {
        int digit = (arr[i] / exp) % radix;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int size) 
{
    int max = getMax(arr, size);

    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, size, exp);
}

int main() 
{
    int arr[] = { 31, 41, 59, 26, 53, 58, 97, 93, 23, 84 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Elements before sort: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << ", ";
    cout << endl;

    radixSort(arr, size);

    cout << "Elements after sort : ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << ", ";
    cout << endl;

    return 0;
}
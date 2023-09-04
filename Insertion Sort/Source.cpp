//-- Problem description --//
// 
// Given:      array of N numbers
// Required:   sort the array
// Case:       { 31, 41, 59, 26, -53, 58, 97, -93, -23, 84 }
// Soloution:  { -93, -53, -23, 26, 31, 41, 58, 59, 84, 97 }


#include<iostream>
using namespace std;

void insertionSort(int arr[], int size) 
{
    for (int i = 1; i < size; i++) 
    {
        int pos = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > pos) 
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = pos;
    }
}

int main()
{
    int arr[] = { 31, 41, 59, 26, -53, 58, 97, -93, -23, 84 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Elements before sort: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << ", ";
    cout << endl;

    insertionSort(arr, size);

    cout << "Elements after sort : ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << ", ";
    cout << endl;
}
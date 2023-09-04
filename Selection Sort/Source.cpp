//-- Problem description --//
// 
// Given:      array of N numbers
// Required:   sort the array
// Case:       { 31, 41, 59, 26, -53, 58, 97, -93, -23, 84 }
// Soloution:  { -93, -53, -23, 26, 31, 41, 58, 59, 84, 97 }


#include<iostream>
using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int size) 
{
    int min;

    for (int i = 0; i < size; i++) 
    {
        min = i;
        for (int j = i + 1; j < size; j++) 
            if (arr[j] < arr[min])
                min = j;
        
        if (min != i)
            swap(&arr[min], &arr[i]);
    }
}

int main()
{
    int arr[] = { 31, 41, 59, 26, -53, 58, 97, -93, -23, 84 };
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Elements before sort: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] <<", ";
    cout << endl;

    selectionSort(arr, size);

    cout << "Elements after sort : ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << ", ";
    cout << endl;
}
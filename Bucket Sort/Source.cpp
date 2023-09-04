//-- Problem description --//
// 
// Given:      array of N numbers
// Required:   sort the array
// Case:       { 0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68 }
// Soloution:  { 0.12, 0.17, 0.21, 0.23, 0.26, 0.39, 0.68, 0.72, 0.78, 0.94 }


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(double arr[], int size) 
{
    vector<double>* buckets;
    buckets = new vector<double>[size];

    for (int i = 0; i < size; i++) 
    {
        int bucketIndex = size * arr[i];
        buckets[bucketIndex].push_back(arr[i]);
    }

    for (int i = 0; i < size; i++)
        sort(buckets[i].begin(), buckets[i].end());

    int index = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < buckets[i].size(); j++)
            arr[index++] = buckets[i][j];
}

int main() 
{
    double arr[] = { 0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Elements before sort: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << ", ";
    cout << endl;

    bucketSort(arr, size);

    cout << "Elements after sort : ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << ", ";
    cout << endl;

    return 0;
}
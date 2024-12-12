/*
    # Binary Search
    - Binary search is a fast search algorithm with run-time complexity of Ο(log n).
    - This search algorithm works on the principle of divide and conquer.

    # Algorithm
    Input : A sorted array arr[] of n elements and a value x.

    first = 0, last = n-1
    Step 1: Middle = (first + last)/2
    Step 2: If arr[middle] == x, return middle.
    Step 3: If arr[middle] < x, then set first = middle + 1 & repeat step 1.
    Step 4: Else If arr[middle] > x, then set last = middle - 1 & repeat step 1.

*/

#include <iostream>
using namespace std;
#define size 10

int binarySearch(int arr[], int value)
{
    int first = 0;
    int last = size - 1;
    while (first <= last)
    {
        int mid = (first + last) / 2;
        if (arr[mid] == value)
            return mid;
        else if (arr[mid] > value)
            last = mid - 1;
        else
            first = mid + 1;
    }
    return -1;
}

int main()
{   
    int arr[size]= {11, 22, 33, 44, 55, 66, 77, 88, 99, 100};
    int value;
    cout << "Enter the value to search: ";
    cin >> value;
    
    if (binarySearch(arr, value) == -1)
        cout << "The value is not present in the array." << endl;
    else
        cout << "The value is at index: " << binarySearch(arr, value) << endl;
    return 0;
}

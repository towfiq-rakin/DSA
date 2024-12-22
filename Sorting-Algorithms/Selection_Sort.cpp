/*  
    # Selection Sort
    Time Complexity: O(n²)
    Space Complexity: O(1)
    
    Algorithm:
    1. Find the minimum element in the array.
    2. Swap the minimum element with the first element.
    3. Repeat the above steps for the remaining elements.
*/

#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

// Function for selection sort
void selectionSort(vector<int> &arr){
    int n = arr.size();
    for(int i = 0; i < n-1; i++){
        int minIndex = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j; // Update the index of minimum element
            }
        }
        swap(arr[minIndex], arr[i]);
    }
    return;
}

int main(){
    cout << "Enter the number of elements: ";
    int n; cin >> n;
    vector<int> arr(n); // Input array of size n
    cout << "Enter the elements: ";
    for(int &i: arr){
        cin >> i;
    }
    selectionSort(arr);
    cout << "Sorted array: ";
    for(int i: arr){
        cout << i << " ";
    }
    return 0;
}

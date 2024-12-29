/*  
    # Bubble Sort
    Time Complexity: O(n²)
    Space Complexity: O(1)
    
    Algorithm:
    1. Compare each pair of adjacent elements from the beginning of an array and, 
        if they are in the wrong order, swap them.
    2. If we go through the array n times, then the largest element will be at the end of the array.
    3. So, we can reduce the number of comparisons in the next iteration.
    4. Repeat this process n-1 times to sort the array.
*/

#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

// Bubble Sort
void bubbleSort(vector<int> &arr){
    int n = arr.size();
    bool swapped;
    for(int i = 0; i < n-1; i++){
        swapped = false;
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]); 
                // Swap the elements if they are in wrong order
                swapped = true;
            }
        }
        if(swapped == false) {
            break; // If no swapping is done in the inner loop, then the array is already sorted
        } // It Reduces the time complexity from O(n²) to O(n) in best case
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
    bubbleSort(arr); // Calling the sort function
    cout << "Sorted array: ";
    for(int i: arr){
        cout << i << " ";
    }
    return 0;
}

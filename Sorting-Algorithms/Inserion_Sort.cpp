/*  
    # Insertion Sort
    Time Complexity: O(n²)
    Space Complexity: O(1)
    
    Algorithm:
    1. Iterate from arr[1] to arr[n] over the array.
    2. Compare the current element (key) to its predecessor.
    3. If the key element is smaller than its predecessor, compare it to the elements before.
    Move the greater elements one position up to make space for the swapped element.
    4. Repeat until the key element is greater than its predecessor.
*/

#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

// Insertion Sort
void insertionSort(vector<int> &arr){
    int n = arr.size();
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
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
    insertionSort(arr); // Call the function to sort the array
    cout << "Sorted array: ";
    for(int i: arr){
        cout << i << " ";
    }
    return 0;
}

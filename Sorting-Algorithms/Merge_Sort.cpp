/*  
    # Merge Sort
    Time Complexity: O(nlogn)
    Space Complexity: O(n)
    
    Algorithm:
    1. Divide the array into two halves
    2. Recursively sort the two halves
    3. Merge the sorted halves
*/
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

// Merge Sort
void mergeSort(vector<int> &arr){
    int n = arr.size();
    if(n < 2) return; // Base case
    int mid = n/2;
    vector<int> left(mid), right(n-mid);
    for(int i = 0; i < mid; i++){
        left[i] = arr[i];
    }
    for(int i = mid; i < n; i++){
        right[i-mid] = arr[i];
    }
    mergeSort(left);
    mergeSort(right);
    int i = 0, j = 0, k = 0;
    while(i < left.size() && j < right.size()){
        if(left[i] < right[j]){
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while(i < left.size()){
        arr[k++] = left[i++];
    }
    while(j < right.size()){
        arr[k++] = right[j++];
    }
    return;
}
int main(){
    //cout << "Enter the number of elements: ";
    int n; cin >> n;
    vector<int> arr(n); // Input array of size n
    //cout << "Enter the elements: ";
    for(int &i: arr){
        cin >> i;
    }
     // Call the function to sort the array
    mergeSort(arr);
    cout << "Sorted array: ";
    for(int i: arr){
        cout << i << " ";
    }
    return 0;
}

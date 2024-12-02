/*
    This code shows-
    1. How to access the boundary of a 2D array (4 sides of a Matrix)
        - Boundary means the Only 1st row, last row, 1st column, and last column of the 2D array
    2. How to do different operation on the boundary of a 2D array
*/

#include <iostream>
using namespace std;

int main(){
    int row, col;
    cout<<"Enter the number of rows and columns of the 2D array: ";
    cin>>row>>col;
    int arr[row][col];

    // Input the elements of the 2D array
    cout<<endl<<"Enter the elements of the 2D array : "<<endl;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin>>arr[i][j];
        }
    }

    // Traverse the 2D array and print the Boundary elements
    cout <<endl<< "Boundary elements of the 2D array are: "<<endl;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(i == 0 || i == row-1){ // 1st row and last row
                cout<<arr[i][j]<<" ";
            }
            else if(j == 0 || j == col-1){ // 1st column and last column
                cout<<arr[i][j]<<" ";
            }
            else{
                cout<<"  "; // Print space for inner elements
            }
        }
        cout << endl;
    }

    /*
    Sum of the outer elements of the 2D array.
    Same as above, but instead of printing the Boundary elements,
    we will calculate the sum of the outer/boundary elements.
    You can do any other operation here.
    */
    cout <<endl<< "Sum of the boundary elements of the 2D array: ";
    int sum = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(i == 0 || i == row-1){ // 1st row and last row
                sum += arr[i][j];
            }
            else if(j == 0 || j == col-1){ // 1st column and last column
                sum += arr[i][j];
            }
        }
    }
    cout<<sum<<endl;
}

/*  
    # Input:
    Enter the number of rows and columns of the 2D array: 5 5

    Enter the elements of the 2D array:
    1 2 3 4 5
    2 5 4 9 4
    3 6 5 4 3
    4 8 9 7 2
    5 4 3 2 1
    
    # Output:
    Boundary elements of the 2D array are:
    1 2 3 4 5
    2       4
    3       3
    4       2
    5 4 3 2 1

    Sum of the boundary elements of the 2D array: 48
*/

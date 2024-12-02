#include <iostream>
#include <string>
using namespace std;
/*
    Family Tree:
    Arif
    ├── Sara
    └── Rahim
        └── Karim
            ├── Karim son 1
            └── Karim son 2
*/
struct Person {
    string Name;
    Person* Child;
};

int main() {
    /*
        *A = Arif
        *R = Rahim
        *K = Karim
    */
    Person P, *A, *R, *K;
    P.Name = "Arif";
    A = P.Child = new Person[2]; // Allocate memory for Arif's two children
    
    // 1st children of Arif
    A[0].Name =  "Sara";
    A[0].Child = nullptr; // Sara has no children

    // 2nd children of Arif
    A[1].Name = "Rahim";
    R = A[1].Child = new Person[1]; // Allocate memory for Rahim's children
    
    // Children of Rahim
    R[0].Name = "Karim";
    K = R[0].Child = new Person[2]; // Allocate memory for Karim's two children
    
    // 1st Children of Karim
    K[0].Name = "Karim son 1";
    K[0].Child = nullptr; // Karim son 1 has no children

    // 2nd Children of Karim
    K[1].Name = "Karim son 2";
    K[1].Child = nullptr; // Karim son 2 has no children

    cout << "Father of all: " << P.Name << endl; // Arif
    cout << "Two son of Arif: ";
    cout << A[0].Name << ", "; // Sara
    cout << A[1].Name << endl; // Rahim

    cout << "Son of Rahim: ";
    cout << R[0].Name << endl; // Karim
    cout << "Two son of Karim: ";
    cout << K[0].Name << ", "; // Karim son 1
    cout << K[1].Name << endl; // Karim son 2

    return 0;
}
/*  
    #Output:
    
    Father of all: Arif
    Two son of Arif: Sara, Rahim
    Son of Rahim: Karim
    Two son of Karim: Karim son 1, Karim son 2
*/

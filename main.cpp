#include "main.hpp"

int main(){
    // Create a vector of 10 random values up to 1000
    cout << "TEST 1: Generated vector" << endl;
    vector<int> random(10);
    generateVector(random, 10);
    
    // Print unsorted random vector
    cout << "Unsorted vector: " << endl;
    printVector(random);

    // Sort the vector using radix sort
    radixSort(random);
    cout << "Sorted vector: " << endl;
    printVector(random);

    // --- Providing a vector of 10 values --- //
    cout << "\t" << endl;
    cout << "TEST 2: Provided vector" << endl;
    vector<int> arr = {321, 123, 919, 414, 555};

    // Print unsorted vector
    cout << "Unsorted vector: " << endl;
    printVector(arr);

    // Sort the vector using radix sort
    radixSort(arr);
    cout << "Sorted vector: " << endl;
    printVector(arr);
}
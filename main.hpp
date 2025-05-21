#include <iostream>
#include <vector>
using namespace std;

// Function Prototypes
void generateVector(vector<int>& vec, int size);
vector<int> countingSort(vector<int>& vec, int place);
void radixSort(vector<int>& vec);
void printVector(vector<int>& vec);

void generateVector(vector<int>& v, int size){
    srand(time(0));
    for (int i = 0; i < size; i++){
        v[i] = (rand() % 1000);
    }
}

vector<int> countingSort(vector<int> &v, int place){
    int N = v.size();
    vector<int> frequency(10, 0);
    vector<int> result(N, 0);

    for (auto i : v){
        int idx = (i / place) % 10;
        frequency[idx]++; 
    }

    for (int i = 1; i < 10; i++)
        frequency[i] += frequency[i - 1];
    

    for (int i = N - 1; i >= 0; i--){
        int currentDigit = (v[i] / place) % 10;
        int idx = frequency[currentDigit] - 1;
        result[idx] = v[i];
        frequency[currentDigit]--;
    }
    
    return result;
}

void radixSort(vector<int> &v){
    int max = v[0];
    for (auto i : v){
        if (i > max)
            max = i;
    }

    for (int i = 1; max/i > 0; i *= 10)
        v = countingSort(v, i);
}

void printVector(vector<int>& v){
    for (auto i : v) 
        cout << i << " ";
    cout << endl;
}

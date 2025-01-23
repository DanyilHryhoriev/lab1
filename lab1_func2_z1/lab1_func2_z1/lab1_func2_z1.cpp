#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void generate(vector<int>& arr, int size) {
    srand(time(0));  
    arr.resize(size);
    for (int& val : arr) val = rand() % 100;  
}

void saveBinary(const vector<int>& arr, const string& file) {
    ofstream out(file, ios::binary);
    out.write(reinterpret_cast<const char*>(arr.data()), arr.size() * sizeof(int));
    out.close();
    cout << "Array saved to binary file: " << file << endl;
}

int main() {
    int size;
    vector<int> arr;
    cout << "Enter array size: ";
    cin >> size;

    generate(arr, size);  
    saveBinary(arr, "array.bin"); 
}

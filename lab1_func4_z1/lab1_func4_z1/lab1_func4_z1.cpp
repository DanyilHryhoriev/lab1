#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void loadBinary(vector<int>& arr, const string& file) {
    ifstream in(file, ios::binary);
    if (in) {
        in.seekg(0, ios::end);
        arr.resize(in.tellg() / sizeof(int));
        in.seekg(0, ios::beg);
        in.read(reinterpret_cast<char*>(arr.data()), arr.size() * sizeof(int));
        in.close();
        cout << "Array loaded from " << file << endl;
    }
    else {
        cerr << "Error opening file: " << file << endl;
    }
}

void print(const vector<int>& arr) {
    for (int val : arr) cout << val << " ";
    cout << endl;
}

int main() {
    vector<int> arr;
    loadBinary(arr, "C:/Users/westt/source/repos/LAB1Z1FUNCTION2/LAB1Z1FUNCTION2/array.bin");  
    print(arr);
}

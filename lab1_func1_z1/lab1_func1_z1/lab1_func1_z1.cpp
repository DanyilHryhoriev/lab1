#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void input(vector<int>& arr) {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    arr.resize(n);
    cout << "Enter array elements: ";
    for (int& val : arr) cin >> val;
}

void saveText(const vector<int>& arr, const string& file) {
    ofstream out(file);
    for (int val : arr) out << val << " ";
    out.close();
    cout << "Array saved to " << file << endl;
}

int main() {
    vector<int> arr;
    input(arr);
    saveText(arr, "input.txt");  
}

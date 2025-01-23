#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

void loadText(vector<int>& arr, const string& file) {
    ifstream in(file);
    if (in.is_open()) {
        int num;
        while (in >> num) {
            arr.push_back(num);
        }
        in.close();
    }
    else {
        cerr << "Error opening file: " << file << endl;
    }
}

void findMin(const vector<int>& arr, const string& outputFile) {
    int minPos = numeric_limits<int>::max();
    int idx = -1;

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] > 0 && arr[i] < minPos) {
            minPos = arr[i];
            idx = i;
        }
    }

    ofstream out(outputFile);
    if (idx != -1) {
        cout << "Min positive: " << minPos << " at index " << idx << endl;
        out << "Min positive: " << minPos << " at index " << idx << endl; 
    }
    else {
        cout << "No positive elements found." << endl;
        out << "No positive elements found." << endl; 
    }
    out.close();
}

int main() {
    vector<int> arr;
    loadText(arr, "C:/Users/westt/source/repos/lab1z1functia1/lab1z1functia1/input.txt");
    findMin(arr, "C:/Users/westt/source/repos/LAB1Z1FUNCTION3/LAB1Z1FUNCTION3/output.txt");  
}

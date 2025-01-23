#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

void inputArray(vector<int>& arr) {
    int size;
    cout << "Enter array size: ";
    cin >> size;
    arr.resize(size);
    cout << "Enter elements: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
}

void saveArrayToFile(const vector<int>& arr, const string& filename) {
    ofstream out(filename);
    for (int num : arr) {
        out << num << " ";
    }
    out.close();
    cout << "Array saved to " << filename << endl;
}


int findmaxneg(const vector<int>& arr, int T) {
    int maxNeg = numeric_limits<int>::min();
    int maxIdx = -1;

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] > T) {
            break;
        }
        if (arr[i] < 0 && arr[i] > maxNeg) {
            maxNeg = arr[i];
            maxIdx = i; 
        }
    }

    return maxIdx; 
}

int main() {
    vector<int> arr;
    inputArray(arr);

    saveArrayToFile(arr, "C:/Users/westt/source/repos/ConsoleApplication2/ConsoleApplication2/input.txt");

    ifstream in("C:/Users/westt/source/repos/ConsoleApplication2/ConsoleApplication2/input.txt");
    vector<int> fileArr;
    int num;
    while (in >> num) {
        fileArr.push_back(num);
    }
    in.close();

    int T;
    cout << "Enter value of T: ";
    cin >> T;

    int index = findmaxneg(fileArr, T);

    ofstream out("C:/Users/westt/source/repos/ConsoleApplication2/ConsoleApplication2/output.txt");
    if (index != -1) {
        cout << "First max negative index before T: " << index << endl;
        out << "First max negative index before T: " << index << endl;
    }
    else {
        cout << "No negative elements found before T." << endl;
        out << "No negative elements found before T." << endl;
    }
    out.close();

    return 0;
}

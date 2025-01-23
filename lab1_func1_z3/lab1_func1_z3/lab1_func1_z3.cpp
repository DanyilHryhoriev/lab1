#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

// Function to write user input into input.txt
void writeArrayToFile(int& n, int& m, const string& filename) {
    ofstream out(filename);
    if (!out) {
        cerr << "Error: Unable to open file " << filename << endl;
        exit(1);
    }

    // Input array dimensions
    cout << "Enter number of rows (n <= 100): ";
    cin >> n;
    cout << "Enter number of columns (m <= 10): ";
    cin >> m;

    if (n <= 0 || m <= 0 || n > 100 || m > 10) {
        cerr << "Error: Invalid array dimensions n = " << n << ", m = " << m << endl;
        exit(1);
    }

    // Input array elements and save to file
    out << n << " " << m << endl;
    cout << "Enter array elements:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            double element;
            cout << "Element[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> element;
            out << element << " ";
        }
        out << endl;
    }
    out.close();
}

// Function to read the array from input.txt
void readArray(vector<vector<double>>& arr, int& n, int& m, const string& filename) {
    ifstream in(filename);
    if (!in) {
        cerr << "Error: Unable to open file " << filename << endl;
        exit(1);
    }

    in >> n >> m;
    if (n <= 0 || m <= 0 || n > 100 || m > 10) {
        cerr << "Error: Invalid array dimensions n = " << n << ", m = " << m << endl;
        exit(1);
    }

    arr.resize(n, vector<double>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            in >> arr[i][j];
        }
    }
    in.close();
}

// Function to save result to output.txt
void saveResult(double result, const string& filename) {
    ofstream out(filename);
    if (!out) {
        cerr << "Error: Unable to open file " << filename << endl;
        exit(1);
    }
    out << "Z = " << result << endl;
    out.close();
}

// Function to calculate the max of the row minimums
double findMaxMin(const vector<vector<double>>& arr, int n, int m) {
    double maxOfMins = numeric_limits<double>::lowest();

    for (int i = 0; i < n; ++i) {
        double minInRow = numeric_limits<double>::max();
        for (int j = 0; j < m; ++j) {
            minInRow = min(minInRow, arr[i][j]);
        }
        maxOfMins = max(maxOfMins, minInRow);
    }

    return maxOfMins;
}

int main() {
    vector<vector<double>> arr;
    int n, m;

    string inputFile = "C:/Users/westt/source/repos/LAB1Z3FUNCTION1/LAB1Z3FUNCTION1/input.txt";
    string outputFile = "C:/Users/westt/source/repos/LAB1Z3FUNCTION1/LAB1Z3FUNCTION1/output.txt";

    // First step: write input to file
    writeArrayToFile(n, m, inputFile);

    // Second step: read input from file and process it
    readArray(arr, n, m, inputFile);

    double result = findMaxMin(arr, n, m);

    cout << "Z = " << result << endl;

    // Save result to output file
    saveResult(result, outputFile);

    return 0;
}

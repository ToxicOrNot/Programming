#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

vector<int> quicksort(vector<int>& array) {
    if (array.size() < 2)
        return array;

    int pivot = array[0];
    vector<int> less, greater;

    for (size_t i = 1; i < array.size(); i++) {
        if (array[i] <= pivot)
            less.push_back(array[i]);
        else
            greater.push_back(array[i]);
    }

    less = quicksort(less);
    greater = quicksort(greater);

    less.push_back(pivot);
    less.insert(less.end(), greater.begin(), greater.end());

    return less;
}

vector<string> quicksort(vector<string>& array) {
    if (array.size() < 2)
        return array;

    string pivot = array[0];
    vector<string> less, greater;

    for (size_t i = 1; i < array.size(); i++) {
        if (array[i] <= pivot)
            less.push_back(array[i]);
        else
            greater.push_back(array[i]);
    }

    less = quicksort(less);
    greater = quicksort(greater);

    less.push_back(pivot);
    less.insert(less.end(), greater.begin(), greater.end());

    return less;
}

vector<int> readIntArrayFromFile(const string& filepath, const string& delimiter = ", ") {
    vector<int> arr;
    ifstream file(filepath);
    string line;

    if (file.is_open()) {
        getline(file, line);
        file.close();

        stringstream ss(line);
        string item;
        while (getline(ss, item, delimiter[0])) {
            arr.push_back(stoi(item));
        }
    }
    return arr;
}

vector<int> readIntArrayFromFileSemicolon(const string& filepath) {
    vector<int> arr;
    ifstream file(filepath);
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string item;
            while (getline(ss, item, ';')) {
                arr.push_back(stoi(item));
            }
        }
        file.close();
    }
    return arr;
}

vector<vector <int> > readTwoDimensionalArrayFromFile(const string& filepath) {
    vector<vector <int> > arr;
    ifstream file(filepath);
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string item;
            vector<int> row;
            while (getline(ss, item, ';')) {
                row.push_back(stoi(item));
            }
            arr.push_back(row);
        }
        file.close();
    }
    return arr;
}

vector<int> extractFirstColumn(const vector<vector <int> >& array) {
    vector<int> firstColumn;
    for (const auto& row : array) {
        if (!row.empty()) {
            firstColumn.push_back(row[0]);
        }
    }
    return firstColumn;
}

vector<string> readStringArrayFromFile(const string& filepath, const string& delimiter = ", ") {
    vector<string> arr;
    ifstream file(filepath);
    string line;

    if (file.is_open()) {
        getline(file, line);
        file.close();

        stringstream ss(line);
        string item;
        while (getline(ss, item, delimiter[0])) {
            arr.push_back(item);
        }
    }
    return arr;
}

int main() {
    int chose;
    cin >> chose;

    switch (chose) {
        case 1: {
            vector<int> arr = readIntArrayFromFile("/Users/toxicornot/Documents/arr.txt");
            vector<int> sortedArr = quicksort(arr);
            for (int num : sortedArr) {
                cout << num << " ";
            }
            cout << endl;
            break;
        }
        case 2: {
            vector<int> arr = readIntArrayFromFile("/Users/toxicornot/Documents/arr.txt");
            vector<int> sortedArr = quicksort(arr);
            for (int num : sortedArr) {
                cout << num << " ";
            }
            cout << endl;
            break;
        }
        case 3: {
            vector<vector <int> > arr = readTwoDimensionalArrayFromFile("/Users/toxicornot/Documents/arr.txt");
            vector<int> firstColumn = extractFirstColumn(arr);
            vector<int> sortedFirstColumn = quicksort(firstColumn);
            for (int num : sortedFirstColumn) {
                cout << num << " ";
            }
            cout << endl;
            break;
        }
        case 4: {
            vector<string> arr = readStringArrayFromFile("/Users/toxicornot/Documents/arr.txt");
            vector<string> sortedArr = quicksort(arr);
            for (const string& str : sortedArr) {
                cout << str << " ";
            }
            cout << endl;
            break;
        }
        default:
            cout << "Invalid choice." << endl;
            break;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

vector<int> chisla;
vector<int> result;

void generateNumbers() {
    srand(time(0));
    for (int i = 1; i < 50; ++i) {
        chisla.push_back(rand() % 41 - 20); // Generate random numbers between -10000 and 10000
    }
}

vector<int> numbers(const vector<int>& array) {
    for (int i : array) {
        if (i > 0) {
            result.push_back(i);
        } else if (i < 0) {
            auto it = find(result.begin(), result.end(), abs(i));
            if (it != result.end()) {
                result.erase(it);
            }
        } else if (i == 0) {
            for (int num : array) {
                
            }
            
        }
    }
    return result;
}

vector<int> quicksort(vector<int> array) {
    if (array.size() < 2)
        return array;

    int pivot = array[0];
    vector<int> less, greater;

    for (size_t i = 1; i < array.size(); ++i) {
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

int main() {
    generateNumbers();
    numbers(chisla);
    vector<int> sortedResult = quicksort(result);

    for (int num : sortedResult) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

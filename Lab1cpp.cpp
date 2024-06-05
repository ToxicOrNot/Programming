#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

// Функция для нахождения и удаления наименьшего элемента из массива чисел
void find_Smallest(std::vector<int>& arr, std::vector<int>& sort, bool reverse = false) {
    int smallest = arr[0];
    int smallest_index = 0;

    for (int i = 1; i < arr.size(); ++i) {
        if (reverse ? arr[i] > smallest : arr[i] < smallest) {
            smallest = arr[i];
            smallest_index = i;
        }
    }

    sort.push_back(smallest);
    arr.erase(arr.begin() + smallest_index);
}

// Функция для чтения массива чисел из файла
void read_array_from_file(std::vector<int>& arr, const std::string& file_path) {
    std::ifstream file(file_path);
    if (file.is_open()) {
        std::string line;
        std::getline(file, line);
        std::stringstream ss(line);
        std::string temp;
        while (ss >> temp) {
            arr.push_back(std::stoi(temp));
        }
        file.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }
}

// Функция для сортировки массива чисел
void sort_array(int choice, const std::string& file_path) {
    std::vector<int> arr;
    read_array_from_file(arr, file_path);

    std::vector<int> sort;
    int f = arr.size();
    bool reverse = (choice == 2);

    while (f != 0) {
        find_Smallest(arr, sort, reverse);
        f--;
    }

    for (const int& num : sort) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Функция для нахождения и удаления наименьшего элемента из массива строк
void find_Smallest_phone(std::vector<std::string>& arr, std::vector<std::string>& sort) {
    std::string smallest = arr[0];
    int smallest_index = 0;

    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] < smallest) {
            smallest = arr[i];
            smallest_index = i;
        }
    }

    sort.push_back(smallest);
    arr.erase(arr.begin() + smallest_index);
}

// Функция для чтения массива строк из файла
void read_phone_array_from_file(std::vector<std::string>& arr, const std::string& file_path) {
    std::ifstream file(file_path);
    if (file.is_open()) {
        std::string line;
        std::getline(file, line);
        std::stringstream ss(line);
        std::string temp;
        while (ss >> temp) {
            arr.push_back(temp);
        }
        file.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }
}

// Функция для сортировки массива телефонных номеров
void sort_phone_numbers(const std::string& file_path) {
    std::vector<std::string> arr;
    read_phone_array_from_file(arr, file_path);

    std::vector<std::string> sort;
    int f = arr.size();

    while (f != 0) {
        find_Smallest_phone(arr, sort);
        f--;
    }

    for (const std::string& phone : sort) {
        std::cout << phone << " ";
    }
    std::cout << std::endl;
}

int main() {
    int choose;
    std::cin >> choose;

    switch (choose) {
        case 1:
            sort_array(1, "/Users/toxicornot/Documents/arr.txt");
            break;
        case 2:
            sort_array(2, "/Users/toxicornot/Documents/arr.txt");
            break;
        case 3:
            sort_phone_numbers("/Users/toxicornot/Documents/arr.txt");
            break;
        default:
            std::cerr << "Invalid choice" << std::endl;

            break;
    }

    return 0;
}

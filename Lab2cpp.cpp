#include <iostream>
#include <cmath>
#include <vector>

void count_1(int i, int& n) {
    i++;
    std::cout << i << std::endl;
    if (i != n) {
        count_1(i, n);
    }
}

void count_2_decrement(int a, int b) {
    std::cout << a << std::endl;
    a--;
    if (a != (b - 1)) {
        count_2_decrement(a, b);
    } else {
        std::cout << b << std::endl;
    }
}

void count_2_increment(int a, int b) {
    std::cout << a << std::endl;
    a++;
    if (a != b) {
        count_2_increment(a, b);
    } else {
        std::cout << b << std::endl;
    }
}

int sum_digits(int N, int& Number) {
    Number += N % 10;
    N /= 10;
    if (N != 0) {
        return sum_digits(N, Number);
    } else {
        return Number;
    }
}

bool is_prime(int num) {
    bool prime = num > 1 && (num % 2 != 0 || num == 2) && (num % 3 != 0 || num == 3);
    int i = 5;
    int d = 2;

    while (prime && i * i <= num) {
        prime = num % i != 0;
        i += d;
        d = 6 - d; // чередование прироста 2 и 4: 5 + 2, 7 + 4, 11 + 2, и т.д.
    }
    return prime;
}

std::vector<int> find_divisors(int N, int& delitel, std::vector<int>& deliteli) {
    if (N % delitel == 0) {
        if (is_prime(delitel)) {
            deliteli.push_back(delitel);
        }
    }
    delitel++;
    if (delitel <= static_cast<int>(std::ceil(std::sqrt(N)) + 1)) {
        return find_divisors(N, delitel, deliteli);
    } else {
        return deliteli;
    }
}

int main() {
    int chose;
    std::cin >> chose;

    switch (chose) {
        case 1: {
            int NN;
            std::cin >> NN;
            int i = 0;
            count_1(i, NN);
            break;
        }
        case 2: {
            int A, B;
            std::cin >> A >> B;
            if (A > B) {
                count_2_decrement(A, B);
            } else {
                count_2_increment(A, B);
            }
            break;
        }
        case 3: {
            int N;
            std::cin >> N;
            int Number = 0;
            std::cout << sum_digits(N, Number) << std::endl;
            break;
        }
        case 4: {
            int N;
            std::cin >> N;
            int delitel = 2;
            std::vector<int> deliteli;
            std::vector<int> result = find_divisors(N, delitel, deliteli);
            for (int d : result) {
                std::cout << d << " ";
            }
            std::cout << std::endl;
            break;
        }
        default:
            std::cerr << "Invalid choice" << std::endl;
            break;
    }

    return 0;
}

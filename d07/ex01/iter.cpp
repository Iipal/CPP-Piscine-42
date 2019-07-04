#include <iostream>

template <typename T>
void iter(T *arr, const size_t length, void (*fn)(T &)) {
    size_t i = ~0ULL;

    while (length > ++i) {
        fn(arr[i]);
    }
}

template <typename T>
void display(T &data) { std::cout << data << std::endl; }

int main(void) {
    int test1[] = { 1, 2, 3, 4, 5, 6 };
    std::string test2[] = { "AAA", "BBB", "CCC", "EEE", "DDD", "FFF" };

    iter<int>(test1, sizeof(test1) / sizeof(*test1), display);
    iter<std::string>(test2, sizeof(test2) / sizeof(*test2), display);
}

#include "Array.hpp"

template <typename T>
static void printArr(Array<T> &a) {
    try {
        size_t i = ~0ULL;
        while (a.size() > ++i) {
            std::cout << std::setiosflags(std::ios::fixed) << a[i] << ' ';
        }
        std::cout << "| ";
        std::cout << std::setiosflags(std::ios::fixed) << a[i];
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

int main(void) {
    Array<int> a(3); std::cout << "Array<int> a: "; printArr(a);
    Array<int> b(5); std::cout << "Array<int> b: "; printArr(b);

    b = a; std::cout << "Array<int> b = Array<int> a: "; printArr(b);

    Array<float> c(2); std::cout << "Array<float> c: "; printArr(c);

    Array<std::string> d(2);
    d[0] = std::string("Hello, World");

    std::cout << "Array<std::string> d: "; printArr(d);
}

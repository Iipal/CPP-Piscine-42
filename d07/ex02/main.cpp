#include "Array.tpp"

int main(void) {
    Array<int> _a(5);
    Array<int> a;

    a = _a;

    try {
        size_t i = ~0ULL;
        while (a.size() > ++i) {
            std::cout << a[i] << std::endl;
        }
        std::cout << a[i] << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    Array<float> *b = new Array<float>(5);
    try {
        size_t i = ~0ULL;
        while (b->size() > ++i) {
            std::cout << std::setiosflags(std::ios::fixed) << (*b)[i] << std::endl;
        }
        std::cout << (*b)[i] << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    delete b;
}

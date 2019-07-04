
#include <iostream>

struct Data { std::string s1; int n; std::string s2; };
static const char _serializeOutputData[] = { "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };

void *serialize(void) {
    size_t  i = ~0ULL;

    char *data = new char[20];

    while (8 > ++i) {
        data[i] = _serializeOutputData[rand() % 62];
    }
    *((int *)(data + i)) = 2;
    // --i;
    // while (12 > ++i) { data[i] = rand() % 127; }
    i = 11;
    while (20 > ++i) {
        data[i] = _serializeOutputData[rand() % 62];
    }
    i = ~0ULL;
    while (20 > ++i) {
        if (8 == i) {
            std::cout << " | " << data[i];
        } else if (12 == i) {
            std::cout << " | " << data[i];
        } else {
            std::cout << data[i];
        }
    }
    std::cout << std::endl;
    data[19] = 0;
    return reinterpret_cast<void*>(data);
}

Data *deserialize(void *raw) {
    Data *out = new Data;

    std::string _data = std::string(static_cast<char*>(raw), 20);

    out->s1 = std::string(_data, 0, 8);
    out->s2 = std::string(_data, 12, 8);
    out->n = *(reinterpret_cast<int*>(&_data[8]));

    return out;
}

int main(void) {
    Data *deser;
    void *raw;

    srand(time(NULL));
    raw = serialize();

    deser = deserialize(raw);

    std::cout << deser->s1 << " | " << deser->n << " | " << deser->s2 << std::endl;
}

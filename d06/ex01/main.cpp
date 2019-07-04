#include "Serialize.hpp"

static const char _serializeOutputData[] = { "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };

void *serialize(void) {
    size_t  i = ~0ULL;

    char *data = new char[20];
    bzero(data, sizeof(char) * 20);

    while (8 > ++i) {
        data[i] = _serializeOutputData[rand() % 62];
    }
    *((int*)data + i) = 2;
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
    return reinterpret_cast<void*>(data);
}

Data *deserialize(void *raw) {
    char *data = static_cast<char*>(raw);

    Data *out = new Data;
    bzero(out, sizeof(Data));


    std::string msg = data;
    std::cout << msg.size() << std::endl;

    out->s1 = std::string(data, 0, sizeof(char) * 8);
    out->s2 = std::string(data, 12, sizeof(char) * 8);
    out->n = *(reinterpret_cast<int*>(data + 8));

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

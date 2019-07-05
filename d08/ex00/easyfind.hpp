#pragma once

template <typename T>
typename T::iterator easyfind(T &container, int find) {
    typename T::iterator it = container.begin();
    typename T::iterator ite = container.end();

    while (ite != it) {
        if (*it == find) {
            return it;
        }
        ++it;
    }
    return ite;
}

#pragma once

#include <iostream>
#include <iomanip>

template <typename T>
class Array {
public:
    Array<T>() : _nElements(0), _arrData(NULL) {}
    Array<T>(size_t const n) : _nElements(n), _arrData(NULL) {
        if (n) {
            _arrData = new T[n]();
        }
    }
    Array<T>(Array<T> const &copy);
    virtual ~Array<T>() { delete[] _arrData; }

    Array<T> &operator=(Array<T> const &copy) {
        this->_nElements = copy._nElements;
        if (this->_arrData) {
            delete[] this->_arrData;
        }
        if (this->_nElements) {
            _arrData = new T[this->_nElements];

            size_t i = ~0ULL;
            while (this->_nElements > ++i) {
                _arrData[i] = copy._arrData[i];
            }
        }
        return *this;
    }

    size_t const &size(void) const { return this->_nElements; }

    class OutOfRangeException : public std::exception {
    public:
        OutOfRangeException(void) { }
        OutOfRangeException(OutOfRangeException const &copy) { *this = copy; }
        virtual ~OutOfRangeException(void) throw() { }

        OutOfRangeException &operator=(OutOfRangeException const &copy) { (void)copy; return *this; }

        const char *what(void) const throw() { return "Exception: Out of range."; }
    };

    T &operator[](size_t const &i) {
        if (this->_nElements <= i) {
            throw Array<T>::OutOfRangeException();
        } else {
            return this->_arrData[i];
        }
    }
private:
    size_t _nElements;
    T *_arrData;
};

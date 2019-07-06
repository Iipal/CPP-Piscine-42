#pragma once

#include <iostream>
#include <list>
#include <stack>

template <typename T>
class MutantStack {
public:
    typedef T                                     container_type;
    typedef	typename std::list<T>::size_type      size_type;
    typedef typename std::list<T>::iterator       iterator;
    typedef typename std::list<T>::const_iterator const_iterator;

    MutantStack<T>() : _dataSize(0), _data() { }
    MutantStack<T>(MutantStack<T> const &copy) { *this = copy; }
    virtual ~MutantStack<T>() { }

    MutantStack<T> &operator=(MutantStack<T> const &copy) {
        this->_data = copy._data;
        this->_dataSize = copy._dataSize;
        return *this;
    }

    void     push(T const &n) { this->_data.push_front(n); ++this->_dataSize; }
    void     pop(void)        { this->_data.pop_front(); --this->_dataSize; }
    T const &top(void)  const { return this->_data.front(); }
    T       &top(void)        { return this->_data.front(); }
    size_t   size(void) const { return this->_data.size(); }
    bool     empty(void)      { this->_dataSize = 0; }

    operator std::stack<T>(void) {
        std::stack<T> s;

        typename std::list<T>::reverse_iterator ti  = this->_data.rbegin();
        typename std::list<T>::reverse_iterator tie = this->_data.rend();

        while (ti != tie) {
            s.push(*ti++);
        }
        return s;
    }

    iterator       begin(void) { return this->_data.begin(); }
    iterator       end(void) { return this->_data.end(); }
    const_iterator begin(void) const { return this->_data.begin(); }
    const_iterator end(void) const { return this->_data.end(); }

private:
    size_type _dataSize;
    std::list<T> _data;
};

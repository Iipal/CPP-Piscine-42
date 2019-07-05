#pragma once

#include <iostream>
#include <list>
#include <vector>

class Span {
public:
    Span();
    Span(unsigned int const &n);
    Span(Span const &copy);
    virtual ~Span();

    Span &operator=(Span const &copy);

    void addNumber(int n);

    int shortestSpan(void) const;
    int longestSpan(void) const;

    class SpanVecOverflowException : public std::exception {
    public:
        SpanVecOverflowException();
        SpanVecOverflowException(SpanVecOverflowException const &copy);
        virtual ~SpanVecOverflowException() throw();

        SpanVecOverflowException &operator=(SpanVecOverflowException const &copy);

        const char *what(void) const throw();
    };

    class SpanVecSmallException : public std::exception {
    public:
        SpanVecSmallException();
        SpanVecSmallException(SpanVecSmallException const &copy);
        virtual ~SpanVecSmallException() throw();

        SpanVecSmallException &operator=(SpanVecSmallException const &copy);

        const char *what(void) const throw();
    };

private:
    unsigned int _maxSpans;
    std::vector<int> _vecSpans;
};

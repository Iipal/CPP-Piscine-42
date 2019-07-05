#include "span.hpp"

Span::Span() { }
Span::Span(unsigned int const &maxSpans) : _maxSpans(maxSpans) { }
Span::Span(Span const &copy) { *this = copy; }
Span::~Span() { }

Span &Span::operator=(Span const &copy) {
    if (this != &copy) { *this = copy; }
    return *this;
}

void Span::addNumber(int n) {
    if (_maxSpans <= this->_vecSpans.size()) {
        throw Span::SpanVecOverflowException();
    } else {
        this->_vecSpans.push_back(n);
    }
}

int Span::shortestSpan(void) const {
    if (1 >= this->_vecSpans.size()) {
        throw Span::SpanVecSmallException();
    } else {
        std::vector<int>    _sortedCopy = this->_vecSpans;
        std::sort(_sortedCopy.begin(), _sortedCopy.end());

        size_t i = ~0ULL;
        while (this->_vecSpans.size() > ++i) {
        }

        return *std::min_element(this->_vecSpans.begin(), this->_vecSpans.end());
    }
}

int Span::longestSpan(void) const {
    if (1 >= this->_vecSpans.size()) {
        throw Span::SpanVecSmallException();
    } else {
        return *std::max_element(this->_vecSpans.begin(), this->_vecSpans.end()) - *std::min_element(this->_vecSpans.begin(), this->_vecSpans.end());
    }
}

Span::SpanVecOverflowException::SpanVecOverflowException() { }
Span::SpanVecOverflowException::SpanVecOverflowException(SpanVecOverflowException const &copy) { *this = copy; }
Span::SpanVecOverflowException::~SpanVecOverflowException() throw() { }

Span::SpanVecOverflowException &Span::SpanVecOverflowException::operator=(Span::SpanVecOverflowException const &copy) { (void)copy; return *this; }

const char *Span::SpanVecOverflowException::what(void) const throw() {
    return "Exception: Span array(`std::vector`) overflow of "
    "max elements(`size_t const maxSpans`) set in constructor.";
}

Span::SpanVecSmallException::SpanVecSmallException() { }
Span::SpanVecSmallException::SpanVecSmallException(SpanVecSmallException const &copy) { *this = copy; }
Span::SpanVecSmallException::~SpanVecSmallException() throw() { }

Span::SpanVecSmallException &Span::SpanVecSmallException::operator=(Span::SpanVecSmallException const &copy) { (void)copy; return *this; }

const char *Span::SpanVecSmallException::what(void) const throw() {
    return "Exception: Span array(`std::vector`) too small for calculating.";
}

#include <stdexcept>

/* 
 *  Iterator 
 */

template <short N>
class FibIterator
{
    short counter;
    int* last;
    int* before;

public:
    FibIterator(int* last, int* before, short counter) : last{ last }, before{ before }, counter{ counter } {}

    int operator *() const {
        return *last;
    }

    bool operator !=(FibIterator& other) const {
        return this->counter != other.counter;
    }

    FibIterator& operator++() {
        int temp = *last + *before;
        *before = *last;
        *last = temp;
        counter++;
        return *this;
    }
};



/*
 *  Fibonacci
 */

template <short N>
class Fibonacci
{
    int last;       // Last generated number
    int before;     // Previous generated number
    FibIterator<N> iter;

public:
    Fibonacci() : 
        before{ 0 }, 
        last{ 1 }, 
        iter{ FibIterator<N>(&last, &before, 0) } 
    {
        if (N < 2) throw std::range_error("Limit must me >= 2!");
    }

    FibIterator<N> begin() {
        return FibIterator<N>(&last, &before, 0);
    }

    FibIterator<N> end() {
        return FibIterator<N>(&last, &before, N);
    }

};



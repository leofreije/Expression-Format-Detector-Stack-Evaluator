#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

template <typename T>
class ArrayStack {

private:
    std::vector<T> data;
    size_t maxSize;

public:
    ArrayStack(size_t maxSize) {
        this->maxSize = maxSize;
    }

    void push(const T& value) {
        // TODO
        if (data.size() >= maxSize) {
            throw overflow_error("Stack overflow");
        }
        data.push_back(value);
    }

    void top() {
        // TODO
        if (data.empty()) {
            throw underflow_error("Stack is empty");
        }
        data.pop_back();
    }

    T top() const {
        // TODO
        if (data.empty()) {
            throw underflow_error("Stack is empty");
        }
        return data.back();
    }

    bool empty() const {
        // TODO
        return data.empty();
    }

    int size() const {
        // TODO
        return data.size();
    }
};

#endif

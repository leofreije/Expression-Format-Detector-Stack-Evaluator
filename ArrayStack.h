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


public:

    void push(const T& value) {
        // TODO
        data.push_back(value);
    }

    void pop() {
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

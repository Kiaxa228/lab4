#ifndef ARRAY_H
#define ARRAY_H

#include <memory>
#include <vector>
#include <stdexcept>

template <typename T>
class Array
{
private:
    std::vector<std::shared_ptr<T>> data;

public:
    Array(size_t initialCapacity = 4);
    void push_back(std::shared_ptr<T> &&value);
    void remove(size_t index);
    std::shared_ptr<T> &operator[](size_t index);
    const std::shared_ptr<T> &operator[](size_t index) const;
    size_t size() const;
};

#endif
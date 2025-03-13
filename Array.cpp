#include "Array.h"
#include "Rhombus.h"
#include "Figure.h"

template <typename T>
Array<T>::Array(size_t initialCapacity)
{
    data.reserve(initialCapacity);
}

template <typename T>
void Array<T>::push_back(std::shared_ptr<T> &&value)
{
    data.push_back(std::move(value));
}

template <typename T>
void Array<T>::remove(size_t index)
{
    if (index >= data.size())
        throw std::out_of_range("Index out of bounds");
    data.erase(data.begin() + index);
}

template <typename T>
std::shared_ptr<T> &Array<T>::operator[](size_t index)
{
    return data[index];
}

template <typename T>
const std::shared_ptr<T> &Array<T>::operator[](size_t index) const
{
    return data[index];
}

template <typename T>
size_t Array<T>::size() const
{
    return data.size();
}

template class Array<Figure<int>>;
template class Array<Rhombus<int>>;
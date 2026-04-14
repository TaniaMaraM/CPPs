/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 15:34:02 by tmarcos           #+#    #+#             */
/*   Updated: 2026/04/14 17:57:05 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//empty constructor
template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n) {}

// allocates a fresh independent block of memory and copies elements one by one
// guards against self-assignment (a = a) to avoid deleting data before copying it
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (this == &other)
        return *this;
    delete[] _data;
    _size = other._size;
    _data = new T[_size]();
    for (unsigned int i = 0; i < _size; i++)
        _data[i] = other._data[i];
    return *this;
}

// initialises to empty first so operator= can safely delete[] _data without crashing
template <typename T>
Array<T>::Array(const Array<T>& other) : _data(NULL), _size(0)
{
    *this = other;
}
// frees the heap memory
template <typename T>
Array<T>::~Array() { 
    delete[] _data; 
}

// returns a reference so the element can be read and modified: arr[i] = 42
// throws if index is out of bounds
template <typename T>
T& Array<T>::operator[](unsigned int i)
{
    if (i >= _size)
         throw std::out_of_range("index out of bounds");
    return _data[i];
}

// same but for const arrays — only allows reading, not modifying
template <typename T>
T const& Array<T>::operator[](unsigned int i) const
{
    if (i >= _size)
        throw std::out_of_range("index out of bounds");
    return _data[i];
}

// const: does not modify the object — safe to call on const arrays
template <typename T>
unsigned int Array<T>::size() const {
     return _size;
    }


// outside the class, each method needs 'template <typename T>' 
// — same T, mandatory syntax
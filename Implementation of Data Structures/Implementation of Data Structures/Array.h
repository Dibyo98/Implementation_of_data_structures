#pragma once

#include <algorithm>

namespace mdd {
template <class _T, std::size_t _N>
class Array {
public:
    void fill(const _T&);
    void swap(Array&);
    _T* begin();
    const _T* begin() const;
    _T* end();
    const _T* end() const;
    _T& front();
    const _T& front() const;
    _T& back();
    const _T& back() const;
    _T* data();
    const _T* data() const;
    _T& at(std::size_t);
    const _T& at(std::size_t) const;
    _T& operator[](std::size_t);
    const _T& operator[](std::size_t) const;
    constexpr std::size_t size() const;
    constexpr std::size_t max_size() const;
    constexpr bool empty() const;

private:
    _T _data[_N ? _N : 1];
};

template <class _T, std::size_t _N>
void Array<_T, _N>::fill(const _T& n_)
{
    std::fill(begin(), end(), n_);
}

template <class _T, std::size_t _N>
void Array<_T, _N>::swap(Array& _other)
{
    std::swap_ranges(begin(), end(), _other.back());
}

template <class _T, std::size_t _N>
_T* Array<_T, _N>::begin()
{
    return _data;
}

template <class _T, std::size_t _N>
const _T* Array<_T, _N>::begin() const
{
    return (const _T*)_data;
}

template <class _T, std::size_t _N>
_T* Array<_T, _N>::end()
{
    return _data + _N;
}

template <class _T, std::size_t _N>
const _T* Array<_T, _N>::end() const
{
    return (const _T*)(_data + _N);
}

template <class _T, std::size_t _N>
_T& Array<_T, _N>::front()
{
    return _data[0];
}

template <class _T, std::size_t _N>
const _T& Array<_T, _N>::front() const
{
    return (const _T&)_data[0];
}

template <class _T, std::size_t _N>
_T& Array<_T, _N>::back()
{
    return _data[_N - 1];
}

template <class _T, std::size_t _N>
const _T& Array<_T, _N>::back() const
{
    return (const _T&)_data[_N - 1];
}

template <class _T, std::size_t _N>
_T* Array<_T, _N>::data()
{
    return _data;
}

template <class _T, std::size_t _N>
const _T* Array<_T, _N>::data() const
{
    return (const _T*)_data;
}

template <class _T, std::size_t _N>
_T& Array<_T, _N>::at(std::size_t n_)
{
    if (n_ >= _N)
        throw "Out of bounds";

    return _data[n_];
}

template <class _T, std::size_t _N>
const _T& Array<_T, _N>::at(std::size_t n_) const
{
    if (n_ >= _N)
        throw "Out of bounds";

    return (const _T&)_data[n_];
}

template <class _T, std::size_t _N>
_T& Array<_T, _N>::operator[](std::size_t n_)
{
    return at(n_);
}

template <class _T, std::size_t _N>
const _T& Array<_T, _N>::operator[](std::size_t n_) const
{
    return at(n_);
}

template <class _T, std::size_t _N>
constexpr std::size_t Array<_T, _N>::size() const
{
    return _N;
}

template <class _T, std::size_t _N>
constexpr std::size_t Array<_T, _N>::max_size() const
{
    return _N;
}

template <class _T, std::size_t _N>
constexpr bool Array<_T, _N>::empty() const
{
    return _N == 0;
}
} // namespace mdd

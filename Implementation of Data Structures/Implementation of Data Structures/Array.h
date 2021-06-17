#pragma once

#include <initializer_list>
#include<algorithm>

namespace mdd {
template <class _T, std::size_t _N>
class Array {
public:
    Array();
    Array(const Array&);
    Array(Array&&);
    Array(const std::initializer_list<_T>&);
    ~Array() = default;
    Array& operator=(const Array&);
    Array& operator=(Array&&);
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
    _T _m_data[_N ? _N : 1];
};

template <class _T, std::size_t _N>
Array<_T, _N>::Array() {};

template <class _T, std::size_t _N>
Array<_T, _N>::Array(const Array& other)
{
    std::copy(other.begin(), other.end(), this->begin());
}

template <class _T, std::size_t _N>
Array<_T, _N>::Array(Array&& other)
    : _m_data { std::move(other) }
{
}

template <class _T, std::size_t _N>
Array<_T, _N>::Array(const std::initializer_list<_T>& values)
{
    int count = 0;
    for (auto& element : values) {
        _m_data[count++] = element;
    }
}

template <class _T, std::size_t _N>
Array<_T, _N>& Array<_T, _N>::operator=(const Array& other)
{
    std::copy(other.begin(), other.end(), this->begin());
    return *this;
}

template <class _T, std::size_t _N>
Array<_T, _N>& Array<_T, _N>::operator=(Array&& other)
{
    _m_data = std::move(other);
    return *this;
}

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
    return _m_data;
}

template <class _T, std::size_t _N>
const _T* Array<_T, _N>::begin() const
{
    return (const _T*)_m_data;
}

template <class _T, std::size_t _N>
_T* Array<_T, _N>::end()
{
    return _m_data + _N;
}

template <class _T, std::size_t _N>
const _T* Array<_T, _N>::end() const
{
    return (const _T*)(_m_data + _N);
}

template <class _T, std::size_t _N>
_T& Array<_T, _N>::front()
{
    return _m_data[0];
}

template <class _T, std::size_t _N>
const _T& Array<_T, _N>::front() const
{
    return (const _T&)_m_data[0];
}

template <class _T, std::size_t _N>
_T& Array<_T, _N>::back()
{
    return _m_data[_N - 1];
}

template <class _T, std::size_t _N>
const _T& Array<_T, _N>::back() const
{
    return (const _T&)_m_data[_N - 1];
}

template <class _T, std::size_t _N>
_T* Array<_T, _N>::data()
{
    return _m_data;
}

template <class _T, std::size_t _N>
const _T* Array<_T, _N>::data() const
{
    return (const _T*)_m_data;
}

template <class _T, std::size_t _N>
_T& Array<_T, _N>::at(std::size_t n_)
{
    return _m_data[n_];
}

template <class _T, std::size_t _N>
const _T& Array<_T, _N>::at(std::size_t n_) const
{
    return (const _T&)_m_data[n_];
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

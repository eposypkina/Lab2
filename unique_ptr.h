#include <iostream>

template <class T>
class unique_ptr
{
 
    T* ptr;
 
public:
    unique_ptr(const unique_ptr&) = delete;
 
    unique_ptr(unique_ptr &&p) noexcept : ptr(p.ptr)
    {
        p.ptr = nullptr;
    }

    unique_ptr() noexcept : ptr(nullptr)
    {}
 
    unique_ptr(T* p) : ptr(p) 
    {}
 
    ~unique_ptr()
    {
        delete ptr;
    }
 
    unique_ptr& operator = (const unique_ptr&) = delete;
 
    unique_ptr& operator = (unique_ptr &&p) noexcept
    {
        ptr = p.ptr;
        p.ptr = nullptr;
        return *this;
    }
 
    T& operator * () const
    {
        return *ptr; 
    }
 
    T* operator -> () const 
    {
        return ptr;
    }
 
    T* get() const 
    {
        return ptr;
    }
 
    void reset() noexcept
    {
        T* result = release();
        delete result;

    }
    
    void swap(unique_ptr& src) noexcept
    {
        std::swap(ptr, src.ptr);
    }
 
    T* release() noexcept
    {
        T* result = ptr;
        ptr = nullptr;
        return result;
    }
};
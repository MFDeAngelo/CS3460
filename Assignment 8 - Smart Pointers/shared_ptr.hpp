#include <iostream>

namespace usu
{
    template <typename T>
    class shared_ptr
    {
      private:
        T* managed_ptr;
        int* count;

      public:
        shared_ptr(T* ptr);
        shared_ptr(const shared_ptr<T>& rhs);
        shared_ptr(shared_ptr<T>&& rhs);
        ~shared_ptr();
        shared_ptr<T>& operator=(const shared_ptr<T>& ptr);
        shared_ptr<T>& operator=(shared_ptr<T>&& ptr);
        T* operator->();
        int use_count();
        T operator*();
        T* get();
    };

    template <typename T>
    shared_ptr<T>::shared_ptr(T* ptr) :
        managed_ptr(ptr),
        count(new int(1))
    {
    }

    template <typename T>
    shared_ptr<T>::shared_ptr(const shared_ptr<T>& rhs)
    {
        managed_ptr = rhs.managed_ptr;
        count = rhs.count;
        *count = *count + 1;
    }

    template <typename T>
    shared_ptr<T>::shared_ptr(shared_ptr<T>&& rhs)
    {
        managed_ptr = rhs.managed_ptr;
        count = rhs.count;
        rhs.count = nullptr;
        rhs.managed_ptr = nullptr;
    }

    template <typename T>
    shared_ptr<T>::~shared_ptr()
    {
        if (count == nullptr)
        {
            return;
        }
        *count = *count - 1;
        if (*count == 0)
        {
            delete count;
            delete managed_ptr;
        }
    }

    template <typename T>
    shared_ptr<T>& shared_ptr<T>::operator=(const shared_ptr<T>& ptr)
    {
        *count = *count - 1;
        if (*count == 0)
        {
            delete count;
            delete managed_ptr;
        }
        this->managed_ptr = ptr.managed_ptr;
        this->count = ptr.count;
        *count = *count + 1;
        return *this;
    }

    template <typename T>
    shared_ptr<T>& shared_ptr<T>::operator=(shared_ptr<T>&& ptr)
    {
        std::swap(this->managed_ptr, ptr.managed_ptr);
        std::swap(this->count, ptr.count);
        return *this;
    }

    template <typename T>
    T* shared_ptr<T>::operator->()
    {
        return (this->managed_ptr);
    }

    template <typename T>
    int shared_ptr<T>::use_count()
    {
        return *count;
    }

    template <typename T>
    T shared_ptr<T>::operator*()
    {
        return *(this->managed_ptr);
    }

    template <typename T>
    T* shared_ptr<T>::get()
    {
        return managed_ptr;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <typename T>
    class shared_ptr<T[]>
    {
      private:
        T* managed_ptr;
        int* count;
        unsigned int n;

      public:
        shared_ptr(T ptr[], unsigned int N);
        shared_ptr(const T& rhs);
        shared_ptr(const T&& rhs);
        ~shared_ptr();
        shared_ptr<T[]> operator=(const shared_ptr<T[]>& ptr);
        shared_ptr<T[]> operator=(shared_ptr<T[]>&& ptr);
        int use_count();
        T& operator[](unsigned int i);
        unsigned int size();
    };

    template <typename T>
    shared_ptr<T[]>::shared_ptr(T ptr[], unsigned int N) :
        count(new int(1)),
        n(N)
    {
        managed_ptr = ptr;
    }

    template <typename T>
    shared_ptr<T[]>::shared_ptr(const T& rhs)
    {
        managed_ptr = rhs.managed_ptr;
        count = rhs.count;
        n = rhs.n;
        *count = *count + 1;
    }

    template <typename T>
    shared_ptr<T[]>::shared_ptr(const T&& rhs)
    {
        managed_ptr = rhs.managed_ptr;
        count = rhs.count;
        n = rhs.n;

        rhs.count = nullptr;
        rhs.managed_ptr = nullptr;
    }

    template <typename T>
    shared_ptr<T[]>::~shared_ptr()
    {
        if (count == nullptr)
        {
            return;
        }
        *count = *count - 1;
        if (*count == 0)
        {
            delete count;
            delete[] managed_ptr;
        }
    }

    template <typename T>
    shared_ptr<T[]> shared_ptr<T[]>::operator=(const shared_ptr<T[]>& ptr)
    {
        *count = *count - 1;
        if (*count == 0)
        {
            delete count;
            delete[] managed_ptr;
        }
        this->managed_ptr = ptr.managed_ptr;
        this->count = ptr.count;
        this->n = ptr.n;
        *count = *count + 1;
        return ptr;
    }

    template <typename T>
    shared_ptr<T[]> shared_ptr<T[]>::operator=(shared_ptr<T[]>&& ptr)
    {
        auto temp_managed = this->managed_ptr;
        auto temp_count = this->count;
        auto temp_n = this->n;

        this->managed_ptr = ptr.managed_ptr;
        this->count = ptr.count;
        this->n = ptr.n;

        ptr.managed_ptr = temp_managed;
        ptr.count = temp_count;
        ptr.n = temp_n;

        return ptr;
    }

    template <typename T>
    int shared_ptr<T[]>::use_count()
    {
        return *count;
    }

    template <typename T>
    T& shared_ptr<T[]>::operator[](unsigned int i)
    {
        return this->managed_ptr[i];
    }

    template <typename T>
    unsigned int shared_ptr<T[]>::size()
    {
        return this->n;
    }

    template <typename T, typename... Args>
    shared_ptr<T> make_shared(Args&&... args)
    {
        return shared_ptr<T>(new T(std::forward<Args>(args)...));
    }

    template <typename T, unsigned int N>
    shared_ptr<T[]> make_shared_array()
    {
        return shared_ptr<T[]>(new T[N], N);
    }

} // namespace usu

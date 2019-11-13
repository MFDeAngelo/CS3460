namespace usu
{
    template <typename T>
    class shared_ptr
    {
      private:
        T* managed_ptr;
        unsigned int* count;

      public:
        shared_ptr(T* ptr);
        shared_ptr(const T*& rhs);
        shared_ptr(const T*&& rhs);
        ~shared_ptr();
        shared_ptr<T> operator=(const shared_ptr<T>& ptr);
        shared_ptr<T>& operator=(shared_ptr<T>& ptr);
        T* operator->();
        unsigned int use_count();
        T operator*();
        T* get();
    };

    template <typename T>
    shared_ptr<T>::shared_ptr(T* ptr) :
        managed_ptr(ptr),
        count(new unsigned int(0))
    {
    }

    template <typename T>
    shared_ptr<T>::shared_ptr(const T*& rhs)
    {
        rhs.managed_ptr = managed_ptr;
        rhs.count = count;
        *count = *count + 1;
    }

    template <typename T>
    shared_ptr<T>::shared_ptr(const T*&& rhs)
    {
        rhs.managed_ptr = managed_ptr;
        rhs.count = count;
    }

    template <typename T>
    shared_ptr<T>::~shared_ptr()
    {
        if (*count == 0)
        {
            delete count;
            delete managed_ptr;
        }
        else
        {
            *count = *count - 1;
        }
    }

    template <typename T>
    shared_ptr<T> shared_ptr<T>::operator=(const shared_ptr<T>& ptr)
    {
        this->managed_ptr = ptr.managed_ptr;
        this->count = ptr.count;
        *count = *count + 1;
    }

    template <typename T>
    shared_ptr<T>& shared_ptr<T>::operator=(shared_ptr<T>& ptr)
    {
        this->managed_ptr = ptr.managed_ptr;
        this->count = ptr.count;
    }

    template <typename T>
    T* shared_ptr<T>::operator->()
    {
        return (this->managed_ptr);
    }

    template <typename T>
    unsigned int shared_ptr<T>::use_count()
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
        T[] * managed_ptr;
        unsigned int* count;
        unsigned int n;

      public:
        shared_ptr(T ptr[], unsigned int N);
        shared_ptr(const T& rhs);
        shared_ptr(const T&& rhs);
        ~shared_ptr();
        shared_ptr<T[]> operator=(const shared_ptr<T[]> ptr);
        shared_ptr<T[]> operator=(shared_ptr<T[]>&& ptr);
        T operator->();
        unsigned int use_count();
        T operator*();
        T get();
        T& operator[](unsigned int i);
        unsigned int size();
    };

    template <typename T>
    shared_ptr<T[]>::shared_ptr(T ptr[], unsigned int N) :
        count(new unsigned int(0)),
        n(N)
    {
        managed_ptr = ptr;
    }

    template <typename T>
    shared_ptr<T[]>::shared_ptr(const T& rhs)
    {
        rhs.managed_ptr = managed_ptr;
        rhs.count = count;
        rhs.n = n;
        *count = *count + 1;
    }

    template <typename T>
    shared_ptr<T[]>::shared_ptr(const T&& rhs)
    {
        rhs.managed_ptr = managed_ptr;
        rhs.count = count;
        rhs.n = n;
    }

    template <typename T>
    shared_ptr<T[]>::~shared_ptr()
    {
        if (*count == 0)
        {
            delete count;
            delete managed_ptr;
        }
        else
        {
            *count = *count - 1;
        }
    }

    template <typename T>
    shared_ptr<T[]> shared_ptr<T[]>::operator=(const shared_ptr<T[]> ptr)
    {
        this->managed_ptr = ptr.managed_ptr;
        this->count = ptr.count;
        this->n = ptr.n;
        *count = *count + 1;
    }

    template <typename T>
    shared_ptr<T[]> shared_ptr<T[]>::operator=(shared_ptr<T[]>&& ptr)
    {
        this->managed_ptr = ptr.managed_ptr;
        this->count = ptr.count;
        this->n = ptr.n;
    }

    template <typename T>
    T shared_ptr<T[]>::operator->()
    {
        return this->managed_ptr;
    }

    template <typename T>
    unsigned int shared_ptr<T[]>::use_count()
    {
        return *count;
    }

    template <typename T>
    T shared_ptr<T[]>::operator*()
    {
        return this->*managed_ptr;
    }

    template <typename T>
    T shared_ptr<T[]>::get()
    {
        return managed_ptr;
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

/*

Write a templated shared_ptr class, contained with a usu namespace according to the following specifications.

If that isn't enough, make another shared_ptr class for arrays!  A few differences between this class and the previous one.

The type declaration will start like...
template<typename T> class shared_ptr<T[]>
The overloaded constructor accepts two parameters:
Raw pointer to the array.
The number of elements in the array.
The destructor needs to delete an array.
Overload the [] operator for array-like access.
A size method that results the number of elements in the array.

*/
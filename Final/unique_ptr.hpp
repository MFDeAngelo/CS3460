#include <utility>

namespace usu
{
	template<typename T>
	class unique_ptr
    {
      public:
        unique_ptr();
        unique_ptr(T* data);
        ~unique_ptr();
        unique_ptr(unique_ptr<T>&& rhs);
        unique_ptr& operator=(unique_ptr<T>&& rhs);
        
		
		T operator*();
        T* operator->();
        bool operator==(const unique_ptr& rhs);
        bool operator!=(const unique_ptr& rhs);


		T* const get();
        T* release();

		
		unique_ptr(unique_ptr& rhs) = delete;
        unique_ptr& operator=(unique_ptr& rhs) = delete;
        

      private:
        T* data;

    };
	
	template <typename T>
    unique_ptr<T>::unique_ptr() :
        data(nullptr)
    {}

	template <typename T>
    unique_ptr<T>::unique_ptr(T* data) :
        data(data)
    {}


	template <typename T>
    unique_ptr<T>::~unique_ptr()
    {
        if (data)
			delete data;
    }



	template <typename T>
    unique_ptr<T>::unique_ptr(unique_ptr<T>&& rhs)
    {
        data = rhs.data;
        rhs.data = nullptr;
	}


	template <typename T>
	unique_ptr<T>& unique_ptr<T>::operator=(unique_ptr<T>&& rhs) //Double check this!!!
    {
        this->data = rhs.data;
        rhs.data = nullptr;
        return *this;
	}





	///////////////////////////////////////////////////////////////

	template <typename T>
    T unique_ptr<T>::operator*()
    {
        return *data;
    }


	template <typename T>
    T* unique_ptr<T>::operator->()
    {
        return data;
    }

	template <typename T>
	bool unique_ptr<T>::operator==(const unique_ptr& rhs) 
	{
        return this->data == rhs.data;
	}

	template <typename T>
    bool unique_ptr<T>::operator!=(const unique_ptr& rhs)
    {
        return this->data != rhs.data;
    }

	///////////////////////////////////////////////////////////////


	template <typename T>
	T* const unique_ptr<T>::get() {
        return this->data;
	}

	template <typename T>
	T* unique_ptr<T>::release() {
        T* result = this->data;
        this->data = nullptr;
        return result;
	}


	///////////////////////////////////////////////////////////////


	template <typename T, typename... Args>
    unique_ptr<T> make_unique(Args&&... args)
    {
        return unique_ptr<T>(new T(std::forward<Args>(args)...));
    }



}






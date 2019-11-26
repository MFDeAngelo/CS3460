

namespace usu
{
	template <typename T>
    class priority_queue
    {

		using size_type = std::size_t;
		using value_type = T;
    
	public:
        size_type size();
      bool empty();
	
	};

	template <typename T>
    priority_queue<T>::size_type priority_queue<T>::size() //Might need a template here...
    {
        return 0;
	}

	template <typename T>
    bool priority_queue<T>::empty()
    {
        return true;
    }
}
#include <vector>
#include <iterator>

namespace usu
{
	template <typename T>
    class priority_queue
    {

      public:
		using size_type = std::size_t;
		using value_type = T;
		//using pointer = T*;
		using reference = T&;
		using priority_type = std::size_t;

        priority_queue();
        size_type size();
      bool empty();
        void enqueue(value_type element, priority_type priority);
      auto dequeue();


	  struct Item
      {
          value_type value;
          priority_type priority;
          Item(value_type value, priority_type priority) :
              value(value),
              priority(priority) {}
          Item() {}
      };


      class iterator
      {
        public:
          using iterator_category = std::forward_iterator_tag;
          iterator() :
              position(0),
              data(nullptr) {}
          iterator(size_type pos, Item* data) :
              position(pos),
              data(data) {}
          iterator(Item* data) :
              position(0),
              data(data) {}
          iterator(iterator& obj)
          {
              this->position = obj.position;
              this->data = obj.data;
          }

          iterator(iterator&& obj)
          {
              std::swap(obj.data, this->data);
              std::swap(obj.position, this->position);
          }

//          reference operator*() { return data[position]; }

		  iterator operator++();
          iterator operator++(int);

		  
		  bool operator==(const iterator& rhs);
          bool operator!=(const iterator& rhs);


		  
		  Item operator*();
		  //priority_queue<T>::Item operator->();

        private:
          size_type position;
          Item* data;
      };



      iterator begin(); 
	  iterator end();
      iterator find(T value);

	  private: 

		  std::vector<Item> data;
          size_type storageSize;
          size_type count;

		  void heapify(unsigned int index);



	};

	template <typename T>
	priority_queue<T>::priority_queue():
        storageSize(0),
        count(0)
	{
        this->data.resize(0);
	}

	template <typename T>
    typename priority_queue<T>::size_type priority_queue<T>::size() //Might need a template here...
    {
        return count;
	}

	template <typename T>
    bool priority_queue<T>::empty()
    {
        return count == 0;
    }

	template <typename T>
    void priority_queue<T>::enqueue(value_type element, priority_type priority)
    {
        if (storageSize == count)
        {
            storageSize = storageSize * 1.25 + 1;
            data.resize(storageSize);
		}
        Item item(element, priority);
        data[count] = item;
        ++count;
        for (int i = count-1; i > 0; --i)
        {
            if (data[i].priority > data[i - 1].priority)
            {
                std::swap(data[i], data[i  - 1]);
            }
            else
                break;
		}
        heapify(0);
	}

	template <typename T>
	auto priority_queue<T>::dequeue() {
        if (count == 0)
            throw std::exception;
        auto result = data[0];

		for (int i = 1; i < count; i++)
        {
            data[i - 1] = data[i];
		}
		
		--count;
		return result;
	}


	template <typename T>
    typename priority_queue<T>::iterator priority_queue<T>::begin()
    {
        return iterator(data.data());
	}

	template <typename T>
    typename priority_queue<T>::iterator priority_queue<T>::end()
    {
        return iterator(count, data.data());
    }



	template <typename T>
    typename priority_queue<T>::iterator priority_queue<T>::iterator::operator++()
    {
        position++;
        return *this;
	}


	template <typename T>
    typename priority_queue<T>::iterator priority_queue<T>::iterator::operator++(int)
    {
        iterator temp = *this;
        position++;
        return temp;
	}

	template <typename T>
    typename priority_queue<T>::Item priority_queue<T>::iterator::operator*()
    {
        return data[position];
	}


	template <typename T>
	bool priority_queue<T>::iterator::operator==(const iterator& rhs) {
        return this->data == rhs.data && this->position == rhs.position;
	}

	template <typename T>
	bool priority_queue<T>::iterator::operator!=(const iterator& rhs) {
        return !operator==(rhs);
	}

	template <typename T>
    typename priority_queue<T>::iterator priority_queue<T>::find(T value)
    {
        iterator i = iterator(data.data());
        while ((*i).value != value && i != end())
        {
            i++;
		}
        return i;
    }

	template <typename T>
	void priority_queue<T>::heapify(unsigned int index) {
        if (index >= count)
            return;
        if (count > (2 * index) + 1) //Could have a bug here...
        {
            if (data[index].priority < data[(2 * index) + 1].priority)
            {
                std::swap(data[index], data[(2 * index) + 1]);
			}
		}
        if (count > (2 * index) + 2)
        {
            if (data[index].priority < data[(2 * index) + 2].priority)
            {
                std::swap(data[index], data[(2 * index) + 2]);
            }
        }
        heapify((2 * index) + 1);
        heapify((2 * index) + 2);

	}


}


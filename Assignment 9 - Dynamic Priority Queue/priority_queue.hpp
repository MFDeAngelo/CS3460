#include <iterator>
#include <vector>
#include <initializer_list>
#include <utility>

namespace usu
{
    template <typename T, typename R = std::size_t>
    class priority_queue
    {

      public:
        using size_type = std::size_t;
        using value_type = T;
        using reference = T&;
        using priority_type = R;

        struct Item
        {
            value_type value;
            priority_type priority;
            Item(value_type value, priority_type priority) :
                value(value),
                priority(priority) {}
            Item() :
                value(T()),
                priority(0) {}
        };

        priority_queue();
        priority_queue(std::initializer_list<std::pair<T, priority_type>> list);

        size_type size();
        bool empty();
        void enqueue(value_type element, priority_type priority);
        auto dequeue();

        using pointer = std::vector<Item>*;

        class iterator : public std::iterator<std::forward_iterator_tag, priority_queue*>
        {
          public:
            using iterator_category = std::forward_iterator_tag;
            iterator() :
                position(0),
                data(nullptr) {}
            iterator(size_type pos, pointer data) :
                position(pos),
                data(data) {}
            iterator(pointer data) :
                position(0),
                data(data) {}
            iterator(const iterator& obj);
            iterator(iterator&& obj) noexcept;

            iterator& operator=(iterator&& rhs);
            iterator& operator=(const iterator& rhs);

            iterator operator++();
            iterator operator++(int);

            bool operator==(const iterator& rhs);
            bool operator!=(const iterator& rhs);

            Item& operator*();
            Item* operator->();

            size_type position;
            pointer data;
        };

        iterator begin();
        iterator end();
        iterator find(T value);
        void update(iterator i, priority_type priority);

      private:
        std::vector<Item> data;
        size_type storageSize;
        size_type count;

        void heapify();
        void siftDown(size_type pos);
        void update(size_type pos);

        bool isLeaf(size_type pos)
        {
            return (pos >= count / 2) && (pos < count);
        }
		size_type leftchild(size_type pos)
        {
            return 2 * pos + 1;
        }
        size_type rightchild(size_type pos)
        {
            return 2 * pos + 2;
        }
        size_type parent(size_type pos)
        {
            return (pos - 1) / 2;
        }
    };

    template <typename T, typename R>
    priority_queue<T, R>::priority_queue() :
        storageSize(0),
        count(0)
    {
        this->data.resize(0);
    }

	template <typename T, typename R>
    priority_queue<T, R>::priority_queue(std::initializer_list<std::pair<T, priority_type>> list) :
		storageSize(0),
        count(0)
	{
        this->data.resize(0);
        for (std::pair p : list)
        {
            enqueue(p.first, p.second);
		}
	}

    template <typename T, typename R>
    typename priority_queue<T, R>::size_type priority_queue<T, R>::size() //Might need a template here...
    {
        return count;
    }

    template <typename T, typename R>
    bool priority_queue<T, R>::empty()
    {
        return count == 0;
    }

    template <typename T, typename R>
    void priority_queue<T, R>::enqueue(value_type element, priority_type priority)
    {
        if (storageSize == count)
        {
            storageSize = static_cast<size_type>(storageSize * 1.25) + 1;
            data.resize(storageSize);
        }
        Item item(element, priority);
        size_type curr = count++;
        data[curr] = item;

        // Now sift up until curr's parent's key > curr's key
        while ((curr != 0) && (data[curr].priority > data[parent(curr)].priority))
        {
            std::swap(data[curr], data[parent(curr)]);
            curr = parent(curr);
        }
    }

    template <typename T, typename R>
    auto priority_queue<T, R>::dequeue()
    {
        if (count == 0)
            throw std::exception();
        auto result = data[0];

        std::swap(data[0], data[--count]);

        siftDown(0);

        return result;
    }

    template <typename T, typename R>
    typename priority_queue<T, R>::iterator priority_queue<T, R>::begin()
    {
        return iterator(&data);
    }

    template <typename T, typename R>
    typename priority_queue<T, R>::iterator priority_queue<T, R>::end()
    {
        return iterator(count, &data);
    }

    template <typename T, typename R>
    typename priority_queue<T, R>::iterator priority_queue<T, R>::iterator::operator++()
    {
        position++;
        return *this;
    }

    template <typename T, typename R>
    typename priority_queue<T, R>::iterator priority_queue<T, R>::iterator::operator++(int)
    {
        iterator temp = *this;
        position++;
        return temp;
    }

    template <typename T, typename R>
    bool priority_queue<T, R>::iterator::operator==(const iterator& rhs)
    {
        return this->data == rhs.data && this->position == rhs.position;
    }

    template <typename T, typename R>
    bool priority_queue<T, R>::iterator::operator!=(const iterator& rhs)
    {
        return !operator==(rhs);
    }

    template <typename T, typename R>
    typename priority_queue<T, R>::iterator priority_queue<T, R>::find(T value)
    {
        iterator i = iterator(&data);
        while (i != end() && (*i).value != value)
        {
            i++;
        }

        return i;
    }

	template <typename T, typename R>
    void priority_queue<T, R>::update(iterator i, priority_type priority)
    {
        (*i).priority = priority;
        if (i.position != 0)
        {
            if (data[i.position].priority > data[parent(i.position)].priority)
            {
                update(i.position);
            }
		}
        heapify();
	}

    template <typename T, typename R>
    void priority_queue<T, R>::heapify()
    {
        for (size_type i = 0; i < count; i++)
        {
            siftDown(i);
        }
    }

    template <typename T, typename R>
    void priority_queue<T, R>::siftDown(size_type pos)
    {
        if ((pos < 0) || (pos >= count))
            return;
        while (!isLeaf(pos))
        {
            size_type j = leftchild(pos);
            if (j < (count - 1) && (data[j].priority < data[j + 1].priority))
                j++; // j is now index of child with greater value
            if (data[pos].priority >= data[j].priority)
                return;
            std::swap(data[pos], data[j]);
            pos = j; // Move down
        }
    }
    
    template <typename T, typename R>
    void priority_queue<T, R>::update(size_type pos)
    {
        // If it is a big value, push it up
        while ((pos > 0) && (data[pos].priority > data[parent(pos)].priority))
        {
            std::swap(data[pos], data[parent(pos)]);
            pos = parent(pos);
        }
        siftDown(pos); // If it is little, push down
    }

    template <typename T, typename R>
    typename priority_queue<T, R>::Item* priority_queue<T, R>::iterator::operator->()
    {
        return &((*data)[position]);
    }

    template <typename T, typename R>
    typename priority_queue<T, R>::Item& priority_queue<T, R>::iterator::operator*()
    {
        return (*data)[position];
    }

    template <typename T, typename R>
    priority_queue<T, R>::iterator::iterator(const iterator& obj)
    {
        this->position = obj.position;
        this->data = obj.data;
    }
    
	template <typename T, typename R>
    priority_queue<T, R>::iterator::iterator(iterator&& obj) noexcept
    {
        this->position = obj.position;
        this->data = obj.data;
        obj.position = 0;
        obj.data = nullptr;
    }
    
	template <typename T, typename R>
    typename priority_queue<T, R>::iterator& priority_queue<T, R>::iterator::operator=(const iterator& rhs)
    {
        this->position = rhs.position;
        this->data = rhs.data;
        return *this;
    }
    
	template <typename T, typename R>
    typename priority_queue<T, R>::iterator& priority_queue<T, R>::iterator::operator=(iterator&& rhs)
    {
        if (this != &rhs)
        {
            std::swap(this->position, rhs.position);
            std::swap(this->data, rhs.data);
        }
        return *this;
    }

} // namespace usu

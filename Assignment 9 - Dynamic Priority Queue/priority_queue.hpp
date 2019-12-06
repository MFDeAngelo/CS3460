#include <iterator>
#include <vector>

namespace usu
{
    template <typename T>
    class priority_queue
    {

      public:
        using size_type = std::size_t;
        using value_type = T;
        using reference = T&;
        using priority_type = std::size_t;

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
        size_type size();
        bool empty();
        void enqueue(value_type element, priority_type priority);
        auto dequeue();

        void heapify();
        void siftDown(size_type pos);
        void update(size_type pos);

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

            Item operator*();
            Item* operator->();

          private:
            size_type position;
            pointer data;
        };

        iterator begin();
        iterator end();
        iterator find(T value);

      private:
        std::vector<Item> data;
        size_type storageSize;
        size_type count;

        // Return true if pos a leaf position, false otherwise
        bool isLeaf(int pos)
        {
            return (pos >= count / 2) && (pos < count);
        }

        // Return position for left child of pos
        size_type leftchild(size_type pos)
        {
            if (pos >= count / 2)
                return -1;
            return 2 * pos + 1;
        }

        // Return position for right child of pos
        size_type rightchild(size_type pos)
        {
            if (pos >= (count - 1) / 2)
                return -1;
            return 2 * pos + 2;
        }

        // Return position for parent
        size_type parent(size_type pos)
        {
            //      if (pos <= 0)
            //        return -1;
            return (pos - 1) / 2;
        }
    };

    template <typename T>
    priority_queue<T>::priority_queue() :
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

    template <typename T>
    auto priority_queue<T>::dequeue()
    {
        if (count == 0)
            throw std::exception;
        auto result = data[0];

        std::swap(data[0], data[--count;]);

        siftDown(0)

            return result;
    }

    template <typename T>
    typename priority_queue<T>::iterator priority_queue<T>::begin()
    {
        return iterator(&data);
    }

    template <typename T>
    typename priority_queue<T>::iterator priority_queue<T>::end()
    {
        return iterator(count, &data);
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
    bool priority_queue<T>::iterator::operator==(const iterator& rhs)
    {
        return this->data == rhs.data && this->position == rhs.position;
    }

    template <typename T>
    bool priority_queue<T>::iterator::operator!=(const iterator& rhs)
    {
        return !operator==(rhs);
    }

    template <typename T>
    typename priority_queue<T>::iterator priority_queue<T>::find(T value)
    {
        iterator i = iterator(&data);
        while ((*i).value != value && i != end())
        {
            i++;
        }
        return i;
    }

    template <typename T>
    void priority_queue<T>::heapify()
    {

        for (int i = 0; i < count; i++)
        {
            siftDown(i);
        }

        /*
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
		*/
    }

    template <typename T>
    void priority_queue<T>::siftDown(size_type pos)
    {
        if ((pos < 0) || (pos >= count))
            return; // Illegal position
        while (!isLeaf(pos))
        {
            int j = leftchild(pos);
            if (j < (count - 1) && (data[j].priority < data[j + 1].priority))
                j++; // j is now index of child with greater value
            if (data[pos].priority >= data[pos].priority)
                return;
            std::swap(data[pos], data[j]);
            pos = j; // Move down
        }
    }
    
    template <typename T>
    void priority_queue<T>::update(size_type pos)
    {
        // If it is a big value, push it up
        while ((pos > 0) && (data[pos].priority > data[parent(pos)].priority > 0))
        {
            std::swap(data[pos], data[parent(pos)]);
            pos = parent(pos);
        }
        siftDown(pos); // If it is little, push down
    }

    template <typename T>
    typename priority_queue<T>::Item* priority_queue<T>::iterator::operator->()
    {
        return &((*data)[position]);
    }

    template <typename T>
    typename priority_queue<T>::Item priority_queue<T>::iterator::operator*()
    {
        return (*data)[position];
    }

    template <typename T>
    priority_queue<T>::iterator::iterator(const iterator& obj)
    {
        this->position = obj.position;
        this->data = obj.data;
    }
    template <typename T>
    priority_queue<T>::iterator::iterator(iterator&& obj) noexcept
    {
        this->position = obj.position;
        this->data = obj.data;
        obj.position = 0;
        obj.data = nullptr;
    }

    template <typename T>
    typename priority_queue<T>::iterator& priority_queue<T>::iterator::operator=(const iterator& rhs)
    {
        this->position = rhs.position;
        this->data = rhs.data;
        return *this;
    }
    template <typename T>
    typename priority_queue<T>::iterator& priority_queue<T>::iterator::operator=(iterator&& rhs)
    {
        if (this != &rhs)
        {
            std::swap(this->position, rhs.position);
            std::swap(this->data, rhs.data);
        }
        return *this;
    }

} // namespace usu

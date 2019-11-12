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
      shared_ptr(const T*& ptr);
			
	
	};

	template <typename T>
    shared_ptr<T>::shared_ptr(T* ptr):
		managed_ptr(ptr),
        count(new count(0))
    {
    }


	
	template <typename T>
    shared_ptr<T>::shared_ptr(const T*& rhs)
    {
        rhs.managed_ptr = managed_ptr;
        rhs.count = count;
        *count = *count + 1;
	  }



}

/*

Write a templated shared_ptr class, contained with a usu namespace according to the following specifications.

Constructors
Copy constructor : Make a copy of the shared_ptr and increments the reference count.
Move constructor : Moves the shared_ptr, does not increment the reference count.
Destructor : decrements the reference count.  If the reference count goes to 0, cleans up an allocated memory.
Operators
assignment operator : Copies the shared_ptr into the destination, increments the reference count.
move assignment operator : Moves the shared_ptr into the destination, does not increment the reference count.
pointer operator (->) : Returns a pointer to the managed raw pointer.
dereference operator (*) : Dereferences the managed raw pointer, returning the value at the memory location.
Other methods
get : Returns a pointer to the managed pointer.
use_count : Returns the reference count.
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
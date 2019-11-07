#include <ratio>

namespace usu
{
    template <typename ratio, typename ct = uint64_t>
    class weight
    {
      private:
        ct count;

      public:
		  weight(ct count) {
              this->count = count;
		}
		  weight() {
              this->count = 0;
          } /*
		  ct count() {
              return count;
		  } */


    };

	template <typename ratio, typename ct = uint64_t>
	weight<ratio, ct> operator*(weight<ratio, ct> w, ct scalar) {
        w.count = w.count * scalar;
	}

	template <typename ratio, typename ct = uint64_t>
    weight<ratio, ct> operator*(ct scalar, weight<ratio, ct> w)
    {
        w.count = w.count * scalar;
    }

} // namespace usu


/*

Overload the + operator to add two items of the same type.
Overload the - operator to subtract two items of the same type.
Overload the * operator to multiply the type by a scalar (integral or floating point).
These will be defined external to the class; not members of the class.
You'll need two overloads to do this, one for each position the scalar and weight type can occur;  A scalar times a weight and a weight times a scalar.
Write a templated weight_cast function (not a member of the weight class) that converts from one weight type to another.  This function is patterned after the std::chrono::duration_cast function.  This function accepts a single template parameter that is the type to convert to, whereas the function parameter is the weight variable to convert from.

Define type aliases inside the usu namespace, in your weight.hpp file for:

microgram
gram
kilogram
ounce
pound
ton


*/
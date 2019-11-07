#include <ratio>

namespace usu
{
    template <typename ratio, typename ct = uint64_t>
    class weight
    {
      private:
        ct countSize;

      public:
		  weight(ct count) {this->countSize = count;}
		  weight() {this->countSize = 0;} 
		  ct count() {return this->countSize;} 


    };

	template <typename ratio, typename ct = uint64_t>
    weight<ratio, ct> operator+(weight<ratio, ct> w1, weight<ratio, ct> w2)
    {
        weight<ratio, ct> result();
        result.countSize = w1.countSize * w2.countSize;
        return result;
    }

	template <typename ratio, typename ct = uint64_t>
    weight<ratio, ct> operator-(weight<ratio, ct> w1, weight<ratio, ct> w2)
    {
        weight<ratio, ct> result();
        result.countSize = w1.countSize - w2.countSize;
        return result;
    }

	template <typename ratio, typename ct = uint64_t>
	weight<ratio, ct> operator*(weight<ratio, ct> w, float scalar) {
        weight<ratio, ct> result();
        result.countSize = w.countSize * scalar;
        return result;
	}

	template <typename ratio, typename ct = uint64_t>
    weight<ratio, ct> operator*(float scalar, weight<ratio, ct> w)
    {
        weight<ratio, ct> result();
        result.countSize = w.countSize * scalar;
        return result;
    }


	
	template <typename weightType>
    weightType weight_cast( w)
    {

	}


	using microgram = weight<std::ratio<1,1000000>, uint64_t>;
    using gram = weight<std::ratio<1, 1>, uint64_t>;
    using pound = weight<std::ratio<453592, 1000>, uint64_t>;
    using ounce = weight<std::ratio<2835, 100>, uint64_t>;
    using ton = weight<std::ratio<1102, 1000000000>, uint64_t>;




} // namespace usu


/*

Overload the + operator to add two items of the same type.
Overload the - operator to subtract two items of the same type.
Overload the * operator to multiply the type by a scalar (integral or floating point).
These will be defined external to the class; not members of the class.
You'll need two overloads to do this, one for each position the scalar and weight type can occur;  A scalar times a weight and a weight times a scalar.
Write a templated weight_cast function (not a member of the weight class) that converts from one weight type to another.  This function is patterned after the std::chrono::duration_cast function.  This function accepts a single template parameter that is the type to convert to, whereas the function parameter is the weight variable to convert from.




*/
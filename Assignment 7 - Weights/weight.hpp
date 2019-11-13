#include <ratio>

namespace usu
{
    template <typename ratio, typename ct = uint64_t>
    class weight
    {
      private:
        ct countSize;

      public:
        weight(ct count) { this->countSize = count; }
        weight() { this->countSize = 0; }
        ct count() { return this->countSize; }
        using Ratio = ratio;
        using Ct = ct;
    };

    template <typename ratio, typename ct = uint64_t>
    weight<ratio, ct> operator+(weight<ratio, ct> w1, weight<ratio, ct> w2)
    {
        weight<ratio, ct> result(w1.count() + w2.count());
        return result;
    }

    template <typename ratio, typename ct = uint64_t>
    weight<ratio, ct> operator-(weight<ratio, ct> w1, weight<ratio, ct> w2)
    {
        weight<ratio, ct> result(w1.count() - w2.count());
        return result;
    }

    template <typename ratio, typename ct = uint64_t>
    weight<ratio, ct> operator*(weight<ratio, ct> w, double scalar)
    {
        weight<ratio, ct> result(w.count() * static_cast<ct>(scalar));
        return result;
    }

    template <typename ratio, typename ct = uint64_t>
    weight<ratio, ct> operator*(double scalar, weight<ratio, ct> w)
    {
        weight<ratio, ct> result(w.count() * static_cast<ct>(scalar));
        return result;
    }

    template <typename newWeight, typename oldWeight>
    newWeight weight_cast(oldWeight w)
    {
        newWeight result(static_cast<typename newWeight::Ct>(w.count() * static_cast<double>(oldWeight::Ratio::num) * static_cast<double>(newWeight::Ratio::den) / static_cast<double>(oldWeight::Ratio::den) / static_cast<double>(newWeight::Ratio::num)));
        return result;
    }

    using microgram = weight<std::ratio<1, 1000000>, uint64_t>;
    using gram = weight<std::ratio<1, 1>, uint64_t>;
    using pound = weight<std::ratio<453592, 1000>, double>;
    using ounce = weight<std::ratio<2835, 100>, double>;
    using ton = weight<std::ratio<907185, 1>, double>;

} // namespace usu
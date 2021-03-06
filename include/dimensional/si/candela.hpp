#pragma once
#include "../units.hpp"
#include "../quotient.hpp"
namespace mitama::si {
struct luminous_intensity {
    using is_base_dimension = void;
};

using candela_t = make_unit_t<luminous_intensity>;

inline constexpr candela_t candelas{};

template < std::intmax_t N = 1 > inline constexpr powered_t<candela_t, N> candela{};

}
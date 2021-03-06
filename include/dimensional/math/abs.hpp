#ifndef MITAMA_DIMENSIONAL_MATH_ABS_HPP
#define MITAMA_DIMENSIONAL_MATH_ABS_HPP

#include <cmath>
#include "../quantity.hpp"

namespace mitama {

template < class T, class... Units >
auto abs(quantity_t<dimensional_t<Units...>, T> const& quantity) {
    return std::decay_t<decltype(quantity)>{ std::abs(quantity.get()) };
}

}

#endif
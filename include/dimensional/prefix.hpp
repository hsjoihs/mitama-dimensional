#ifndef MITAMA_DIMENSIONAL_PREFIX_HPP
#define MITAMA_DIMENSIONAL_PREFIX_HPP
#include "mitamagic/utility.hpp"
#include "dimensional_phantom.hpp"
#include "units.hpp"
namespace mitama {
template <
    class Rational, class Unit,
    std::enable_if_t<mitamagic::is_rational_v<Rational> && is_units_v<Unit>,
                     bool> = false>
constexpr auto operator*(Rational, dimensional_t<Unit>) {
  return scaled_unit_t<dimensional_t<Unit>, Rational>{};
}

inline constexpr auto pico = std::pico{};
inline constexpr auto nano = std::nano{};
inline constexpr auto micro = std::micro{};
inline constexpr auto milli = std::milli{};
inline constexpr auto centi = std::centi{};
inline constexpr auto deci = std::deci{};
inline constexpr auto deca = std::deca{};
inline constexpr auto hecto = std::hecto{};
inline constexpr auto kilo = std::kilo{};
inline constexpr auto mega = std::mega{};
inline constexpr auto giga = std::giga{};
inline constexpr auto tera = std::tera{};

} // namespace mitama

#endif
#ifndef MITAMA_DIMENSIONAL_REFINEMENT_HPP
#define MITAMA_DIMENSIONAL_REFINEMENT_HPP
#include "quantity.hpp"
#include "si/all.hpp"
namespace mitama {

namespace sym {
class refinement_symbol_tag {};

template <std::intmax_t N = 1> struct L : private refinement_symbol_tag {
  using basis = ::mitama::length;
  using exp = std::ratio<N>;
};
template <std::intmax_t N = 1> struct M : private refinement_symbol_tag {
  using basis = ::mitama::mass;
  using exp = std::ratio<N>;
};
template <std::intmax_t N = 1> struct T : private refinement_symbol_tag {
  using basis = ::mitama::time;
  using exp = std::ratio<N>;
};
template <std::intmax_t N = 1> struct I : private refinement_symbol_tag {
  using basis = ::mitama::electric_current;
  using exp = std::ratio<N>;
};
template <std::intmax_t N = 1> struct S : private refinement_symbol_tag {
  using basis = ::mitama::thermodynamic_temperature;
  using exp = std::ratio<N>;
};
template <std::intmax_t E = 1> struct N : private refinement_symbol_tag {
  using basis = ::mitama::amount_of_substance;
  using exp = std::ratio<E>;
};
template <std::intmax_t N = 1> struct J : private refinement_symbol_tag {
  using basis = ::mitama::luminous_intensity;
  using exp = std::ratio<N>;
};

template <class T>
using is_refinement_symbol = std::is_base_of<refinement_symbol_tag, T>;
template <class T>
inline constexpr bool is_refinement_symbol_v = is_refinement_symbol<T>::value;

} // namespace sym

template <class = void, class...> struct refinement_type;

template <class... Symbols>
struct refinement_type<
    std::enable_if_t<(sym::is_refinement_symbol_v<Symbols> && ...)>,
    Symbols...> {
  template <class Q,
            std::enable_if_t<
                is_same_dimensional_v<
                    std::decay_t<Q>,
                    quantity<make_dimensional_t<units_t<
                        typename Symbols::basis, typename Symbols::exp>...>>>,
                bool> = false>
  decltype(auto) operator()(Q &&q) const {
    return std::forward<Q>(q);
  }

  template <class Q,
            std::enable_if_t<
                !is_same_dimensional_v<
                    std::decay_t<Q>,
                    quantity<make_dimensional_t<units_t<
                        typename Symbols::basis, typename Symbols::exp>...>>>,
                bool> = false>
  decltype(auto) operator()(Q &&q) const = delete;

  template <class Q,
            std::enable_if_t<
                is_same_dimensional_v<
                    std::decay_t<Q>,
                    quantity<make_dimensional_t<units_t<
                        typename Symbols::basis, typename Symbols::exp>...>>>,
                bool> = false>
  decltype(auto) operator|=(Q &&q) const {
    return std::forward<Q>(q);
  }

  template <class Q,
            std::enable_if_t<
                !is_same_dimensional_v<
                    std::decay_t<Q>,
                    quantity<make_dimensional_t<units_t<
                        typename Symbols::basis, typename Symbols::exp>...>>>,
                bool> = false>
  decltype(auto) operator|=(Q &&q) const = delete;
};

template <template <class...> class Requires, class... Symbols>
struct refinement_type<
    std::enable_if_t<(sym::is_refinement_symbol_v<Symbols> && ...)>,
    Requires<Symbols...>> {
  template <class Q,
            std::enable_if_t<
                is_same_dimensional_v<
                    std::decay_t<Q>,
                    quantity<make_dimensional_t<units_t<
                        typename Symbols::basis, typename Symbols::exp>...>>>,
                bool> = false>
  decltype(auto) operator()(Q &&q) const {
    return std::forward<Q>(q);
  }

  template <class Q,
            std::enable_if_t<
                !is_same_dimensional_v<
                    std::decay_t<Q>,
                    quantity<make_dimensional_t<units_t<
                        typename Symbols::basis, typename Symbols::exp>...>>>,
                bool> = false>
  decltype(auto) operator()(Q &&q) const = delete;

  template <class Q,
            std::enable_if_t<
                is_same_dimensional_v<
                    std::decay_t<Q>,
                    quantity<make_dimensional_t<units_t<
                        typename Symbols::basis, typename Symbols::exp>...>>>,
                bool> = false>
  decltype(auto) operator|=(Q &&q) const {
    return std::forward<Q>(q);
  }

  template <class Q,
            std::enable_if_t<
                !is_same_dimensional_v<
                    std::decay_t<Q>,
                    quantity<make_dimensional_t<units_t<
                        typename Symbols::basis, typename Symbols::exp>...>>>,
                bool> = false>
  decltype(auto) operator|=(Q &&q) const = delete;
};

template <class... Requires>
inline constexpr refinement_type<void, Requires...> refined{};
} // namespace mitama

namespace mitama {
using length_r = mitamagic::type_list<sym::L<1>>;
using mass_r = mitamagic::type_list<sym::M<1>>;
using time_r = mitamagic::type_list<sym::T<1>>;
using current_r = mitamagic::type_list<sym::I<1>>;
using thermo_r = mitamagic::type_list<sym::S<1>>;
using amount_r = mitamagic::type_list<sym::N<1>>;
using luminous_r = mitamagic::type_list<sym::J<1>>;

using area_r = mitamagic::type_list<sym::L<2>>;
using volume_r = mitamagic::type_list<sym::L<3>>;
} // namespace mitama

#endif
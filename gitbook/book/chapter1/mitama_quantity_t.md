## mitama::quantity_t

Defined in header [`<dimensional/quantity.hpp>`]()

`Quantity_t <Units, T>` is a class that represents a quantity, the value is represented by `T`, and the unit is` Units`.

**definition**

```cpp
namespace mitama {
    template <
        class Units, // phantom type
        class T = double // underlying type
    >
    class quantity_t;

    template < class Units, class T = double >
    using quantity = quantity_t<Units, T>;
}
```


{% hint style='info' %}
If the second template argument is omitted, it will be of type `double`.
{% endhint %}


**example**

```cpp
// begin example
#include <dimensional/quantity.hpp>
#include <dimensional/si/all.hpp>

int main() {
    namespace si = mitama::si;
    using mitama::quantity_t;

    quantity_t<si::meter_t, int> len1 = 1; // 1 [m]
    quantity_t<si::meter_t, double> len2 = 1.45; // 1.45 [m]
}
// end example
```



### dimensional quantifiers
-----

Dimensional quantifiers are defined as constexpr variables.

**dimensional quantifiers example**

### pipe operator overload for dimensional quantifiers

Pipe operators are provided to attach units to values.

It is allowed to convert values into quantities by piping values to dimensional quantifiers.

**example**

```cpp
// begin example
#include <dimensional/quantity.hpp>
#include <dimensional/si/all.hpp>

int main() {
    namespace si = mitama::si;
    using mitama::quantity_t;

    // Template argument deduction for class templates
    quantity_t mass = 3 | si::kilograms; // 1 [kg]
    quantity_t time = 1.66 | si::seconds; // 1.66 [s]
}
// end example
```

### conversions

Conversion between different units is perform automatically.
Conversion between units with different dimensions will result in compilation errors.

```cpp
// begin example
#include <dimensional/quantity.hpp>
#include <dimensional/si/all.hpp>

int main() {
    namespace si = mitama::si;
    using mitama::quantity_t;

    quantity_t a = 3 | si::kilograms;
    quantity_t<si::gram_t, int> b = a; // 3000 [g]
    // quantity_t<si::meter_t, int> b = a; // compile error!
}
// end example
```

### arithmetic operators

arithmetic operators listed bellow are defined:

- Additions and subtractions between quantity_t with the same dimensions, and
- Multiplication and division between all quantity_t, and
- multiplication and division of all quantity_t and non-quantity values(for coefficient).


```cpp
// begin example
#include <dimensional/quantity.hpp>
#include <dimensional/arithmetic.hpp>
#include <dimensional/si/all.hpp>

int main() {
    namespace si = mitama::si;
    using mitama::quantity_t;

    quantity_t a = 4 | si::kilograms;
    quantity_t b = 2 | si::kilograms;

    a + b; // 6 [kg]
    a - b; // 2 [kg]
    a * b; // 8 [kg]
    a / b; // 2 [kg]
    2 * b; // 8 [kg]
    b / 2; // 1 [kg]
}
// end example
```
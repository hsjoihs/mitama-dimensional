## Basic Concepts
-------

### Type System of Quantity

Dimensional quantity is designed as `quantity_t` that is a class that represents a dimensional quantity based on `ValueType` that is distinguished by a phantom type of `dimensional_t<Units...>`:

```cpp
template < class ValueType, class... Units >
class quantity_t<dimensional_t<Units...>, ValueType>
```

And each type of `Units...` is designed as `units_t`:

```cpp
template < class BaseDimension, // base dimension tag class
           class Exponent,      // std::ratio
           class Scale          // std::ratio
>
class units_t<BaseDimension, Exponent, Scale>
```

### Tracking units in types

**（執筆中）**
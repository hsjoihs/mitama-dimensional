## Basic Concepts

### Representation of Unit
----------------------------

Basic unit of a dimension $$\lambda$$ with exponent is represented as a pair of exponent $$e$$ and scale $$s$$:

$$
U_\lambda := (e, s)_{\lambda}
$$

This corresponds to `units_t` in Mitama.Dimensional.

### Representation of Derived Unit
----------------------------

Let $$\Lambda$$ is a set of basic dimensions of Derived Unit, derived units is represented as a sets of Unit over $$\Lambda$$:

$$
D_\Lambda := {\{U_\lambda\}}_{\lambda \in \Lambda}
$$

This corresponds to `dimensional_t` in Mitama.Dimensional.


### Type System of Quantity
----------------------------

Dimensional quantity is designed as `quantity_t` that is a class that represents a dimensional quantity based on `ValueType` that is distinguished by a phantom type `dimensional_t<Units...>`:

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

### Tracking units and conversion factors in types
----------------------------

Let value $$a$$ has derived unit $$D_\Lambda$$ as:

$$
a: D_\Lambda
$$

then

**$$(a:A_\Lambda) \pm (b:B_\Lambda)$$**

$$
= a \pm b:{\{ ( e, min(s_a, s_b) )_{\lambda} \ | \ (e_a, s_a)_{\lambda} \in A_\Lambda, (e_b, s_b)_{\lambda} \in B_\Lambda \}}_{\lambda \in \Lambda}
$$

$$min (s_a, s_b)$$ means it is automatically converted to a high precision factor.


```cpp
// `a` = 1 mm
quantity_t<millimetre_t> a = 1;
// `b`  = 1 m
quantity_t<metre_t> b = 1;

// a + b will be millimetre
a + b; // 1001 mm
```

**$$(a:A_{\Gamma}) \times (b:B_{\Lambda})$$**

$$
= a \times b: {\{ ( e_a + e_b, min(s_a, s_b) )_{\sigma} \ | \ (e_a, s_a)_{\sigma} \in A_\sigma, (e_b, s_b)_{\sigma} \in B_\sigma \}}_{\sigma \in \Gamma \cap \Lambda  }
$$
$$
\cup {\{ (e_a, s_a)_{\gamma} \ | \ (e_a, s_a)_{\gamma} \in A_\gamma\}}_{\gamma \in \Gamma \backslash \Lambda  }
$$
$$
\cup {\{ (e_b, s_b)_{\lambda} \ | \ (e_b, s_b)_{\lambda} \in B_\lambda\}}_{\lambda \in \Lambda \backslash \Gamma  }
$$

It is automatically converted to a high precision factor, too.

**Unit multiplication example**

$$
[m^2 \cdot s^{-1}] \times [kg \cdot s^{-1}]
$$

Consider simple dual loop:

Let 
$$
U_1 = (e_1, s_1)_\lambda
$$
$$
U_2 = (e_2, s_2)_\lambda
$$

and

$$
mul(U_1, U_2) = (e_1 + e_2, min(s_1, s_2))_\lambda
$$

1. Pick a `unit_t` **A** from left.
2. If there is a right for **B** with the same dimensions as **A**, push If there is a right for **B** with the same dimensions as **A**, push $$mul(A, B)$$ result and pop **A** and **B**, else push **A** to result and pop **A**.
3. If left does not empty, return to 1, else push the rest of right to result

start with empty result.

$$
left = [m^2 \cdot s^{-1}]
$$
$$
right = [kg \cdot s^{-1}]
$$
$$
result = [\ ]
$$

pick $$A=m^2$$, and not found B.
$$
left = [s^{-1}]
$$
$$
right = [kg \cdot s^{-1}]
$$
$$
result = [m^2]
$$

pick $$A=s^{-1}$$, found $$B=s^{-1}$$.
$$
left = [\ ]
$$
$$
right = [kg]
$$
$$
result = [m^2 \cdot s^{-2}]
$$

push the rest of right to result
$$
left = [\ ]
$$
$$
right = [\ ]
$$
$$
result = [m^2 \cdot s^{-2} \cdot kg]
$$

-- end example

**$$(a:A_{\Gamma}) \div (b:B_{\Lambda})$$**

define

$$
{D_\Lambda}^{-1} := {\{ (-e, s)_{\lambda} \ | \ (e, s)_{\lambda} \in D_\Lambda \}}_{\lambda \in \Lambda}
$$

and 

$$
(a:A_{\Gamma}) \div (b:B_{\Lambda}) := (a:A_{\Gamma}) \times (b^{-1}:{B_{\Lambda}}^{-1})$$

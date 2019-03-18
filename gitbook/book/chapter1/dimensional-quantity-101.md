## Dimensional Quantity 101

### Unit systems

There are three basic unit systems in use today:

- the International System of Units (SI units, from Le Systeme International d’Unites, more commonly simply called metric units)
- the English Engineering System of Units (commonly called English units)
- the British Gravitational System of Units (BG)

This library only suports SI units by library default.


### Base units and dimensions

Base units have the important property that all other units derive from them.
In the SI system, there are seven such base units and corresponding physical quantities:

- meter (m) for length,
- kilogram (kg) for mass,
- second (s) for time,
- kelvin (K) for temperature,
- ampere (A) for electric current,
- candela (cd) for luminous intensity, and
- mole (mol) for the amount of substance.

We need some suitable mathematical notation to calculate with dimensions like length, mass, time, and so forth.
The dimension of length is written as [ $$L$$ ], the dimension of mass as [ $$M$$ ]  and the dimension of time as [ $$T$$ ].
The dimension of a derived unit like velocity, which is distance (length) divided by time, then becomes [ $$LT^{-1}$$ ] in this notation. The dimension of force, another derived unit, is the same as the dimension of mass times acceleration, and hence the dimension of force is [ $$MLT^{-2}$$ ].

### Dimensions of common physical quantities
Many derived quantities are measured in derived units that have their own name. Force is one example: Newton (N) is a derived unit for force, equal to $$kg \cdot m \cdot s^{-2}$$.
Another derived unit is Pascal (Pa) for pressure, i.e., force per area.
The unit of Pa then equals $$N/m^2$$ or $$kg \cdot m^{-1} \cdot s^{-2}$$.

Below are more names for derived quantities, listed with their units.

|  Name  | Symbol | Physical quantity  |            Unit             |
| :----: | :----: | :----------------: | :-------------------------: |
| radian |  rad   |       angle        |            $$1$$            |
| hertz  |   Hz   |     frequency      |         $$s^{-1}$$          |
| newton |   N    |   force, weight    | $$kg \cdot m \cdot s^{-2}$$ |
| pascal |   Pa   |  pressure, stress  |          $$N/m^2$$          |
| joule  |   J    | energy, work, heat |       $$N \times m$$        |
|  watt  |   W    |       power        |           $$J/s$$           |

Some common physical quantities and their dimensions are listed next.

|        Quantity        |                   Relation                   |               Unit               |           Dimension           |
| :--------------------: | :------------------------------------------: | :------------------------------: | :---------------------------: |
|        pressure        |                  force/area                  |      $$N \cdot m^{-2}=Pa$$       |     [ $$MT^{-2}L^{-1}$$ ]     |
|        density         |                 mass/volume                  |       $$kg \cdot m^{-3}$$        |        [ $$ML^{-3}$$ ]        |
|         strain         |             displacement/length              |              $$1$$               |           [ $$1$$ ]           |
|    Young's modulus     |                stress/strain                 |      $$N \cdot m^{-2}=Pa$$       |     [ $$MT^{-2}L^{-1}$$ ]     |
|    Poisson's ratio     |        transverse strain/axial strain        |              $$1$$               |           [ $$1$$ ]           |
|   moment (of force)    |          distance $$\times$$ force           |          $$N \cdot m$$           |      [ $$ML^2T^{-2}$$ ]       |
|        impulse         |            force $$\times$$ time             |          $$N \cdot s$$           |       [ $$MLT^{-1}$$ ]        |
|    linear momentum     |           mass $$\times$$ velocity           |      $$kg m \cdot s^{-1}$$       |       [ $$MLT^{-1}$$ ]        |
|    angular momentum    | distance $$\times$$ mass $$\times$$ velocity |  $$kg \cdot m^2 \cdot s^{-1}$$   |      [ $$ML^2T^{-1}$$ ]       |
|          work          |          force $$\times$$ distance           |         $$N \cdot m=J$$          |      [ $$ML^2T^{-2}$$ ]       |
|         energy         |                     work                     |         $$N \cdot m=J$$          |      [ $$ML^2T^{-2}$$ ]       |
|         power          |                  work/time                   |   $$N \cdot m \cdot s^{-1}=W$$   |      [ $$ML^2T^{-3}$$ ]       |
|          heat          |                     work                     |              $$J$$               |      [ $$ML^2T^{-2}$$ ]       |
|       heat flux        |                heat rate/area                |        $$W \cdot m^{-2}$$        |        [ $$MT^{-3}$$ ]        |
|      temperature       |                  base unit                   |              $$K$$               |       [ $$ \Theta $$ ]        |
|     heat capacity      |                 heat change                  |             $$J/K$$              | [ $$ML^2T^{-2}\Theta^{-1}$$ ] |
| specific heat capacity |           heat capacity/unit mass            | $$J \cdot K^{-1} \cdot kg^{-1}$$ | [ $$L^2T^{-2}\Theta^{-1}$$ ]  |
|  thermal conductivity  |        heat flux/temperature gradient        | $$W \cdot m^{-1} \cdot K^{-1}$$  |  [ $$MLT^{-3}\Theta^{-1}$$ ]  |
|   dynamic viscosity    |        shear stress/velocity gradient        | $$kg \cdot m^{-1} \cdot s^{-1}$$ |     [ $$ML^{-1}T^{-1}$$ ]     |
|  kinematic viscosity   |          dynamic viscosity/density           |            $$m^2/s$$             |       [ $$L^2T^{-1}$$ ]       |
|    surface tension     |                 energy/area                  |        $$J \cdot s^{-2}$$        |        [ $$MT^{-2}$$ ]        |

### Conversion Factors


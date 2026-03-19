# Functions

- `deriv` - simply compute the 0-st derivative of a function `f`
- `derivn` - compute the n-th derivative of a function `f` using Pascal's triagle

---

# Things you might wanna edit

## [`deriv.h`](./inc/deriv.h)

- `DerivFloat` if you don't need a lot of precision

## [`deriv.c`](./src/deriv.c)

- `DerivUInt` if you don't need to find a really high-order derivative
- `REFERENCE_EPS` is quite good by default but changing it may improve accuracy for some functions

#pragma once

typedef long double DerivFloat;

// Calculate the first derivative of the function
DerivFloat deriv(DerivFloat (*f)(DerivFloat), const DerivFloat x);

// Calculate the n-th derivative of the function
DerivFloat derivn(DerivFloat (*f)(DerivFloat), const DerivFloat x, const size_t n);

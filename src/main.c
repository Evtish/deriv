#include <stdio.h>
#include <math.h>

#include "deriv.h"

#ifndef M_PIl
#define M_PIl 3.141592653589793238462643383279502884l
#endif

#define ARG_PR	"3"		// Argument precision
#define ARG_WDH	"9"		// Argument column width

#define VAL_PR	"20"	// Value precision
#define VAL_WDH	"26"	// Value column width

#define DERIV_ORDER 2

// Example function
DerivFloat f(const DerivFloat x) {
	return sinl(log10l(powl(logl(x), M_PIl) * powl(M_PIl, x)));
}

int main(void) {
	for (DerivFloat x = 2.0l; x < 15.0l; x += 0.03l) {
		const DerivFloat my_deriv = derivn(f, x, DERIV_ORDER);
		const DerivFloat actual_deriv = -(powl(x * logl(M_PIl) * logl(x) + M_PIl, 2.0l) *
			sinl(logl(powl(M_PIl, x) * powl(logl(x), M_PIl)) / logl(10.0l)) + M_PIl *
			logl(10.0l) * (logl(x) + 1.0l) * cosl(logl(powl(M_PIl, x) * powl(logl(x), M_PIl)) /
			logl(10.0l))) / (x * x * powl(logl(10.0l), 2.0l) * powl(logl(x), 2.0l));
		printf(
			"x = %-+"ARG_WDH"."ARG_PR"Lf my_deriv = %-+"VAL_WDH"."VAL_PR"Lf actual_deriv = %-+"VAL_WDH"."VAL_PR"Lf error = %-+"VAL_WDH"."VAL_PR"Lf\n",
			x, my_deriv, actual_deriv, my_deriv - actual_deriv
		);
	}
	return 0;
}

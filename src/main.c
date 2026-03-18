#include <stdio.h>
#include <math.h>

#ifndef M_PIl
# define M_PIl		3.141592653589793238462643383279502884L /* pi */
#endif

#include "deriv.h"

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
		const DerivFloat my_deriv = derivn(f, x, DERIV_ORDER), actual_deriv = -(powl(x*logl(M_PIl)*logl(x)+M_PIl,2)*sinl(logl(powl(M_PIl, x)*powl(logl(x),M_PIl))/logl(10))+M_PIl*logl(10)*(logl(x)+1)*cosl(logl(powl(M_PIl, x)*powl(logl(x),M_PIl))/logl(10))) / (x*x*powl(logl(10),2)*powl(logl(x),2));
		printf(
			"x = %-+"ARG_WDH"."ARG_PR"Lf my_deriv = %-+"VAL_WDH"."VAL_PR"Lf actual_deriv = %-+"VAL_WDH"."VAL_PR"Lf error = %-+"VAL_WDH"."VAL_PR"Lf\n",
			x, my_deriv, actual_deriv, my_deriv - actual_deriv
		);
	}
	return 0;
}

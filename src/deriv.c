#include <stdint.h>
#include <string.h>
#include <math.h>

#include "deriv.h"

#define REFERENCE_EPS 1e-8l

typedef uint64_t DerivUInt;

// Write the nth (starting from 0) line from Pascal's triangle to an array
// NOTE: Line array must have length == n + 1
static void pascals_line(DerivUInt *line, const size_t n) {
	DerivUInt prev_line[n];
	for (size_t i = 0; i < n + 1; i++) {
		for (size_t j = 0; j < i + 1; j++) {
			if (j == 0 || j == i)
				line[j] = 1;
			else
				line[j] = prev_line[j - 1] + prev_line[j];
		}
		if (0 < i && i < n)
			memcpy(prev_line, line, (i + 1) * sizeof(DerivUInt));
	}
}

DerivFloat deriv(DerivFloat (*f)(DerivFloat), const DerivFloat x) {
	return (f(x + REFERENCE_EPS) - f(x)) / REFERENCE_EPS;
}

// TODO: Replace with (f(x + eps) - f(x - eps)) / (2 * eps) for more precision
DerivFloat derivn(DerivFloat (*f)(DerivFloat), const DerivFloat x, const size_t n) {
	const DerivFloat eps = powl(REFERENCE_EPS, 1.0l / n);
	DerivFloat res = 0.0l;
	DerivUInt k[n + 1];
	pascals_line(k, n);
	for (size_t i = 0; i < n + 1; i++) {
		int8_t sign = (i % 2) ? -1 : 1;
		res += f(x + (n - i) * eps) * sign * k[i];
	}
	res /= powl(eps, n);
	return res;
}

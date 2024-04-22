#include "Tools.hpp"

long long mod_exp(long long x, int power, long long mod) {
	if (power == 0)
		return 1;
	
	if (power % 2 == 0) {
		long long z = mod_exp(x, power / 2, mod);
		return (z * z) % mod;
	}
	else {
		long long z = mod_exp(x, (power-1) / 2, mod);
		return (x * z * z) % mod;
	}
}
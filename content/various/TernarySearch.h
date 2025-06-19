

/**
 * Author: Nill
 * Date: 2025(Happy New Year)
 * License: LOL
 * Source: Hello @everyone.
 * Description: Example structures and functions that doesn't really do
 *  anything. Latex commands are supported here, though! Like this: $2^2=3$
 * Usage:
 * Status: Untested
 */
// If only take Integers
	template <typename F> int find_min(int l, int r, const F &f) {
	while (r - l > 3) {
		int m1 = l + (r - l) / 3;
		int m2 = r - (r - l) / 3;
		f(m1) > f(m2) ? l = m1 : r = m2;
	}

	int res = l;
	for (int i = l + 1; i <= r; i++) {
		if (f(i) < f(res)) { res = i; }
	}

	return res;
}
// floating point 	
template <typename F> double find_min(double l, double r, double eps, const F &f) {
	while (r - l > eps) {
		double m1 = l + (r - l) / 3;
		double m2 = r - (r - l) / 3;
		f(m1) > f(m2) ? l = m1 : r = m2;
	}

	return l;
}
// Binary search 
	template <typename F> int find_min(int l, int r, const F &f) {
	while (l < r) {
		int m = (l + r) / 2;
		f(m) < f(m + 1) ? r = m : l = m + 1;
	}

	return l;
}


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


#pragma once

int knapsack(vi w, int t) {
	int a = 0, b = 0, x;
	while (b < sz(w) && a + w[b] <= t) a += w[b++];
	if (b == sz(w)) return a;
	int m = *max_element(all(w));
	vi u, v(2*m, -1);
	v[a+m-t] = b;
	rep(i,b,sz(w)) {
		u = v;
		rep(x,0,m) v[x+w[i]] = max(v[x+w[i]], u[x]);
		for (x = 2*m; --x > m;) rep(j, max(0,u[x]), v[x])
			v[x-w[j]] = max(v[x-w[j]], j);
	}
	for (a = t; v[a+m-t] < 0; a--) ;
	return a;
}

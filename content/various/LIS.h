/**
 * Author: Null
 * Date: Happy new Year 2025
 * License: CC0
 * Source: Conversation with Håkan and Ulf.
 * Description: Example structures and functions that doesn't really do
 *  anything. Latex commands are supported here, though! Like this: $2^2=3$

 */

#pragma once

template<class I> vi lis(const vector<I>& S) {
	if (S.empty()) return {};
	vi prev(sz(S));
	typedef pair<I, int> p;
	vector<p> res;
	rep(i,0,sz(S)) {
		// change 0 -> i for longest non-decreasing subsequence
		auto it = lower_bound(all(res), p{S[i], 0});
		if (it == res.end()) res.emplace_back(), it = res.end()-1;
		*it = {S[i], i};
		prev[i] = it == res.begin() ? 0 : (it-1)->second;
	}
	int L = sz(res), cur = res.back().second;
	vi ans(L);
	while (L--) ans[L] = cur, cur = prev[cur];
	return ans;
}

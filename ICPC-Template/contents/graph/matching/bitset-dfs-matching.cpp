const int N = 505;
using set = std::bitset<N>;
set edge[N];
std::vector<int> match(int nl, int nr) {
	set unvis; unvis.set();
	std::vector<int> match(nr + 1), ret(nl + 1);
	auto dfs = [&](auto dfs, int x) {
		for(set z = edge[x];;) {
			z &= unvis;
			int y = z._Find_first();
			if(y == N) return 0;
			if(unvis.reset(y), !match[y] || dfs(dfs, match[y])) {
				return match[y] = x, 1;
			}
		}
	};
	for(int i = 1;i <= nl;++i) 
		if(dfs(dfs, i)) unvis.set();
	for(int i = 1;i <= nr;++i) ret[match[i]] = i;
	return ret[0] = 0, ret;
}

std::vector<int> edge[N];
std::vector<int> match(int nl, int nr) {
	std::vector<int> vis(nr + 1), match(nr + 1), ret(nl + 1);
	auto dfs = [&](auto dfs, int x) -> int {
		for(int y : edge[x]) if(!vis[y]) 
			if(vis[y] = 1, !match[y] || dfs(dfs, match[y]))
				return match[y] = x, 1;
		return 0;
	};
	for(int i = 1;i <= nl;++i) if(dfs(dfs, i))
		memset(vis.data(), 0, vis.size() << 2);
	for(int i = 1;i <= nr;++i) if(int t = match[i]) ret[t] = i;
	return ret;
}
std::array<std::vector<int>, 3> minedgeconver(int nl, int nr) {
	std::vector<int> vis(nr + 1), match(nr + 1), ret(nl + 1);
	auto dfs = [&](auto dfs, int x) -> int {
		for(int y : edge[x]) if(!vis[y]) 
			if(vis[y] = 1, !match[y] || dfs(dfs, match[y]))
				return match[y] = x, 1;
		return 0;
	};
	for(int i = 1;i <= nl;++i) if(dfs(dfs, i))
		memset(vis.data(), 0, vis.size() << 2);
	for(int i = 1;i <= nr;++i) if(int t = match[i]) ret[t] = i;
	for(int i = 1;i <= nl;++i) if(!ret[i]) dfs(dfs, i);
	std::vector<int> le, ri;
	for(int i = 1;i <= nl;++i) if(ret[i] && !vis[ret[i]]) le.push_back(i);
	for(int i = 1;i <= nr;++i) if(vis[i]) ri.push_back(i);
	return {le, ri, ret};
}

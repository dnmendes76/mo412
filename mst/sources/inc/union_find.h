#ifndef UNION_FIND_H
#define UNION_FIND_H

#include<vector>

using namespace std;

class UnionFind{
public:
	vector<int> parent;
	vector<int> rank;

	UnionFind(int n);
	void make_set(int x);
	int find_set(int i);
	bool same_set(int i, int j);
	void union_set(int i, int j);
};

#endif

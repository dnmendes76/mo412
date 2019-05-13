//#include "union_find.h"
//
//UnionFind::UnionFind(int n) {
//	parent.resize(n);
//}
//
//void UnionFind::make_set(int x) {
//    parent[x] = x;
//}
//
//int UnionFind::find_set(int i) {
//    return (parent[i] == i) ? i : (parent[i] = find_set(parent[i]));
//}
//
//bool UnionFind::same_set(int i, int j) {
//    return find_set(i) == find_set(j);
//}
//
//void UnionFind::union_set(int i, int j) {
//    int x, y;
//    if (!same_set(i, j)) {
//        x = find_set(i);
//        y = find_set(j);
//        parent[x] = y;
//    }
//}
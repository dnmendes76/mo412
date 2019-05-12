#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "soluction.h"
#include <algorithm>

using namespace std;

class MST_Kruskal{
public:

	Graph graph;
	MST_Kruskal(Graph graph);

	Soluction solve();

};

#endif


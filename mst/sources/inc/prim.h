#include "soluction.h"
#include <limits>

using namespace std;

class MST_Prim{
	Soluction obter_soluction();
public:

	Graph graph;
	vector<int> parent;

	MST_Prim(Graph graph);
	Soluction solve(int root);

};



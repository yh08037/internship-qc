#include "graph.h"

int main() {

	Graph* graph = new Graph("../graph/graph1.txt");
	int lqubit = 5;
	graph->getgraph();
	graph->ViewNeighbors(4);
	graph->judge_neighbor(3, 5);
	
	delete graph;
	return 0;
}
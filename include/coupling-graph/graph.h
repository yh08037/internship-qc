#ifndef COUPLING_GRAPH_GRAPH_H
#define COUPLING_GRAPH_GRAPH_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <random>

using namespace std;

class Graph {
public:
	Graph(string path);
	~Graph(void);
	void getgraph();
	void ViewNeighbors(int node);
	bool judge_neighbor(int n, int m);
	void COMrand(int lqubit);
	vector<vector<int>> arr; // arr[Qi][Qj]
	vector<int> COM;
private:
	int qubit_number;
	vector<vector<int>> ary; // ary[qi][qj]
};

#endif // COUPLING_GRAPH_GRAPH_Htp
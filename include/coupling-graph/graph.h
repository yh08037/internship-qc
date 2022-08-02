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
	vector<vector<int>> logical_arr; // logical_arr[qi][qj]
	vector<vector<int>> physical_arr; // physical_arr[Qi][Qj]
	vector<int> COM;
private:
	int qubit_number;
};

#endif // COUPLING_GRAPH_GRAPH_Htp
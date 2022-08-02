#include "graph.h"

int main() {

	Graph* graph = new Graph("../graph/graph1.txt");
	int lqubit = 5;
	graph->getgraph();
	graph->ViewNeighbors(4);
	graph->judge_neighbor(3, 5);
	graph->COMrand(lqubit);


	string ciruit_file = "test.txt";

	ifstream fin(ciruit_file);
	if (!fin) {
		cout << "에러 입력파일";
		return 0;
	}

	vector<string> v;	
	vector<int> Line;
	string line;

	while (getline(fin, line))
		v.push_back(line);

	for (int i = 0; i < v.size(); i++) {
		int index = v[i].find("cx");
		Line.push_back(i);
		if (index != -1)
			cout << "line " << i + 1 << " : " << v[i] << endl;
	}
	
	int q1, q2;

	string cx;
	//int i1, i2;

	for (int i = 0; i < Line.size(); i++) {
		stringstream ss(v[Line[i]]);
		ss >> cx >> q1 >> q2;
		//ss >> cx >> i1 >> i2;
		/*if (cx == "cx") {
			q1 = i1;
			q2 = i2;			//q1 : control, q2 : target
		}*/
		cout << q1 << " " << q2 << endl;

		
		int index = 0;
		for (int j = 0; j < lqubit; j++) {
			if (graph->COM[j] == q1)
				index = j;
		}

		int obj;
		if (graph->judge_neighbor(q1, q2) == false) {
			int k = 0;
			while (k < lqubit) {
				if (graph->logical_arr[index][k] == 1) {
					obj = k;
					break;
				}
				else
					k++;
			}
		}

		// + obj랑 q2 SWAP --> gate.addSWPgate(q2, obj);
		
	}
	
	delete graph;
	return 0;
}
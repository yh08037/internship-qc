#include "graph.h"


Graph::Graph(string path) {
	ifstream file(path);
	if (!file)
	{
		cout << "Error" << endl;
		exit(100);
	}

	if (file.is_open())
		cout << "File open success. \n\n";
	else
		cout << "File open fail. \n\n";


	char qbit_number[9];
	file.getline(qbit_number, 9, '\n');
	qubit_number = atoi(qbit_number);
	cout << "The number of qubits: " << qubit_number << endl;

	string str;
	int line_number = 0;
	vector<string> v;

	while (getline(file, str)) {
		line_number += 1;
		v.push_back(str);
	}

	cout << "The number of lines: " << line_number << endl;
	cout << endl;

	int n1, n2;

	ary = vector<vector<int>>(qubit_number, vector<int>(qubit_number, 0));

	for (int i = 0; i < line_number; i++) {
		stringstream ss(v[i]);
		ss >> n1 >> n2;
		ary[n1][n2] = 1;
		ary[n2][n1] = 1;
	}

	for (int i = 0; i < qubit_number; i++) {
		for (int k = 0; k < qubit_number; k++) {
			if (ary[i][k] != 1)
				ary[i][k] = 0;
		}
	}

	file.close();
}


Graph::~Graph(void) {
	//for (int i = 0; i < qubit_number; i++)
	//	delete[] ary[i];
	//delete[] ary;
}

void Graph::getgraph() {
	for (int i = 0; i < qubit_number; i++) {
		cout << "Qubit index: " << i << endl;
		cout << "Adjacent qubit: ";
		for (int j = 0; j < qubit_number; j++) {
			if (ary[i][j] == true)
				cout << j << ", ";
		}
		cout << endl << endl;
	}
}

bool Graph::judge_neighbor(int node1, int node2) {
	cout << "node" << node1 << " & node" << node2 << endl;
	if (ary[node1][node2]) {
		cout << "connected!" << endl << endl;
		return true;
	}
	else {
		cout << "unconnected!" << endl << endl;
		return false;
	}
}

void Graph::ViewNeighbors(int node) {
	//neighbor = vector<int>();
	cout << "node: " << node << endl;
	cout << "connected node: ";
	for (int i = 0; i < qubit_number; i++) {
		if (ary[node][i]) {
			//neighbor.push_back(i);
			cout << i << ", ";
		}
	}
	cout << endl << endl;
}

void Graph::COMrand(int lqubit) {

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, qubit_number - 1);

	COM = vector<int>(lqubit);
	int tempt = 0;
	int connection;

	for (int i = 0; i < lqubit; i++) {
		COM[i] = dis(gen);
		tempt = COM[i];
		connection = 0;
		for (int j = 0; j < i; j++)
		{
			if (COM[j] == tempt)
				i--;
			else
				for (int k = 0; k < i; k++) {
					if (ary[tempt][COM[k]] == 1)
						connection += 1;
				}
			if (connection == 0)
				i--;
		}
	}

	cout << endl;
	cout << "Selected qubits: ";
	for (int i = 0; i < lqubit; i++)
		cout << COM[i] << ", ";
	cout << endl << endl;

	arr = vector<vector<int>>(lqubit, vector<int>(lqubit, 0));

	for (int i = 0; i < lqubit; i++) {
		for (int j = 0; j < lqubit; j++) {
			if (ary[COM[i]][COM[j]] == 1) {
				arr[i][j] = 1;
				arr[j][i] = 1;
			}
		}
	}

	for (int i = 0; i < qubit_number; i++) {
		for (int k = 0; k < qubit_number; k++) {
			if (ary[i][k] != 1)
				ary[i][k] = 0;
		}
	}

	for (int i = 0; i < lqubit; i++) {
		for (int k = 0; k < lqubit; k++) {
			cout << arr[i][k] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
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

	physical_arr = vector<vector<int>>(qubit_number, vector<int>(qubit_number, 0));

	for (int i = 0; i < line_number; i++) {
		stringstream ss(v[i]);
		ss >> n1 >> n2;
		physical_arr[n1][n2] = 1;
		physical_arr[n2][n1] = 1;
	}

	for (int i = 0; i < qubit_number; i++) {
		for (int k = 0; k < qubit_number; k++) {
			if (physical_arr[i][k] != 1)
				physical_arr[i][k] = 0;
		}
	}

	file.close();
}

void Graph::printMatrix(vector<vector<int>> &matrix) {
	for (int i = 0; i < qubit_number; i++) {
		for (int j = 0; j < qubit_number; j++) {
		if (matrix[i][j] == 999)
			printf("%4s", "INF");
		else
			printf("%4d", matrix[i][j]);
		}
		printf("\n");
	}
}


Graph::~Graph(void) {
	//for (int i = 0; i < qubit_number; i++)
	//	delete[] physical_arr[i];
	//delete[] physical_arr;
}

void Graph::getgraph() {
	for (int i = 0; i < qubit_number; i++) {
		cout << "Qubit index: " << i << endl;
		cout << "Adjacent qubit: ";
		for (int j = 0; j < qubit_number; j++) {
			if (physical_arr[i][j] == true)
				cout << j << ", ";
		}
		cout << endl << endl;
	}
}

bool Graph::judge_neighbor(int node1, int node2) {
	cout << "node" << node1 << " & node" << node2 << endl;
	if (physical_arr[node1][node2]) {
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
		if (physical_arr[node][i]) {
			//neighbor.push_back(i);
			cout << i << ", ";
		}
	}
	cout << endl << endl;
}

/* void Graph::COMrand(QASMparser &parser, int lqubit) {

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, qubit_number - 1);

	COM = vector<int>(lqubit);
	int tempt = 0;
	int connection;

	int nqubit = parser.getNqubits();
    auto layers = parser.getLayers();
	int cxconnection = -1;
	int i;

	while (cxconnection != 1) {
		for (i = 0; i < lqubit; i++) {
			COM[i] = dis(gen);
			tempt = COM[i];
			connection = 0;
			for (int j = 0; j < i; j++)
			{
				if (COM[j] == tempt)
					i--;
				else
					for (int k = 0; k < i; k++) {
						if (physical_arr[tempt][COM[k]] == 1)
							connection += 1;
					}
				if (connection == 0)
					i--;
			}
		}

		int brk = i;
		for (auto &layer : layers) {
			for (auto &gate : layer) {
				if (string(gate.type) == "cx") {

					int qc = gate.control;
					int qt = gate.target;
					
					if (physical_arr[COM[qc]][COM[qt]] == 0) { 
						i--;
						break;
					}
					else {
						cxconnection = 1;
						break;
					}
				}
			}
			if (brk != i) break;
			if (cxconnection == 1) break;
		}
	}



	cout << endl;
	cout << "Selected qubits: ";
	for (int i = 0; i < lqubit; i++)
		cout << COM[i] << ", ";
	cout << endl << endl;


	// ----------------------- print logical array -----------------------

	logical_arr = vector<vector<int>>(lqubit, vector<int>(lqubit, 0));

	for (int i = 0; i < lqubit; i++) {
		for (int j = 0; j < lqubit; j++) {
			if (physical_arr[COM[i]][COM[j]] == 1) {
				logical_arr[i][j] = 1;
				logical_arr[j][i] = 1;
			}
		}
	}

	for (int i = 0; i < qubit_number; i++) {
		for (int k = 0; k < qubit_number; k++) {
			if (physical_arr[i][k] != 1)
				physical_arr[i][k] = 0;
		}
	}

	for (int i = 0; i < lqubit; i++) {
		for (int k = 0; k < lqubit; k++) {
			cout << logical_arr[i][k] << " ";
		}
		cout << endl;
	}
	cout << endl;


	// ----------------------- calculate distance -----------------------
	for (const auto &row : physical_arr) {
		distance.emplace_back(row);
	}

	for (int i = 0; i < qubit_number; i++) {
		// check Qi is included in initial mapping
		bool is_i_mapped = false;
		for (int q = 0; q < nqubit; q++) {
			if (i == COM[q]) {
				is_i_mapped = true;
			}
		}

		for (int j = 0; j < qubit_number; j++) {
			// check Qj is included in initial mapping
			bool is_j_mapped = false;
			for (int q = 0; q < nqubit; q++) {
				if (j == COM[q]) {
					is_j_mapped = true;
				}
			}

			// set distance
			if (is_i_mapped && is_j_mapped) {
				if (distance[i][j] == 0) {
					if (i == j) {
						distance[i][j] = 0;
					} else {
						distance[i][j] = 999;
					}
				}
			} else {
				distance[i][j] = 999;
			}
		}
	}

	// Adding vertices individually
	for (int k = 0; k < qubit_number; k++) {
		for (int i = 0; i < qubit_number; i++) {
			for (int j = 0; j < qubit_number; j++) {
				if (distance[i][k] + distance[k][j] < distance[i][j])
				distance[i][j] = distance[i][k] + distance[k][j];
			}
		}
	}
	printMatrix(distance);
} */


void Graph::COMrand(QASMparser &parser, int lqubit) {

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, qubit_number - 1);

	COM = vector<int>(lqubit);
	int tempt = 0;
	int connection;

	int nqubit = parser.getNqubits();
    auto layers = parser.getLayers();

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
					if (physical_arr[tempt][COM[k]] == 1)
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

	logical_arr = vector<vector<int>>(lqubit, vector<int>(lqubit, 0));

	for (int i = 0; i < lqubit; i++) {
		for (int j = 0; j < lqubit; j++) {
			if (physical_arr[COM[i]][COM[j]] == 1) {
				logical_arr[i][j] = 1;
				logical_arr[j][i] = 1;
			}
		}
	}

	for (int i = 0; i < qubit_number; i++) {
		for (int k = 0; k < qubit_number; k++) {
			if (physical_arr[i][k] != 1)
				physical_arr[i][k] = 0;
		}
	}

	for (int i = 0; i < lqubit; i++) {
		for (int k = 0; k < lqubit; k++) {
			cout << logical_arr[i][k] << " ";
		}
		cout << endl;
	}
	cout << endl;

	// ----------------------- calculate distance -----------------------

	for (const auto &row : physical_arr) {
		distance.emplace_back(row);
	}

	for (int i = 0; i < qubit_number; i++) {
		// check Qi is included in initial mapping
		bool is_i_mapped = false;
		for (int q = 0; q < nqubit; q++) {
			if (i == COM[q]) {
				is_i_mapped = true;
			}
		}

		for (int j = 0; j < qubit_number; j++) {
			// check Qj is included in initial mapping
			bool is_j_mapped = false;
			for (int q = 0; q < nqubit; q++) {
				if (j == COM[q]) {
					is_j_mapped = true;
				}
			}

			// set distance
			if (is_i_mapped && is_j_mapped) {
				if (distance[i][j] == 0) {
					if (i == j) {
						distance[i][j] = 0;
					} else {
						distance[i][j] = 999;
					}
				}
			} else {
				distance[i][j] = 999;
			}
		}
	}

	// Adding vertices individually
	for (int k = 0; k < qubit_number; k++) {
		for (int i = 0; i < qubit_number; i++) {
			for (int j = 0; j < qubit_number; j++) {
				if (distance[i][k] + distance[k][j] < distance[i][j])
				distance[i][j] = distance[i][k] + distance[k][j];
			}
		}
	}
	printMatrix(distance);
}
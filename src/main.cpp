#include <string>
#include "QASMparser.h"
#include "graph.h"
#include "mainmapping.h"
#include "write_qasm.h"


int main(int argc, char** argv) {
    
    if (argc != 2) {
        std::cout << "Usage: mapping [file_path]" << std::endl;
        exit(1);
    }

    std::string fileName = argv[1];

    QASMparser parser(fileName);
    parser.Parse();

    int nqubits = parser.getNqubits();
    int ngates = parser.getNgates();
    auto layers = parser.getLayers();

    // create coupling graph
    Graph graph("../graph/graph2.txt");
	graph.getgraph();

    // test
	graph.ViewNeighbors(4);
	graph.judge_neighbor(3, 5);
	
    // initial mapping - random
    graph.COMrand(parser, nqubits);

    // main mapping
    Main main(parser, graph);
    //main.print_main();
    write_qasm output(main, fileName, nqubits);
    cout << "finish!" << endl;

    int num_gates = 0;
    int cx_count = 0;

    for (const auto &layer : main.newLayers) {
        num_gates += layer.size();
        for (auto &gate : layer) {
            if (string(gate.type) == "cx") {
                cx_count++;
            }
        }
    }

    cout << "num_gates: " << num_gates << endl;
    cout << "num_cx: " << cx_count << endl;

    
    // create output
    // write_qasm(new_layers, '../output/asdf.qasm');

    return 0;
}
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
    //graph.COMrand(nqubits);

    // main mapping
    Main main(parser, graph);
    if(main.failure) {
        cout << "fail!" << endl;
    } else {
        main.print_main();
        write_qasm output(main, fileName, nqubits);
        cout << "finish!" << endl;
    }
    // create output
    // write_qasm(new_layers, '../output/asdf.qasm');

    return 0;
}
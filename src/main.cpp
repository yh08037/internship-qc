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
    
    /* auto printGate = [](QASMparser::gate gate) {
        std::cout << gate.type << " ";
        if (gate.control != -1)
            std::cout << "q[" << gate.control << "],";
        std::cout << "q[" << gate.target << "]" << std::endl;
    };

    for (auto &layer : layers) {
        for (auto &gate : layer) {
            printGate(gate);
        }
        std::cout << "----------------------------------------" << std::endl;
    } */


    // create coupling graph
    Graph graph("../graph/graph2.txt");
	graph.getgraph();

    // test
	graph.ViewNeighbors(4);
	graph.judge_neighbor(3, 5);
	
    // initial mapping - random
    graph.COMrand(nqubits);


    // main mapping
    Main main(parser, graph);
    main.print_main();

    // create output
    // write_qasm(new_layers, '../output/asdf.qasm');

    write_qasm output(main, fileName, nqubits);
    cout << "finish!" << endl;

    return 0;
}
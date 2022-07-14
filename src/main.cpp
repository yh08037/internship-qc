#include <string>
#include "QASMparser.h"


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

    auto printGate = [](QASMparser::gate gate) {
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
    }

    return 0;
}
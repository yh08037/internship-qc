#include "write_qasm.h"

void write_qasm::mkdir(const string &path) {
    fs::path p(path);

    if (fs::is_directory(p))
        return;

    fs::create_directories(p);
}

write_qasm::write_qasm(Main &main, string &fileName, int nqubits) {
    mkdir("../output");
    
    string FileName = fileName.substr(35);
    //cout << FileName << endl;
    string newFileName = "new_" + FileName;
    //cout << newFileName << endl;
    string newFilePath = "../output/" + newFileName;
    //cout << newFilePath << endl;

    ifstream read;

    read.open(newFilePath);

    if (read) {
        fs::remove(newFilePath);
    }

    ofstream out(newFilePath);

    out << "OPENQASM 2.0;" << endl;
    out << "include \"qelib1.inc\";" << endl;
    out << "qreg[" << nqubits << "];" << endl;
    out << "creg[" << nqubits << "];" << endl;

    for (auto &newlayer : main.newLayers) {
        for (auto &gate : newlayer) {
            out << gate.type << " ";
            if (gate.control != -1)
                out << "q[" << gate.control << "],";
            out << "q[" << gate.target << "];" << endl;
        }
    }
}   
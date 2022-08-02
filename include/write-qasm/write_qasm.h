#ifndef WRITE_QASM_H
#define WRITE_QASM_H

#include <iostream>
#include <string>
#include <filesystem>
#include <unistd.h>
#include "graph.h"
#include "QASMparser.h"
#include "mainmapping.h"

using namespace std;
namespace fs = std::filesystem;

class write_qasm {
public:
    void mkdir(const string &path);
    write_qasm(Main main, string FileName, int nqubits);
};

#endif // WRITE_QASM_Htp
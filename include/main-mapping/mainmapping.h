#ifndef MAINMAPPING_H
#define MAINMAPPING_H

#include <iostream>
#include <string>
#include <vector>
#include "graph.h"
#include "QASMparser.h"


using namespace std;

class Main {
private:
//    QASMparser parser;
public:
//    void main_mapping(QASMparser parser, Graph graph, vector<vector<QASMparser::gate> > layers);
    vector<vector<QASMparser::gate> > newLayers;
    Main(QASMparser &parser, Graph &graph);
    void print_main();
    void addSWP(vector<QASMparser::gate>  &newl, int control, int target);
    void addCX(vector<QASMparser::gate>  &newl, int control, int target);
};

#endif
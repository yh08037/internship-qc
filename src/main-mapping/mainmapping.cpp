#include "mainmapping.h"

Main::Main(QASMparser &parser, Graph &graph) {

    int i = 0;
    int nqubit = parser.getNqubits();
    auto layers = parser.getLayers();

    for (auto &layer : layers) {

        newLayers.push_back(vector<QASMparser::gate>());
        auto &newlayer = newLayers.back();
        
        for (auto &gate : layer) {
            if (string(gate.type) == "cx") {

                int qc = gate.control;
                int qt = gate.target;
                                
                int obj;
                if (graph.physical_arr[graph.COM[qc]][graph.COM[qt]] == 0) {
                    int qobj = -1;
			        for (int k = 0; k < nqubit; k++) {
			            if (graph.physical_arr[graph.COM[qc]][graph.COM[k]] == 1) {
                            qobj = k;
                            obj = graph.COM[qobj];
                            /* for (int j = 0; j < nqubit; j++) {
                                if (graph.COM[j] == obj) {
                                    qobj = j;
                                    break;
                                }
                                else
                                    k++; */
                            break;
                        }       
			        }
                    if (qobj == -1) {
                        for (int k = 0; k < nqubit; k++) {
                            if (graph.physical_arr[graph.COM[qt]][graph.COM[k]] == 1) {
                                qobj = k;
                                obj = graph.COM[qobj];
                                break;
                            }       
                        }
                    }
                    if (qobj == -1) {
                        cout << "?????" << endl;
                    }
                    //add SWP
                    /* int qobj;
                    for (int j = 0; j < nqubit; j++) {
                        if (graph.COM[j] == obj) {
                            qobj = j;
                            break;
                        }
                    } */

                    addSWP(newlayer, qt, qobj);
                    // update logical qubit - physical qubit mapping 
                    int qq = graph.COM[qt];
                    graph.COM[qt] = obj;
                    graph.COM[qobj] = qq;

                    for (int i = 0; i < nqubit; i++)
		                cout << graph.COM[i] << ", ";
	                cout << endl << endl;
                }
                //else break;    
            }
            //else break;
            
            //newlayer에 gate들 추가
            newlayer.push_back(gate);   //오류

            //cout << "check5" << endl;
        
        }
        i += 1;    
    }
}

void Main::print_main() {
    auto printGate = [](QASMparser::gate gate) {
        std::cout << gate.type << " ";
        if (gate.control != -1)
            std::cout << "q[" << gate.control << "],";
        std::cout << "q[" << gate.target << "]" << std::endl;
    };

    for (auto &newlayer : newLayers) {
        for (auto &gate : newlayer) {
            printGate(gate);
        }
        std::cout << "----------------------------------------" << std::endl;
    }
    
}

void Main::addSWP(vector<QASMparser::gate> &newl, int control, int target) {
    addCX(newl, control, target);
    addCX(newl, target, control);
    addCX(newl, control, target);
}

void Main::addCX(vector<QASMparser::gate> &newl, int control, int target) {
    QASMparser::gate g;

    g.control = control;
    g.target = target;

    snprintf (g.type, 127, "cx");

    newl.push_back(g);
    //newLayers.push_back(newl);  
    /* vector<QASMparser::gate> layer;
    layer.push_back(g);

    newLayers.push_back(layer); */
}


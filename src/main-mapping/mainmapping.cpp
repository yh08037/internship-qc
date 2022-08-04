#include "mainmapping.h"

/* Main::Main(QASMparser &parser, Graph &graph, int fail) {

    fail = 0;
    int nqubit = parser.getNqubits();
    auto layers = parser.getLayers();

    for (int layer_iter = 0; layer_iter < layers.size(); layer_iter++) {

        newLayers.push_back(vector<QASMparser::gate>());
        auto &newlayer = newLayers.back();

        for (int gate_iter = 0; gate_iter < layers[layer_iter].size(); gate_iter++) {
            if (string(layers[layer_iter][gate_iter].type) == "cx") {

                int qc = layers[layer_iter][gate_iter].control;
                int qt = layers[layer_iter][gate_iter].target;
                                
                int obj;
                int mobj;
                int mqobj;
                if (graph.physical_arr[graph.COM[qc]][graph.COM[qt]] == 0) {
                    int qobj = -1;
                    int k = 0;
                    bool FIRST;
                    int middle = -1;
                    
                    while (k < nqubit) {
                        for (k; k < nqubit; k++) {
                            if (graph.physical_arr[graph.COM[qc]][graph.COM[k]] == 1 && graph.physical_arr[graph.COM[qt]][graph.COM[k]] == 1) {
                                qobj = k;
                                obj = graph.COM[qobj];
                                cout << "t: " << graph.COM[qt] << ", obj: " << obj << endl;
                                break;
                            }     
                        }
                    
                        if (qobj != -1) {
                            //add SWP
                            FIRST = true;
                            // update logical qubit - physical qubit mapping 
                            int qq = graph.COM[qt];
                            graph.COM[qt] = obj;
                            graph.COM[qobj] = qq;
                            cout << "first" << endl;
                            for (int i = 0; i < nqubit; i++)
                                cout << graph.COM[i] << ", ";
                            cout << endl << endl;
                        }


                        if (qobj == -1) {
                            cout << "t: " << graph.COM[qt] << endl;
                            for (int t = 0; t < nqubit; t++) {
                                if (graph.physical_arr[graph.COM[qt]][graph.COM[t]] == 1) {
                                    mqobj = t;
                                    mobj = graph.COM[mqobj];

                                    cout << "mobj: " << mobj <<", t: " << graph.COM[qt] << endl;
                                    
                                    int mqq = graph.COM[qt];
                                    graph.COM[qt] = mobj;
                                    graph.COM[mqobj] = mqq;

                                    cout << "middle" << endl;
                                    for (int i = 0; i < nqubit; i++)
                                        cout << graph.COM[i] << ", ";
                                    cout << endl;
                                
                                    for (int y = 0; y < nqubit; y++) {
                                        if (graph.physical_arr[graph.COM[qc]][graph.COM[y]] == 1 && graph.physical_arr[graph.COM[qt]][graph.COM[y]] == 1) {
                                            qobj = y;
                                            obj = graph.COM[qobj];
                                            int qq = graph.COM[qt];
                                            graph.COM[qt] = obj;
                                            graph.COM[qobj] = qq;
                                            for (int i = 0; i < nqubit; i++)
                                                cout << graph.COM[i] << ", ";
                                            cout << endl;
                                            break;
                                        }       
                                    }
                                }
                            }
                            middle = 1;
                        }

                        if (qobj == -1) {
                            fail = 1;
                            cout << "?????" << endl;
                        }
                        else if (middle == 1) {
                            for (int i = 0; i < nqubit; i++)
                                cout << graph.COM[i] << ", ";
                            cout << endl;
                        }

                        int next_gate = gate_iter + 1;
                        int success = -1;

                        for (next_gate; next_gate < layers[layer_iter].size(); next_gate++) {
                            if (string(layers[layer_iter][next_gate].type) == "cx") {
                                int qc2 = layers[layer_iter][next_gate].control;
                                int qt2 = layers[layer_iter][next_gate].target;

                                if (graph.physical_arr[graph.COM[qc2]][graph.COM[qt2]] == 0) {
                                    k++;
                                    break;
                                }
                                else {
                                    success = 1;
                                    break;
                                }
                            }
                        }

                        int next_layer = layer_iter + 1;
                        int brk = k;

                        if (next_gate == layers[layer_iter].size()) {
                            if (success != 1) {
                                for (next_layer; next_layer < layers.size(); next_layer++) {
                                    for (int next_gate_iter = 0; next_gate_iter < layers[next_layer].size(); next_gate_iter++) {
                                        if (string(layers[next_layer][next_gate_iter].type) == "cx") {
                                            int qc2 = layers[next_layer][next_gate_iter].control;
                                            int qt2 = layers[next_layer][next_gate_iter].target;

                                            if (graph.physical_arr[graph.COM[qc2]][graph.COM[qt2]] == 0) {
                                                k++;
                                                break;
                                            }
                                            else {
                                                success = 1;
                                                break;
                                            }
                                        }
                                    }
                                    if (brk != k) {
                                        break;
                                    }
                                    if (success == 1) {
                                        k = nqubit;
                                        break;
                                    }
                                }
                            }
                            else {
                                k = nqubit;
                                break;
                            }
                        }

                        if (next_layer == layers.size()) {
                            k = nqubit;
                            break;
                        }

                        if (success == 1) {
                            k = nqubit;
                            break;
                        }
                    }
                    if (FIRST == true) {
                        addSWP(newlayer, qt, qobj);
                    }
                    else if (middle == 1) {
                        addSWP(newlayer, qt, mqobj);
                        addSWP(newlayer, qt, qobj);
                    }

                } 
            }
            
            //newlayer에 gate들 추가
            newlayer.push_back(layers[layer_iter][gate_iter]);
        }
        if (fail != 0) {
            failure = false;
        }
    }
} */


Main::Main(QASMparser &parser, Graph &graph, int fail) {

    fail = 0;
    int nqubit = parser.getNqubits();
    auto layers = parser.getLayers();

    for (auto &layer : layers) {

        newLayers.push_back(vector<QASMparser::gate>());
        auto &newlayer = newLayers.back();
        
        for (auto &gate : layer) {
            if (string(gate.type) == "cx") {

                int qc = gate.control;
                int qt = gate.target;
                                
                //int obj;
                if (graph.physical_arr[graph.COM[qc]][graph.COM[qt]] == 0) {
                    //int qobj = -1;
                    int min_i = 999;
                    int log_min = -1;
                    do {
                        min_i = 999;
                        log_min = -1;
                        for (int k = 0; k < nqubit; k++) {
                            if (graph.distance[graph.COM[qt]][graph.COM[k]] == 1) {
                                if (min_i > graph.distance[graph.COM[qc]][graph.COM[k]]){
                                    min_i = graph.distance[graph.COM[qc]][graph.COM[k]];
                                    log_min = k;
                                }
                            }
                        }
                        int qq = graph.COM[qt];
                        graph.COM[qt] = graph.COM[log_min];
                        graph.COM[log_min] = qq;
                        addSWP(newlayer, qt, log_min);
                        cout << "SWAP " << qt << " " << log_min << endl;
                    } while(min_i > 1);
			        

                    

                    /* int mobj;
                    int mqobj;
                    int middle = -1;

                    if (qobj == -1) {
                        cout << "t: " << graph.COM[qt] << endl;
                        for (int t = 0; t < nqubit; t++) {
                            if (graph.physical_arr[graph.COM[qt]][graph.COM[t]] == 1) {
                                mqobj = t;
                                mobj = graph.COM[mqobj];

                                cout << "mobj: " << mobj <<", t: " << graph.COM[qt] << endl;
                                
                                int mqq = graph.COM[qt];
                                graph.COM[qt] = mobj;
                                graph.COM[mqobj] = mqq;

                                cout << "middle" << endl;
                                for (int i = 0; i < nqubit; i++)
                                    cout << graph.COM[i] << ", ";
                                cout << endl;
                              
                                for (int y = 0; y < nqubit; y++) {
                                    if (graph.physical_arr[graph.COM[qc]][graph.COM[y]] == 1 && graph.physical_arr[graph.COM[qt]][graph.COM[y]] == 1) {
                                        qobj = y;
                                        obj = graph.COM[qobj];
                                        int qq = graph.COM[qt];
                                        graph.COM[qt] = obj;
                                        graph.COM[qobj] = qq;
                                        for (int i = 0; i < nqubit; i++)
                                            cout << graph.COM[i] << ", ";
                                        cout << endl;
                                        break;
                                    }       
                                }
                            }
                        }
                        middle = 1;
                    }

                    if (qobj == -1) {
                        fail = 1;
                        cout << "?????" << endl;
                    }

                    else if (middle == 1) {
                        //add SWP
                        addSWP(newlayer, qt, mqobj);
                        addSWP(newlayer, qt, qobj);
                        // update logical qubit - physical qubit mapping 
                    

                        for (int i = 0; i < nqubit; i++)
		                    cout << graph.COM[i] << ", ";
                        cout << endl;
                    } */
                }   
            }
            //newlayer에 gate들 추가
            newlayer.push_back(gate);
        }
        if (fail != 0) {
            failure = false;
        }   
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


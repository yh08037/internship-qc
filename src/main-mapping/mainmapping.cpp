#include "mainmapping.h"

/* Main::Main(QASMparser &parser, Graph &graph) {
    vector<int> actual;
    vector<int> nearby;
    //actual.push_back(-1);

    int nqubit = parser.getNqubits();
    auto layers = parser.getLayers();

    for (int layer_iter = 0; layer_iter < layers.size(); layer_iter++) {

        newLayers.push_back(vector<QASMparser::gate>());
        auto &newlayer = newLayers.back();

        for (int gate_iter = 0; gate_iter < layers[layer_iter].size(); gate_iter++) {
            if (string(layers[layer_iter][gate_iter].type) == "cx") {

                int qc = layers[layer_iter][gate_iter].control;
                int qt = layers[layer_iter][gate_iter].target;

                int qc2 = -1;
                int qt2 = -1;

                int next_gate = gate_iter + 1;
                int success = -1;

                for (next_gate; next_gate < layers[layer_iter].size(); next_gate++) {
                    if (string(layers[layer_iter][next_gate].type) == "cx") {
                        qc2 = layers[layer_iter][next_gate].control;
                        qt2 = layers[layer_iter][next_gate].target;
                        success = 1;
                        break;
                    }
                }

                if (success != 1) {
                    int next_layer = layer_iter + 1;
                    if (next_gate == layers[layer_iter].size()) {
                        for (next_layer; next_layer < layers.size(); next_layer++) {
                            for (int next_gate_iter = 0; next_gate_iter < layers[next_layer].size(); next_gate_iter++) {
                                if (string(layers[next_layer][next_gate_iter].type) == "cx") {
                                    qc2 = layers[next_layer][next_gate_iter].control;
                                    qt2 = layers[next_layer][next_gate_iter].target;
                                    success = 1;
                                    break;
                                }
                            }
                            if (success == 1) {
                                break;
                            }
                        }
                    }
                }

                if (graph.physical_arr[graph.COM[qc]][graph.COM[qt]] == 0) {
                    int min_dist = 999;
                    int q_min_dist = -1;

                    int next_min_dist = 999;

                    do {
                        min_dist = 999;
                        q_min_dist = -1;
                        //fill(actual.begin(), actual.end(), -1);
                        int storage = -1;

                        //cout << "qc: q" << qc << " Q" << graph.COM[qc] << " ";
                        //cout << "qt: q" << qt << " Q" << graph.COM[qt] << endl;
                        //cout << "mapping: ";
                        //for (int i = 0; i < nqubit; i++) {
                        //    cout << graph.COM[i] << " ";
                        //}
                        //cout << endl;

                        for (int k = 0; k < nqubit; k++) {
                            if (k == qc)
                                continue;
                            if (graph.distance[graph.COM[qt]][graph.COM[k]] == 1) {
                                //cout << "(q" << k << " Q" << graph.COM[k] << ") ";

                                int curr_dist = graph.distance[graph.COM[qc]][graph.COM[k]]; 
                                
                                vector<int> next_COM(graph.COM);
                                int qq = next_COM[qt];
                                next_COM[qt] = next_COM[k];
                                next_COM[k] = qq;
                                
                                if (min_dist > curr_dist) {
                                    min_dist = curr_dist;
                                    q_min_dist = k;
                                    if (success == 1) {
                                        next_min_dist = graph.distance[next_COM[qc2]][next_COM[qt2]];
                                    }
                                }
                                else if (min_dist == curr_dist) {
                                    if (success == 1) {
                                        int next_curr_dist = graph.distance[next_COM[qc2]][next_COM[qt2]]; 
                                        if (next_min_dist > next_curr_dist) {
                                            next_min_dist = next_curr_dist;
                                            q_min_dist = k;
                                        }
                                    }
                                }
                            }
                        }

                        if (q_min_dist == -1) {
                            cout << "q_min_dist: " << q_min_dist << endl;
                            exit(1);
                        }

                        // cout << "SWAP: q" << qt << " Q" << graph.COM[qt];
                        //cout << " <-> q" << q_min_dist  << " Q" << graph.COM[q_min_dist] << endl;
                        // cout << "min_dist: " << min_dist << " "; 

                        int qq = graph.COM[qt];
                        graph.COM[qt] = graph.COM[q_min_dist];
                        graph.COM[q_min_dist] = qq;

                        //actual.push_back(q_min_dist);
                        addSWP(newlayer, qt, q_min_dist);

                        //cout << "actual: " << graph.distance[graph.COM[qc]][graph.COM[qt]] << endl;
                    } while(min_dist > 1);

                }
            }
            //newlayer에 gate들 추가
            newlayer.push_back(layers[layer_iter][gate_iter]);
        }
    }
}
 */

Main::Main(QASMparser &parser, Graph &graph) {

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
                    int min_dist = 999;
                    int q_min_dist = -1;
                    do {
                        // cout << "qc: q" << qc << " Q" << graph.COM[qc] << " ";
                        // cout << "qt: q" << qt << " Q" << graph.COM[qt] << endl;
                        
                        // cout << "mapping: ";
                        // for (int i = 0; i < nqubit; i++) {
                        //     cout << graph.COM[i] << " ";
                        // }
                        // cout << endl;

                        min_dist = 999;
                        q_min_dist = -1;
                        
                        // cout << "candidate: ";
                        for (int k = 0; k < nqubit; k++) {
                            if (k == qc)
                                    continue;
                            if (graph.distance[graph.COM[qt]][graph.COM[k]] == 1) {
                                // cout << "(q" << k << " Q" << graph.COM[k] << ") ";
                                if (min_dist > graph.distance[graph.COM[qc]][graph.COM[k]]){
                                    min_dist = graph.distance[graph.COM[qc]][graph.COM[k]];
                                    q_min_dist = k;
                                }
                            }
                        }
                        // cout << endl;

                        // cout << "SWAP: q" << qt << " Q" << graph.COM[qt];
                        // cout << " <-> q" << q_min_dist  << " Q" << graph.COM[q_min_dist] << endl;
                        // cout << "min_dist: " << min_dist << " ";

                        int qq = graph.COM[qt];
                        graph.COM[qt] = graph.COM[q_min_dist];
                        graph.COM[q_min_dist] = qq;
                        addSWP(newlayer, qt, q_min_dist);

                        // cout << "actual: " << graph.distance[graph.COM[qc]][graph.COM[qt]] << endl;
                    } while(min_dist > 1);
                }   
            }
            //newlayer에 gate들 추가
            newlayer.push_back(gate);
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


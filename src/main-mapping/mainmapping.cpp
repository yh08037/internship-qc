#include "mainmapping.h"

Main::Main(QASMparser &parser, Graph &graph) {
    vector<int> actual;
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
                  
                if (graph.physical_arr[graph.COM[qc]][graph.COM[qt]] == 0) {
                    int k = 0;
                    int min_dist = 999;
                    int q_min_dist = -1;
                    
                    while (k < nqubit) {
                        do {
                            min_dist = 999;
                            q_min_dist = -1;
                            fill(actual.begin(), actual.end(), -1);

                            for (k; k < nqubit; k++) {
                                if (k == qc)
                                    continue;
                                if (graph.distance[graph.COM[qt]][graph.COM[k]] == 1) {
                                cout << "(q" << k << " Q" << graph.COM[k] << ") ";
                                    if (min_dist > graph.distance[graph.COM[qc]][graph.COM[k]]) {
                                        min_dist = graph.distance[graph.COM[qc]][graph.COM[k]];
                                        q_min_dist = k;
                                    }
                                }
                            }
                            cout << endl;

                            cout << "SWAP: q" << qt << " Q" << graph.COM[qt];
                            cout << " <-> q" << q_min_dist  << " Q" << graph.COM[q_min_dist] << endl;
                            cout << "min_dist: " << min_dist << " ";

                            int qq = graph.COM[qt];
                            graph.COM[qt] = graph.COM[q_min_dist];
                            graph.COM[q_min_dist] = qq;

                            actual.push_back(q_min_dist);
                            //addSWP(newlayer, qt, q_min_dist);

                            cout << "actual: " << graph.distance[graph.COM[qc]][graph.COM[qt]] << endl;
                        } while(min_dist > 1);

                        k = q_min_dist;

                        cout << "escape" << endl;

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
                    for (auto nswp : actual) {
                        addSWP(newlayer, qt, nswp);
                    }
                } 
            }
            //newlayer에 gate들 추가
            newlayer.push_back(layers[layer_iter][gate_iter]);
        }
    }
}


/* Main::Main(QASMparser &parser, Graph &graph) {

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
} */


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


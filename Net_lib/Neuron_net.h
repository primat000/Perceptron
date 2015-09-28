#ifndef NEURON_NET_H_INCLUDED
#define NEURON_NET_H_INCLUDED

class neuron_net
{
private:
    vector <layer> net;
    layer zero_layer;
    vector <double> In;
    vector <double> Out;
    /*vector <matrix> weights;*/
public:
    neuron_net(int layers, vector<int> n_in_layers);
    void train();
    double test();
    void initialize();
    double MSE();
    void info();
    layer & operator[](int n);
    vector<double> prediction(vector<double> set);
    /*gradient algo's*/
    /*heuristic algo's*/
};

#endif // NEURON_NET_H_INCLUDED

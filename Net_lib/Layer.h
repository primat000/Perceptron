#ifndef LAYER_H_INCLUDED
#define LAYER_H_INCLUDED

class layer
{
private:
    vector<neuron> n_layer;
    int size_l;
public:
    layer(int n);
    layer();
    void resize(int n);
    int size();
    neuron & operator[](int n);
    vector<double> OUT(vector<double> set);
    vector<double> Inputs();
};

#endif // LAYER_H_INCLUDED

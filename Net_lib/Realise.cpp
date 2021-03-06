#include "Header.h"
using namespace std;

/*..........................class dataset..........................*/

/*..........................class matrix..........................*/

/*..........................class neuron..........................*/

/*..........................class layer..........................*/
/*layer::layer(int n)
{
    n_layer.resize(n);
    size_l = n;
};
layer::layer(){size_l = 0;};
void layer::resize(int n)
{
    size_l = n;
    n_layer.resize(n);
};
int layer::size()
{
    return n_layer.size();
};
neuron & layer::operator[](int n)
{
    return n_layer[n];
};
vector<double> layer::OUT(vector<double> set)
{
    vector<double> out(size_l);
    //cout<<n_layer[0].conect()<<endl;
    for (int i = 0; i < size_l; i++)
    {
        if (n_layer[i].conect()) {out[i]=n_layer[i].function(set[i]*n_layer[i].get_weight(i));}
        else {out[i]=n_layer[i].function(set[i]);}
    }
    //cout<<out.size()<<endl;
    return out;
};
vector<double> layer::Inputs()
{
    vector<double> inputs(size_l);
    for (int i = 0; i < size_l; i++)
        inputs.push_back(n_layer[i].get_exit());
    return inputs;
};*/
/*..........................class neuron_net..........................*/


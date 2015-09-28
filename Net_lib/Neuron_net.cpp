#include "Header.h"
using namespace std;
/*..........................class neuron_net..........................*/

neuron_net::neuron_net(int layers, vector<int> neuron_in_layers)
{
    int IN = neuron_in_layers[0];
    int OUT = neuron_in_layers[neuron_in_layers.size()-1];
    In.resize(IN);
    Out.resize(OUT);
    net.resize(layers);
    zero_layer.resize(neuron_in_layers[0]);
    for (int j = 0; j < zero_layer.size(); j++)
    {
        zero_layer[j].conection(NULL);
        zero_layer[j].change_function(linear);
    }

    for (int i = 1; i < neuron_in_layers.size(); i++)
        {
            net[i].resize(neuron_in_layers[i]);
            if (i == 1) for (int j = 0; j < net[i].size(); j++)
                {
                    net[i][j].conection(&zero_layer);
                    net[i][j].weight_ini(zero_layer.size());

                }
            else for (int j = 0; j < net[i].size(); j++)
                {
                    net[i][j].conection(&net[i-1]);
                    net[i][j].weight_ini(net[i-1].size());
                }
        }
};

layer & neuron_net::operator[](int n)
{
    return net[n];
};

void neuron_net::info()
{
    cout<<"IN - "<<In.size()<<endl;
    cout<<"Out - "<<Out.size()<<endl;
    cout<<"Layers count - "<<net.size()<<endl;
    cout<<"Neuron in layers - "<<zero_layer.size()<<" ";
    for(int i = 1; i < net.size(); i++)
        {
            cout<<net[i].size()<<" ";
        }
    cout<<endl;
    for(int i = 1; i < net.size(); i++)
        {
            cout<<i<<" : "<<net[i].size()<<endl;
            for (int j = 0; j < net[i].size(); j++)
            {
                cout<<"neuron "<<j+1<<": inputs-"<<net[i][j].get_inputs().size()<<endl;
            }

        }
};
vector<double> neuron_net::prediction(vector<double> set)
{
    In.assign(set.begin(),set.begin()+In.size());
    vector<double> res=zero_layer.OUT(In);
    /*cout<<endl<<"result"<<endl;
    for (int i = 0; i < res.size(); i++)
        cout<<res[i]<<endl;*/
    for (int i = 1; i < net.size(); i++)
    {
        res = net[i].OUT(res);
        /*cout<<endl<<"result"<<endl;
        for (int j = 0; j < res.size(); j++)
        cout<<res[j]<<endl;*/
    }

    return res;
}



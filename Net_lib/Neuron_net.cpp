#include "Header.h"
using namespace std;
/*..........................class neuron_net..........................*/

neuron_net::neuron_net(int layers, vector<int> neuron_in_layers)
{
    L_count = layers;
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
    if (n==0) return zero_layer;
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
        cout<<endl<<"result"<<endl;
        for (int j = 0; j < res.size(); j++)
        cout<<res[j]<<endl;
    }
    Out = res;

    return res;
};
void neuron_net::online_bpe(vector<double> target)
{
    double step = 0.2;//*надо доработать
    //cout<<"\n bpe"<<endl;
    vector<vector <double> > DE;
    DE.resize(L_count);
    //cout<<L_count<<endl;
    DE[0].resize(In.size());
    //cout<<DE[0].size()<<endl;
    for (int i = 1; i < L_in_net(); i++ )
    {
        DE[i].resize(net[i].size());
        //cout<<DE[i].size()<<endl;
    }
    for (int i = 0; i < DE.size(); i++)
        for (int j = 0; j < DE[i].size(); j++)
        DE[i][j] = 0;
    for (int i = 0; i < DE[L_count - 1].size(); i++)
    {
        DE[L_count - 1][i] = Out[i] - target[i];
        //cout<<DE[L_count - 1][i]<<endl;
    }
    for (int i = DE.size() - 2; i >= 0; i--)//дл€ логистической функции
        for (int j = 0; j < DE[i].size(); j++)
    {
        //cout<<DE[i][j]<<"  -->  ";
        for(int u = 0; u < DE[i+1].size(); u++) //вли€ние нейронов из скрытых слоев
        DE[i][j] += DE[i+1][u] * net[i+1][u].get_exit() * (1 - net[i+1][u].get_exit()) * net[i+1][u].get_weight(j);
        //cout<<DE[i][j]<<endl;
    }
    for (int i = DE.size() - 1; i > 0; i--)//дл€ логистической функции
        for (int j = 0; j < DE[i].size(); j++)//мен€ю веса
        {
            //cout<<DE[i].size()<<"   "<<DE[i-1].size()<<endl;
            for (int u = 0; u < DE[i-1].size(); u++)
                {

                    double dw = step * DE[i][j] * (net[i][j].get_exit() * (1 - net[i][j].get_exit()))/**net[i-1][u].get_exit()*/;
                    if ( i-1 == 0) dw *= In[u];
                    else dw *= net[i-1][u].get_exit();
                    //cout<<"dw  "<<dw<<endl;
                    net[i][j].change_weight(u, net[i][j].get_weight(u) - dw);

                }
        }
};
int neuron_net::L_in_net()
{
    return L_count;
};


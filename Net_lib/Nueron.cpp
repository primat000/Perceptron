#include "Header.h"
using namespace std;
/*..........................class neuron..........................*/

neuron::neuron(double(*f)(double), vector<double> w , layer* nl)
{
    function_type = f;
    weights = w;
    inputs = nl;
    exit = 0;

};
neuron::neuron()
{
    double (*f)(double) = functions::logistic_function;
    function_type = f;
    weights = {};
    inputs = NULL;
    exit = 0;

};
layer & neuron::get_inputs()
{
    return *inputs;
}
void neuron::conection(layer * l)
{
    inputs = l;
};

void neuron::die()
{
    st = false;
};
void neuron::alive()
{
    st = true;
};

bool neuron::status()
{
    return st;
};

double neuron::function(double x)
{
    exit = function_type(x);
    return exit;
};

void neuron::weight_ini(int n)
{
    srand(time(0));
    weights.resize(n);
    for (int i = 0; i < weights.size(); i++)
        {
            weights[i] = (rand() % 10)/1000.0;
            //cout<<"w ="<<weights[i]<<endl;
        }
    //cout<<endl;
}
 bool neuron::conect()
 {
     if (inputs!=NULL) return true;
     else false;
 }
 double neuron::get_weight(int n)
 {
     return weights[n];
 }
 double neuron::get_exit()
 {
     return exit;
 }
 void neuron::change_function(double (*f)(double))
 {
     function_type = f;
 }
void neuron::change_weight (int n, double w)
{
    weights[n]=w;
}



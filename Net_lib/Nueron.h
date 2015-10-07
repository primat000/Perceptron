#ifndef NUERON_H_INCLUDED
#define NUERON_H_INCLUDED

class neuron
{
private:
    bool st;
    double (*function_type)(double);
    double exit;
    vector<double> weights;
    layer * inputs;

public:
    neuron(double(*f)(double), vector<double> w = {}, layer* nl = NULL);
    neuron ();
    double function(double x);
    void die();
    void alive();
    void conection(layer * l);
    layer & get_inputs();
    bool status();
    void weight_ini(int n);
    bool conect();
    double get_weight(int n);
    double get_exit();
    void change_function(double (*f)(double));
    void change_weight (int n, double w);
};



#endif // NUERON_H_INCLUDED

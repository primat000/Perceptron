#include <iostream>
#include "Header.h"
#include "H_Namespace_funtions.h"
//#include "Namespace_functions.cpp"
using namespace std;
using namespace functions;

int main()
{

    int m[]={1,2,1};
    vector<int> a(m, m + sizeof(m) / sizeof(int) );
    vector<double> b;
    b.push_back(1);
    double (*f)(double) = functions::th;
    neuron n(logistic_function);
    neuron_net net(3,a);
    net.info();
    net.prediction(b);
    return 0;
}

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
    //layer b();
    neuron n(logistic_function);
    neuron_net net(3,a);
    net.info();

    net.prediction(b);

    /*cout<<th(1)<<endl;
    cout<<th(2)<<endl;*/

    return 0;
}

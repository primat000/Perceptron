#include <iostream>
#include "Header.h"
#include "H_Namespace_funtions.h"
//#include "Namespace_functions.cpp"
using namespace std;
using namespace functions;

int main()
{

    int m[]={3,1};
    vector<int> a(m, m + sizeof(m) / sizeof(int) );
    vector<double> b,c;
    c.push_back(1);
    c.push_back(0);
    c.push_back(0);
    b.push_back(1);
    b.push_back(1);
    b.push_back(1);
    vector<double> t;
    t.push_back(1);
    double (*f)(double) = functions::logistic_function;
    neuron n(logistic_function);
    neuron_net net(a.size(),a);
    net.info();

    for(int i = 0; i< 50; i++)
    {
        cout<<i<<" : "<<endl;
        t[0]=1;
        net.prediction(b);
        net.online_bpe(t);
        t[0]=0;
        net.prediction(c);
        net.online_bpe(t);
    }
        net.online_bpe(t);

    net.prediction(b);
    net.prediction(c);
    b[2]=0;
    net.prediction(b);
    c[1]=1;
    net.prediction(c);

    return 0;
}

#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include "vector"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "H_Namespace_funtions.h"
#include <cmath>
//#define matrix vector<vector <double> >
using namespace std;
using namespace functions;
class neuron;
class layer;
class dataset;
class neuron_net;
#include "Layer.h"
#include "Nueron.h"
#include "Neuron_net.h"


/*class dataset
{
private:
    vector <vector <double> > data;
    vector <double> target;
    vector <string> features;
public:
    dataset();

    void add();

    void errase();

};*/



/*class matrix{
    public:
    vector<vector<double> > mat;
    int a;
    int b;
    matrix (int n, int m){
        a=n;
        b=m;
        mat.resize(a);
        for (int i = 0; i < a; i++)
        {
            mat[i].resize(b);
        }
    };
    vector<double> & operator[](int n)
    {
        return mat[n];
    };
};*/





#endif // HEADER_H_INCLUDED

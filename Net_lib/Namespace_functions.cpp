#include "H_Namespace_funtions.h"

namespace functions
{
    double step_function(double u)
    {
        if (u > 1) return 1;
        else return 0;

    };
    double logistic_function(double u)
    {
        return 1/(1 + pow(M_E,-u));
    };

    double th(double u)
    {
        return (pow(M_E,u) - pow(M_E,-u)) / (pow(M_E,u) + pow(M_E,-u));
    };
    double linear (double u)
    {
        return u;
    }
}

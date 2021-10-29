//
// Created by reiche on 10/27/21.
//

#include "Hammersley.h"


double Hammersley::getElement()
{
    double xs=0;
    double xsi=1.0;
    unsigned int    i1;

    unsigned int i2=++idx;

    do{
        xsi=xsi/base;
        i1=i2/ibase;
        xs+=(i2-base*i1)*xsi;
        i2=i1;
    } while(i2>0);

    return xs;
}
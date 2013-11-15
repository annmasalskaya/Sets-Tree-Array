#include "set_nvi.h"


void NVI::insertElement(int value)
{
    insertElementVirt(value);

}
bool NVI::findElement(int value)
{

    bool k=findElementVirt(value);
    return k;

}


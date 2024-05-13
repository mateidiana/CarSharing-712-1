#ifndef CONTROLLER_AUTOS_CONTROLLER_H
#define CONTROLLER_AUTOS_CONTROLLER_H

#include <iostream>
#inlcude <string>

using namespace std;

class Control {
private:

public:
    Control();
    bool PlateCheck();
    string PlateLettersCheck();
    bool YearCheck();
    bool KmPriceCheck();
};

#endif //CONTROLLER_AUTOS_CONTROLLER_H

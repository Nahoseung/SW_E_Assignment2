#ifndef REGISTERBICYCLEUI_H
#define REGISTERBICYCLEUI_H

#include "ClassTypes.h"

class RegisterBicycleUI
{
private:
    std::ifstream& inputFileRef;
    std::ofstream& outputFileRef;

public:
    RegisterBicycleUI(std::ifstream& inputF, std::ofstream& outputF);
    BicycleInfo getBicycleInfo();
    void showBicycleRegistrationInfo(BicycleInfo bikeInfo);
};

#endif // REGISTERBICYCLEUI_H
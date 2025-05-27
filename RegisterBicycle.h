#ifndef REGISTERBICYCLE_H
#define REGISTERBICYCLE_H

#include "RegisterBicycleUI.h"
#include "BicycleManager.h"
#include <fstream>

class RegisterBicycle
{
private:
    RegisterBicycleUI registerBicycleUI;

public:
    RegisterBicycle(std::ifstream& inputF, std::ofstream& outputF);
    void registerBicycle(BicycleManager* bicycleManager);
};

#endif // REGISTERBICYCLE_H
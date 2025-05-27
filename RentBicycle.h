#ifndef RENTBICYCLE_H
#define RENTBICYCLE_H

#include "RentBicycleUI.h"
#include "MemberManager.h"
#include "BicycleManager.h"
#include "ClassTypes.h" 
#include <fstream> 

class RentBicycle
{
private:
    RentBicycleUI rentBicycleUI;

public:
    RentBicycle(std::ifstream& inputF, std::ofstream& outputF);
    void rental(MemberManager* memberManager, BicycleManager* bicycleManager);
};

#endif // RENTBICYCLE_H
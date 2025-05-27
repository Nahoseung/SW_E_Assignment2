#ifndef RENTBICYCLEUI_H
#define RENTBICYCLEUI_H

#include "ClassTypes.h"

class RentBicycleUI
{
private:
    std::ifstream& inputFileRef;
    std::ofstream& outputFileRef;

public:
    RentBicycleUI(std::ifstream& inputF, std::ofstream& outputF);
    BicycleInfo getBicycleInfo();
    void showRentalInfo(BicycleInfo bikeInfo);
};

#endif // RENTBICYCLEUI_H
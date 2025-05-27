#include "RegisterBicycleUI.h"

RegisterBicycleUI::RegisterBicycleUI(std::ifstream& inputF, std::ofstream& outputF)
    : inputFileRef(inputF), outputFileRef(outputF)
{
}

BicycleInfo RegisterBicycleUI::getBicycleInfo()
{
    BicycleInfo bikeInfo;
    inputFileRef >> bikeInfo.id >> bikeInfo.name;
    bikeInfo.renter = "NULL"; 

    return bikeInfo;
}

void RegisterBicycleUI::showBicycleRegistrationInfo(BicycleInfo bikeInfo)
{
    std::cout << bikeInfo.id << bikeInfo.name << std::endl;
    outputFileRef << bikeInfo.id << " " << bikeInfo.name << std::endl;
    return;
}


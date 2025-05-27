#include "RentBicycleUI.h"

RentBicycleUI::RentBicycleUI(std::ifstream& inputF, std::ofstream& outputF)
    : inputFileRef(inputF), outputFileRef(outputF)
{
}

BicycleInfo RentBicycleUI::getBicycleInfo()
{
    BicycleInfo bikeInfo;
    inputFileRef >> bikeInfo.id;
    return bikeInfo;
}

void RentBicycleUI::showRentalInfo(BicycleInfo bikeInfo)
{
    std::cout << bikeInfo.id << bikeInfo.name << std::endl;
    outputFileRef << bikeInfo.id << " " << bikeInfo.name << std::endl;
    return;
}
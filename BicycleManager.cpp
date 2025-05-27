#include "BicycleManager.h"

void BicycleManager::addNewBicycle(std::string id, std::string name)
{
    Bicycle newBike(id, name);
    if (numberOfBicycles < MAX_NUM_BICYCLES) 
    {
        this->bicycleList[this->numberOfBicycles++] = newBike;
    }
    return;
}

BicycleInfo BicycleManager::rentBicycle(MemInfo memberInfo, BicycleInfo bikeInfo)
{
    int i = 0;
    while (bikeInfo.id != bicycleList[i].getId()) i++;

    bikeInfo.name = bicycleList[i].getName();

    bicycleList[i].setRenter(memberInfo.name);

    return bikeInfo;
}

int BicycleManager::getRentedList(BicycleInfo myList[], MemInfo memberInfo)
{
    int len = 0;
    for (int i = 0; i < this->numberOfBicycles; i++)
    {
        if (memberInfo.name == this->bicycleList[i].getRenter())
        {
            myList[len++] = this->bicycleList[i].getBicycleInfo();
        }
    }
    return len;
}
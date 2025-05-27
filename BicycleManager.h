#ifndef BICYCLEMANAGER_H
#define BICYCLEMANAGER_H

#include "ClassTypes.h"
#include "Bicycle.h"
#define MAX_NUM_BICYCLES 50
// Bicycle 객체들을 관리하는 class
class BicycleManager
{
private:
    int numberOfBicycles = 0;
    Bicycle bicycleList[MAX_NUM_BICYCLES];
public:
    void addNewBicycle(std::string id, std::string name);
    BicycleInfo rentBicycle(MemInfo memberInfo, BicycleInfo bikeInfo);
    int getRentedList(BicycleInfo myList[], MemInfo memberInfo);
};

#endif // BICYCLEMANAGER_H
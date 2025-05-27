#include "Bicycle.h"

Bicycle::Bicycle()
{
    bikeInfo.id = "";
    bikeInfo.name = "";
    bikeInfo.renter = "NULL"; 
}

Bicycle::Bicycle(std::string id, std::string name)
{
    this->bikeInfo.id = id;
    this->bikeInfo.name = name;
    this->bikeInfo.renter = "NULL";
}
// Private 변수인 bikeInfo에 접근하는 함수들
std::string Bicycle::getId() const { return bikeInfo.id; }
std::string Bicycle::getName() const { return bikeInfo.name; }
std::string Bicycle::getRenter() const { return bikeInfo.renter; }
void Bicycle::setRenter(std::string renterName) { bikeInfo.renter = renterName; }
BicycleInfo Bicycle::getBicycleInfo() const {return bikeInfo;}
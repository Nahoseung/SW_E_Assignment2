#ifndef BICYCLE_H
#define BICYCLE_H

#include "ClassTypes.h"

class Bicycle
{
private:
    BicycleInfo bikeInfo;
public:
    Bicycle();
    Bicycle(std::string id, std::string name);

    std::string getId() const;
    std::string getName() const;
    std::string getRenter() const;
    void setRenter(std::string renterName);
    BicycleInfo getBicycleInfo() const;
};

#endif // BICYCLE_H
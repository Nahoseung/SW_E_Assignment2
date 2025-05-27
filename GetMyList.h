#ifndef GETMYLIST_H
#define GETMYLIST_H

#include "GetMyListUI.h"
#include "MemberManager.h"
#include "BicycleManager.h"
#include "ClassTypes.h" 
#include <fstream> 

class GetMyList
{
private:
    GetMyListUI getMyListUI;

public:
    BicycleInfo myList[MAX_NUM_BICYCLES]; 
    GetMyList(std::ofstream& outputF);
    void getMyList(MemberManager* memberManager, BicycleManager* bicycleManager);
};

#endif // GETMYLIST_H
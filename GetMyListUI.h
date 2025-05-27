#ifndef GETMYLISTUI_H
#define GETMYLISTUI_H

#include "ClassTypes.h"

class GetMyListUI
{
private:
    std::ofstream& outputFileRef;

public:
    GetMyListUI(std::ofstream& outputF);
    void showList(BicycleInfo myList[], int length);
};

#endif // GETMYLISTUI_H
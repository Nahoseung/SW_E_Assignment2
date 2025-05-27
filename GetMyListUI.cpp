#include "GetMyListUI.h"

GetMyListUI::GetMyListUI(std::ofstream& outputF)
    : outputFileRef(outputF)
{
}

void GetMyListUI::showList(BicycleInfo myList[], int length)
{
    for (int i = 0; i < length; i++)
    {
        std::cout << myList[i].id << " " << myList[i].name << std::endl;
        outputFileRef << myList[i].id << " " << myList[i].name << std::endl;
    }
    return;
}
#include "SignUpUI.h"

SignUpUI::SignUpUI(std::ifstream& inputF, std::ofstream& outputF)
    : inputFileRef(inputF), outputFileRef(outputF)
{
}

MemInfo SignUpUI::getMemInfo()
{
    MemInfo userInfo;
    inputFileRef >> userInfo.name >> userInfo.password >> userInfo.phoneNumber;
    return userInfo;
}

void SignUpUI::showMemInfo(MemInfo userInfo)
{
    std::cout << userInfo.name << userInfo.password << userInfo.phoneNumber << std::endl;
    outputFileRef << userInfo.name << " " << userInfo.password << " " << userInfo.phoneNumber << std::endl;
    return;
}
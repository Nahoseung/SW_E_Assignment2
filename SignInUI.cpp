#include "SignInUI.h"

SignInUI::SignInUI(std::ifstream& inputF, std::ofstream& outputF)
    : inputFileRef(inputF), outputFileRef(outputF)
{
}

MemInfo SignInUI::getUserInfo()
{
    MemInfo userInfo;
    inputFileRef >> userInfo.name >> userInfo.password;

    return userInfo;
}

void SignInUI::showSignInResult(MemInfo userInfo)
{
    std::cout << userInfo.name << userInfo.password << std::endl;
    outputFileRef << userInfo.name << " " << userInfo.password << std::endl;
    return;
}
#include "SignOutUI.h"

SignOutUI::SignOutUI(std::ofstream& outputF)
    : outputFileRef(outputF)
{
}

void SignOutUI::showSignOutInfo(std::string memberName)
{
    outputFileRef << memberName << std::endl;
    return;
}
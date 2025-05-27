#ifndef SIGNOUTUI_H
#define SIGNOUTUI_H

#include "ClassTypes.h"

class SignOutUI
{
private:
    std::ofstream& outputFileRef;

public:
    SignOutUI(std::ofstream& outputF);
    void showSignOutInfo(std::string memberName);
};

#endif // SIGNOUTUI_H
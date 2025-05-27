#ifndef SIGNINUI_H
#define SIGNINUI_H

#include "ClassTypes.h"

class SignInUI
{
private:
    std::ifstream& inputFileRef;
    std::ofstream& outputFileRef;

public:
    SignInUI(std::ifstream& inputF, std::ofstream& outputF);
    MemInfo getUserInfo();
    void showSignInResult(MemInfo userInfo);
};

#endif // SIGNINUI_H
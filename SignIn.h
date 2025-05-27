#ifndef SIGNIN_H
#define SIGNIN_H

#include "SignInUI.h"
#include "MemberManager.h"
#include <fstream> 

class SignIn
{
private:
    SignInUI signInUI;

public:
    SignIn(std::ifstream& inputF, std::ofstream& outputF);
    void signIn(MemberManager* memberManager);
};

#endif // SIGNIN_H
#ifndef SIGNUP_H
#define SIGNUP_H

#include "SignUpUI.h"
#include "MemberManager.h"
#include <fstream> 

class SignUp
{
private:
    SignUpUI signUpUI;

public:
    SignUp(std::ifstream& inputF, std::ofstream& outputF);
    void signUp(MemberManager* memberManager);
};

#endif // SIGNUP_H
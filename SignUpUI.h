#ifndef SIGNUPUI_H
#define SIGNUPUI_H

#include "ClassTypes.h"

class SignUpUI
{
private:
    std::ifstream& inputFileRef;
    std::ofstream& outputFileRef;

public:
    SignUpUI(std::ifstream& inputF, std::ofstream& outputF);
    MemInfo getMemInfo();
    void showMemInfo(MemInfo userInfo);
};

#endif // SIGNUPUI_H
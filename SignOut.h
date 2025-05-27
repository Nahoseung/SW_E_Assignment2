#ifndef SIGNOUT_H
#define SIGNOUT_H

#include "SignOutUI.h"
#include "MemberManager.h"
#include <fstream> 

class SignOut
{
private:
    SignOutUI signOutUI; 
public:
    SignOut(std::ofstream& outputF);
    void signOut(MemberManager* memberManager);
};

#endif // SIGNOUT_H
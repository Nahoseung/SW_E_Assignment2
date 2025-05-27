#ifndef MEMBER_H
#define MEMBER_H

#include "ClassTypes.h"

class Member
{
private:
    MemInfo memberInfo;

public:
    Member();
    Member(std::string name, std::string password, std::string phoneNumber);
};

#endif // MEMBER_H
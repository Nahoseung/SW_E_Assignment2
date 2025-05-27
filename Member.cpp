#include "Member.h"

Member::Member()
{
    memberInfo.name = "";
    memberInfo.password = "";
    memberInfo.phoneNumber = "";
}

Member::Member(std::string name, std::string password, std::string phoneNumber)
{
    this->memberInfo.name = name;
    this->memberInfo.password = password;
    this->memberInfo.phoneNumber = phoneNumber;
}
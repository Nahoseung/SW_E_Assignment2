#include "MemberManager.h"

void MemberManager::addNewMember(std::string name, std::string password, std::string phoneNumber)
{
    Member newMember(name, password, phoneNumber);
    if (numberOfMembers < MAX_NUM_OF_MEMBERS)
    {
        this->memberList[this->numberOfMembers++] = newMember;
    }
}

void MemberManager::signIn(MemInfo userInfo)
{
    this->currentMember = userInfo;
    return;
}

void MemberManager::signOut()
{
    this->currentMember.name = "NULL";
    this->currentMember.password = "NULL";
    this->currentMember.phoneNumber = "NULL";
    return;
}

MemInfo MemberManager::getCurrentUser()
{
    return this->currentMember;
}
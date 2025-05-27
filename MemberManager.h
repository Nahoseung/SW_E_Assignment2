#ifndef MEMBERMANAGER_H
#define MEMBERMANAGER_H

#include "ClassTypes.h"
#include "Member.h"
// Member 객체들을 관리하는 class
class MemberManager
{
private:
    int numberOfMembers = 0;
    Member memberList[MAX_NUM_OF_MEMBERS];

public:
    MemInfo currentMember; //현재 로그인한 회원의 정보를 담고 있음

    void addNewMember(std::string name, std::string password, std::string phoneNumber);
    void signIn(MemInfo userInfo);
    void signOut();
    MemInfo getCurrentUser();
};

#endif // MEMBERMANAGER_H
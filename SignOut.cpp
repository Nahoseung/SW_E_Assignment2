#include "SignOut.h"

SignOut::SignOut(std::ofstream& outputF)
    : signOutUI(outputF)
{
}

/*
	함수 이름 : signOut
	기능	  : 로그 아웃
	전달 인자 :  meber 객체를 관리하는 Manager 인스턴스
	반환값    : 없음
*/
void SignOut::signOut(MemberManager* memberManager)
{
    std::string currentMemberName = memberManager->currentMember.name; 
    memberManager->signOut();
    signOutUI.showSignOutInfo(currentMemberName); 
    return;
}
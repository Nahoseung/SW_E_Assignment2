#include "SignIn.h"

SignIn::SignIn(std::ifstream& inputF, std::ofstream& outputF)
    : signInUI(inputF, outputF)
{
}

/*
	함수 이름 : signIn
	기능	  : 로그인
	전달 인자 :  meber 객체를 관리하는 Manager 인스턴스
	반환값    : 없음
*/
void SignIn::signIn(MemberManager* memberManager)
{
    MemInfo userInfo;

    userInfo = signInUI.getUserInfo();
    memberManager->signIn(userInfo);

    signInUI.showSignInResult(userInfo); 
    return;
}
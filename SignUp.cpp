#include "SignUp.h"

SignUp::SignUp(std::ifstream& inputF, std::ofstream& outputF)
    : signUpUI(inputF, outputF)
{
}

/*
	함수 이름 : signUp
	기능	  : 회원가입
	전달 인자 :  meber 객체를 관리하는 Manager 인스턴스 
	반환값    : 없음
*/
void SignUp::signUp(MemberManager* memberManager)
{
    MemInfo userInfo;

    userInfo = signUpUI.getMemInfo();
    memberManager->addNewMember(userInfo.name, userInfo.password, userInfo.phoneNumber);

    signUpUI.showMemInfo(userInfo);
    return;
}
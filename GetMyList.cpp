#include "GetMyList.h"
// 입출력 파일을 매개변수로 받기 위한 생성자
GetMyList::GetMyList(std::ofstream& outputF)
    : getMyListUI(outputF)
{
}


/*
	함수 이름 : getMyList
	기능	  : 자신이 대여한 자전거 리스트 조회
	전달 인자 :  meber 객체를 관리하는 Manager 인스턴스, bicycle 객체를 관리하는 Manager 인스턴스
	반환값    : 없음
*/
void GetMyList::getMyList(MemberManager* memberManager, BicycleManager* bicycleManager)
{
    MemInfo memberInfo;
    int len;
    memberInfo = memberManager->getCurrentUser();
    len = bicycleManager->getRentedList(this->myList, memberInfo);
    getMyListUI.showList(this->myList, len); 
    return;
}
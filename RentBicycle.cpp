#include "RentBicycle.h"

RentBicycle::RentBicycle(std::ifstream& inputF, std::ofstream& outputF)
    : rentBicycleUI(inputF, outputF)
{
}

/*
	함수 이름 : rental
	기능	  : 자전거를 대여
	전달 인자 :  meber 객체를 관리하는 Manager 인스턴스 ,bicycle 객체를 관리하는 Manager 인스턴스
	반환값    : 없음
*/
void RentBicycle::rental(MemberManager* memberManager, BicycleManager* bicycleManager)
{
    BicycleInfo bikeInfo;
    MemInfo memberInfo;

    bikeInfo = rentBicycleUI.getBicycleInfo();
    memberInfo = memberManager->getCurrentUser();

    bikeInfo.renter = memberInfo.name; 
    bikeInfo = bicycleManager->rentBicycle(memberInfo, bikeInfo);

    rentBicycleUI.showRentalInfo(bikeInfo); 
    return;
}
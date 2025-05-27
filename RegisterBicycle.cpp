#include "RegisterBicycle.h"

RegisterBicycle::RegisterBicycle(std::ifstream& inputF, std::ofstream& outputF)
    : registerBicycleUI(inputF, outputF)
{
}

/*
	함수 이름 : registerBicycle
	기능	  : 새로운 자전거를 등록
	전달 인자 :  bicycle 객체를 관리하는 Manager 인스턴스
	반환값    : 없음
*/
void RegisterBicycle::registerBicycle(BicycleManager* bicycleManager)
{
    BicycleInfo bikeInfo;
    bikeInfo = registerBicycleUI.getBicycleInfo();
    bicycleManager->addNewBicycle(bikeInfo.id, bikeInfo.name);

    registerBicycleUI.showBicycleRegistrationInfo(bikeInfo); 
    return;
}

#include <iostream>
#include <fstream>
#include <string>

// 각 컨트롤 클래스 및 관리자 클래스 헤더 포함
#include "SignUp.h"
#include "SignIn.h"
#include "SignOut.h"
#include "RegisterBicycle.h"
#include "RentBicycle.h"
#include "GetMyList.h"
#include "MemberManager.h"
#include "BicycleManager.h"


#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

void doTask(std::ifstream& inputFile, std::ofstream& outputFile); 

/****************** MAIN *********************/
int main()
{
    std::ifstream inputFile(INPUT_FILE_NAME);
    std::ofstream outputFile(OUTPUT_FILE_NAME);

    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open input file " << INPUT_FILE_NAME << std::endl;
        return 1;
    }
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not open output file " << OUTPUT_FILE_NAME << std::endl;
        return 1;
    }

    doTask(inputFile, outputFile);

    return 0;
}

void doTask(std::ifstream& inputFile, std::ofstream& outputFile)
{
    /************** CONTROL CLASS Instances *****************/
    SignUp signUpInstance(inputFile, outputFile);
    SignIn signInInstance(inputFile, outputFile);
    SignOut signOutInstance(outputFile);
    RegisterBicycle registerBicycleInstance(inputFile, outputFile);
    RentBicycle rentBicycleInstance(inputFile, outputFile);
    GetMyList getMyListInstance(outputFile);
    /************** Entity CLASS Instances *****************/
    MemberManager memberManagerInstance;
    BicycleManager bicycleManagerInstance;

    int menuLevel1 = 0, menuLevel2 = 0;
    int isProgramExit = 0;
    
    //  관리자 계정 등록
    memberManagerInstance.addNewMember("admin","admin","");

    while (!isProgramExit)
    {
        inputFile >> menuLevel1 >> menuLevel2;

        switch (menuLevel1)
        {
        case 1:
        {
            switch (menuLevel2)
            {
            case 1:
            {
                //  회원가입
                signUpInstance.signUp(&memberManagerInstance);
                break;
            }
            } // switch(menuLevel2)
            break;
        } // case 1

        case 2:
        {
            switch (menuLevel2)
            {
            case 1:
            {
                // 로그인
                signInInstance.signIn(&memberManagerInstance);
                break;
            }

            case 2:
            {
                // 로그 아웃
                signOutInstance.signOut(&memberManagerInstance);
                break;
            }
            } // switch(menuLevel2)
            break;
        } // case 2

        case 3:
        {
            switch (menuLevel2)
            {
            case 1:
            {
                // 자전거 등록
                registerBicycleInstance.registerBicycle(&bicycleManagerInstance);
                break;
            }
            } // switch(menuLevel2)
            break;
        } // case 3

        case 4:
        {
            switch (menuLevel2)
            {
            case 1:
            {
                // 자전거 대여
                rentBicycleInstance.rental(&memberManagerInstance, &bicycleManagerInstance);
                break;
            }
            } // switch(menuLevel2)
            break;
        } // case 4

        case 5:
        {
            switch (menuLevel2)
            {
            case 1:
            {
                // 대여 중인 자전거 리스트 조회
                getMyListInstance.getMyList(&memberManagerInstance, &bicycleManagerInstance);
                break;
            }
            } // switch(menuLevel2)
            break;
        } // case 5

        case 6:
        {
            switch (menuLevel2)
            {
            case 1:
            {
                // Program Exit
                isProgramExit = 1;
                break;
            }
            break;
            } // switch(menuLevel2)
        } // case 6
        } // switch(menuLevel1)
    }  // while(!isProgramExit)

    return;
}


#include "class.h"

#define MAX_STRING 32
#define TEST 0

#if TEST
#define INPUT_FILE_NAME "txt/test_input.txt"
#define OUTPUT_FILE_NAME "txt/test_output.txt"

#else
#define INPUT_FILE_NAME "txt/input.txt"
#define OUTPUT_FILE_NAME "txt/output.txt"
#endif

void doTask();
void program_exit();

ofstream outputFile;
ifstream inputFile;

/************* CLASS FUNCTIONS ***************/

// * 회원 가입
void SignUp::signUp(MemberManager* memberManager)
{
    MemInfo userInfo;

    userInfo = signUpUI.getMemInfo();
    memberManager->addNewMember(userInfo.name, userInfo.password, userInfo.phoneNumber);

    cout << userInfo.name << userInfo.password << userInfo.phoneNumber << endl;
    outputFile << userInfo.name << " " << userInfo.password << " " << userInfo.phoneNumber << endl;
}

MemInfo SignUpUI::getMemInfo()
{
    MemInfo userInfo;
    inputFile >> userInfo.name >> userInfo.password >> userInfo.phoneNumber;
    return userInfo;
}

void MemberManager::addNewMember(string name, string password, string phoneNumber)
{
    Member newMember(name, password, phoneNumber);
    if (numberOfMembers < MAX_NUM_OF_MEMBERS)
    {
        this->memberList[this->numberOfMembers++] = newMember;
    }
}

// * 로그인/로그아웃
void SignIn::signIn(MemberManager* memberManager)
{
    MemInfo userInfo;

    userInfo = signInUI.getUserInfo();
    memberManager->signIn(userInfo);

    cout << userInfo.name << userInfo.password << endl;
    outputFile << userInfo.name << " " << userInfo.password << endl;
    return;
}

MemInfo SignInUI::getUserInfo()
{
    MemInfo userInfo;
    inputFile >> userInfo.name >> userInfo.password;

    return userInfo;
}

void SignOut::signOut(MemberManager* memberManager)
{
    outputFile << memberManager->currentMember.name << endl;
    memberManager->signOut();
    return;
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

// * 자전거 등록
void RegisterBicycle::registerBicycle(BicycleManager* bicycleManager)
{
    BicycleInfo bikeInfo;
    bikeInfo = registerBicycleUI.getBicycleInfo();
    bicycleManager->addNewBicycle(bikeInfo.id, bikeInfo.name);

    cout << bikeInfo.id << bikeInfo.name << endl;
    outputFile << bikeInfo.id << " " << bikeInfo.name << endl;
}

BicycleInfo RegisterBicycleUI::getBicycleInfo()
{
    BicycleInfo bikeInfo;
    inputFile >> bikeInfo.id >> bikeInfo.name;
    bikeInfo.renter = "NULL";

    return bikeInfo;
}

void BicycleManager::addNewBicycle(string id, string name)
{
    Bicycle newBike(id, name);
    if (numberOfBicycles < 50)
    {
        this->bicycleList[this->numberOfBicycles++] = newBike;
    }
}

// * 자전거 대여
void RentBicycle::rental(MemberManager* memberManager, BicycleManager* bicycleManager)
{
    BicycleInfo bikeInfo;
    MemInfo memberInfo;

    bikeInfo = rentBicycleUI.getBicycleInfo();
    memberInfo = memberManager->getCurrentUser();

    bikeInfo.renter = memberInfo.name;
    bikeInfo = bicycleManager->rentBicycle(memberInfo, bikeInfo);

    cout << bikeInfo.id << bikeInfo.name << endl;
    outputFile << bikeInfo.id << " " << bikeInfo.name << endl;
}

BicycleInfo BicycleManager::rentBicycle(MemInfo memberInfo, BicycleInfo bikeInfo)
{
    int i = 0;
    while (bikeInfo.id != bicycleList[i].getId()) i++;

    bikeInfo.name = bicycleList[i].getName();

    bicycleList[i].setRenter(memberInfo.name);

    return bikeInfo;
}

MemInfo MemberManager::getCurrentUser()
{
    return this->currentMember;
}

BicycleInfo RentBicycleUI::getBicycleInfo()
{
    BicycleInfo bikeInfo;
    inputFile >> bikeInfo.id;
    return bikeInfo;
}

// * 자전거 대여 리스트 조회
void GetMyList::getMyList(MemberManager* memberManager, BicycleManager* bicycleManager)
{
    MemInfo memberInfo;
    int len;
    memberInfo = memberManager->getCurrentUser();
    len = bicycleManager->getRentedList(this->myList, memberInfo);
    getMyListUI.showList(this->myList, len);
}

void GetMyListUI::showList(BicycleInfo myList[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << myList[i].id << " " << myList[i].name << endl;
        outputFile << myList[i].id << " " << myList[i].name << endl;
    }
}

int BicycleManager::getRentedList(BicycleInfo myList[], MemInfo memberInfo)
{
    int len = 0;
    for (int i = 0; i < this->numberOfBicycles; i++)
    {
        if (memberInfo.name == this->bicycleList[i].getRenter())
        {
            myList[len++] = this->bicycleList[i].getBicycleInfo();
        }
    }
    return len;
}

/****************** MAIN *********************/
int main()
{
    inputFile.open(INPUT_FILE_NAME);
    outputFile.open(OUTPUT_FILE_NAME);

    doTask();

    outputFile.close();
    inputFile.close();

    return 0;
}

void doTask()
{
    /************** CONTROL CLASS Instances *****************/
    SignUp signUpInstance;
    SignIn signInInstance;
    SignOut signOutInstance;
    RegisterBicycle registerBicycleInstance;
    RentBicycle rentBicycleInstance;
    GetMyList getMyListInstance;
    /************** Entity CLASS Instances *****************/
    MemberManager memberManagerInstance;
    BicycleManager bicycleManagerInstance;

    int menuLevel1 = 0, menuLevel2 = 0;
    int isProgramExit = 0;

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
                // * 회원가입
                signUpInstance.signUp(&memberManagerInstance);
                break;
            }
            } // * switch(menuLevel2)
            break;
        } // * case 1

        case 2:
        {
            switch (menuLevel2)
            {
            case 1:
            {
                // * 로그인
                signInInstance.signIn(&memberManagerInstance);
                break;
            }

            case 2:
            {
                // * 로그 아웃
                signOutInstance.signOut(&memberManagerInstance);
                break;
            }
            } // * switch(menuLevel2)
            break;
        } // * case 2

        case 3:
        {
            switch (menuLevel2)
            {
            case 1:
            {
                // * 자전거 등록
                registerBicycleInstance.registerBicycle(&bicycleManagerInstance);
                break;
            }
            } // * switch(menuLevel2)
            break;
        } // * case 3

        case 4:
        {
            switch (menuLevel2)
            {
            case 1:
            {
                // * 자전거 대여
                rentBicycleInstance.rental(&memberManagerInstance, &bicycleManagerInstance);
                break;
            }
            } // * switch(menuLevel2)
            break;
        } // * case 4

        case 5:
        {
            switch (menuLevel2)
            {
            case 1:
            {
                // * 대여 중인 자전거 리스트 조회
                getMyListInstance.getMyList(&memberManagerInstance, &bicycleManagerInstance);
                break;
            }
            } // * switch(menuLevel2)
            break;
        } // * case 5

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
            } // * switch(menuLevel2)
        } // * case 6
        } // * switch(menuLevel1)
    }     // * while(!isProgramExit)

    cout << "LAST LOGIN USER : " << memberManagerInstance.currentMember.name << endl;
}
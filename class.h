#include <iostream>
#include <string>
#include <fstream>
#define MAX_NUM_OF_MEMBERS 10
using namespace std;

/************* 회원 가입 ***************/
typedef struct
{
    string name;
    string password;
    string phoneNumber;
} MemInfo;

class Member
{
private:
    MemInfo memberInfo;

public:
    Member()
    {
        memberInfo.name = "";
        memberInfo.password = "";
        memberInfo.phoneNumber = "";
    }

    Member(string name, string password, string phoneNumber)
    {
        this->memberInfo.name = name;
        this->memberInfo.password = password;
        this->memberInfo.phoneNumber = phoneNumber;
    }
};

class MemberManager
{
private:
    int numberOfMembers = 0;
    Member memberList[MAX_NUM_OF_MEMBERS];

public:
    MemInfo currentMember;

    void addNewMember(string name, string password, string phoneNumber);
    void signIn(MemInfo userInfo);
    void signOut();
    MemInfo getCurrentUser();
};

class SignUpUI
{
private:
public:
    MemInfo getMemInfo();
    void showMemInfo(MemInfo userInfo); 
};

class SignUp
{
private:
    SignUpUI signUpUI;

public:
    void signUp(MemberManager* memberManager);
};

/********* 로그인/로그아웃 *********/
class SignInUI
{
private:
public:
    MemInfo getUserInfo();
    void showSignInResult(MemInfo userInfo); 
};

class SignIn
{
private:
    SignInUI signInUI;

public:
    void signIn(MemberManager* memberManager);
};

class SignOutUI 
{
private:
public:
    void showSignOutInfo(string memberName); 
};

class SignOut
{
private:
    SignOutUI signOutUI; 
public:
    void signOut(MemberManager* memberManager);
};

/********* 자전거 등록 *********/
typedef struct
{
    string id;
    string name;
    string renter;
} BicycleInfo;

class Bicycle
{
private:
    BicycleInfo bikeInfo;
public:
    Bicycle()
    {
        bikeInfo.id = "";
        bikeInfo.name = "";
    }

    Bicycle(string id, string name)
    {
        this->bikeInfo.id = id;
        this->bikeInfo.name = name;
    }

    string getId() const { return bikeInfo.id; }
    string getName() const { return bikeInfo.name; }
    string getRenter() const { return bikeInfo.renter; }
    void setRenter(string renterName) { bikeInfo.renter = renterName; }
    BicycleInfo getBicycleInfo() const {return bikeInfo;}
};

class BicycleManager
{
private:
    int numberOfBicycles = 0;
    Bicycle bicycleList[50];
public:
    void addNewBicycle(string id, string name);
    BicycleInfo rentBicycle(MemInfo memberInfo, BicycleInfo bikeInfo);
    int getRentedList(BicycleInfo myList[], MemInfo memberInfo);
};

class RegisterBicycleUI
{
private:
public:
    BicycleInfo getBicycleInfo();
    void showBicycleRegistrationInfo(BicycleInfo bikeInfo); 
};

class RegisterBicycle
{
private:
    RegisterBicycleUI registerBicycleUI;

public:
    void registerBicycle(BicycleManager* bicycleManager);
};

/********* 자전거 대여 *********/
class RentBicycleUI
{
private:
public:
    BicycleInfo getBicycleInfo();
    void showRentalInfo(BicycleInfo bikeInfo); 
};

class RentBicycle
{
private:
    RentBicycleUI rentBicycleUI;

public:
    void rental(MemberManager* memberManager, BicycleManager* bicycleManager);
};

/********* 대여 중인 자전거 리스트 조회 *********/

class GetMyListUI
{
private:
public:
    void showList(BicycleInfo myList[], int length); 
};

class GetMyList
{
private:
    GetMyListUI getMyListUI;

public:
    BicycleInfo myList[50];
    void getMyList(MemberManager* memberManager, BicycleManager* bicycleManager);
};
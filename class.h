#include <iostream>
#include <string>
#include <fstream>
#define MAX_NUM_OF_MEMBERS 10
using namespace std;



/************* 회원 가입  ***************/
typedef struct {
    string name;
    string pwd;
    string digit;
}mem_info;

class Customer
{
private:
    mem_info M_info;
    // * NOT YET * //

public:
    Customer()
    {
        M_info.name = "";
        M_info.pwd = "";
        M_info.digit = "";
    }

    Customer(string name,string pwd, string digit)
    {
        this->M_info.name = name; 
        this->M_info.pwd = pwd;
        this->M_info.digit = digit;
    }
};

//* Entity class를 이렇게 사용해도 되나 ?
class Member_manager
{
private:
    // * NOT YET * //
    int num_of_memebr=0;
    Customer member_list[MAX_NUM_OF_MEMBERS];
    
public:
    mem_info curr_member;

    void Add_New_Member(string name,string pwd,string digit);
    void signin(mem_info usr_info);
    void signout();
    mem_info get_curr_usr();
}; // * Member



class SignUpUI
{
private: 
    // * NOT YET * //
    
public:
    mem_info get_mem_info();
}; // * SignUpUI



class SignUp
{
private:
    SignUpUI UI;

public:
    void signup(Member_manager* member_manager);
}; // * SignUp

/********* 로그인/로그 아웃 *********/
class SignInUI
{
private:

public:
    mem_info get_usr_info();
};


class SignIn
{
private:
    SignInUI UI;

public: 
    void signin(Member_manager* member_manager);
};

class SignOut
{
private:

public:
    void signout(Member_manager* member_manager);
};


/********* 자전거 등록 *********/

typedef struct {
    string ID;
    string name;
    string renter;
}bicycle_info;

class Bicycle
{
private:
    
    // * NOT YET * //

public:
    bicycle_info B_info; // * Getter,setter 설정 필요
    Bicycle()
    {
        B_info.ID="";
        B_info.name="";
    }

    Bicycle(string ID,string name)
    {
        this->B_info.ID = ID; 
        this->B_info.name = name;
    }
};

class Bicycle_manager
{
private:
    int num_of_Bicycle=0;
    Bicycle bicycle_list[50];

    /*NOT YET*/
public:
    int num_of_renataled_Bicycle =0;
    bicycle_info rentaled_Bicycle[50];
    
    void Add_New_Bicycle(string ID,string name);
    bicycle_info Rent_Bicycle(bicycle_info B_info);
};

class RegisterUI
{
private:
    /*NOT YET*/
public:
    bicycle_info get_bicycle_info();
};

class Register
{
private:
    /*NOT YET*/
    RegisterUI UI;
    // Bicycle_manager bicycle_manager;

public:
    void regist(Bicycle_manager* bicycle_manager);
};


/********* 자전거 대여 *********/
class RentUI
{
private:

public:
    bicycle_info get_Bicycle_info();
};


class Rent
{
private:
    RentUI UI;
public:
    void Rental(Member_manager* member_manager, Bicycle_manager* bicycle_manager);
};


/********* 대여 중인 자전거 리스트 조회 *********/

class Get_my_listUI
{
private:

public:
    void Show_list(bicycle_info my_list[],int len);
};

class Get_my_list
{
private:
    Get_my_listUI UI;
public: 
    bicycle_info my_list [50];
    void get_rentaled_list(Member_manager* member_manager, Bicycle_manager* bicycle_manager);
};
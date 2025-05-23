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
    string name;
    string pwd;
    string digit;
    // * NOT YET * //

public:
    Customer()
    {
        name = "";
        pwd = "";
        digit = "";
    }

    Customer(string name,string pwd, string digit)
    {
        this->name = name; 
        this->pwd = pwd;
        this->digit = digit;
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
    Customer curr_member;

    void Add_New_Member(string name,string pwd,string digit);
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
    Member_manager member_manager;

public:
    void signup();
}; // * SignUp


/********* 자전거 등록 *********/

typedef struct {
    string ID;
    string name;
}bicycle_info;

class Bicycle
{
private:
    string ID;
    string name;
    // * NOT YET * //

public:
    Bicycle()
    {
        ID="";
        name="";
    }

    Bicycle(string ID,string name)
    {
        this->ID = ID; 
        this->name = name;
    }
};

class Bicycle_manager
{
private:
    int num_of_Bicycle=0;
    Bicycle bicycle_list[50];
    /*NOT YET*/
public:
    void Add_New_Bicycle(string ID,string name);
    
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
    Bicycle_manager bicycle_manager;

public:
    void regist();
};
#include <iostream>
#include <string>
#include <fstream>
#define MAX_NUM_OF_MEMBERS 10
using namespace std;




typedef struct {
    string name;
    string pwd;
    string digit;
}info;


/************* CLASS  ***************/
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
    info get_info();
}; // * SignUpUI



class SignUp
{
private:
    SignUpUI UI;
    Member_manager member_manager;

public:
    void signup();
}; // * SignUp
#include <iostream>
#include <string>
#include <fstream>

#define MAX_STRING 32
#define INPUT_FILE_NAME "intput.txt"
#define OUTPUT_FILE_NAME "output.txt"


using namespace std;

void doTask();
void join();
void program_exit();

ofstream out_fp;
ifstream in_fp;


int main()
{
    in_fp.open(INPUT_FILE_NAME);
    out_fp.open(OUTPUT_FILE_NAME);

    doTask();

    out_fp.close();
    in_fp.close();

    return 0;
}


void doTask()
{
    int menu_level_1 =0 , menu_level_2 =0;
    int is_program_exit =0;

    while(!is_program_exit)
    {
        in_fp >> menu_level_1 >> menu_level_2 ;
        
        switch(menu_level_1)
        {
            case 1:
            {
                switch(menu_level_2)
                {
                    case 1:
                    {
                        /* 회원 가입 */

                        break;
                    }
                } // * switch(menu_level_2)
            } // * case 1

            case 2:
            {
                switch(menu_level_2)
                {
                    case 1: 
                    {
                        /* 로그인 */

                        break;
                    }

                    case 2:
                    {
                        /* 로그 아웃 */

                        break;
                    }
                } // * switch(menu_level_2)
            } // * case 2

            case 3:
            {
                switch(menu_level_2)
                {
                    case 1:
                    {
                        /* 자전거 등록 */

                        break;
                    }
                } // * switch(menu_level_2)
            } // * case 3

            case 4:
            {
                switch(menu_level_2)
                {
                    case 1:
                    {
                        /* 자전거 대여 */

                        break;
                    }
                } // * switch(menu_level_2)
            } // * case 4

            case 5:
            {
                switch(menu_level_2)
                {
                    case 1:
                    {
                        /* 대여 중인 자전거 리스트 조회 */

                        break;
                    }
                } // * switch(menu_level_2)
            } // * case 5

            case 6:
            {
                switch(menu_level_2)
                {
                    case 1:
                    {
                        /* 프로그램 종료 */

                        is_program_exit = 1;
                        break;
                    }
                } // * switch(menu_level_2)
            } // * case 6

        } // * switch(menu_level_1)

    } // * while(!is_program_exit)
}

/************* ALL CLASS DEF  ***************/

typedef struct {
    string name;
    int pwd;
    int digit;
}info;


class Customer
{
private:
    string name;
    int pwd;
    int digit;
    // * NOT YET * //
public:
    Customer(string name,int pwd, int digit);
};

class Member_manager
{
private:
    // * NOT YET * //
    int num_of_memebr=0;
    Customer* member_list[10];
    
public:
    void Add_New_Member(string name,int pwd,int digit)
    {
        Customer New_mem(name,pwd,digit);
        this->member_list[this->num_of_memebr++] = &New_mem;
    }
}; // * Member



class SignUpUI
{
private: 
    // * NOT YET * //
public:
    info* get_info()
    {
        info* usr_info;
        in_fp >> usr_info->name >> usr_info->pwd >> usr_info->digit;

        return usr_info;
    }
}; // * SignUpUI



class SignUp
{
private:
    string Name;
    int pwd;
    int digit;

    SignUpUI UI;
    Member_manager member_manager;

public:
    void signup()
    {
        info* usr_info;

        usr_info = UI.get_info();
        member_manager.Add_New_Member(usr_info->name,usr_info->pwd,usr_info->digit);
    }

}; // * SignUp


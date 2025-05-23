#include "class.h"

#define MAX_STRING 32
#define test 1

#if test
#define INPUT_FILE_NAME "txt/test_input.txt"
#define OUTPUT_FILE_NAME "txt/test_output.txt"

#else
#define INPUT_FILE_NAME "txt/intput.txt"
#define OUTPUT_FILE_NAME "txt/output.txt"
#endif



void doTask();
void join();
void program_exit();

ofstream out_fp;
ifstream in_fp;

/************* CLASS FUNCTIONS ***************/

void Member_manager::Add_New_Member(string name,string pwd,string digit)
{
    Customer New_mem(name,pwd,digit);
    if(num_of_memebr<10)
    {
        this->member_list[this->num_of_memebr++] = New_mem;
    }      
}


info SignUpUI::get_info()
{
    info usr_info;
    in_fp >> usr_info.name >> usr_info.pwd >> usr_info.digit;

    return usr_info;
}


void SignUp::signup()
{
    info usr_info;
        
    usr_info = UI.get_info();
    member_manager.Add_New_Member(usr_info.name,usr_info.pwd,usr_info.digit);

    cout << usr_info.name << usr_info.pwd << usr_info.digit<<endl;
    out_fp << usr_info.name << " " << usr_info.pwd << " " << usr_info.digit << endl;
}




/************** MAIN *********************/
int main()
{
    in_fp.open(INPUT_FILE_NAME);
    if (!in_fp) {
        cout << "Error: Unable to open input file " << INPUT_FILE_NAME << endl;
        return 1;
    }

    out_fp.open(OUTPUT_FILE_NAME);
    if (!out_fp) {
        cout << "Error: Unable to open output file " << OUTPUT_FILE_NAME << endl;
        in_fp.close();
        return 1;
    }

    doTask();

    out_fp.close();
    in_fp.close();

    return 0;
}


void doTask()  
{
    /************** Instances *****************/
    SignUp signup_instance;
    Member_manager mem_manager_instacne;

    int menu_level_1 =0 , menu_level_2 =0;
    int is_program_exit = 0;

    

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
                        signup_instance.signup();
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


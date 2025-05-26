#include "class.h"

#define MAX_STRING 32
#define test 0

#if test
#define INPUT_FILE_NAME "txt/test_input.txt"
#define OUTPUT_FILE_NAME "txt/test_output.txt"

#else
#define INPUT_FILE_NAME "txt/input.txt"
#define OUTPUT_FILE_NAME "txt/output.txt"
#endif



void doTask();
void join();
void program_exit();

ofstream out_fp;
ifstream in_fp;

/************* CLASS FUNCTIONS ***************/

    /*회원 가입*/
void SignUp::signup(Member_manager* member_manager)
{
    mem_info usr_info;
        
    usr_info = UI.get_mem_info();
    member_manager->Add_New_Member(usr_info.name,usr_info.pwd,usr_info.digit);

    cout << usr_info.name << usr_info.pwd << usr_info.digit<<endl;
    out_fp << usr_info.name << " " << usr_info.pwd << " " << usr_info.digit << endl;
}

mem_info SignUpUI::get_mem_info()
{
    mem_info usr_info;
    in_fp >> usr_info.name >> usr_info.pwd >> usr_info.digit;
    return usr_info;
}

void Member_manager::Add_New_Member(string name,string pwd,string digit)
{
    Customer New_mem(name,pwd,digit);
    if(num_of_memebr<10)
    {
        this->member_list[this->num_of_memebr++] = New_mem;
    }      
}
    /*로그인/로그아웃*/
void SignIn::signin(Member_manager* member_manager)
{
    mem_info usr_info;

    usr_info = UI.get_usr_info();
    member_manager->signin(usr_info);

    cout << usr_info.name << usr_info.pwd <<endl;
    out_fp << usr_info.name << " " << usr_info.pwd << endl;
    return;
}

mem_info SignInUI::get_usr_info()
{
    mem_info usr_info;
    in_fp >> usr_info.name >> usr_info.pwd;

    return usr_info;
}

void SignOut::signout(Member_manager* member_manager)
{
    out_fp << member_manager->curr_member.name << endl;
    member_manager->signout();
    return;
}


void Member_manager::signin(mem_info usr_info)
{
    this->curr_member = usr_info;
    return;
}


void Member_manager::signout()
{
    this->curr_member.name = "NULL";
    this->curr_member.pwd = "NULL";
    this->curr_member.digit = "NULL";
    return;
}

    /*자전거 등록*/
void Register::regist(Bicycle_manager* bicycle_manager)
{
    bicycle_info b_info;
    b_info = UI.get_bicycle_info();
    bicycle_manager->Add_New_Bicycle(b_info.ID, b_info.name);

    cout << b_info.ID << b_info.name <<endl;
    out_fp << b_info.ID << " "<< b_info.name << endl;
}

bicycle_info RegisterUI::get_bicycle_info()
{
    bicycle_info b_info;
    in_fp >> b_info.ID >> b_info.name;
    b_info.renter="NULL";

    return b_info;
}

void Bicycle_manager::Add_New_Bicycle(string ID,string name)
{
    Bicycle New_B(ID,name);
    if(num_of_Bicycle<50)
    {
        this->bicycle_list[this->num_of_Bicycle++] = New_B;
    }
}

    /*자전거 대여*/
void Rent::Rental(Member_manager* member_manager, Bicycle_manager* bicycle_manager)
{
    bicycle_info B_info;
    mem_info M_info;

    B_info = UI.get_Bicycle_info();
    M_info = member_manager->get_curr_usr();
    B_info.renter = M_info.name;
    B_info = bicycle_manager->Rent_Bicycle(B_info);

    cout << B_info.ID << B_info.name <<endl;
    out_fp << B_info.ID << " "<< B_info.name << endl;
}

bicycle_info Bicycle_manager::Rent_Bicycle(bicycle_info B_info)
{
    if(num_of_renataled_Bicycle<50)
    {
        int i=0;
        while(B_info.ID != bicycle_list[i].B_info.ID) i++;

        B_info.name = bicycle_list[i].B_info.name;
        this->rentaled_Bicycle[num_of_renataled_Bicycle++]=B_info;
    }

    return B_info;
}
mem_info Member_manager::get_curr_usr()
{
    return this->curr_member;
}
bicycle_info RentUI::get_Bicycle_info()
{
    bicycle_info B_info;
    in_fp >> B_info.ID;
    return B_info;
}

    /* 자전거 대여 리스트 조회 */
    
void Get_my_list::get_rentaled_list(Member_manager* member_manager, Bicycle_manager* bicycle_manager)
{
    mem_info M_info;
    int j=0;
    M_info = member_manager->get_curr_usr();
    
    for(int i=0; i< bicycle_manager->num_of_renataled_Bicycle; i++)
    {
        // cout<< M_info.name << " : " << bicycle_manager->rentaled_Bicycle[i].name << "(" << bicycle_manager->rentaled_Bicycle[i].
        if(M_info.name == bicycle_manager->rentaled_Bicycle[i].renter)
        {
            this->my_list[j++] = bicycle_manager->rentaled_Bicycle[i];
        }
    }
    UI.Show_list(this->my_list,j);
}

void Get_my_listUI::Show_list(bicycle_info my_list[],int len)
{
    for(int i=0; i<len; i++)
    {
        cout << my_list[i].ID << " "<< my_list[i].name << endl;
        out_fp << my_list[i].ID << " "<< my_list[i].name << endl;
    }
}

/****************** MAIN *********************/
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
    /************** CONTROL CLASS Instances *****************/
    SignUp signup_instance;
    SignIn signin_instance;
    SignOut signout_instance;
    Register register_instance;
    Rent Rent_instance;
    Get_my_list get_my_list_instance;
    /************** Entity CLASS Instances *****************/
    Member_manager mem_manager_instacne;
    Bicycle_manager B_manager_instance;


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
                        signup_instance.signup(&mem_manager_instacne);
                        break;
                    }
                } // * switch(menu_level_2)
                break;
            } // * case 1

            case 2:
            {
                switch(menu_level_2)
                {
                    case 1: 
                    {
                        /* 로그인 */
                        signin_instance.signin(&mem_manager_instacne);
                        break;
                    }

                    case 2:
                    {
                        /* 로그 아웃 */
                        signout_instance.signout(&mem_manager_instacne);
                        break;
                    }
                } // * switch(menu_level_2)
                break;
            } // * case 2

            case 3:
            {
                switch(menu_level_2)
                {
                    case 1:
                    {
                        /* 자전거 등록 */
                        register_instance.regist(&B_manager_instance);
                        break;
                    }
                } // * switch(menu_level_2)
                break;
            } // * case 3

            case 4:
            {
                switch(menu_level_2)
                {
                    case 1:
                    {
                        /* 자전거 대여 */
                        Rent_instance.Rental(&mem_manager_instacne, &B_manager_instance);
                        break;
                    }
                } // * switch(menu_level_2)
                break;
            } // * case 4

            case 5:
            {
                switch(menu_level_2)
                {
                    case 1:
                    {
                        /* 대여 중인 자전거 리스트 조회 */
                        get_my_list_instance.get_rentaled_list(&mem_manager_instacne,&B_manager_instance);
                        break;
                    }
                } // * switch(menu_level_2)
                break;
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


    cout<<"LAST LOGIN USER : "<<mem_manager_instacne.curr_member.name << endl;
}


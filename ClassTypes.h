#ifndef CLASSTYPES_H
#define CLASSTYPES_H

#include <string>
#include <iostream>
#include <fstream>

#define MAX_NUM_OF_MEMBERS 10
// 회원의 정보를 담고있는 구조체
typedef struct
{
    std::string name;
    std::string password;
    std::string phoneNumber;
} MemInfo;
// 자전거의 정보를 담고있는 구조체
typedef struct
{
    std::string id;
    std::string name;
    std::string renter;
} BicycleInfo;

#endif // CLASSTYPES_H
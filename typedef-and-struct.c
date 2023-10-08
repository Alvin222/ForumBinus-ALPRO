//
// Created by User on 08/10/2023.
//
#include <stdio.h>
#include <string.h>

//mendefinisikan struct dengan typedef
typedef struct {
  char name[100];
  char phoneNumber[100];
  char address[100];
} ContactInfo;

//mendefinisikan struct tanpa typedef
struct PersonalInfo{
    char name[100];
    char nickname[100];
    char hobby[100];
};

int main() {
    //deklarasi variable dengan tipe ContactInfo
    ContactInfo contactInfo;
    strcpy(contactInfo.name,"Andre Andreas");
    strcpy(contactInfo.phoneNumber,"081234567890");
    strcpy(contactInfo.address,"Jalan Sukarelawan No 3");

    printf("Contact Name : %s\n",contactInfo.name);
    printf("Contact Number : %s\n",contactInfo.phoneNumber);
    printf("Contact Address : %s\n",contactInfo.address);

    //deklarasi variable dengan tipe PersonalInfo
    struct PersonalInfo personalInfo;
    strcpy(personalInfo.name,"Andre Andreas");
    strcpy(personalInfo.nickname,"Andrey");
    strcpy(personalInfo.hobby,"Beli paku");

    printf("Name : %s\n",personalInfo.name);
    printf("Nickname : %s\n",personalInfo.nickname);
    printf("Hobby : %s\n",personalInfo.hobby);
}

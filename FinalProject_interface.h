#ifndef FINALPROJECT_INTERFACE_H_
#define FINALPROJECT_INTERFACE_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node
{
    struct node *next;

    char nameP[100];
    int ageP;
    char genderP;
    int IDP;
    const char *slotsP;


}node;




typedef enum features
{
    add=1,
    edit,
    reserve,
    cancel,
    record=1,
    TodRevs

}feats;


typedef enum reservation
{
    No,
    Two,
    TwoAndHalf,
    Three,
    Four,
    FourAndHalf

}slots;




#define ADMIN 'a'
#define USER 'u'
#define EXIT 'x'
#define UNIQUE 0
#define TAKEN 1
#define MALE 'm'
#define FEMALE 'f'





//function prototypes

void insertATfirst(char *name,int age,int ID,char gender,const char *slots);


void ViewCertianID(int ID);


void DeleteAtID(int ID);


void viewList(void);


void ViewAllRes(void);


int checkID(int ID);











#endif 
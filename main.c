#include "FinalProject_interface.h"


int main()
{

    char choice_mode=ADMIN,gender,again;
    int pass_trials=0,admin_pass,ID,age,editID;
    feats featuers;
    char name[100];
    int slots=No;//  Default no reservation
    int ID_flag=TAKEN;//    True expression to the while loop to allow the user to enter the ID again.
    const char *Res[] = {
        "No reservation",
        "2pm to 2:30pm",
        "2:30pm to 3pm",
        "3pm to 3:30pm",
        "4pm to 4:30pm",
        "4:30pm to 5pm"
    };

     const char *Available_slots[] = {
         "No reservation",
        "2pm to 2:30pm",
        "2:30pm to 3pm",
        "3pm to 3:30pm",
        "4pm to 4:30pm",
        "4:30pm to 5pm"
    };





    while(again!=EXIT)
    {
        printf("Press a/A to enter Admin mode or u/U to enter User mode or any other button to exit.\n");
        scanf(" %c",&choice_mode);


        if(choice_mode==ADMIN)
        {

            while(pass_trials<3)
            {


                printf("Enter your Admin password:");
                scanf("%d",&admin_pass);
                if(admin_pass!=1234)
                {
                    pass_trials++;
                    printf("Wrong password you have %d trials left.\n",3-(pass_trials));

                }
                else{
                        pass_trials=0;
                    break;
                }
            }

                 if (pass_trials == 3)
                {
                    printf("Access denied.\n");
                    break;
                }
            printf("Welcome Admin\n");
            printf("Do you want to\n");
            printf("--------------------------------\n");
            printf(" 1)Add new patient record\n 2)Edit patient record\n 3)Reserve a slot with the doctor\n 4)Cancel reservation\n");
            printf("--------------------------------\n");
            scanf("%d",&featuers);
            switch (featuers)
            {
            case add:
                 printf("Enter the patient's name: ");
                    getchar(); // Consume the newline character left by previous scanf
                    fgets(name, sizeof(name), stdin);
                    name[strcspn(name, "\n")] = '\0'; // Remove the newline character from fgets
                    printf("Enter the patient's ID: ");
                    scanf("%d", &ID);
                    ID_flag=checkID(ID);

                    while(ID_flag==TAKEN)
                    {

                      if(ID_flag==TAKEN)
                      {
                         printf("ID is already taken try again\n");
                          scanf("%d", &ID);
                          ID_flag=checkID(ID);
                      }
                      else{
                        break;
                      }

                    }
                    printf("ID accepted.\n");

                    printf("Enter the patient's age: ");
                    scanf("%d", &age);

                    while(gender!=MALE||gender!=FEMALE)
                    {
                        printf("Enter the patient's gender (M/F): ");
                        getchar(); // Consume the newline character left by previous scanf
                        scanf(" %c", &gender);
                        if(gender==MALE||gender==FEMALE)
                        {
                            insertATfirst(name, age, ID, gender,Res[slots]);

                            viewList();
                            break;
                        }
                        else{
                            printf("\nInvalid character\n");
                        }

                    }





                break;

            case edit:
                printf("Enter the ID of the patient you would like to edit.\n");
                scanf("%d",&editID);
                ID_flag=checkID(editID);

                if(ID_flag==TAKEN)
                {

                    DeleteAtID(editID);
                    printf("Enter the patient's name: ");
                    getchar(); // Consume the newline character left by previous scanf
                    fgets(name, sizeof(name), stdin);
                    name[strcspn(name, "\n")] = '\0'; // Remove the newline character from fgets
                    printf("Enter the patient's age: ");
                    scanf("%d", &age);
                    printf("Enter the patient's gender (M/F): ");
                    getchar(); // Consume the newline character left by previous scanf
                    scanf(" %c", &gender);
                    insertATfirst(name, age, editID, gender,Res[slots]);
                    printf("List after edit:\n");
                    viewList();


                }
                else
                {
                    printf("This ID is not found.\n");
                }
                break;


           case reserve:
               printf("Enter the patients ID:");
               scanf("%d",&ID);
               ID_flag=checkID(ID);
               if(ID_flag==TAKEN)
               {
                   printf("The available slots are:\n");
                   for(int i=1;i<=5;i++)
                   {
                       if(i==slots)
                       {
                        continue;
                       }
                       else
                       {
                       printf("%d)%s\n",i,Available_slots[i]);
                       }

                   }
                   printf("Choose the time suitable for the patient\n");
                   scanf("%d",&slots);
                   DeleteAtID(ID);
                  insertATfirst(name,age,ID,gender,Res[slots]);
                  viewList();

               }
               else
               {
                   printf("This ID is has no patient record.\n");
               }

               break;

           case cancel:

            printf("Enter the patients ID:");
               scanf("%d",&ID);
               ID_flag=checkID(ID);
               if(ID_flag==TAKEN)
               {
                   slots=No;
                   DeleteAtID(ID);
                   insertATfirst(name,age,ID,gender,Res[slots]);
                   viewList();

               }
               else
               {
                   printf("This ID is has no patient record.\n");
               }

               break;

            default: printf("Invalid input.\n");

            }




        }

        else if(choice_mode==USER)
        {
            printf("Welcome user.\n");
            printf("1)View patient's record.\n2)View today's reservation.\n");
            scanf("%d",&featuers);
            switch(featuers)
            {
            case record:
                printf("Enter the patients ID:");
                scanf("%d",&ID);
                ViewCertianID(ID);
                break;

            case TodRevs:
                printf("Today's reservation:\n");
                ViewAllRes();



            }

        }

        printf("\nTo return to the main menu enter any button. To exit press 'X'\n");
        scanf(" %c",&again);



    }
    printf("Thank you.\n");


    return 0;
}


#include "FinalProject_interface.h"


static node *head=NULL;//static to avoid extern.



void insertATfirst(char *name,int age,int ID,char gender,const char *slots)
{
    node *temp=(node*)malloc(sizeof(node));

        strncpy(temp->nameP, name, sizeof(temp->nameP) - 1);
        temp->nameP[sizeof(temp->nameP) - 1] = '\0';
        temp->ageP=age;
        temp->IDP=ID;
        temp->genderP=gender;
        temp->slotsP=slots;

        temp->next=head;

        head=temp;


}






void DeleteAtID(int ID)
{
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }

    node *temp1 = head;
    node *prev = NULL;

    // Special case: The node to delete is the head
    if (head->IDP == ID) {
        node *terminate = head;
        head = head->next; // Update head to the next node
        free(terminate);
        return;
    }

    // Traverse the list to find the node to delete
    while (temp1 != NULL && temp1->IDP != ID) {
        prev = temp1;
        temp1 = temp1->next;
    }

    // If the node was found, delete it
    if (temp1 != NULL) {
        prev->next = temp1->next; // Update the previous node's next pointer
        free(temp1); // Free the memory of the node to delete
    } else {
        printf("ID not found\n");
    }
}




void ViewCertianID(int ID)
{
    if (head == NULL)
    {
        printf("Empty list\n");
    }

    node *temp = head;

    // Traverse the list to find the node with the given ID
    while (temp != NULL)
    {
        if (temp->IDP == ID)
        {
            // Print the found node's information
            printf("\n----------------------------------\n");
            printf("      Name: %s                        \n", temp->nameP);
            printf("      ID: %d                          \n", temp->IDP);
            printf("      Age: %d                         \n", temp->ageP);
            printf("      Gender: %c                      \n", temp->genderP);
            printf("      Reservation: %s                 \n", temp->slotsP);
            printf("----------------------------------\n");
            return;
        }
        temp = temp->next;
    }

    // If the ID was not found
    printf("ID not found\n");
}




void viewList(void)
{
    if(head!=NULL)
    {
        node *temp=head;
        do
        {


            printf("\n----------------------------------\n");
            printf("|      Name: %s                        \n",temp->nameP);
            printf("|      ID: %d                          \n",temp->IDP);
            printf("|      age: %d                         \n",temp->ageP);
            printf("|      Gender: %c                      \n",temp->genderP);
            printf("|      Reservation: %s                 \n", temp->slotsP);
            printf("----------------------------------\n");

            temp=temp->next;
        }while(temp!=NULL);
    }
    else
    {
        printf("Empty List\n");
    }
}




void ViewAllRes(void)
{
    if(head!=NULL)
    {
        node *temp=head;
        do
        {


            printf("\n----------------------------------\n");
            printf("|      Name: %s                        \n",temp->nameP);
            printf("|      ID: %d                          \n",temp->IDP);
            printf("|      Reservation: %s                 \n", temp->slotsP);
            printf("----------------------------------\n");

            temp=temp->next;
        }while(temp!=NULL);
    }
    else
    {
        printf("Empty List\n");
    }
}


int checkID(int ID)
 {
    node *temp = head;

    while (temp != NULL) {
        if (temp->IDP == ID) {
            return TAKEN;
        }
        temp = temp->next;
    }

    return UNIQUE;
}

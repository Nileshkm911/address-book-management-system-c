#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) 
{
    FILE *fptr = fopen("contacts.txt", "w");
    int size = addressBook->contactCount;
    fprintf(fptr, "#%d#\n", size);
    for(int i = 0; i< size; i++)
    {
        fprintf(fptr, "%s,%s,%s\n", addressBook->contacts[i].name,addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }

    fclose(fptr);
  
}

void loadContactsFromFile(AddressBook *addressBook) 
{
    char str[100];
    int i;
    FILE *fptr = fopen("contacts.txt", "r");
    if(fptr == NULL)
    {
        printf("File is not present.");
        return ;
    }
    else
    {
        fscanf(fptr, " %[^\n]", str);
        int size = atoi(strtok(&str[1], "#"));
        addressBook->contactCount = size;

        for(i = 0; i < size; i++)
        {
            fscanf(fptr," %[^\n]", str);
            strcpy(addressBook->contacts[i].name, strtok(str, ","));
            strcpy(addressBook->contacts[i].phone, strtok(NULL, ","));
            strcpy(addressBook->contacts[i].email, strtok(NULL, ","));
        }

    }

    
}

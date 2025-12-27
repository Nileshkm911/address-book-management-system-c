#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

// list the all contact details by sorting
void listContacts(AddressBook *addressBook) 
{
    // Sort contacts based on the chosen criteria
    int choice, i, j;
    int size = addressBook->contactCount;

    if(size == 0)
    {
        printf("No contacts to display.\n");
        return;
    }

    // take choice from user how user want to sort
    printf("Select sort criteria:\n");
    printf("1. Sort by name\n");
    printf("2. Sort by phone\n");
    printf("3. Sort by email\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    Contact temp;

    switch(choice)
    {
        case 1:     // sort by name
                for(i = 0; i < size - 1; i++)
                {
                    for(j= 0; j < size - i - 1; j++)
                    {
                        if(strcmp(addressBook->contacts[j].name, addressBook->contacts[j + 1].name) > 0)
                        {
                            temp = addressBook->contacts[j];
                            addressBook->contacts[j] = addressBook->contacts[j + 1];
                            addressBook->contacts[j + 1] = temp;
                        }
                    }
                }
        break;

        case 2:     // sort by phone
                for(i = 0; i < size - 1; i++)
                {
                    for(j= 0; j < size - i - 1; j++)
                    {
                        if(strcmp(addressBook->contacts[j].phone, addressBook->contacts[j + 1].phone) > 0)
                        {
                            temp = addressBook->contacts[j];
                            addressBook->contacts[j] = addressBook->contacts[j + 1];
                            addressBook->contacts[j + 1] = temp;
                        }
                    }
                }
        break;

        case 3:     // sort by email
                for(i = 0; i < size - 1; i++)
                {
                    for(j= 0; j < size - i - 1; j++)
                    {
                        if(strcmp(addressBook->contacts[j].email, addressBook->contacts[j + 1].email) > 0)
                        {
                            temp = addressBook->contacts[j];
                            addressBook->contacts[j] = addressBook->contacts[j + 1];
                            addressBook->contacts[j + 1] = temp;
                        }
                    }
                }
        break;

    }
    // print details after sorting
    for(int i = 0; i < size; i++)
    {
        printf("%s      %s      %s\n", addressBook->contacts[i].name,addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
    
}

void initialize(AddressBook *addressBook) {
    //addressBook->contactCount = 0;
   // populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
   
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}

// function to check phone number is already present or not
char check_phone(AddressBook *addressBook, char *phone)
{
    for(int i=0; i< addressBook->contactCount; i++)
    {
        if(strcmp(phone, addressBook->contacts[i].phone) == 0)
        {
            return 0;
        }
    }
    return 1;
}

// function to check the email is valid or invalid
char check_email(char *email)
{
    // Check if '@' and '.com' both are present in the email
    if(strstr(email, "@") != NULL && strstr(email, ".com") != NULL)
    {

        char *at = strstr(email, "@");
        char *dot = strstr(email, ".com");

         // '@' should come before '.com' to be valid
        if(at < dot)
        {
            return 1; // valid email
        }
    }
    return 0; // invalid email
}

void createContact(AddressBook *addressBook)
{
    int n;  // number of contacts to create
    printf("How many contacts do you want to create? ");
    scanf("%d", &n);
    getchar(); // clear input buffer

    for (int c = 0; c < n; c++)
    {
        printf("\n--- Creating Contact %d ---\n", c + 1);

        char name[20], phone[20], email[50];
        int len, valid = 0, flag = 0;

        // --- Name input ---
        printf("Enter Name: ");
        scanf(" %[^\n]", name);

        // --- Phone validation ---
        do
        {
            printf("Enter Phone Number: ");
            scanf("%s", phone);

            len = strlen(phone);
            if (len != 10)
            {
                printf("Invalid number! Please enter a 10-digit number.\n");
            }
            else if (check_phone(addressBook, phone) == 0)
            {
                printf("This number already exists. Please enter a different one.\n");
                len = 0;
            }
            else
            {
                valid = 1;
            }
        } while (valid == 0);

        // --- Email validation ---
        do
        {
            printf("Enter Email ID: ");
            scanf("%s", email);

            if (check_email(email) == 0)
            {
                printf("Invalid email format! Please include '@' and '.com'\n");
            }
            else
            {
                flag = 1;
            }
        } while (flag == 0);

        // --- Save contact ---
        strcpy(addressBook->contacts[addressBook->contactCount].name, name);
        strcpy(addressBook->contacts[addressBook->contactCount].phone, phone);
        strcpy(addressBook->contacts[addressBook->contactCount].email, email);
        addressBook->contactCount++;
    }
    printf("All contacts added successfully!\n");
}


void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    int choice, flag=0;
    char name[50];
    char phone[20];
    char email[50];

    //ask user to search contact by name , phone or email 
    printf("Select sort criteria:\n");
    printf("1. Search by name\n");
    printf("2. Search by phone\n");
    printf("3. Search by email\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();

        switch(choice)
        {
            case 1:     // search by name
                    printf("Enter the Name:");
                    scanf("%[^\n]", name);

                    for(int i = 0; i < addressBook->contactCount; i++)
                    {
                        if((strcmp(name, addressBook->contacts[i].name)) == 0)
                        {
                            printf("%s      %s      %s\n", addressBook->contacts[i].name,addressBook->contacts[i].phone, addressBook->contacts[i].email);
                            flag = 1;
                            break;
                        }
                    }
                    if(flag == 0)
                    {
                        printf("Given name is not present in the list.");
                    }
            break;

           case 2:      //search by phone
                    printf("Enter the Phone Number:");
                    scanf("%[^\n]", phone);

                    for(int i = 0; i < addressBook->contactCount; i++)
                    {
                        if((strcmp(phone, addressBook->contacts[i].phone)) == 0)
                        {
                            printf("%s      %s      %s\n", addressBook->contacts[i].name,addressBook->contacts[i].phone, addressBook->contacts[i].email);
                            flag = 1;
                            break;
                        }
                    }
                    if(flag == 0)
                    {
                        printf("Given Phone number is not present in the list.");
                    }
            break;

            case 3:     //search by email
                    printf("Enter the Email ID:");
                    scanf("%[^\n]", email);

                    for(int i = 0; i < addressBook->contactCount; i++)
                    {
                        if((strcmp(email, addressBook->contacts[i].email)) == 0)
                        {
                            printf("%s      %s      %s\n", addressBook->contacts[i].name,addressBook->contacts[i].phone, addressBook->contacts[i].email);
                            flag = 1;
                            break;
                        }
                    }
                    if(flag == 0)
                    {
                        printf("Given Email ID is not present in the list.");
                    }
            break;

            default:
                    printf("Enter a valid choice.");
            break;
        }
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    int option, index, flag = 0;
    int i, j, matchCount = 0, choice;
    char name[50];
    char phone[20];
    char email[50];
    int matchIndices[100];

    printf("Please Select the contact :\n");
    printf("1. Search by name\n");
    printf("2. Search by phone\n");
    printf("3. Search by email\n");
    printf("Enter the option\n");
    scanf("%d",&option);

    switch(option)
    {
        case 1:         // search by name then edit by user choice
                printf("Enter the Name: ");
                getchar();
                scanf("%[^\n]", name);

                do
                {
                    flag = 0;
                    matchCount = 0;

                    for(i = 0; i < addressBook->contactCount; i++)
                    {
                        if(strcmp(name, addressBook->contacts[i].name) == 0)
                        {
                            matchIndices[matchCount++] = i;  // store index of each match
                            flag = 1;
                        }
                    }

                    if(flag == 0)
                    {
                        printf("The entered name is not present in contact book, please enter again: ");
                        getchar();
                        scanf("%[^\n]", name);
                    }
                    else if(matchCount > 1)
                    {
                        printf("\nMultiple contacts found with name '%s':\n", name);
                        for(j = 0; j < matchCount; j++)
                        {
                            int idx = matchIndices[j];
                            printf("%d. %s  %s  %s\n", j + 1,
                                addressBook->contacts[idx].name,
                                addressBook->contacts[idx].phone,
                                addressBook->contacts[idx].email);
                        }
                        printf("Enter the number of the contact you want to edit: ");
                        scanf("%d", &choice);

                        if(choice >= 1 && choice <= matchCount)
                        {
                            index = matchIndices[choice - 1];
                        }
                        else
                        {
                            printf("Invalid choice. Selecting first contact by default.\n");
                            index = matchIndices[0];
                        }
                    }
                    else
                    {
                        index = matchIndices[0];
                    }
                        
                } while(flag == 0);
        break;

        case 2:         //search by phone and edit by user choice
                printf("Enter the Phone Number: ");
                getchar();
                scanf("%s", phone);

                do
                {
                    flag = 0;
                    for( i=0; i< addressBook->contactCount; i++)
                    {
                        if(strcmp(phone, addressBook->contacts[i].phone) == 0)
                        {
                            index = i;
                            flag = 1;
                            break;
                        }
                    }

                    if(flag == 0)
                    {
                        printf("The enterd number is not present in contact book, plz enter again.");
                    }
                    
                }while(flag == 0);
        break;

        case 3:         //search by email and edit by user choice
                printf("Enter the Email ID: ");
                getchar();
                scanf("%[^\n]", email);

                do
                {
                    flag = 0;
                    for( i=0; i< addressBook->contactCount; i++)
                    {
                        if(strcmp(email, addressBook->contacts[i].email) == 0)
                        {
                            index = i;
                            flag = 1;
                            break;
                        }
                    }

                    if(flag == 0)
                    {
                        printf("The enterd Email ID is not present in contact book, plz enter again.");
                    }
                    
                }while(flag == 0);
        break;

        default: 
                printf("Plase select option from these 3.");
        break;
    }

    // Edit into the contact book

    printf("Please Select the contact :\n");
    printf("1. Edit the name\n");
    printf("2. Edit the phone\n");
    printf("3. Edit the email\n");
    printf("4. Edit the all details");
    printf("Enter the option\n");
    scanf("%d",&option);

    switch(option)
    {
        case 1: 
                printf("Enter the Name: ");
                getchar();
                scanf("%[^\n]", name);
                strcpy(addressBook->contacts[index].name, name);
        break;

        case 2:
                printf("Enter the Phone Number: ");
                getchar();
                scanf("%s", phone);
                strcpy(addressBook->contacts[index].phone, phone);
                
        break;

        case 3:
                printf("Enter the Email ID: ");
                getchar();
                scanf("%[^\n]", email);
                strcpy(addressBook->contacts[index].email, email);
        break;

        case 4:
                printf("Enter the Name: ");
                getchar();
                scanf("%[^\n]", name);
                getchar();
                printf("Enter the Phone Number: ");
                getchar();
                scanf("%s", phone);
                getchar();
                printf("Enter the Email ID: ");
                getchar();
                scanf("%[^\n]", email);
                getchar();

                strcpy(addressBook->contacts[index].name, name);
                strcpy(addressBook->contacts[index].phone, phone);
                strcpy(addressBook->contacts[index].email, email);
        break;

        default:
                printf("Enter valid option.");
        break;

    }
    printf("Contact Edit Successfull..");
}

void deleteContact(AddressBook *addressBook)
{
    // Delete contact by searching name, phone or email
    // Also added option to delete all contacts at once

    int option, index, flag = 0;
    int i, j, matchCount = 0, choice;
    int matchIndices[100];
    char name[50];
    char phone[20];
    char email[50];

    // Ask user how they want to delete contact
    printf("Please Select the contact :\n");
    printf("1. Search by name\n");
    printf("2. Search by phone\n");
    printf("3. Search by email\n");
    printf("4. Delete all contacts\n"); // new option added
    printf("Enter the option\n");
    scanf("%d", &option);

    switch(option)
    {
        case 1: 
            // Delete by name
            printf("Enter the Name: ");
            getchar();
            scanf("%[^\n]", name);

            do
            {
                flag = 0;
                matchCount = 0;

                // Search all contacts for given name
                for(i = 0; i < addressBook->contactCount; i++)
                {
                    if(strcmp(name, addressBook->contacts[i].name) == 0)
                    {
                        matchIndices[matchCount++] = i;
                        flag = 1;
                    }
                }

                // If name not found, ask again
                if(flag == 0)
                {
                    printf("The entered name is not present in contact book, please enter again: ");
                    getchar();
                    scanf("%[^\n]", name);
                }
                // If more than one contact found, ask which one to delete
                else if(matchCount > 1)
                {
                    printf("\nMultiple contacts found with name '%s':\n", name);
                    for(j = 0; j < matchCount; j++)
                    {
                        int idx = matchIndices[j];
                        printf("%d. %s  %s  %s\n", j + 1,
                               addressBook->contacts[idx].name,
                               addressBook->contacts[idx].phone,
                               addressBook->contacts[idx].email);
                    }
                    printf("Enter the number of the contact you want to delete: ");
                    scanf("%d", &choice);

                    // Validate choice
                    if(choice >= 1 && choice <= matchCount)
                    {
                        index = matchIndices[choice - 1];
                    }
                    else
                    {
                        printf("Invalid choice. Selecting first contact by default.\n");
                        index = matchIndices[0];
                    }
                }
                else
                {
                    // Only one contact matched
                    index = matchIndices[0];
                }

            } while(flag == 0);
        break;

        case 2: 
            // Delete by phone number
            printf("Enter the Phone Number: ");
            getchar();
            scanf("%s", phone);

            do
            {
                flag = 0;
                // Search for matching phone
                for(i = 0; i < addressBook->contactCount; i++)
                {
                    if(strcmp(phone, addressBook->contacts[i].phone) == 0)
                    {
                        index = i;
                        flag = 1;
                        break;
                    }
                }

                if(flag == 0)
                {
                    printf("The entered number is not present in contact book, please enter again: ");
                }

            } while(flag == 0);
        break;

        case 3: 
            // Delete by email
            printf("Enter the Email ID: ");
            getchar();
            scanf("%[^\n]", email);

            do
            {
                flag = 0;
                // Search for matching email
                for(i = 0; i < addressBook->contactCount; i++)
                {
                    if(strcmp(email, addressBook->contacts[i].email) == 0)
                    {
                        index = i;
                        flag = 1;
                        break;
                    }
                }

                if(flag == 0)
                {
                    printf("The entered Email ID is not present in contact book, please enter again: ");
                }

            } while(flag == 0);
        break;

        case 4:
            // Delete all contacts in one go
            printf("Are you sure you want to delete all contacts? (1-Yes / 0-No): ");
            scanf("%d", &choice);

            if(choice == 1)
            {
                addressBook->contactCount = 0; // reset contact count
                printf("\nAll contacts deleted successfully!\n");
                return; // exit after deleting all
            }
            else
            {
                printf("Delete all cancelled.\n");
                return;
            }
        break;

        default: 
            // Invalid option
            printf("Please select option from these 4.\n");
            return;
    }

    // Delete selected single contact
    if(flag == 1)
    {
        // Shift all contacts one step up after deletion
        for(i = index; i < addressBook->contactCount - 1; i++)
        {
            addressBook->contacts[i] = addressBook->contacts[i + 1];
        }

        addressBook->contactCount--; // Decrease total contacts
        printf("\nContact deleted successfully!\n");
    }
}

/*

 Project1 Title   : Address Book 
 Description     : This project is a simple Address Book application in C that allows
                   users to manage their personal contacts. It provides options to:
                     → Add new contacts
                     → Edit existing contacts
                     → Delete contacts
                     → Search contacts (by name, phone, or email)
                     → Sort and list all contacts
                     → Save and load contacts from a file

 Functionality   :
                   - Each contact includes Name, Phone Number, and Email ID.
                   - The program checks for duplicate phone numbers or email IDs.
                   - It validates phone numbers and email formats before saving.
                   - Contacts are stored in a structure array.
                   - Data is automatically saved to a text file on exit.
                   - Simple menu-driven interface for user interaction.

 File Handling   : Contacts are stored in a text file (contacts.txt) using FILE pointers.
                   On program start, existing contacts are loaded from the file.
                   On exit, all updated contacts are saved back to the file.

 Input Fields    :
                   • Name  : String (max 50 chars)
                   • Phone : String (must be valid 10-digit number, unique)
                   • Email : String (must contain '@' and '.com', unique)

 Features Summary:
                   ✅ Add Contact
                   ✅ Edit Contact
                   ✅ Delete Contact
                   ✅ Search Contact
                   ✅ Sort Contacts by Name
                   ✅ List All Contacts
                   ✅ Prevent Duplicates (Phone/Email)
                   ✅ Validate Inputs
                   ✅ Save & Load Data using Files

 Author          : Nilesh Kundan Mahajan
 Submission Date : 28 October 2025
 course          : ECEP

*/


#include <stdio.h>
#include "contact.h"

int main() {
    int choice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do {
        printf("\n╔══════════════════════════════════════════════╗\n");
        printf("║         💼 PROJECT 1 : ADDRESS BOOK          ║\n");
        printf("╚══════════════════════════════════════════════╝\n");

        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            
            case 5:
                /* printf("Select sort criteria:\n");
                printf("1. Sort by name\n");
                printf("2. Sort by phone\n");
                printf("3. Sort by email\n");
                printf("Enter your choice: ");
                int sortChoice;
                scanf("%d", &sortChoice); */
                listContacts(&addressBook);
                break;
            case 6:
                printf("Saving and Exiting...\n");
                saveContactsToFile(&addressBook);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    
       return 0;
}

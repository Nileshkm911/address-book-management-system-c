# Address Book Management System in C

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Standard](https://img.shields.io/badge/Standard-C99%2FC11-yellow.svg)](https://en.wikipedia.org/wiki/C99)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)

A modular, console-based **Address Book Management System** written in C. This project implements full **CRUD** (Create, Read, Update, Delete) operations on contact records with persistent file storage and robust validation for phone numbers and email addresses.

---

## 📌 Features

- **Add Contact**: Record contact details including full name, mobile number, and email address with real-time format validation.
- **Search Contact**: Search records by:
  - Name (case-insensitive search)
  - Phone number
  - Email ID
- **Edit Contact**: Update individual attributes of any existing contact without altering unrelated fields.
- **Delete Contact**: Safely remove contact entries and maintain data array consistency.
- **List All Contacts**: Formatted tabular display of all registered entries.
- **Data Persistence**: Automatic file handling to save records to disk (`contacts.txt`) and reload them upon application restart.
- **Validation**:
  - Phone number uniqueness and digit length verification.
  - Email syntax validation (checking `@`, `.com`, and valid domain formats).

---

## 🏗️ Architecture & Data Structures

The system is designed with clean modular separation:

| File | Description |
| :--- | :--- |
| [`contact.h`](contact.h) / [`contact.c`](contact.c) | Core contact structure definitions and CRUD operation logic |
| [`file.h`](file.h) / [`file.c`](file.c) | File I/O operations for disk persistence |
| [`populate.h`](populate.h) / [`populate.c`](populate.c) | Dummy/sample contact initialization helper |
| [`main.c`](main.c) | Interactive terminal menu loop and user command dispatcher |

### Data Model
```c
typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;
```

---

## ⚙️ Build and Installation

### Prerequisites
- GCC / Clang compiler
- Make (optional, direct GCC command supported)

### Using Makefile
```bash
# Compile the project
make

# Run the application
make run

# Clean build artifacts
make clean
```

### Manual Compilation
```bash
gcc -Wall -Wextra main.c contact.c file.c populate.c -o address_book
./address_book
```

---

## 💻 Sample Usage

```text
Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List contacts
6. Save contacts
7. Exit
Enter your choice: 1

Enter Name: Nilesh Mahajan
Enter Phone: 9112709257
Enter Email: nileshmahajan560@gmail.com
Contact added successfully!
```

---

## 👤 Author

**Nilesh Mahajan**  
- GitHub: [@Nileshkm911](https://github.com/Nileshkm911)
- LinkedIn: [Nilesh Mahajan](https://linkedin.com/in/nilesh-mahajan-150a1b2a5)

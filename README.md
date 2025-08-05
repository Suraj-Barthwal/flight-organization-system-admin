
# Flight Organisation System – Admin Module

## Description
This C-based project is the **Admin Module** of a Flight Organisation System. It allows administrators to manage flights and users with basic features like adding or cancelling flights, sorting and searching them, and managing user access.

The system uses:
- Arrays and strings for data manipulation
- File handling for persistent storage (`flights.txt`, `users.txt`)
- A console-based menu interface for admin and user operations

##  Project Structure

```
├── main.c           // Entry point and main menu logic
├── library.c        // Core functions: flight & user management
├── library.h        // Function declarations
├── flights.txt      // (Generated) Stores flight data
├── users.txt        // (Generated) Stores user login credentials
```

## Admin Credentials
By default:
```
Username: suraj
Password: asdfghjkl;'
```
You can change these in `library.c` under:
```c
#define ADMIN_USERNAME "suraj"
#define ADMIN_PASSWORD "asdfghjkl;'"
```

## Features

### Admin Functions:
- Add new flights
- Cancel existing flights
- Generate complete flight reports
- Sort flights by:
  - Time
  - Price
- Search flights by:
  - Flight number
  - Destination
- Add new user credentials

### User Functions:
- Search flights (by number or destination)
- Sort and view flights
- Generate report of all flights

## Technologies Used
- Language: **C**
- Data Structures: **Arrays**, **Strings**
- Storage: **File Handling**
- Interface: **Console-based menus**

## How to Run

1. Compile:
   ```bash
   gcc main.c library.c -o flight_system
   ```

2. Run:
   ```bash
   ./flight_system
   ```

## Notes

- `flights.txt` and `users.txt` will be created in the working directory.
- The project does **not** use pointers, structs across multiple files, or dynamic memory allocation—making it beginner-friendly.
- You can extend it with seat booking or payment functionality.

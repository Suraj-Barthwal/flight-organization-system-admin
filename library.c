#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Flight 
{
    char number[10];
    char source[20];
    char destination[20];
    char time[10];
    char type[20];
    int totalSeats;
    int bookedSeats;
    float price;
};


#define ADMIN_USERNAME "suraj"
#define ADMIN_PASSWORD "asdfghjkl;'"


// This function checks the admin credentials. It compares the entered username and password with the predefined ones.

int admin_authentication() 
{
    char user[20], pass[20];
    printf("Enter username: ");
    scanf("%s", user);
    printf("Enter password: ");
    scanf("%s", pass);

    if (strcmp(user, ADMIN_USERNAME) == 0 && strcmp(pass, ADMIN_PASSWORD) == 0) 
    {
        return 1;
    }
    return 0;
}

// This function adds a flight to the file. It prompts the user for flight details and appends them to the file.

void addFlight() 
{
    struct Flight f;
    int typeChoice;

    //flight.txt is opened in append mode to add new flights at then end other wise it will overwrite the existing data everytime and no previous data will be saved.

    FILE *fp = fopen("flights.txt", "a");
    if (!fp) 
    {
        printf("Could not open file.\n");
        return;
    }

    printf("Enter flight number: "); 
    scanf("%s", f.number);
    printf("Enter source: "); 
    scanf("%s", f.source);
    printf("Enter destination: "); 
    scanf("%s", f.destination);
    printf("Enter departure time (HH:MM): "); 
    scanf("%s", f.time);
    printf("Type of flight:\n1. A319\n2. B777\n3. B787\n4. B747\n5. A380\n");
    scanf("%d", &typeChoice);

    switch (typeChoice) 
    {
        case 1: strcpy(f.type, "A319"); 
        break;
        case 2: strcpy(f.type, "B777"); 
        break;
        case 3: strcpy(f.type, "B787"); 
        break;
        case 4: strcpy(f.type, "B747"); 
        break;
        case 5: strcpy(f.type, "A380"); 
        break;
        default: strcpy(f.type, "Unknown"); 
        break;
    }

    printf("Enter total seats: "); 
    scanf("%d", &f.totalSeats);
    printf("Enter booked seats: "); 
    scanf("%d", &f.bookedSeats);
    printf("Enter ticket price: "); 
    scanf("%f", &f.price);

    fprintf(fp, "%s %s %s %s %s %d %d %.2f\n", f.number, f.source, f.destination, f.time, f.type, f.totalSeats, f.bookedSeats, f.price);
    fclose(fp);
    printf("Flight added successfully.\n");
}

// cancel flight function
// This function allows the admin to cancel a flight by copying all flights to a temporary file except the one to be cancelled.
// After that, it renames the temporary file to the original file name.

void cancel_flight() 
{
    struct Flight f;
    char target[10];
    int found=0;
    FILE *fp = fopen("flights.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!fp || !temp) 
    {
        printf("Error opening files.\n");
        return;
    }

    printf("Enter flight number to cancel: ");
    scanf("%s", target);

    while (fscanf(fp, "%s %s %s %s %s %d %d %f", f.number, f.source, f.destination, f.time, f.type, &f.totalSeats, &f.bookedSeats, &f.price) != EOF) 
    {
        if (strcmp(f.number, target) != 0) 
        {
            fprintf(temp, "%s %s %s %s %s %d %d %.2f\n", f.number, f.source, f.destination, f.time, f.type, f.totalSeats, f.bookedSeats, f.price);
        } 
        else 
        {
            found=1;
        }
    }

    fclose(fp);
    fclose(temp);

    // Remove the original file and rename the temporary file to the original file name (found these functions in a reddit thread chat).

    remove("flights.txt");
    rename("temp.txt", "flights.txt");

    if (found)
        printf("Flight cancelled successfully.\n");
    else
        printf("Flight not found.\n");
}

// This function generates a report of all flights by reading from the file and printing the details to the desktop.

void generateReport() 
{

    //traverse through the file and display the data of all the flights.
    // we can also use linked list if it exists in c 
        
            //0001,New York,London,12:30,A319,100,50,500.00
            //0002,Paris,Berlin,14:00,A380,200,100,300.00
            //0003,Tokyo,Sydney,22:00,Boeing 777,150,75,700.00
            //0004,Los Angeles,New York,18:00,Boeing 787,120,60,400.00


    struct Flight f;
    FILE *fp = fopen("flights.txt", "r");
    if (!fp) 
    {
        printf("Error opening file.\n");
        return;
    }

    printf("\n--- Flight Report ---\n");
    while (fscanf(fp, "%s %s %s %s %s %d %d %f", f.number, f.source, f.destination, f.time, f.type, &f.totalSeats, &f.bookedSeats, &f.price) != EOF) 
    {
        printf("%s %s %s %s %s %d %d %.2f\n", f.number, f.source, f.destination, f.time, f.type, f.totalSeats, f.bookedSeats, f.price);
    }
    fclose(fp);
}

// This function searches for a flight by flight number. It reads the flight details from the file and compares the flight number with the user input.

void search_flight_flightno() 
{
    struct Flight f;
    char num[10];
    int found=0;
    FILE *fp = fopen("flights.txt", "r");
    if (!fp) 
    {
        printf("Error opening file.\n");
        return;
    }
    printf("Enter flight number to search: ");
    scanf("%s", num);
    while (fscanf(fp, "%s %s %s %s %s %d %d %f", f.number, f.source, f.destination, f.time, f.type, &f.totalSeats, &f.bookedSeats, &f.price) != EOF) 
    {
        if (strcmp(f.number, num)==0) 
        {
            printf("Flight found: %s %s %s %s %s %d %d %.2f\n", f.number, f.source, f.destination, f.time, f.type, f.totalSeats, f.bookedSeats, f.price);
            found=1;
            break;
        }
    }
    if (!found) printf("Flight not found.\n");
    {
    fclose(fp);
    }
}

// This function searches for flights by destination. It reads the flight details from the file and compares the destination with the user input.
// If a match is found, it prints the flight details. If no match is found, it informs the user.

void search_flight_destination() 
{
    struct Flight f;
    char dest[20];
    int found = 0;
    FILE *fp = fopen("flights.txt", "r");
    if (!fp) 
    {
        printf("Error opening file.\n");
        return;
    }
    printf("Enter destination to search: ");
    scanf("%s", dest);
    while (fscanf(fp, "%s %s %s %s %s %d %d %f", f.number, f.source, f.destination, f.time, f.type, &f.totalSeats, &f.bookedSeats, &f.price) != EOF) 
    {
        if (strcmp(f.destination, dest) == 0) 
        {
            printf("%s %s %s %s %s %d %d %.2f\n", f.number, f.source, f.destination, f.time, f.type, f.totalSeats, f.bookedSeats, f.price);
            found = 1;
        }
    }
    if (!found) 
    {
        printf("No flights to that destination.\n");
    }
    fclose(fp);
}

// This function sorts the flights by price. It reads the flight details from the file, stores them in an array, and then sorts the array based on the price.

void sort_flights_by_price() 
{
    struct Flight f[100], temp;
    int i = 0, j, n;
    FILE *fp = fopen("flights.txt", "r");
    if (!fp) 
    {
        printf("Error opening file.\n");
        return;
    }

    while (fscanf(fp, "%s %s %s %s %s %d %d %f", f[i].number, f[i].source, f[i].destination, f[i].time, f[i].type, &f[i].totalSeats, &f[i].bookedSeats, &f[i].price) != EOF) 
    {
        i++;
    }
    fclose(fp);
    n = i;

// using bubble sort to sort the flights by price although it is not the most efficient way to sort, it is simple and easy to understand, and the only one i know

    for (i = 0; i < n - 1; i++) 
    {
        for (j = i + 1; j < n; j++) 
        {
            if (f[i].price > f[j].price) 
            {
                temp = f[i];
                f[i] = f[j];
                f[j] = temp;
            }
        }
    }

    printf("\n--- Flights Sorted by Price ---\n");
    for (i = 0; i < n; i++) 
    {
        printf("%s %s %s %s %s %d %d %.2f\n", f[i].number, f[i].source, f[i].destination, f[i].time, f[i].type, f[i].totalSeats, f[i].bookedSeats, f[i].price);
    }
}

// This function sorts the flights by time. It reads the flight details from the file, stores them in an array, and then sorts the array based on the time.

void sort_flights_by_time() 
{
    struct Flight f[100], temp;
    int i = 0, j, n;
    FILE *fp = fopen("flights.txt", "r");
    if (!fp) 
    {
        printf("Error opening file.\n");
        return;
    }

    while (fscanf(fp, "%s %s %s %s %s %d %d %f", f[i].number, f[i].source, f[i].destination, f[i].time, f[i].type, &f[i].totalSeats, &f[i].bookedSeats, &f[i].price) != EOF) 
    {
        i++;
    }
    fclose(fp);
    n = i;

    for (i = 0; i < n - 1; i++) 
    {
        for (j = i + 1; j < n; j++) 
        {
            if (strcmp(f[i].time, f[j].time) > 0) 
            {
                temp = f[i];
                f[i] = f[j];
                f[j] = temp;
            }
        }
    }

    printf("\n--- Flights Sorted by Time ---\n");
    for (i = 0; i < n; i++) 
    {
        printf("%s %s %s %s %s %d %d %.2f\n", f[i].number, f[i].source, f[i].destination, f[i].time, f[i].type, f[i].totalSeats, f[i].bookedSeats, f[i].price);
    }
}

// This function authenticates the user by checking the username and password against a file.

int user_authentication() 
{
    char uname[20], pass[20], fileUser[20], filePass[20];
    FILE *fp = fopen("users.txt", "r");

    if (!fp) 
    {
        printf("User file not found. Ask admin to create users.\n");
        return 0;
    }

    printf("Enter username: ");
    scanf("%s", uname);
    printf("Enter password: ");
    scanf("%s", pass);

    while (fscanf(fp, "%s %s", fileUser, filePass) != EOF) 
    {
        if (strcmp(uname, fileUser) == 0 && strcmp(pass, filePass) == 0) 
        {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    printf("Invalid username or password.\n");
    return 0;
}

// this fucntion adds a user to the file.

void add_user() 
{
    char uname[20], pass[20];
    FILE *fp = fopen("users.txt", "a");

    if (!fp) 
    {
        printf("Error opening user file.\n");
        return;
    }

    printf("Enter new username: ");
    scanf("%s", uname);
    printf("Enter new password: ");
    scanf("%s", pass);

    fprintf(fp, "%s %s\n", uname, pass);
    fclose(fp);

    printf("User added successfully.\n");
}
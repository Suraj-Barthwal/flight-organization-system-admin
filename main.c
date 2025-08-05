#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

int main() 
{
    int choice, admchoice, acounter = 0, ucounter = 0, loop = 0;

    while (loop == 0)
    {

        
        // Main menu
        printf("\nWELCOME TO THE FLIGHT RESERVATION SYSTEM\n");
        printf("1. Admin Login\n");
        printf("2. User Login\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);




        if (choice == 1) 
        {
            if (admin_authentication()) 
            {
                printf("Admin login successful.\n");

                // Call admin functions here
                acounter = 0;

                while (acounter == 0)
                {
                    printf("\nAdmin Menu:\n");
                    printf("1. Add Flight\n");
                    printf("2. Cancel Flight\n");
                    printf("3. Generate Report\n");
                    printf("4. Sort Flights By Time\n");
                    printf("5. Sort Flights By Price\n");
                    printf("6. Search Flight By Number\n");
                    printf("7. Search Flight By Destination\n");
                    printf("8. Add New User\n");
                    printf("9. Exit\n");
                    printf("Enter your choice: ");
                    scanf("%d", &admchoice);

                    switch (admchoice) 
                    {
                        case 1: addFlight(); break;
                        case 2: cancel_flight(); break;
                        case 3: generateReport(); break;
                        case 4: sort_flights_by_time(); break;
                        case 5: sort_flights_by_price(); break;
                        case 6: search_flight_flightno(); break;
                        case 7: search_flight_destination(); break;
                        case 8: add_user(); break;
                        case 9: 
                            printf("Exiting admin menu...\n");
                            acounter = 1; // return to main menu
                            break;
                        default: printf("Invalid choice.\n"); break;
                    }
                }
            } 
            else 
            {
                printf("Admin login failed.\n");
            }
        }



        else if (choice == 2) 
        {
            if (user_authentication()) 
            {
                printf("User login successful.\n");

                // Call user functions here

                ucounter = 0;

                while (ucounter == 0)
                {
                    printf("User Menu:\n");
                    printf("1. Search Flight By Flight Number\n");
                    printf("2. Search Flight By Destination\n");
                    printf("3. Sort Flights By Time\n");
                    printf("4. Sort Flights By Price\n");
                    printf("5. Generate Report\n");
                    printf("6. Exit\n");
                    printf("Enter your choice: ");
                    scanf("%d", &admchoice);

                    switch (admchoice) 
                    {
                        case 1: search_flight_flightno(); break;
                        case 2: search_flight_destination(); break;
                        case 3: sort_flights_by_time(); break; 
                        case 4: sort_flights_by_price(); break;
                        case 5: generateReport(); break;
                        case 6: 
                            printf("Exiting user menu...\n"); 
                            ucounter = 1;
                            // return to main menu
                            break;
                        default: printf("Invalid choice.\n"); break;
                    }
                }
            } 
            else 
            {
                printf("User login failed.\n");
            }
        }




        else if (choice == 3) 
        {
            printf("Exiting system...\n");
            loop = 1;
             // ends the main loop
        }
        
        

        else 
        {
            printf("Invalid choice.\n");
        }
    }

    return 0;
    // Program ends after loop is finished
}

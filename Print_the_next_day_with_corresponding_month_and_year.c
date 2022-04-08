#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int day, month, year, leap, error;
    printf("This program prints the next day with corresponding month and year.\n"
           "It might seem that's a very simple task in normal live, and it really is,\n"
           "but what's difficult is the implementation of that task using C programming language.\n"
           "Please imput the day, month and a year (using the following numeric format - 08 04 2022): ");
    scanf("%d %d %d", &day, &month, &year);

    error = 0; // we assume that the iniiput value were correct

    if (year % 400 == 0)    // we need to check if the input year is a leap year
        leap = 1;
    else if (year % 100 == 0)
        leap = 0;
    else if (year % 4 == 0)
        leap = 1;

    switch (month)  // commands for the month and the correlated days
    {
        case 1: // for the months with 31 days
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (day >= 1 && day <= 30)
                day++;
            else if (day == 31 && month == 12)  // condition for switching the year and month to the next one
            {
                day = 1;
                month = 1;
                year++;
            }
            else if (day == 31 && month >= 1 && month <= 11)  // condition for switching the month to the next one
            {
                day = 1;
                month++;
            }
            else
            {
                printf("\nInvalid day input\n");  // message in case the incorrect day input (for any day ouside the correct range)
                error = 1; // in this case we give the error flag equal to 1
            }
            break;
        case 4: // for the months with 30 days
        case 6:
        case 9:
        case 11:
            if (day >= 1 && day <= 29)
                day++;
            else if (day == 30)
            {
                day = 1;
                month++;
            }
            else
            {
                printf("\nInvalid day input\n");
                error = 1;  // in this case we give the error flag equal to 1
            }
            break;
        case 2: // for a month with 28/29 days (February)
            if (leap == 1)  // commands for the leap year
            {
                if  (day >= 1 && day <= 28)
                    day++;
                else if (day == 29)
                {
                    day = 1;
                    month++;
                }
                else
                {
                    printf("\nInvalid day input\n");  // similarly, message in case the incorrect day input (for any day ouside the correct range)
                    error = 1; // also, in this case we give the error flag equal to 1
                }
                break;
            }
            else if (leap == 0)
            {
                if (day >= 1 && day <= 27)
                    day++;
                else if (day == 28)
                {
                    day = 1;
                    month++;
                }
                else
                {
                    printf("\nInvalid day input\n");  // similarly, message in case the incorrect day input (for any day ouside the correct range)
                    error = 1;  // also, in this case we give the error flag equal to 1
                }
                break;
            }
        default:
            printf("\nInvalid month input\n");    // message in case of the invalid month input (for any month outside the correct range)
            error = 1;
    }
    if (error == 0)
    {
        printf("\nThe next day date is ");
        if (day >= 1 && day <= 9)
            printf("0%d ", day);    // adds the 0 to print the day in corresponding format - DD-MM-YY
        else
            printf("%d ", day);
        if (month >= 1 && month <= 9)
            printf("0%d ", month);  // adds the 0 to print the month in corresponding format - DD-MM-YY
        else
            printf("%d ", month);
        printf("%d", year);
        printf("\n\nThank you fou using our program :)\n");
    }
    return 0;
}

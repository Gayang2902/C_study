/* Modify Programming Project 8 from Chapter 5 so that the user enters a time using
 * the 12-hour clock. The input will have the form housr:minutes followed by either A, P, AM or
 * PM (either lower-case or upper-case). White space is allowed (but not required) between the
 * numerical time and the AM/PM indicator. Examples of valid input:
   1:15P
   1:15PM
   1:15p
   1:15pm
   1:15 P
   1:15 PM
   1:15 p
   1:15 pm
 * You may assume that the input has one of these forms; there is no need to test for errors. */

#include <stdio.h>
#include <ctype.h>

int main(void)
{ // 12:00 pm = 720
    int hour, min, con;
    char time;
    printf("Enter a 12-hour time: ");
    scanf("%d:%d %c", &hour, &min, &time);

    time = toupper(time);
    if (time == 'P') {
        hour += 12;
    }
    con = ((hour*60) + min) / 100;
    

    switch (con) {
    case 4:
        printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
        break;
    case 5:
        printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
        break;
    case 6:
        printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
        break;
    case 7:
        printf("Closest departure time is 12:47 p.m., arriving at 3:00 p.m.\n");
        break;
    case 8:
        printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n");
        break;
    case 9:
        printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n");
        break;
    case 11:
        printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.\n");
    case 13:
        printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");
        break;
    }

    return 0;    
}
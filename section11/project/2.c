#include <stdio.h>

void find_closet_flight(int desired_time, int* departure_time, int* arrival_time);

int main(void)
{ // 12:00 pm = 720
    int hour, min, con;
    int desired_time, depature_time, arrival_time;
    
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &min);
    desired_time = (hour * 60) + min;
    find_closet_flight(desired_time, &depature_time, &arrival_time);

    printf("Closet depature time is %.2d:%.2d., arrving at %.2d:%.2d.\n", depature_time / 60, depature_time % 60, arrival_time / 60, arrival_time % 60);

    return 0;    
}

void find_closet_flight(int desired_time, int* departure_time, int* arrival_time)
{
    int con = desired_time / 100;

    switch (con) {
    case 4:
        *departure_time = 480;
        *arrival_time = 616;
        break;
    case 5:
        *departure_time = 583;
        *arrival_time = 712;
        break;
    case 6:
        *departure_time = 679;
        *arrival_time = 811;
        break;
    case 7:
        *departure_time = 767;
        *arrival_time = 900;
        break;
    case 8:
        *departure_time = 840;
        *arrival_time = 968;
        break;
    case 9:
        *departure_time = 945;
        *arrival_time = 1075;
        break;
    case 11:
        *departure_time = 1140;
        *arrival_time = 1280;
    case 13:
        *departure_time = 1305;
        *arrival_time = 1438;
        break;
    }
}
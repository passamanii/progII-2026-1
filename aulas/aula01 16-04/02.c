#include <stdio.h>


#define spd_1 60 //Km/h
#define spd_2 90


float how_many_time(int dist) {

    int time = (dist*2); //t em min
    
    return time;
}

int main() {
    
    int distance; //Km
    int time;
    
    printf("Input the distance between the two cars(X): ");
    scanf("%d", &distance);

    time = how_many_time(distance);

    printf("The time needed for the first car to pass the second one is: %d minutes.\n", time);

    return 0;
}

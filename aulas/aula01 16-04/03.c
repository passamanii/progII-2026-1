#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float euclidian_distance(int x1, int y1, int x2, int y2) {
    
    float d = (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));

    return d;
}

float manhattan_distance(int x1, int y1, int x2, int y2) {

    float d = (abs(x2 - x1) + abs(y2 - y1));

    return d;
}

int main() {

    int x1, y1, x2, y2;
    float e_dist, m_dist, c_dist;

    printf("Input a point(X Y): ");
    scanf("%d %d", &x1, &y1);

    printf("Input another point(X Y): ");
    scanf("%d %d", &x2, &y2);

    e_dist = euclidian_distance(x1, y1, x2, y2);
    m_dist = manhattan_distance(x1, y1, x2, y2);
//    c_dist = chebyshev_distance(x, y);

    printf("Euclidian Distance: %.2f.\n", e_dist);
    printf("Manhattan Distance: %.2f.\n", m_dist);
//    printf("Euclidian Distance: %.2f.\n", c_dist);
//
    return 0;
}

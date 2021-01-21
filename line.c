#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} point;

double distance(point point_a, point point_b) {
    double x_sqrd = pow(point_b.x - point_a.x, 2);
    double y_sqrd = pow(point_b.y - point_a.y, 2);
    return sqrt(x_sqrd + y_sqrd);
}

typedef struct {
    point p1;
    point p2;
} line;

double length(line line_a) {
       return distance(line_a.p1, line_a.p2);
}

double slope(line line_a) {
    double delta_y = line_a.p2.y - line_a.p1.y;
    double delta_x = line_a.p2.x - line_a.p1.x;
    return delta_y/delta_x;
}

bool point_on_line(line line_a, point point_a) {
    double m = slope(line_a);
    double y_on_line = (m*(point_a.x - line_a.p1.x)) + line_a.p1.y;
    if (point_a.y == y_on_line) {
        return true;
    }
    else {
        return false;
    }
}

int main(int argc, char *argv[]) {
    point p1 = { 0 , -1 };
    point p2 = { 5 , 9 };
    point on_line = { 3 , 5 };
    point off_line = { 4 , 10 };
    line line_a = { p1 , p2 };
    printf("%f \n", slope(line_a));
    printf("%i \n", point_on_line(line_a, on_line));
    printf("%i \n", point_on_line(line_a, off_line));
}
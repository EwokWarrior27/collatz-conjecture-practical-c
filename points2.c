#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} point;

typedef struct {
    size_t n;
    point points[];
} polygon;

polygon *read_polygon(size_t point_count) {
    polygon *shape = malloc(sizeof(polygon)+sizeof(point)*point_count);;
    shape->n = point_count;
    for (int i = 0; i < point_count; i++) {
        double x;
        double y;
        printf("Enter one point: ");
        scanf("%lf %lf", &x, &y);
        shape->points[i].x = x;
        shape->points[i].y = y;
    }
    return shape;
}

double perimeter(const polygon *p) {
    double perimeter = 0;
    for (int i = 0; i < p->n-1; i++) {
        double side_x = p->points[i+1].x - p->points[i].x;
        double side_y = p->points[i+1].y - p->points[i].y;
        perimeter += sqrt(side_x*side_x + side_y*side_y);
    }
    double side_x = p->points[p->n-1].x - p->points[0].x;
    double side_y = p->points[p->n-1].y - p->points[0].y;
    perimeter += sqrt(side_x*side_x + side_y*side_y);

    return perimeter;
}

double area(const polygon *p) {
    double area = 0;
    for (size_t i = 0; i < p->n-1; i++) {
        double sum_x = p->points[i+1].x + p->points[i].x;
        double sum_y = p->points[i+1].y - p->points[i].y;
        area += fabs(sum_x) * fabs(sum_y) / 2;
    }
    double sum_x = p->points[0].x + p->points[p->n-1].x;
    double sum_y = p->points[0].y - p->points[p->n-1].y;
    area = fabs(sum_x) * fabs(sum_y)/2;

    return area;
}

int main(int argc, char *argv[]) {
    printf("How many points will you input? ");
    double count;
    scanf("%lf", &count);
    polygon *shape = read_polygon(count);
    printf("%lf\n", perimeter(shape));
    printf("%lf\n", area(shape));
    free(shape);
}
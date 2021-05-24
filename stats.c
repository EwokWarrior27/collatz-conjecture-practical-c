#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

double *read_array(size_t count) {
    double *nums;
    nums = malloc(sizeof(double)*count);
    for (int i = 0; i < count; i++) {
        double x;
        printf("Enter one number: ");
        scanf("%lf", &x);
        nums[i] = x;
    }
    return nums;
}

double sum(const double *nums, size_t count) {
    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += nums[i];
    }
    return sum;
}

double average(const double *nums, size_t count) {
    return sum(nums, count)/count;
}

double std_dev(const double *nums, size_t count) {
    double top_sum = 0;
    for (int i = 0; i < count; i++) {
        double dif = nums[i] - average(nums, count);
        top_sum += dif*dif;
    }
    return sqrt(top_sum/count);
}

int main(int argc, char *argv[]) {
    printf("How many numbers will you input? ");
    double count;
    scanf("%lf", &count);
    double *nums = read_array(count);
    printf("%lf\n", sum(nums, count));
    printf("%lf\n", average(nums, count));
    printf("%lf\n", std_dev(nums, count));
}
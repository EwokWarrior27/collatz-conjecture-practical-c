#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int stopping_time(int n) {
    int stopcount = 0;
    while (n != 1) {
        /*if (n % 2 == 0) {n /= 2;}
        else {n = (3 * n) + 1;}*/
        n = (n % 2 == 0) ? n/2 : (3*n)+1;
        stopcount++;
    }
    return stopcount;
}

int main( int argc, char *argv[] ) {
    int max = 0;
    int n = 1;
    int bestN;
    while (n < 100000) {
        if (stopping_time(n) > max) {
            max = stopping_time(n);
            bestN = n;
        }
        n++;
    }
    printf("%i has a stopping power of %i\n", bestN, max);
    return 0;
}
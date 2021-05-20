#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <gmp.h>

void fibonacci() {
    int turn = 1;
    mpz_t val1;
    mpz_t val2;
    mpz_init_set_ui(val1, 1);
    mpz_init_set_ui(val2, 1);
    while (turn != 3) {
        if (turn == 1) {
            mpz_add(val1, val1, val2);
            turn = 2;
            if (mpz_sizeinbase(val1, 10) == 1000) {
                gmp_printf("%Zd \n", val1);
                turn = 3;
            }
        }
        else if (turn == 2) {
            mpz_add(val2, val1, val2);
            turn = 1;
            if (mpz_sizeinbase(val2, 10) == 1000) {
                gmp_printf("%Zd \n", val2);
                turn = 3;
            }
        }
    }
    mpz_clear(val1);
    mpz_clear(val2);
}

int main(int argc, char *argv[]) {
    fibonacci();
}
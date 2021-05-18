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
    mpz_init_set_ui(val2, 2);
    gmp_printf("%Zd ", val1);
    gmp_printf("%Zd ", val1);
    gmp_printf("%Zd ", val2);
    for (int i = 1; i <= 1000; i++) {
        if (turn == 1) {
            mpz_add(val1, val1, val2);
            gmp_printf("%Zd ", val1);
            turn = 2;
        }
        else if (turn == 2) {
            mpz_add(val2, val1, val2);
            gmp_printf("%Zd ", val2);
            turn = 1;
        }
    }
    mpz_clear(val1);
    mpz_clear(val2);
}

int main(int argc, char *argv[]) {
    fibonacci();
}
#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <math.h>
#include "application.h"
#include "helpers.h"

int main(int argc, char *argv[]) {
    Application *app = app_make();
    app_loop(app);

	return 0;
}
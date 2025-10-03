/*
 * test_lapply.c ---
 *
 * Author: Magpie N. Carino
 * Created: 09-30-2025
 * Version: 1.0
 *
 * Description:
 * Tests the lapply() function
 *
 */
#include "list.h"

static double sum = 0;

void f(car_t *cp) {
	sum += *cp->price;
}

void test_lapply_empty() {
	lapply(&f);
	if (sum != 0) {
		exit(1);
	}
}

void test_lapply_nonempty() {
	car_t carA = {NULL, "1", 6.0, 1999};
	car_t carB = {NULL, "2", 2.0, 2000};
	car_t carC = {NULL, "3", 1.0, 2001};

  lput(carA);
	lput(carB);
	lput(carC);

  lapply(&f);
	if (sum != 9.0) {
		exit(EXIT_FAILURE);
	}
}


int main() {

	test_lapply_empty();
	test_lapply_nonempty();
	
	exit(EXIT_SUCCESS);
}

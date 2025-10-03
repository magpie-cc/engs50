/* 
 * test_lremove.c --- 
 * 
 * Author: Magpie N. Carino
 * Created: 10-01-2025
 * Version: 1.0
 * 
 * Description: 
 * Tests the lremove() function
 */
#include "list.h"

void test_lremove_empty() {
	if (lremove("0") != NULL) {
		exit(1);
	}
}

void test_lremove_list_end() {
	if (lremove("5")->plate != "5") {
		exit(2);
	}
}

void test_lremove_list_beginning() {
	if (lremove("1")->plate != "1") {
		exit(2);
	}
}

void test_lremove_list_middle() {
	if (lremove("3")->plate != "3") {
		exit(2);
	}
}

int main() {

	test_lremove_empty();
	
	car_t carA = {NULL, "1", 6.0, 1999};
	car_t carB = {NULL, "2", 2.0, 2000};
	car_t carC = {NULL, "3", 1.0, 2001};
	car_t carD = {NULL, "4", 2.0, 2000};
	car_t carE = {NULL, "5", 1.0, 2001};
	
	lput(carA);
	lput(carB);
	lput(carC);
	lput(carD);
	lput(carE);

	test_lremove_list_end();
	test_lremove_list_beginning();
	test_lremove_list_middle();
	
	exit(EXIT_SUCCESS);
}

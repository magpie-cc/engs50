/* 
 * firsttest.c --- 
 * 
 * Author: Eigen H. Schinaman
 * Created: 10-02-2025
 * Version: 1.0
 * 
 * Description: 
 * 
 */

#include "list.h"

int main(void){
	car_t t, h;
	int boop;
	car_t *h, *g, *a;

	g = lget();
	if(g != NULL) return 1;
	
	a=(car_t *)malloc(sizeof(car_t));
	a->plate = "BVW975g";
	a->price = 29990.8;
	a->year = 1927;
	a->next = NULL;
	boop = lput(&a);
	if(boop != 0){
		free(a);
		return 2;
	}

	g=(car_t *)malloc(sizeof(car_t));
	g->plate = "JK83FB";
	g->price = 2000;
	g->year = 2024;
	g->next = NULL;

	boop = lput(&g);
	if(boop != 0){
		free(g);
		free(a);
		return 3;
	}

	h = lget();
	if(h == NULL) {
		free(g);
		free(a);
		return 4;
	}else{
		free(g);
		free(a);
		return 4;
	}
}

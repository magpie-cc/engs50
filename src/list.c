/* 
 * list.c --- 
 * 
 * Author: Magpie N. Carino
 * Created: 10-02-2025
 * Version: 1.0
 * 
 * Description: 
 * Implementation of a linked list specific to the car datatype
 */

typedef struct car {
        struct car *next;
        char plate[MAXREG];
        double price;
        int year;
} car_t;

int32_t lput(car_t *cp) {

 TODO: implement

	return 0;
}

car_t *lget() {

 TODO: implement

	return NULL;
}


void lapply(void (*fn)(car_t *cp)) {
	
	car_t *cp = head;
	
	while (*cp != NULL) {
		fn(*cp);
		*cp = head->next;
	}
}

car_t *lremove(char *platep) {
	car_t *cp = head;
	car_t *pp = NULL;

	// if removing at the start
	if (strcmp(cp->&plate, *platep)) {
		head = cp->*next;
		return cp;
	}

  while (*cp != NULL) {
		if (strcmp(cp->&plate, *platep)) {
			pp->*next = cp->*next;
			return cp;
		}
		
		*pp = *cp;
		*cp = head->next;
  }
	
	return NULL
}

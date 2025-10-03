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



/* the representation of a car */
typedef struct car {
        struct car *next;
        char plate[MAXREG];
        double price;
        int year;
} car_t;

/* put(): place a car at the beginning of the list
 * returns 0 if successful; nonzero otherwise 
 */
int32_t lput(car_t *cp) {

 TODO: implement

	return 0;
}

/* get(): remove and return the first car in the list;
 * return NULL if the list is empty
 */
car_t *lget() {

 TODO: implement

	return NULL;
}


/* apply a function to every car in the list */
void lapply(void (*fn)(car_t *cp)) {
	
	car_t *cp = head;
	
	while (*cp != NULL) {
		fn(*cp);
		*cp = head->next;
	}
}

/* remove(): find, remove, and return any car with
 * the designated plate; return NULL if not present
 */
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

/*
 * queue.c ---
 *
 * Author: Magpie N. Carino
 * Created: 10-04-2025
 * Version: 1.0
 *
 * Description:
 * linked list implmentation of a queue
 */

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct node {
	node *next;
	void *data;
} node_t;

typedef struct queue {
	node *front;
	node *back;
} queue_t;

queue_t* qopen(void) {
	queue_t *qp = malloc(sizeof(node_t));
	if (qp = NULL) {
		perror("malloc failed");
		return NULL;
	}
	return *qp
}

void qclose(queue_t *qp) {

	free(*qp);
	cp = NULL;
	// free queue memory
	// and anything that's left inside. If I do have to free all the node's memoryies then ah later problem
}

int32_t qput(queue_t *qp, void *elementp) {
	if (qp == NULL || elementp == NULL) {
		return -1;
	}

	node_t *newnode = malloc(sizeof(node_t));
	if (newnode == NULL) {
		perror("malloc failed");
		return -1;
	}

	newnode->data = elementp;
	newnode->next = NULL;

	if (qp->front == NULL) {
		// empty queue
		qp->front = newnode;
		qp->back = newnode;
	}
	else {
		// non-empty queue
		qp->back->next = newnode;
		qp->back = newnode;
	}

	return 0;
}

void* qget(queue_t *qp) {
	node_t *fp = qp->front != NULL ? front->next : return NULL;
	node_t *np = *fp;
	fp = fp->next;
	return np->data;
}

void qapply(queue_t *qp, void (*fn)(void* elementp)) {
	node_t *np = qp->front;
	while (np != NULL) {
		fn(np->data);
		np = np->next;
	}
}

void* qsearch(queue_t *qp,
							bool (*searchfn)(void* elementp,const void* keyp),
							const void* skeyp) {
	node_t *np = qp->front;
	while (np != NULL) {
		if (searchfn(np->data, skeyp)) {
			return np->data;
		}
		np = np->next;
	}
	
	return NULL;
}

void* qremove(queue_t *qp,
							bool (*searchfn)(void* elementp,const void* keyp),
							const void* skeyp) {
	node_t *np = qp-> front;
	node_t *pp;
	while (np != NULL) {
		if (searchfn(np->data, skeyp)) {
			pp->next = np->next;
			return np->data;
		}
		pp = np;
		np = np->next;
	}
	return NULL;
}

void qconcat(queue_t *q1p, queue_t *q2p) {
	node_t *bp = q1p->back;
	node_t *np = q2p->front;
	while (np != NULL) {
		bp->next = np;
		np = np->next;
	}
	q1p->back = bp;
	qclose(q2p);
	// qget on q2 until finds next -> NULL
	// qclose q2p
}

#include <stdio.h>
#include <stdlib.h>
#include "room.h"

// Clean up memory
void free_area(struct room ** b){
	free(*b);

	*b = NULL;
}

// Allocate memory for a struct room
struct room * create_area(char * name){
	struct room * temp = malloc(sizeof(struct room));

	if(temp == NULL){
		printf("Error allocating memory\n");
		exit(0);
	}

	temp->name = name;

	return temp;
}

/** 
 * Take two areas and link them
 *
 * The second argument is how b is located to a
 * a, 'w', b goes to 
 * a->west = b
 * b->east = a
 */
void link_areas(struct room * a, char l, struct room * b){
	switch(l){
		case 'n':
			a->north = b;
			b->south = a;
			break;
		case 'e':
			a->east = b;
			b->west = a;
			break;
		case 'w':
			a->west = b;
			b->east = a;
			break;
		case 's':
			a->south = b;
			b->north = a;
			break;
	}
}


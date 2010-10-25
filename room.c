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

	temp->north = NULL;
	temp->east = NULL;
	temp->west = NULL;
	temp->south = NULL;

	return temp;
}

/** 
 * Take two areas and link them
 *
 * The second argument is how b is located to a
 * a, 'w', b goes to 
 * a->west = b
 * b->east = a
 * 
 * return -1 if link failed
 */
int link_areas(struct room * a, char l, struct room * b){
	switch(l){
		case 'n':
			if(a->north != NULL || b->south != NULL){
				return -1;
			}

			a->north = b;
			b->south = a;
			break;
		case 'e':
			if(a->east != NULL || b->west != NULL){
				return -1;
			}

			a->east = b;
			b->west = a;
			break;
		case 'w':
			if(a->west != NULL || b->east != NULL){
				return -1;
			}

			a->west = b;
			b->east = a;
			break;
		case 's':
			if(a->south != NULL || b->north != NULL){
				return -1;
			}

			a->south = b;
			b->north = a;
			break;
	}

	return 1;
}

void show_map(struct room * map){
	printf("%s:\n", map->name);

	if(map->north != NULL)
		printf("\tNorth: %s\n", map->north->name);

	if(map->east != NULL)
		printf("\tEast:  %s\n", map->east->name);
		
	if(map->west != NULL)
		printf("\tWest:  %s\n", map->west->name);

	if(map->south != NULL)
		printf("\tSouth: %s\n", map->south->name);
}


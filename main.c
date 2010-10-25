#include <stdio.h>
#include <stdlib.h>
#include "room.h"

struct room * create_area(char *);
void free_area(struct room **);
void link_areas(struct room *, char, struct room *);

int main(){
	struct room * start;
	struct room * hallway;
	struct room * finish;

	start = create_area("Starting area");

	hallway = create_area("Hallway");

	finish = create_area("Finish area");

	link_areas(start, 'w', hallway);
	link_areas(hallway, 's', finish);

	printf("Welcome to the text game!\n");
	printf("Your goal is to get to the finish\n");

	printf("\nYou are currently in %s\n", start->name);
	printf("To the west is %s\n", start->west->name);

	// Clear memory
	free_area(&start);

	free_area(&hallway);

	free_area(&finish);

	return 0;
}

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


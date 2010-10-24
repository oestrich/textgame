#include <stdio.h>
#include "room.h"

void link_areas(struct room *, char, struct room *);

int main(){
	struct room start;
	struct room finish;

	start.name = "Starting area";

	finish.name = "Finish area";

	link_areas(&start, 'w', &finish);


	printf("Welcome to the text game!\n");
	printf("Your goal is to get to the finish\n");

	printf("\nYou are currently in %s\n", start.name);
	printf("To the west is %s\n", start.west->name);

	return 0;
}

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


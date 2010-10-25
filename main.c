#include <stdio.h>
#include <stdlib.h>
#include "room.h"

int main(){
	struct room * start;
	struct room * hallway;
	struct room * deadend;
	struct room * finish;

	start = create_area("Starting area");

	hallway = create_area("Hallway");

	deadend = create_area("Dead end");

	finish = create_area("Finish area");

	link_areas(start, 'w', hallway);
	link_areas(hallway, 'n', deadend);
	link_areas(hallway, 's', finish);

	printf("Welcome to the text game!\n");
	printf("Your goal is to get to the finish\n");

	printf("\nYou are currently in %s\n", start->name);
	printf("To the west is %s\n", start->west->name);

	show_map(start);
	show_map(hallway);
	show_map(deadend);
	show_map(finish);

	// Clear memory
	free_area(&start);

	free_area(&hallway);

	free_area(&finish);

	return 0;
}


#ifndef ROOM_H
#define ROOM_H

struct room{
	char * name;

	struct room * north;
	struct room * east;
	struct room * west;
	struct room * south;
};

struct room * create_area(char *);

void free_area(struct room **);

void link_areas(struct room *, char, struct room *);

#endif


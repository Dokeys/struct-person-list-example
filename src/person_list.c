/*
 * person_list.c
 *
 *  Created on: 17.12.2022
 *      Author: Dominik Knoll
 *
 */
#include "person.h"
#include "person_list.h"

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct person_list_s{
	person_t **list;
	size_t entrys;
};

/* person list functions */
person_list_t* create_person_list() {
	person_list_t *self = malloc(sizeof(person_list_t));
	if (self == NULL) {
		printf("unable to allocate memory for person list");
		return self;
	}
	self->entrys = 0;
	self->list = malloc(0);

	return self;
}

void add_person_to_person_list(person_list_t *self, const person_t *new_person) {
	self->list = realloc(self->list, sizeof(person_t*) * (self->entrys + 1));
	if (self->list == NULL) {
		printf("unable to allocate memory for person list pointer for %s.\n", get_person_string(new_person));
		return;
	}

	self->list[self->entrys] = malloc(get_sizeof_person_t());
	if (self->list[self->entrys] == NULL) {
		printf("unable to allocate memory for new person in list.\n");
		return;
	}
	self->list[self->entrys] = create_person(get_person_first_name(new_person),
											 get_person_last_name(new_person),
											 get_person_age(new_person));
	self->entrys++;
}

person_t* get_list_person(person_list_t *self, unsigned int entry) {
	if (entry >= self->entrys) {
		printf("entry of index %d is empty.\n", entry);
		return NULL;
	}
	return self->list[entry];
}

void print_person_list(const person_list_t *self) {
	printf("person_list = [\n");
	for (int i = 0; i < self->entrys; i++) {
		printf("\t");
		print_person(self->list[i]);
	}
	printf("]\n");
}

void destroy_person_list(person_list_t *self) {
	for(int i=0; i<self->entrys; i++)
		destroy_person(self->list[i]);
	free(self->list);
	free(self);
}

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

/* person list functions */
void init_person_list(person_list_t *self) {
	destroy_person_list(self);
	self->list = malloc(0);
}

void add_person_to_person_list(person_list_t *self, const person_t *new_person) {
	self->list = realloc(self->list, sizeof(person_t*) * (self->entrys + 1));
	if (self->list == NULL) {
		printf("unable to allocate memory for person list pointer for %s.\n", new_person->first_name);
		return;
	}

	self->list[self->entrys] = malloc(sizeof(person_t));
	if (self->list[self->entrys] == NULL) {
		printf("unable to allocate memory for new person in list.\n");
		return;
	}
	init_person(self->list[self->entrys], new_person->first_name, new_person->last_name, new_person->age);

	self->entrys++;
}

person_t *get_list_person(person_list_t *self, unsigned int entry) {
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
	free(self->list);
	self->list = NULL;
	self->entrys = 0;
}

/*
 * person.c
 *
 *  Created on: 17.12.2022
 *      Author: Dominik Knoll
 *
 */
#include "person.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* person functions */
void init_person(person_t *self, const char *first_name, const char *last_name, int age) {
	destroy_person(self);
	set_person_first_name(self, first_name);
	set_person_last_name(self, last_name);
	set_person_age(self, age);
}

/* person setters */
void set_person_first_name(person_t *self, const char *first_name) {
	if (self->first_name == NULL) // for init
		self->first_name = malloc(sizeof(first_name));
	else
		self->first_name = realloc(self->first_name, sizeof(first_name));

	if (self->first_name == NULL) {
		printf("unable to allocate memory for first name of %s.\n", first_name);
		return;
	}
	strcpy(self->first_name, first_name);
}

void set_person_last_name(person_t *self, const char *last_name) {
	if (self->last_name == NULL)  // for init
		self->last_name = malloc(sizeof(last_name));
	else
		self->last_name = realloc(self->last_name, sizeof(last_name));

	if (self->last_name == NULL) {
		printf("unable to allocate memory for last name of %s.\n", last_name);
		return;
	}
	strcpy(self->last_name, last_name);
}

void set_person_age(person_t *self, unsigned int age) {
	self->age = age;
}

/* person getters */
char* get_person_first_name(person_t *self) {
	return self->first_name;
}

char* get_person_last_name(person_t *self) {
	return self->last_name;
}

unsigned int get_person_age(person_t *self) {
	return self->age;
}

void destroy_person(person_t *self) {
	free(self->first_name);
	self->first_name = NULL;
	free(self->last_name);
	self->last_name = NULL;
	self->age = 0;
}

void print_person(person_t *self) {
	if (self == NULL) {
		printf("print person with null pointer.");
		return;
	}
	printf("person: %s %s is %u years old.\n", self->first_name, self->last_name, self->age);
}


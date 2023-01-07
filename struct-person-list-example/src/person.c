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
#include <stddef.h>
#include <string.h>

struct person_s {
	char *first_name;
	char *last_name;
	unsigned int age;
};

/* person functions */
person_t* create_person(const char *first_name, const char *last_name, int age) {
	person_t *self = malloc(sizeof(person_t));
	self->first_name = NULL;
	self->last_name = NULL;
	set_person_first_name(self, first_name);
	set_person_last_name(self, last_name);
	set_person_age(self, age);
	return self;
}

/* person setters */
void set_person_first_name(person_t *self, const char *first_name) {
	if (self->first_name == NULL) // for init
		self->first_name = malloc(sizeof(char) * strlen(first_name) + 1);
	else
		self->first_name = realloc(self->first_name, sizeof(char) * strlen(first_name) + 1);

	if (self->first_name == NULL) {
		printf("unable to allocate memory for first name of %s.\n", first_name);
		return;
	}
	strcpy(self->first_name, first_name);
}

void set_person_last_name(person_t *self, const char *last_name) {
	if (self->last_name == NULL)  // for init
		self->last_name = malloc(sizeof(char) * sizeof(last_name) + 1);
	else
		self->last_name = realloc(self->last_name, sizeof(char) * sizeof(last_name) + 1);

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
char* get_person_first_name(const person_t *self) {
	return self->first_name;
}

char* get_person_last_name(const person_t *self) {
	return self->last_name;
}

unsigned int get_person_age(const person_t *self) {
	return self->age;
}

char* get_person_string(const person_t *self) {
	static char *str;
	int len;

	free(str);
	len = sprintf(NULL, "person: first_name=%s, last_name%s, age=%d", self->first_name, self->last_name, self->age);
	str = malloc(len + 1);
	if (str == NULL) {
		printf("unable to allocate memory for the person string of %s.\n", self->first_name);
		return NULL;
	}
	sprintf(str, "person: first_name=%s, last_name%s, age=%d", self->first_name, self->last_name, self->age);
	return str;
}

void destroy_person(person_t *self) {
	free(self->first_name);
	free(self->last_name);
	free(self);
}

size_t get_sizeof_person_t() {
	return sizeof(person_t);
}

void print_person(person_t *self) {
	if (self == NULL) {
		printf("print person with null pointer.");
		return;
	}
	printf("person: %s %s is %u years old.\n", self->first_name, self->last_name, self->age);
}


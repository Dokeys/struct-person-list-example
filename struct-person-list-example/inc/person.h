/*
 * person.h
 *
 *  Created on: 17.12.2022
 *      Author: Dominik Knoll
 *
 *  Description:
 *  person_t can be used like a object with getters and setters.
 *  Dynamic memory allocation is used to save the strings from the struct.
 *
 *  Example:
 *  person_t *dome = create_person("Dominik", "Knoll", 32);
 *	print_person(dome);
 *
 */
#ifndef INC_PERSON_H_
#define INC_PERSON_H_

#include <stddef.h>

typedef struct person_s person_t;  /* Opaque object. The person struct is hidden and can only be used by person.c. */

/* global prototypes */
person_t* create_person(const char *first_name, const char *last_name, int age);
void set_person_first_name(person_t *self, const char *first_name);
void set_person_last_name(person_t *self, const char *first_name);
void set_person_age(person_t *self, unsigned int age);
char* get_person_first_name(const person_t *self);
char* get_person_last_name(const person_t *self);
unsigned int get_person_age(const person_t *self);
char* get_person_string(const person_t *self);
void destroy_person(person_t *self);
size_t get_sizeof_person_t();
void print_person(person_t *self);

#endif /* INC_PERSON_H_ */

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
 *  person_t dome;
 *	init_person(&dome, "Dominik", "Knoll", 32);
 *	print_person(&dome);
 *
 */
#ifndef INC_PERSON_H_
#define INC_PERSON_H_

typedef struct {
	char *first_name;
	char *last_name;
	unsigned int age;
} person_t;

/* global prototypes */
void init_person(person_t *self, const char *first_name, const char *last_name, int age);
void set_person_first_name(person_t *self, const char *first_name);
void set_person_last_name(person_t *self, const char *first_name);
void set_person_age(person_t *self, unsigned int age);
char* get_person_first_name(person_t *self);
void destroy_person(person_t *self);
void print_person(person_t *self);

#endif /* INC_PERSON_H_ */

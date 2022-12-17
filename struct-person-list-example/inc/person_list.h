/*
 * person_list.h
 *
 *  Created on: 17.12.2022
 *      Author: Dominik Knoll
 *
 *  Description:
 *  person_list_t is for saving "objects" of type person_t in a list.
 *  Dynamic memory allocation is used.
 *
 *  Example:
 *  person_t dome, klaus;
 *	init_person(&dome, "Dominik", "Knoll", 32);
 *	init_person(&klaus, "Klaus", "Kleber", 66);
 *
 *	person_list_t list;
 *	init_person_list(&list);
 *	add_person_to_person_list(&list, &dome);
 *	add_person_to_person_list(&list, &klaus);
 *
 *	print_person_list(&list);
 *
 */
#ifndef INC_PERSON_LIST_H_
#define INC_PERSON_LIST_H_

#include <stdlib.h>

typedef struct {
	person_t **list;
	size_t entrys;
} person_list_t;

/* global prototypes */
void init_person_list(person_list_t *self);
void add_person_to_person_list(person_list_t *self, const person_t *new_person);
person_t *get_list_person(person_list_t *self, unsigned int entry);
void print_person_list(const person_list_t *self);
void destroy_person_list(person_list_t *self);

#endif /* INC_PERSON_LIST_H_ */

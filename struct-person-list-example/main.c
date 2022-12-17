/*
 * main.c
 *
 *  Created on: 16.12.2022
 *      Author: Dominik Knoll
 *
 *  Description:
 *  This is a simple example of the opaque struct pattern in c .
 *  person_t can be used like an object. The objects can be stored in an person_list_t object.
 *  Dynamic memory allocation is used for most of the stuff.
 *
 *  Output:
 *	person_list = [
 *		person: Dominik Knoll is 32 years old.
 *		person: Klaus Kleber is 66 years old.
 *		person: Petra Schmitt is 35 years old.
 *	]
 *	person: Klaus Kleber is 66 years old.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "person.h"
#include "person_list.h"

int main(int argc, char **argv) {
	/* create persons */
	person_t *dome = create_person("Dominik", "Knoll", 32);
	person_t *klaus = create_person("Klaus", "Kleber", 66);
	person_t *petra = create_person("Petra", "Schmitt", 35);

	// petra->age = 16;  // is not possible because person_t is an opeque object.

	print_person(dome);

	/* create person list an add persons to list */
	person_list_t *list = create_person_list();
	add_person_to_person_list(list, dome);
	add_person_to_person_list(list, klaus);
	add_person_to_person_list(list, petra);

	print_person_list(list);

	/* get a person from list */
	person_t *person_list_ptr;
	unsigned int list_index = 1;
	person_list_ptr = get_list_person(list, list_index);
	print_person(person_list_ptr);

	destroy_person_list(list);

	return 0;
}

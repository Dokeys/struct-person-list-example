/*
 * main.c
 *
 *  Created on: 16.12.2022
 *      Author: Dominik Knoll
 *
 *  Description:
 *  This is a simple example of the struct pattern in c.
 *  person_t can be used like an object. The objects can be stored in an person_list_t object.
 *  Dynamic memory allocation is used for the most of the stuff.
 *
 *  Output:
 *	person_list = [
 *		person: Klaus Kleber is 66 years old.
 *		person: Petra Schmitt is 35 years old.
 *	]
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "person.h"
#include "person_list.h"

int main(int argc, char **argv) {
	/* create persons */
	person_t dome, klaus, petra;
	init_person(&dome, "Dominik", "Knoll", 32);
	init_person(&klaus, "Klaus", "Kleber", 66);
	init_person(&petra, "Petra", "Schmitt", 35);

	/* create person list an add persons to list */
	person_list_t list;
	init_person_list(&list);
	add_person_to_person_list(&list, &dome);
	add_person_to_person_list(&list, &klaus);
	add_person_to_person_list(&list, &petra);

	print_person_list(&list);

	/* get a person from list */
	person_t *person_list_ptr;
	unsigned int list_index = 1;
	person_list_ptr = get_list_person(&list, list_index);
	print_person(person_list_ptr);


	return 0;
}

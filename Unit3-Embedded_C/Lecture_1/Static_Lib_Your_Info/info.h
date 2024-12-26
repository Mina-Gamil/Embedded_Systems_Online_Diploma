#ifndef INFO_H
#define INFO_H


/***** Typedef Struct Sperson_t *****/
typedef struct {
	char FirstName[50];
	char SecondName[50];
	int Age;
}Sperson_t;

/***** vPrint_Details Finction Prototype *****/
void vPrint_Details(void* vPtr);

#endif 
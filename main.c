
#include <stdlib.h>
#include <stdio.h>
#include "shelltask.c"


/* ********************************************************************* */
/* Local functions */
int modulexxx_init(void)
{ 	
	extern unsigned int  _customized_start;
	extern unsigned int  _customized_end;
	unsigned int * start = (unsigned int *)&_customized_start;
	unsigned int * end = (unsigned int *)&_customized_end;
	int (*module_init)(int);
	
	
	int i=1;
	while (start < end)
	{
		module_init = (int (*)(int))(*start);
		(*module_init)(i);
		start++;
		i++;
	}

	return 1;
}

void main (void)
{
	init_command();                  
	modulexxx_init();

	shelltask();
}

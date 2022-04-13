#include <stdio.h>	/* printf, sprintf */
#include <string.h>	/* memset, memcpy, memcmp, strtok_r */
#include <stdlib.h>	/* atoi */

/*
 * Written by leewsdaddy@gmail.com for SW LEE
 * This is about how to parse a string.
 * You have learned how to handle char and char array.
 * Now, we're going to use it practically.
 */

/*
 * Print out command line arguments
 */
void printArgs (int argc, char **argv){
	int i=0;
	printf ("argc=>%d\n", argc);
	for (i=0; i<argc; i++){
		printf ("argv[%d]=>\"%s\"\n", i, argv[i]);
	}
}

/*
 * Get a string to parse and a delimiter.
 * Print out parsed tokens(strings).
 * Using strtok_r in string.h
 * https://www.qnx.com/developers/docs/7.1/#com.qnx.doc.neutrino.lib_ref/topic/s/strtok_r.html
 */
int useStrtok_r (char *x){
	return 1;
}

int main (int argc, char **argv){
	printArgs (argc, argv);
	return 1;
}

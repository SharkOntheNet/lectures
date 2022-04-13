#include <stdio.h>	/* printf, sprintf */
#include <string.h>	/* memset, memcpy, memcmp, strtok_r, strchr, strrchr */
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
 * Print out usage message.
 */
void usage (char *binName){
	printf ("\n### Usage ###\n");
	printf ("%s requires 1 argument.\n", binName);
	printf ("ex) %s adfadfadfkjkjfdk\n", binName);
	printf ("ex) %s \"adfadf adfkj kjfdk\"\n", binName);
	printf ("ex) %s name=shark\n", binName);
	printf ("\n");
	return;
}

/*
 * Get a string to parse and a delimiter.
 * Print out parsed tokens(strings).
 * Using strtok_r in string.h
 * https://www.qnx.com/developers/docs/7.1/#com.qnx.doc.neutrino.lib_ref/topic/s/strtok_r.html
 */
int useStrtok_r (char *x){
#ifdef DEBUG
	char *name = "useStrtok_r@002_parseStrtok_r.c";
#endif

	printf ("Before strtok_r=>\"%s\" (len=%lu)\n", x, strlen(x));
	char *delimiter = " :;=/\\";
	char *context = NULL;
	char *token = strtok_r (x, delimiter, &context);
	//char *token = strtok_r (x, " ", &context);
	while (token != NULL){
		printf ("\ttoken string=>%s\n", token);
		token = strtok_r(NULL, delimiter, &context);
		//token = strtok_r(NULL, " ", &context);
	}
	/* strtok_r or strtok replaces the delimiter with 0x00 */
	printf ("After strtok_r=>\"%s\" (len=%lu)\n", x, strlen(x));

	return 1;
}

int main (int argc, char **argv){
	/* Print out args */
	printArgs (argc, argv);

	/* Check args */
	if (argc != 2){
		usage (argv[0]);
		return 0;
	}

	/* Parse an string */
	useStrtok_r (argv[1]);

	return 1;
}

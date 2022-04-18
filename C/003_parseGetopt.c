#include <stdio.h>	/* printf, sprintf */
#include <string.h>	/* memset, memcpy, memcmp, strtok_r */
#include <stdlib.h>	/* atoi */
#include <unistd.h> /* getopt */

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
 * Get all the arguments and parse with option flags
 * Using getopt function in unistd.h
 * https://www.qnx.com/developers/docs/7.1/#com.qnx.doc.neutrino.lib_ref/topic/g/getopt.html
 * https://www.gnu.org/software/libc/manual/html_node/Example-of-Getopt.html
 *
 * ./x -a -b -c adfadfadf
 */
int useGetopt (int argc, char **argv){
	u_int8_t aflag=0, bflag=0;
	int c=0;
	char *cvalue = NULL;

	while ((c = getopt (argc, argv, "abc:")) != -1){
		switch (c){
			case 'a':
				aflag = 1;
				break;
			case 'b':
				bflag = 1;
				break;
			case 'c':
				cvalue = optarg;
				break;
			case '?':
				/* if unknown one */
				printf ("unknown option: %c\n", optopt);
				break;
			default:
				break;
		}
	}

	printf ("aflag=%u, bflag=%u, cvalue=%s\n", aflag, bflag, cvalue);

	return 1;
}

int main (int argc, char **argv){
	printArgs (argc, argv);

	useGetopt (argc, argv);

	return 1;
}

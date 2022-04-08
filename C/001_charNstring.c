#include <stdio.h>			/* printf, sprintf */
#include <string.h> 		/* strlen, memset, memcpy, memcmp */
#include <sys/types.h>	/* u_int8_t */
#include <stdlib.h> 		/* atoi */

/*
 * This is a lecture for SW Lee written by me, daddy / leeswdaddy@gmail.com
 * Contents: char, char array == string, how to handle them and
 * When printArgs is enabled, try command like
 * ./tt adfadf "adkfadlsfjdf akadjlfj lafjdkf"
 * ./tt adflkjaldfj abcd"   "efg' 'xxx XX
 * #ifdef DEBUG to enable or disable debug messages, commands are below
 * enable: 	gcc -o tt tt.c -D DEBUG
 * disable:	gcc -o tt tt.c
 */


/*
 * Print out command line arguments.
 */
void printArgs (int argc, char **argv){
  /* Print out arguments count */
  printf ("argc=%d\n", argc);

  /* Print out each argument */
	int i=0, j=0;
  for (i=0; i<argc; i++){
		/* strlen returns size_t type number, int x=strlen(s) is Ok, but printf needs %zd or %zu */
    printf ("argv[%d] => \"%s\" (len=>%zu)\n", i, argv[i], strlen(argv[i]));
		for (j=0; j<strlen(argv[i]); j++){
			printf ("\targv[%d][%d] => %c (u_int8_t=>%u), &argv[%d][%d] string => \"%s\" (len=%zu)\n",
			i, j, argv[i][j], argv[i][j], i, j, &argv[i][j], strlen(&argv[i][j]));
		}
  }
}

/*
 * Change the values of an array both char and int.
 * Returns -1 when error
 */
int changeArrayValues (char *s, int slen, int *d, int dlen){
	if (s == NULL || d == NULL){
		return -1;
	}
	int i=0;
	for (i=0; i<slen; i++){
		s[i] = 'Z';
	}
	for (i=0; i<dlen; i++){
		d[i] = 100;
	}
	return 1;
}

/*
 * A string is an array of char.
 */
void howtoArray (){
  char *s1="abcdefg";
  char s2[8];
	int i=0;
  printf("char[3] == [][][], a string is an array of char\n");

	/* This is why we use array type of [] */
  char *ts = "abc";
  //ts[0]= 'z';
  //ts[4]= 'd';
  /* ts is readonly */

	printf ("/////////////// Array initialization\n");
	/* An array initilization using memset */
  printf ("s2 without memset (initialization)\n");
  for (i=0; i<8; i++){
    printf("\ts2[%d]=%d\n", i, s2[i]);
  }
  printf ("s2 after memset (initialization)\n");
  memset (s2, 0x00, 8);
  for (i=0; i<8; i++){
    printf("\ts2[%d]=%d\n", i, s2[i]);
  }

	/* Use sprintf to print a string into an char array. */
	printf ("/////////////// Print out to an array\n");
  sprintf (s2, "test%d", 123);
	printf ("After sprintf s2=>%s\n", s2);

	/* An array's address is the address of the 1st indice */
	printf ("/////////////// Address\n");
	printf ("address of s2=%p, address of s2[0]=%p\n", s2, &s2[0]);
	/* where as a variable gives you its value */
	int testInt=7;
	printf ("testInt's address=%p, value=%d\n", &testInt, testInt);

	/* Just print out. */
	printf ("/////////////// Just print out\n");
  printf ("print string s1 and s2\n");
  printf ("\ts1=%s, s2=%s\n", s1, s2);

  /* Get the length of strings. */
	printf ("/////////////// Get array length\n");
  int s1len = strlen (s1);
  int s2len = strlen (s2);
  printf ("print the length of strings\n");
  printf ("\ts1len=%d, s2len=%d\n", s1len, s2len);

	/* To traverse a char array by index number. */
	printf ("/////////////// Traverse/visit each indices/itme by index number\n");
  printf ("print each char of an array by index number\n");
  printf ("\ts1=%s\n", s1);
  for (i=0; i<s1len; i++){
    printf ("\t\ts1[%d]=%c(%d)\n", i, s1[i], s1[i]);
  }
  printf ("\ts2=%s\n", s2);
  for (i=0; i<s2len; i++){
    printf ("\t\ts2[%d]=%c(%d)\n", i, s2[i], s2[i]);
  }

	/* To traverse a char array with pointer. */
	printf ("/////////////// Traverse/visit each indices/itme with pointer\n");
  printf ("print each char of an array by pointer\n");
  char *t=s1;
  for (i=0; i<s1len; t++, i++){
    printf ("\ts1*%d=%c\n", i+1, *t);
  }
  printf ("set char pointer to the 1st bucket\n");
  t=&s2[0];
  for (i=0; i<s1len; t++, i++){
    printf ("\ts2*%d=%c\n", i+1, *t);
    printf ("\ts2*%d=%s\n", i+1, t);
  }
  printf ("set char pointer to the array variable\n");
  t=s2;
  for (i=0; i<s2len; t++, i++){
    printf ("\ts2*%d=%c\n", i+1, *t);
    printf ("\ts2*%d=%s\n", i+1, t);
  }

	/* This is how printf works. */
	printf ("/////////////// Kind of printf, how it works\n");
  printf ("This is how it prints a string (== char array)\n\t");
	t=&s2[0]; // char *t is declared above
  for (;;t++){
    printf ("%c", *t);
    if (*t == 0x00){
      break;
    }
  }
  printf ("\n");

	/* To change a value of an array. */
	printf ("/////////////// Change an array's values\n");
	printf ("before change: s2=>%s\n", s2);
  for (i=0; i<s2len; i++){
    s2[i] = 'z';
  }
	printf ("after change: s2=>%s\n", s2);

	/*
	 * Array copy or compare operation will be simple when you use memcpy and memcmp
	 * otherwise you have to copy or compare each of char in an char array.
	 * memset, memcpy and memcmp are defined in string.h
	 * The memset example is above, here will show you memcpy and memcmp.
	 * So useful if you are careful about the length parameter of those functions.
	 * memcpy (target array address, source array address, lengh)
	 * The length of the target array should be bigger than the length.
	 */
	printf ("/////////////// memset, memcpy, memcmp\n");
	char cs[8], ct[16];
	/* To initialize arrays with memset */	
	memset (cs, 0x00, 8);
	memset (ct, 0x00, 16);
	cs[0] = 'a'; cs[1] = 'b'; cs[2] = 'c'; cs[3] = 'd';
	printf ("before memcpy: cs(source array)=>\"%s\", ct(target array)=>\"%s\"\n", cs, ct);
	/* To copy cs array => ct array */
	memcpy (ct, cs, strlen(cs));
	printf ("after memcpy: cs(source array)=>\"%s\", ct(target array)=>\"%s\"\n", cs, ct);
	/* Set a pointer to a indice of ts array and copy cs again */
	char *cp = &ct[4];
	memcpy (cp, cs, strlen(cs));
	printf ("after memcpy again: cs(source array)=>\"%s\", ct(target array)=>\"%s\"\n", cs, ct);

	/* Now compare cs and ct */
	char css[8];
	memset (css, 0x00, 8);
	memcpy (css, cs, strlen(cs));
	/* Both cs and css arrays have the same values for memcpy */
	printf ("1st, before comcmp: cs=>\"%s\", css=>\"%s\"\n", cs, css);
	if (memcmp (cs, css, strlen(cs)) == 0){
		printf ("after memcmp: memcmp returns 0, meaning cs and css are identical/same\n");
	}
	else{
		printf ("after memcmp: memcmp returns not 0, meaning cs and css are not identical/same\n");
	}
	/* Change a bit in the css array and compare */
	css[1] = 'B';
	printf ("2nd, before comcmp: cs=>\"%s\", css=>\"%s\"\n", cs, css);
	if (memcmp (cs, css, strlen(cs)) == 0){
		printf ("after memcmp: memcmp returns 0, meaning cs and css are identical/same\n");
	}
	else{
		printf ("after memcmp: memcmp returns not 0, meaning cs and css are not identical/same\n");
	}
	/* Compare a certine part of the array, cs[2] cs[3] and css[2] css[3] */
	printf ("3rd, before comcmp: cs=>\"%s\", css=>\"%s\"\n", cs, css);
	if (memcmp (&cs[2], &css[2], 2) == 0){
		printf ("after memcmp: memcmp returns 0, meaning cs and css are identical/same\n");
	}
	else{
		printf ("after memcmp: memcmp returns not 0, meaning cs and css are not identical/same\n");
	}
	/* Make 2 arrays out of 1 array with deleting one value in the array */
	printf ("before split an array: ct=>%s\n", ct);
	char *array1 = NULL, *array2 = NULL;
	array1 = ct; // array1 = &ct[0]; // all the same
	ct[3] = 0x00;
	array2 = &ct[4];
	printf ("after splitting: ct=>%s, array1=%s, array2=%s\n", ct, array1, array2);

	/*
	 * How to call a function with char and int pointers of both arrays and
	 * change values of those arrays.
	 * Note: Get the length of a char array is easy anywhere because of 0x00 at the end of the array,
	 * but other type of array does not. So, you need to send the length otherwise you will mess it up.
	 */
	printf ("/////////////// Call a function with char and int pointers and the function changes the values of arrays\n");
	char carray[4] = {'a','b','c',0x00};
	int darray[5] = {7, 7, 7, 7, 7};
	printf ("before changeArrayValues: carray=>\"%s\", darray=>%d,%d,%d,%d,%d\n", carray, darray[0], darray[1], darray[2], darray[3], darray[4]);
	//if (changeArrayValues (carray, strlen(carray), darray, 5) == -1){
	if (changeArrayValues (carray, 3, darray, 5) == -1){
		printf ("changeArrayValues error\n");
	}
	printf ("after changeArrayValues: carray=>\"%s\", darray=>%d,%d,%d,%d,%d\n", carray, darray[0], darray[1], darray[2], darray[3], darray[4]);
	
}

/*
 * This is my take on converting a char to a integer.
 * returns -1 when the char is not a number letter.
 */
int charToInt (char x){
#ifdef DEBUG
	char *FNAME="charToInt@tt.c";
#endif
	/* Not a number letter */
#ifdef DEBUG
	//printf ("[INFO]%s: input char=%c (int=%u)\n", FNAME, x, x);
#endif
	//if (x < '0' || x > '9'){  // slow
	if (x < 48 || x > 57){ // fast
		return -1;
	}
	return x-48;
}

/*
 * This is my take on converting a char aray to an integer.
 * returns -1 when the char is not an number letter or empty.
 */
int myAtoI (char *x){
#ifdef DEBUG
	char *FNAME="myAtoI@tt.c";
#endif
	int t=0, ret=0, i=0, n=0, len=strlen(x);
	if (len < 1){
		return -1;
	}
#ifdef DEBUG
	printf ("[INFO]%s: input char array => \"%s\" (len=%d)\n", FNAME, x, len);
#endif

	/* Traverse a string in reverse order. */
	for(i=len-1, n=1; i>-1; i--){
		if ((t = charToInt(x[i])) < 0){
			return -1;
		}
		/* 1 => 10 => 100 => 1000 => 10000 ... */
		if (i != len-1){
			n *= 10;
		}
#ifdef DEBUG
		printf("[INFO]%s: x[%d] t=%d * n=%d => %d\n", FNAME, i, t, n, t*n);
#endif

		/* To accumulate all the values. */
		ret += t * n;
	}
	return ret;
}

/*
 * Get pointers and change values
 */
void changeValue (char *x, int *y){
	if (x == NULL || y == NULL){
		return;
	}
	*x = 'Z';
	*y = 100;
	return;
}

/*
* A char is an u_int8_t. now lookup the ASCII table and you will see it has an linear number order.
* You can treat a char as an number and compare with other chars because it is a number defined as a char.
*/
void howtoChar (){

	/* Test cases below, small letter, capital letter, number letter and space */
	char k='h';
	//char k='U';
	//char k='7';
	//char k=' ';

	/*
	 * lookup ASCII table in CLI(command line interface) with the command like
	 * $ascii
	 * install ascii: mac=>brew install ascii, ubuntu=>apt install ascii, redhat/centos=>yum install ascii
	 */
	printf ("////////////////////////////////////////////////////\n");
	printf ("ASCII table numbers for the alphabet letters/chars\n");
	printf ("lower case letters, \'a\':%u to \'z\':%u\n", 'a', 'z');
	printf ("capital letters, \'A\':%u to \'Z\':%u\n", 'A', 'Z');
	printf ("number letters, \'0\':%u to \'9\':%u\n", '0', '9');
	printf ("A space is an letter, \'%c\':%u\n", ' ', ' ');
	printf ("////////////////////////////////////////////////////\n");
	if (k >= 'a' && k <= 'z'){
		printf ("\'%c\' is an lower case letter (%c:%u)\n", k, k,k);
	}
	else if (k >= 'A' && k <= 'Z'){
		printf ("\'%c\' is an captial letter (%c:%u)\n", k, k,k);
	}
	else if (k >= '0' && k <= '9'){
		printf ("\'%c\' is a number letter (%c:%d)\n", k, k,k);
	}
	else{
		printf ("\'%c\' is not a letter\n", k);
	}

	/* Compare as like numbers. */
	if (k >= 97 && k <= 122){
		printf ("** \'%c\' is an lower case letter (%c:%u)\n", k, k,k);
	}
	else if (k >= 65 && k <= 90){
		printf ("** \'%c\' is an captial letter (%c:%u)\n", k, k,k);
	}
	else if (k >= 48 && k <= 49){
		printf ("** \'%c\' is a number letter (%c:%d)\n", k, k,k);
	}
	else{
		printf ("** \'%c\' is not a letter\n", k);
	}

	/* A space is a letter, meaning it has its own number. */
	if (k == ' '){
		printf ("\'%c\' is an space\n", k);
	}
	if (k == 32){
		printf ("** \'%c\' is an space\n", k);
	}

	/*
	 * A char is an u_int8_t basically. integer without a sign bit in a 8bit box.
	 * so, char == u_int8_t, it is a number with a ASCII table in order to find a character corresponding the number.
	 * The header file for the u_int8_t is sys/types.h
	 */
	printf ("/////////////// char is actually int, u_int8_t exactly\n");
	char ts[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 0x00};
	printf ("1st: char array=> \t%s\n", ts);

	char ts2[8] = {97, 98, 99, 100, 101, 102, 103, 0};
	printf ("2nd: char array=> \t%s\n", ts2);

	u_int8_t tx[8] = {97, 98, 99, 100, 101, 102, 103, 0};
	printf ("3rd: u_int8_t array=> \t%s\n", tx);


	/*
	 * When you get a number letter, you may want to convert it into an integer.
	 * This can be done by a function from a standard C library, its name is atoi.
	 * The atoi means a(ascii number letter) to i(integer), header file is stdlib.h
	 * You may want to lookup the man page of atoi. It takes an address of a char.
	 */
	printf ("/////////////// ASCII to integer\n");
	char tn = '6';
	printf ("number char \'%c\' => into integer %d\n", tn, atoi(&tn));
	char ttn[3] = {'1', '2', 0x00};
	printf ("number string \'%s\' with ttn => into integer %d\n", ttn, atoi(ttn));
	printf ("number string \'%s\' with &ttn[0]=> into integer %d\n", ttn, atoi(&ttn[0]));

	/* myAtoI (char *) using charToInt (char) */
	printf ("/// myAtoI (char *) using charToInt (char) ///\n");
	char n = '7';
	printf ("\'%c\' => charToInt (char) => %d\n", n, charToInt(n));
	char *ns = "567";
	printf ("\"%s\" => myAtoI (char *) => %d\n", ns, myAtoI(ns));


	/*
 	 * Sometimes you may want to call a function with an address of a char or int.
 	 * When you deal with the value of that pointer/address like inserting a value,
 	 * you may have to do like this
 	 */
	printf ("/////////////// How to change values by char or int variable pointers in a function\n");
	char cxx = 'a';
	int iyy = 7;
	printf ("before changeValue: cxx=%c, iyy=%d\n", cxx, iyy);
	changeValue (&cxx, &iyy);
	printf ("after changeValue: cxx=%c, iyy=%d\n", cxx, iyy);

}

int main (int argc, char **argv){
  /* Print out each argument. */
  //printArgs(argc, argv);

  /* Test array. */
	//howtoArray();

	/* Let's get used to char array aka string. */
	howtoChar();

  return 1;
}

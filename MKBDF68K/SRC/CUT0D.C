/*
* file filter ( code name "Cut 0x0D")
* 1998.10  Tetsuo.Mitsuda
* Compile:
*    (GCC) : gcc -o cut0d cut0d.c
* (X68GCC) : gcc -o cut0d.x cut0d.c
*  (X68XC) : cc cut0d.c
*
* Usage:
*  cut0d outputfile < inputfile  
*/

#include <stdio.h>
#include <stdlib.h>

char default_name[]="DEFAULT.TMP";

int main(int argc , char *argv[])
{
	int    c;
	char  *ptr;
	FILE  *fp;

	ptr = &default_name[0];

	if( argc >= 2 ){ ptr = argv[1]; }


	fp = fopen( ptr ,"wb" );
	if( fp == NULL ){
		printf("Can't Create file ;%s\n",ptr);
		exit(1);
	}

	while( (c = getchar() ) != EOF ){

		if( c != 0x0D ){ fputc( c, fp ); }

	}

	fclose(fp);

}



/*
* bdf file filter ( code name "Bold as love")
* 1998.10  Tetsuo.Mitsuda
*
* Compile:
*    (GCC) : gcc -o bdfbold bdfbold.c
* (X68GCC) : gcc -o bdfbold.x bdfbold.c
*  (X68XC) : cc bdfbold.c
*
* Usage:
*  bdfbold < input_bdffile.bdf > bold_bdffile.bdf
*/

#include <stdio.h>
#include <stdlib.h>


char s_hex[16]={ '0','1','2','3','4','5','6','7',
                 '8','9','A','B','C','D','E','F',};


char s_tmp0[255];
char s_tmp1[255];

char *mkbold( char *ptr );
int cphexs(char *ptr1, char *ptr2);
int hexs2int(char *ptr );
char *int2hexs( int i,char *ptr,int len);
int hc2i( int c );
int i2hc( int c );
int mygets( char *ptr ); 


int main( int argc , char *argv[] ){

	int	flg0,flg1;
	char *ptr;

	flg0 = 0;
	flg1 = 0;
 
	ptr = &s_tmp0[0];


	while(( mygets( ptr ) != EOF ) && ( flg1 == 0 )){
		switch( flg0 ){
			case 0:	if( strcmp( ptr , "BITMAP") == 0){

					flg0 =1;
				}
				puts( ptr );
				break;
			case 1:	if( strcmp( ptr , "ENDCHAR") == 0){
					flg0 =0;
					puts( ptr );
				}else{
					if( (ptr = mkbold( ptr )) != 0){
						puts( ptr );
					}else{
						flg1 =1;
					}					
				}
				break;
		}
	}

}


char *mkbold( char *ptr ){

	int len;
	int i,j;
	char *ptr1;

	ptr1= &s_tmp1[0];

	len = cphexs( ptr , ptr1 );	 	
	if( len > 0 ){
		i = hexs2int( ptr1 );
		i = i | (i>>1);
		len = (len + 1) & 0xFFFFFE;
		return( int2hexs( i , ptr1 , len ));
	}else{
		return(0);
	
	}
} 

int cphexs(char *ptr1, char *ptr2){

	char c,d;
	int len;

	len = 0 ; 
	
 	while(1){
		c =(int)( *ptr1++ );

		if(( d = hc2i( (int)(c) ) )  >= 0 ){
			c = (char)( i2hc( (int)(d) ) );
		}else{
			c = 0;
		}

		*ptr2++ = c;

		if( c == 0 ){break;}

		len ++;
	}
	return(len);
}

int hexs2int(char *ptr ){
	int sum;
	int i;
	char c;
	
	i=0;
	sum=0;
	
 	while(1){
		c = *ptr++;
		i = hc2i( (int)( c ));
		if( i < 0 ){break;}
		sum= sum*16 +i;
	}
	return(sum);
}

char *int2hexs( int i,char *ptr,int len){

	int c;
	int j,k;

	*( ptr + len ) = 0;

	 for( j=(len-1);j>=0;j--){
		k = i & 0x0F;  
		c = i2hc(k);
		*(ptr + j)=(char)(c);
		i = i>>4;
	 }

	return( ptr );
}

int hc2i( int c ){
	int d;
	int i;

	c = myupper( c );

	for( i=0;i<=0x0F;i++){
		if( c == (int)( s_hex[i] ) ){
			return( i );
		}
	}

	return( -1 );

}

int i2hc( int h ){

	if(( h >= 0 )&&(h<=0x0f)){
		return( (int)( s_hex[h] ));
	}
	return( -1 );
}

int mygets( char *ptr ){
	
	int c;
	while( (c = getchar()) != EOF ){
		if( c == 0x0D ){ c = getchar();}
		if( c == 0x0A  ){break;} 
		*ptr++= (char)( c );	
	}
	*ptr=0;
	return(c);
}
	 
int myupper( int c ){

	if(( c >= 'a' )&&( c <= 'z' )){
		c = c - 0x20;
	}
	return( c );
}



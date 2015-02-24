/*
* ROM to BDF fontfile (KANJI) / Tricky Versoin
* 1998.10  Tetsuo.Mitsuda
* Compile:
* (X68GCC) : gcc -liocs -o mkbdf16k.x mkbdf16k.c
*  (X68XC) : cc  -y mkbdf16k.c
*
* Usage:
*   mkbdf16k [-t -a -b] > bdfkanji.bdf
*/

#include <stdio.h>
#include <iocslib.h>

#define	KCG_BUF		32

char  tinyflg; /* CR code */

void get_font16( int, unsigned char* );
void scan_code(int startcode, int endcode);
void code_inc( int* );
void print_header(void);


int main(int argc ,char *argv[])
{

	char c;

	int div_a,div_b;

	div_a = div_b = 1;

	tinyflg = 0x0a;

	/* tinyflg_set;'-a -b -t'option is alternative.*/
	
	if ( argc >= 2 ){ 
		c = *argv[1];
		if( (c == '-') || (c == '/')){
			argv[1]++;
			c=*argv[1];
			switch(c){
				case  'a'  : 
				case  'A'  : div_b = 0 ; break;
				case  'b'  : 
				case  'B'  : div_a = 0 ; break;
				case  't'  : 
				case  'T'  : tinyflg = ':' ; break;
				default    : exit(1);
			}
		}
	}

	if( div_a != 0 ){		
		print_header();

		scan_code(0x2121, 0x222e);
		scan_code(0x223a, 0x2241);
		scan_code(0x224a, 0x2250);
		scan_code(0x225c, 0x226a);
		scan_code(0x2272, 0x2279);
		scan_code(0x227e, 0x227e);
		scan_code(0x2330, 0x2339);
		scan_code(0x2341, 0x235a);
		scan_code(0x2361, 0x237a);
		scan_code(0x2421, 0x2473);
		scan_code(0x2521, 0x2576);
		scan_code(0x2621, 0x2638);
		scan_code(0x2641, 0x2658);
		scan_code(0x2721, 0x2741);
		scan_code(0x2751, 0x2771);
		scan_code(0x2821, 0x2840);

	}
	if( div_b != 0 ){		
		scan_code(0x3021, 0x4f53);
		scan_code(0x5021, 0x737e);
		scan_code(0x7421, 0x7424);

		printf("ENDFONT\n");
	}

	exit(0);
}


/* write font data */

void scan_code(int startcode, int endcode)
{
	int i,code;
	char raster[KCG_BUF+1];
	int c;

	for (code = startcode; code<=endcode; code_inc( &code ) ){
		get_font16( code, raster);

			printf( "STARTCHAR %x%c",code,tinyflg);
        	printf( "ENCODING %5d%c",code,tinyflg);
        	printf( "SWIDTH 96 0%c",tinyflg);
        	printf( "DWIDTH 16 0%c",tinyflg);
        	printf( "BBX 16 16 0 -2%c",tinyflg);
           	printf( "BITMAP%c",tinyflg);

		for (i=0; i< KCG_BUF; i+=2){
			c =( (raster[i] & 0xff) << 8 ) + ( raster [i+1] & 0xff);
			printf("%04x%c",c,tinyflg);
		}
		printf( "ENDCHAR%c",tinyflg);
		
	}
}


/* get font data from X68k ROM */

void get_font16( int char_code, unsigned char* raster )
{
	char	temp_buf[KCG_BUF+4];
	int	i;

	FNTGET(8, char_code ,temp_buf);


	for( i=0 ; i<32 ;i++ ){
		*raster++ = temp_buf[i+4];
	}

}


/* code increment */

void code_inc(int *i)
{
	if ( (*i & 0xff) == 0x7e ){
		*i = (*i & 0xff00) + 0x121;
	}else{
		(*i)++;
	}
}


/* print out header */

void print_header(){

	printf("STARTFONT 2.1%c",tinyflg); 
	printf("COMMENT 16x16 kanji font%c",tinyflg); 
	printf("COMMENT from SHARP X680x0 ROMFONT%c",tinyflg); 
	printf("FONT -PEKE-Fixed-Medium-R-Normal--16-150-75-75");
	printf("-C-160-JISX0208.1983-0%c",tinyflg); 
	printf("SIZE 6 78 78%c",tinyflg); 
	printf("FONTBOUNDINGBOX 16 16 0 2%c",tinyflg); 
	printf("STARTPROPERTIES 19%c",tinyflg); 
	printf("FONT_ASCENT 14%c",tinyflg); 
	printf("FONT_DESCENT 2%c",tinyflg); 
	printf("DEFAULT_CHAR 8481%c",tinyflg); 
	printf("COPYRIGHT \"from SHARP X680x0 ROMFONT\"%c",tinyflg); 
	printf("FONTNAME_REGISTRY \"\"%c",tinyflg); 
	printf("FOUNDRY \"PEKE\"%c",tinyflg); 
	printf("FAMILY_NAME \"Fixed\"%c",tinyflg); 
	printf("WEIGHT_NAME \"Medium\"%c",tinyflg); 
	printf("SLANT \"R\"%c",tinyflg); 
	printf("SETWIDTH_NAME \"Normal\"%c",tinyflg); 
	printf("ADD_STYLE_NAME \"\"%c",tinyflg); 
	printf("PIXEL_SIZE 16%c",tinyflg); 
	printf("POINT_SIZE 150%c",tinyflg); 
	printf("RESOLUTION_X 75%c",tinyflg); 
	printf("RESOLUTION_Y 75%c",tinyflg); 
	printf("SPACING \"C\"%c",tinyflg); 
	printf("AVERAGE_WIDTH 160%c",tinyflg); 
	printf("CHARSET_REGISTRY \"JISX0208.1983\"%c",tinyflg); 
	printf("CHARSET_ENCODING \"0\"%c",tinyflg); 
	printf("ENDPROPERTIES%c",tinyflg); 
	printf("CHARS 6877%c",tinyflg); 

}


/*
* ROM to BDF fontfile (ROMAN-KANA)
* 1998.10  Tetsuo.Mitsuda
* Compile:
* (X68GCC) : gcc -liocs -o mkbdf16r.x mkbdf16r.c
*  (X68XC) : cc -y mkbdf16r.c
*
* Usage:
*   mkbdf16r > bdfroman.bdf
*/

#include <stdio.h>
#include <iocslib.h>

#define	KCG_BUF		16


void get_font16( int, unsigned char* );
void scan_code(int startcode, int endcode);
void print_header(void);




void main()
{

	print_header();

	scan_code(0x20, 0x7F);
	scan_code(0xA0, 0xDF);

	printf("ENDFONT\n");

}


/* write font data */

void scan_code(int startcode, int endcode)
{
	int i,code;
	char raster[KCG_BUF+1];
	for (code = startcode; code<=endcode; code++ ){
		get_font16( code, raster);

		printf( "STARTCHAR %x\n",code);
        	printf( "ENCODING %5d\n",code);
        	printf( "SWIDTH 480 0\n");
        	printf( "DWIDTH 8 0\n");
        	printf( "BBX 8 16 0 -2\n");
               	printf( "BITMAP\n");

		for (i=0; i< KCG_BUF; i++){
			printf("%02x\n", (raster[i] & 0xff ));
		}
		printf("ENDCHAR\n");
	}
}


/* get font data from X68k ROM */

void get_font16( int char_code, unsigned char* raster )
{

	char	char_buf[KCG_BUF+2];
	char	temp_buf[KCG_BUF+4];
	int	i;

	FNTGET(8, char_code ,temp_buf);


	for( i=0 ; i<KCG_BUF ;i++ ){
		*raster++ = temp_buf[i+4];
	}

}


/* print out header */

void print_header( void ){

	printf("STARTFONT 2.1\n"); 
	printf("COMMENT 8x16 roman/kana font\n"); 
	printf("COMMENT from SHARP X680x0 ROMFONT\n"); 
	printf("FONT -PEKE-Fixed-Medium-R-Normal--16-150-75-75");
	printf("-C-80-JISX0201.1976-0\n"); 
	printf("SIZE 6 78 78\n"); 
	printf("FONTBOUNDINGBOX 8 16 0 -2\n"); 
	printf("STARTPROPERTIES 19\n"); 
	printf("FONT_ASCENT 14\n"); 
	printf("FONT_DESCENT 2\n"); 
	printf("DEFAULT_CHAR 32\n"); 
	printf("COPYRIGHT \"from SHARP X680x0 ROMFONT\"\n"); 
	printf("FONTNAME_REGISTRY \"\"\n"); 
	printf("FOUNDRY \"PEKE\"\n"); 
	printf("FAMILY_NAME \"Fixed\"\n"); 
	printf("WEIGHT_NAME \"Medium\"\n"); 
	printf("SLANT \"R\"\n"); 
	printf("SETWIDTH_NAME \"Normal\"\n"); 
	printf("ADD_STYLE_NAME \"\"\n"); 
	printf("PIXEL_SIZE 16\n"); 
	printf("POINT_SIZE 150\n"); 
	printf("RESOLUTION_X 75\n"); 
	printf("RESOLUTION_Y 75\n"); 
	printf("SPACING \"C\"\n"); 
	printf("AVERAGE_WIDTH 80\n"); 
	printf("CHARSET_REGISTRY \"JISX0201.1976\"\n"); 
	printf("CHARSET_ENCODING \"0\"\n"); 
	printf("ENDPROPERTIES\n"); 
	printf("CHARS 160\n"); 

}


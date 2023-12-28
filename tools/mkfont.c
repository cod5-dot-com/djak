#include <stdio.h>
#define STB_TRUETYPE_IMPLEMENTATION  // force following include to generate implementation
#include "../stb/stb_truetype.h"
//#include "font.xpm"
#include "font.h"

char ttf_buffer[1<<25];

int jack()
{
	int c = 0;
	int i = 0;
	int v = 0;
	int j, k, m;
   	printf("// ");
	for (c = 32; c < 127; c++) {
		putchar(c);
	}
   	printf("\nclass Font {\n");
   	printf("\tfield Array fnt;\n");
   	printf("\tconstructor Font new() {\n");
   	printf("\t\tlet fnt = Array.new(570);\n");
	for (c = 32; c < 127; c++) {
   		printf("\t\t// %c (%d)\n", c, c);
		m = 0x1;
		for (j = 0; j < 11; j++) {
			for (k = 0; k < 8; k++) {
				if (fnt[c-32][j * 8 + k] == '+') {
					v = v | m;
				}
				m = m << 1;
			}
			if (j != 10 && !(j & 0x1)) {
				continue;
			}
   			printf("\t\tlet fnt[%d] = ", i);
			if (v < 0x8000) {
   				printf("%d;\n", v);
			} else if (v == 0x8000) {
   				printf("%d + 1;\n", 0x7FFF);
			} else {
   				printf("-%d;\n", ((~v) & 0xFFFF) + 1);
			}
			i++;
			v = 0;
			m = 0x1;
		}
	}
   	printf("\t\treturn this;\n");
   	printf("\t}\n");
   	printf("\tmethod Array get(char c) {\n");
   	printf("\t\tvar int i;\n");
   	printf("\t\tlet i = (c - 32) * 6;\n");
   	printf("\t\treturn fnt + i;\n");
   	printf("\t}\n");
   	printf("}\n");
	return 0;
}

int main(int argc, char **argv)
{
   stbtt_fontinfo font;
   unsigned char *bitmap;
   int lw = 0;
   int w,h,i,j,xoff, yoff, iy0,ix0, c = (argc > 1 ? atoi(argv[1]) : 'a'), s = (argc > 2 ? atoi(argv[2]) : 20);

   if (argc <= 2) {
	   return jack();
   }
   fread(ttf_buffer, 1, 1<<25, fopen(argc > 3 ? argv[3] : "c:/windows/fonts/arialbd.ttf", "rb"));

   stbtt_InitFont(&font, ttf_buffer, stbtt_GetFontOffsetForIndex(ttf_buffer,0));
   printf("char *fnt[] = {\n");
   for (c = 32; c < 127; c++) {	
	/*
	w = 6;
	if (c >= '0' && c < '[') {
		w = 7;
	}
	printf("// %c (%d)\n", c, c);
   //	printf("\"........\" \n");
   	for (j=0; j < 11; j++) {
		putchar('"');
		putchar('.');
      		for (i=0; i < w; i++) {
			if (i > 0 || lw > 0)  {
				putchar(font_xpm[4 + j][(i-1) + lw]);
			} else {
				putchar('.');
			}
		}
		if (w == 6) {
			putchar('.');
		}
		putchar('"');
		putchar('\n');
	}
	putchar(',');
	putchar('\n');
	lw += w;
	continue;*/
   	bitmap = stbtt_GetCodepointBitmap(&font, 
			0, stbtt_ScaleForPixelHeight(&font, 12), 
			c, &w, &h, &xoff, &yoff);
	printf("// %c (%d)\n", c, c);
   	stbtt_GetCodepointBitmapBox(&font,
			0, stbtt_ScaleForPixelHeight(&font, 12), 
		       c, &ix0, &iy0, 0, 0);	

	xoff = (8 - w) / 2;	
	yoff = 10 + yoff -2;
	if (yoff + h > 11) {
		yoff = 11 - h;
	}
	printf("// %d %d %d %d\n", xoff, yoff, ix0, iy0);
	for (j = 0; j < yoff; j++) {
		printf("\"        \"\n");
	}

   	for (j=0; j < h; ++j) {
		putchar('"');
		for (i = 0; i < xoff; i++) {
			putchar(' ');
		}
      		for (i=0; i < w; ++i) {
			if (bitmap[j*w+i] > 64) {
				putchar('+');
			} else {
				putchar(' ');
			}
		}
		for (i = 0; i < ((8 - w) - xoff); i++) {
			putchar(' ');
		}
		putchar('"');
      		putchar('\n');
   	}
	for (j = 0; j < (11 - h - yoff); j++) {
		printf("\"        \"\n");
	}
	putchar(',');
	putchar('\n');
   }
	putchar('"');
	putchar('"');
	putchar('}');
	putchar(';');
	putchar('\n');
   return 0;
}

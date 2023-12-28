/*
 *                     jack public domain compiler
 *
 *                      15 may MMXXI PUBLIC DOMAIN
 *           The author disclaims copyright to this source code.
 *
 *
 */


#ifndef JACK_X11_C_H
#define JACK_X11_C_H
#ifndef _WIN32
#ifndef __APPLE__

#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>
#include <X11/keysymdef.h>
#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glext.h>
#include <GL/glu.h>

#ifdef JACK_IMPLEMENTATION
var Screen__need_refresh = -1;
Display *__display = NULL;
XImage *ximage;
int width = 512;
int height = 256;
Visual *visual;
Window window;
Window root;
GC gc;
XVisualInfo *vi;
Colormap cmap;
XSetWindowAttributes swa;
XWindowAttributes gwa;
GLXFBConfig *fbc;
GLuint base;
GLuint tex = 1;
Atom wm_del;
var isfirst = -1;
var is_wait = 0;
var need_update = -1;
GLint att[] = {GLX_RENDER_TYPE, GLX_RGBA_BIT, 
		GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
	       	GLX_DOUBLEBUFFER, True,
		GLX_RED_SIZE, 1,
		GLX_GREEN_SIZE, 1,
		GLX_BLUE_SIZE, 1,
		None};
GLXContext glc;
void init();

var Screen__clear()
{
	var i, j;
	unsigned char *p;
	unsigned char *q;
	init();
	for (i = 0; i < height; i++) {
		p = image32 + (i * width * 4);	
		for (j = 0; j < width; j++) {
			q = p + (j << 2);
			q[0] = 0xFF; //blue
			q[1] = 0xFF; //green
			q[2] = 0xFF; //red
			q[3] = 0xFF; //alpha
		}
	}
	Screen__need_refresh = -1;
	return 0;
}

/*XImage *CreateImage()
{
	image32 = (unsigned char*)malloc(width * height * sizeof(unsigned int));
	//return XCreateImage(display, visual, 
	//		DefaultDepth(display, DefaultScreen(display)),
	//
	return NULL;
}*/


void init() 
{
	int fbcount;
	if (__display != NULL) {
		return;
	}
	__display = XOpenDisplay(NULL);
	root = DefaultRootWindow(__display);
	fbc = glXChooseFBConfig(__display, DefaultScreen(__display), att, &fbcount);
	if (fbc == NULL) {
		printf("\n Failed to get config.\n");
		return;
	}
	//vi = glXChooseVisual(display, 0, att);
	vi = glXGetVisualFromFBConfig(__display, fbc[0]);
	if (vi == NULL) {
		printf("\n No GL visual found.\n");
		return;
	}
	//visual = XDefaultVisual(display, 0);
	cmap = XCreateColormap(__display, root, vi->visual, AllocNone);
	swa.colormap = cmap;
	swa.event_mask = ButtonPressMask|ExposureMask|KeyPressMask
		|KeyReleaseMask;
	window = XCreateWindow(__display, root, 
			0, 0, width, height, 0, vi->depth, InputOutput,
			vi->visual, CWColormap|CWEventMask, &swa);  

	XMapWindow(__display, window);
	XStoreName(__display, window, "JACK Application");

	glc = glXCreateContext(__display, vi, NULL, GL_TRUE);
	glXMakeCurrent(__display, window, glc);
	//glEnable(GL_DEPTH_TEST);

	wm_del = XInternAtom(__display, "WM_DELETE_WINDOW", False);
	XSetWMProtocols(__display, window, &wm_del, 1);
	XMapWindow(__display, window);	
	
	glWindowPos2i(0, 0);
	glViewport(0, 0, width, height);
	glClearColor(1,1,1,1);
	glClearDepth(1);
	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexImage2D(
		GL_TEXTURE_2D,
		0,
		3,
		width,
		height,
		0,
		GL_RGBA,
		GL_UNSIGNED_BYTE,
		image32);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glEnable(GL_TEXTURE_2D);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D, 0);
}

var dump_font(var c);

void deInit()
{
	if (__display != NULL) {
		glXMakeCurrent(__display, None, NULL);
		glXDestroyContext(__display, glc);
		XDestroyWindow(__display, window);
		XCloseDisplay(__display);
		__display = NULL;
	}
}

void display()
{
	//glClearColor(1,0,0,1);
	//glClear(GL_COLOR_BUFFER_BIT);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexImage2D(
		GL_TEXTURE_2D,
		0,
		3,
		width,
		height,
		0,
		GL_RGBA,
		GL_UNSIGNED_BYTE,
		image32);
	glLoadIdentity();
	glBegin(GL_QUADS);
	glColor4f(1, 1, 1, 1);
	glTexCoord2f(0,0); glVertex3f(-1,1, -1);
	glTexCoord2f(1,0); glVertex3f( 1,1, -1);
	glTexCoord2f(1,1); glVertex3f( 1, -1, -1);
	glTexCoord2f(0,1); glVertex3f(-1, -1, -1);
	glTexCoord2f(0,0); glVertex3f(-1,1, -1);
	glColor4f(0, 0, 0, 1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
//	dump_font('A');
}


var dump_font(var c)
{
	FILE *f;
	int x, y, xx, i, l;
	char text[255];
	if (!c) {
		return 0;
	}
	Screen__clear();
	display();
	text[0] = c;
	glDisable(GL_TEXTURE_2D);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, height, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRasterPos2i(0, 11);
//	glBegin(GL_QUADS);
//	glColor4f(0, 0, 0, 1);
//	glEnd();
	glListBase(base);
	glCallLists(1, GL_UNSIGNED_BYTE, text);
	glReadPixels(0, 0, width, height, GL_RGBA, 
			GL_UNSIGNED_BYTE, image32);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	i = (c - 32) * 6;
	f = fopen("Font.jack", "a+w");
	fprintf(f, "\t\t// %c (%d)\n", (int)c, (int)c);
	for (y = 0; y < 11; y++) {
		x = 0;
		l =  (height - y - 1) * width + (x << 4);
		c = 0;
		for (xx = 0; xx < 8; xx++) {
			if (!image32[(l+xx)*4+1]) {
				 c = c | (1 << xx);
			}
		}
		y++;
		l =  (height - y - 1) * width + (x << 4);
		if (y < 11) {
			for (xx = 0; xx < 8; xx++) {
				if (!image32[(l+xx)*4+1]) {
					 c = c | (256 << xx);
				}
			}
		}
		if (c > 32767) {
			if (c == 32768) {
				fprintf(f, "\t\tlet v[%d] = 32767 + 1;\n", i);
			} else {
				fprintf(f, "\t\tlet v[%d] = -%d;\n", i,
					((~(int)c) + 1) & 0x7FFF);
			}
		} else {
			fprintf(f, "\t\tlet v[%d] = %d;\n", i, (int)c);
		}
		i++;
	}
	fclose(f);
	return 0;
}


void make_font()
{
	var c;
	FILE *f;
	XFontStruct *fontInfo;
	Font id;
	unsigned int first,last;
	fontInfo = XLoadQueryFont(__display, "*-24-*");
	id = fontInfo->fid;
	first = fontInfo->min_char_or_byte2;
	last = fontInfo->max_char_or_byte2;
	base = glGenLists(last + 1);
	glXUseXFont(id, first, last-first+1, base+first);
	f = fopen("Font.jack", "a+w");
	fprintf(f, "class Font {\n");
	fprintf(f, "\tfield Array v;\n");
	fprintf(f, "\tconstructor Font new() {\n");
	fprintf(f, "\t\tlet v = Array.new(570);\n");
	fclose(f);
	for (c = 32; c < 127; c++) {
		dump_font(c);
	}
	Screen__clear();
	display();
}

var processEvent()
{
	XEvent ev;
	KeySym key;
	char text[255];
	int r;
	var c;

	XWindowAttributes a;

	XNextEvent(__display, &ev);
	gc = DefaultGC(__display, 0);
	switch (ev.type) {
	case KeyRelease:
		if (!is_wait) {
			Memory__poke(24576, 0);
		}
		return 0;
	case KeyPress:
		c = 0;
		r = XLookupString(&ev.xkey, text, 255, &key, 0);
		if (r == 1 && text[0]) {
			c = text[0];
		}
		switch (key) {
		case XK_Left:
			c = Keyboard__LEFT_ARROW();
			break;
		case XK_Right:
			c = Keyboard__RIGHT_ARROW();
			break;
		case XK_Up:
			c = Keyboard__UP_ARROW();
			break;
		case XK_Down:
			c = Keyboard__DOWN_ARROW();
			break;
		case XK_Return:
			c = Keyboard__NEWLINE();
			break;
		case XK_BackSpace:
			c = Keyboard__BACKSPACE();
			break;
		case XK_Home:
			c = Keyboard__HOME();
			break;
		case XK_Page_Up:
			c = Keyboard__PAGE_UP();
			break;
		case XK_Page_Down:
			c = Keyboard__PAGE_DOWN();
			break;
		case XK_Insert:
			c = Keyboard__INSERT();
			break;
		case XK_Delete:
			c = Keyboard__DELETE();
			break;
		case XK_Escape:
			c = Keyboard__ESC();
			break;
		case XK_F12:
			c = Keyboard__F12();
			break;
		}
		if (key >= XK_F1 && key <= XK_F11) {
			c = (key - XK_F1) + Keyboard__F1();
		}
		if (c) {	
			return c;
		}
		break;
	case Expose:
		XGetWindowAttributes(__display, window, &a);	
		glViewport(0, 0, a.width, a.height);
		glXMakeCurrent(__display, window, glc);
		display();
		//if (!done) {	
		//	make_font();
		//}
		glXSwapBuffers(__display, window);	
		isfirst = 0;	
		break;
	case ButtonPress:
		//printf("Click\n");	
		break;
	case ClientMessage:
		if (ev.xclient.data.l[0] == wm_del) {
			deInit();
			exit(0);
		}
		break;
	}
	return 0;
}

var refresh() 
{
	XEvent ev;
	init();
	screen2rgba(width, height);
	memset(&ev, 0, sizeof(ev));
	ev.type = Expose;
	ev.xexpose.window = window;
	XSendEvent(__display, window, True,ExposureMask, &ev);
	return 0;
}

var Screen__refresh()
{
	Screen__need_refresh = -1;
	return 0;
}

var Screen__processEvents(var iswait)
{
	static var nextk = 0;
	var e, r;

	r = nextk;
	nextk = 0;
	is_wait = iswait;
	init();
	if (Screen__need_refresh) {
		while (XPending(__display)) {
			e = processEvent();
			if (e) {
				if (r || iswait) {
					nextk = e;
				} else {
					r = e;
				}
			}
		}
		refresh();
		while (!XPending(__display)) {
			usleep(1000);
		}
	}
	while (XPending(__display)) {
		e = processEvent();
		if (e) {
			if (r || iswait) {
				nextk = e;
			} else {
				r = e;
			}
		}
	}
	if (!r) {
		if (!iswait && Screen__need_refresh) {
			usleep(1000);
		}
	} else {
		Memory__poke(24576, r);
	}
	Screen__need_refresh = 0;
	return r;
}


#endif // JACK_IMPLEMENTATION

#endif // __APPLE
#endif // _WIN32
#endif // H


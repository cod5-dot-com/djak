/*
 *                     jack public domain compiler
 *
 *                      15 may MMXXI PUBLIC DOMAIN
 *           The author disclaims copyright to this source code.
 *
 *
 */


#ifndef JACK_WIN32_H
#define JACK_WIN32_H
#ifdef _WIN32
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>

#ifdef _WIN64
#else
#endif

#ifdef JACK_IMPLEMENTATION
HDC hDC;
HGLRC hRC;
HWND hWnd = NULL;
MSG msg;
HINSTANCE hInstance = 0;
PAINTSTRUCT ps;
var key = 0;
int width = 512;
int height = 256;
GLuint tex = 1;
var refresh = 0;
COORD coord;
HANDLE output;
var is_wait = 0;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
	glTexCoord2f(0,0); glVertex3f(-1,1, -1);
	glTexCoord2f(1,0); glVertex3f( 1,1, -1);
	glTexCoord2f(1,1); glVertex3f( 1, -1, -1);
	glTexCoord2f(0,1); glVertex3f(-1, -1, -1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	SwapBuffers(hDC);
}

void deInit()
{
	wglMakeCurrent(NULL, NULL);
	ReleaseDC(hWnd, hDC);
	wglDeleteContext(hRC);
	DestroyWindow(hWnd);
	exit(0);
}

LONG WINAPI WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static var waskey = 0;
	RECT r;

	switch(uMsg) {
	case WM_PAINT:
		GetClientRect(hWnd, &r);
		BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		glViewport(0, 0, r.right, r.bottom);
		wglMakeCurrent(hDC, hRC);
		screen2rgba(width, height);
		display();
		return 0;
	case WM_SIZE:
		PostMessage(hWnd, WM_PAINT, 0, 0);
		return 0;
	case WM_KEYUP:
		key = 0;
		if (!is_wait) {
			Memory__poke(24576, 0);
		}
		break;
	case WM_KEYDOWN:
		switch (wParam) {
		case VK_LEFT:
			key = Keyboard__LEFT_ARROW();
			break;
		case VK_RIGHT:
			key = Keyboard__RIGHT_ARROW();
			break;
		case VK_UP:
			key = Keyboard__UP_ARROW();
			break;
		case VK_DOWN:
			key = Keyboard__DOWN_ARROW();
			break;
		case VK_RETURN:
			key = Keyboard__NEWLINE();
			break;
		case VK_BACK:
			key = Keyboard__BACKSPACE();
			break;
		case VK_HOME:
			key = Keyboard__HOME();
			break;
		case VK_PRIOR:
			key = Keyboard__PAGE_UP();
			break;
		case VK_NEXT:
			key = Keyboard__PAGE_DOWN();
			break;
		case VK_INSERT:
			key = Keyboard__INSERT();
			break;
		case VK_DELETE:
			key = Keyboard__DELETE();
			break;
		case VK_ESCAPE:
			key = Keyboard__ESC();
			break;
		}
		if (wParam >= VK_F1 && wParam <= VK_F12) {
			key = (wParam - VK_F1) + Keyboard__F1();
		}
		if (key) {
			waskey = -1;
			return 0;
		}
		waskey = 0;
		break;
	case WM_CHAR:
		key = wParam;
		if (waskey) {
			key = 0;
			waskey = 0;
		}
		return 0;
	case WM_QUIT:
		deInit();
		return 0;
		break;
	case WM_CLOSE:
		deInit();
		return 0;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}


void init()
{	
	int pf;
	WNDCLASSW wc;
	PIXELFORMATDESCRIPTOR pfd;
	RECT r;
	DWORD s;
	if (hWnd) {
		return;
	}
	FreeConsole();
	if (!hInstance) {
		hInstance = GetModuleHandle(NULL);
		wc.style = CS_OWNDC;
		wc.lpfnWndProc = (WNDPROC)WindowProc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = hInstance;
		wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hbrBackground = NULL;
		wc.lpszMenuName = NULL;
		wc.lpszClassName = L"Jack App";
		if (!RegisterClass(&wc)) {
			printf("Cannot register class!!\n");
			return;
		}
	}
	r.top = 0;
	r.left = 0;
	r.bottom = height;
	r.right = width;
	s = WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
	AdjustWindowRect(&r, s, FALSE);
	hWnd = CreateWindowW(L"Jack App", L"Jack application", s,
			CW_USEDEFAULT, CW_USEDEFAULT, 
			r.right - r.left , r.bottom - r.top,
			NULL, NULL, hInstance, NULL);
	if (hWnd == NULL) {
		printf("Cannot Create Window!!\n");
		return;
	}
	GetClientRect(hWnd, &r);
	
	hDC = GetDC(hWnd);
	memset(&pfd, 0, sizeof(pfd));
	pfd.nSize = sizeof(pfd);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;

	pf = ChoosePixelFormat(hDC, &pfd);
	if (pf == 0) {
		printf("Cannot choose pixel format!\n");
		return;
	}

	if (SetPixelFormat(hDC, pf, &pfd) == FALSE) {
		printf("Cannot set pixel format!\n");
		return;
	}

	DescribePixelFormat(hDC, pf, sizeof(PIXELFORMATDESCRIPTOR), &pfd);

	ReleaseDC(hWnd, hDC);
	hDC = GetDC(hWnd);
	hRC = wglCreateContext(hDC);
	wglMakeCurrent(hDC, hRC);

	ShowWindow(hWnd, _nCmdShow);

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
	//glBindTexture(GL_TEXTURE_2D, 0);
	glEnable(GL_TEXTURE_2D);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glViewport(0, 0, width, height);
}

var Screen__refresh() 
{
	if (refresh) return 0;
	refresh = -1;
	init();
	PostMessage(hWnd, WM_PAINT, 0, 0);
	return 0;
}

var Screen__processEvents(var iswait)
{
	static var nextk = 0;
	var k = nextk;
	nextk = 0;
	is_wait = iswait;
	init();
	key = 0;
	if (refresh) {
		while (PeekMessage(&msg, hWnd, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			if (key) { 
				if (k || iswait) {
					nextk = key;
				} else {
					k = key;
				}
				key = 0;
			}
		}
		PostMessage(hWnd, WM_PAINT, 0, 0);
		while (!PeekMessage(&msg, hWnd, 0, 0, PM_NOREMOVE)) {
			Sleep(2);
		}
	}
	while (PeekMessage(&msg, hWnd, 0, 0, PM_REMOVE)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		if (key) {
			if (k || iswait) {
				nextk = key;
			} else {
				k = key;
			}
			key = 0;
		}
	}
	if (!k) {
		if (!iswait && refresh) {
			Sleep(2);
		}
	} else {
		Memory__poke(24576, k);
	}
	refresh = 0;
	return k;
}

#endif // JACK:IMPLEMENTATION

#endif // _WIN32
#endif // H


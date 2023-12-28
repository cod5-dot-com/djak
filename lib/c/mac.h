/*
 *                          Apple MacOS support
 *
 *                      7 may MMXXI PUBLIC DOMAIN
 *           The author disclaims copyright to this source code.
 *
 *  This source code is vastly inspired by that work :
 *  https://github.com:/jimon/osx_app_in_plain_c
 */

#ifndef JACK_MAC_H
#define JACK_MAC_H
#ifdef __APPLE__
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR
         // iOS Simulator
#elif TARGET_OS_IPHONE
        // iOS device
#elif TARGET_OS_MAC
        // Other kinds of Mac OS
#else
#   error "Unknown Apple platform"
#endif

#ifdef __LP64__
#define EncodeNSInteger "q"
#define EncodeNSUInteger "L"
#else
#define EncodeNSInteger "i"
#define EncodeNSUInteger "I"
#endif
#include <stdio.h>
#include <objc/objc.h>
#include <objc/runtime.h>
#include <objc/message.h>
#include <objc/NSObjCRuntime.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <CoreGraphics/CGBase.h>
#include <CoreGraphics/CGGeometry.h>
#include <Carbon/Carbon.h>

#define kVK_Insert 0x72

enum  {   
    	NSEventTypeLeftMouseDown             = 1,
    	NSEventTypeLeftMouseUp               = 2,
    	NSEventTypeRightMouseDown            = 3,
    	NSEventTypeRightMouseUp              = 4,
    	NSEventTypeMouseMoved                = 5,
    	NSEventTypeLeftMouseDragged          = 6,
    	NSEventTypeRightMouseDragged         = 7,
    	NSEventTypeMouseEntered              = 8,
    	NSEventTypeMouseExited               = 9,
    	NSEventTypeKeyDown                   = 10,
    	NSEventTypeKeyUp                     = 11,
    	NSEventTypeFlagsChanged              = 12,
    	NSEventTypeAppKitDefined             = 13,
    	NSEventTypeSystemDefined             = 14,
    	NSEventTypeApplicationDefined        = 15,
    	NSEventTypePeriodic                  = 16,
    	NSEventTypeCursorUpdate              = 17,
    	NSEventTypeScrollWheel               = 22,
    	NSEventTypeTabletPoint               = 23,
    	NSEventTypeTabletProximity           = 24,
    	NSEventTypeOtherMouseDown            = 25,
    	NSEventTypeOtherMouseUp              = 26,
    	NSEventTypeOtherMouseDragged         = 27,
    	NSEventTypeGesture  		     = 29,
    	NSEventTypeMagnify 		     = 30,
    	NSEventTypeSwipe   		     = 31,
    	NSEventTypeRotate  		     = 18,
    	NSEventTypeBeginGesture   	     = 19,
    	NSEventTypeEndGesture 		     = 20,
    	NSEventTypeSmartMagnify		     = 32,
    	NSEventTypeQuickLook 		     = 33,
    	NSEventTypePressure 		     = 34,
    	NSEventTypeDirectTouch 		     = 37,
	NSEventTypeChangeMode 		     = 38
};

enum {
    	NSOpenGLPFAAllRenderers           =   1,
    	NSOpenGLPFATripleBuffer           =   3,
    	NSOpenGLPFADoubleBuffer           =   5,	
    	NSOpenGLPFAAuxBuffers             =   7,	
    	NSOpenGLPFAColorSize              =   8,	
    	NSOpenGLPFAAlphaSize              =  11,	
    	NSOpenGLPFADepthSize              =  12,	
    	NSOpenGLPFAStencilSize            =  13,	
    	NSOpenGLPFAAccumSize              =  14,
    	NSOpenGLPFAMinimumPolicy          =  51,	
    	NSOpenGLPFAMaximumPolicy          =  52,	
    	NSOpenGLPFASampleBuffers          =  55,	
    	NSOpenGLPFASamples                =  56,	
    	NSOpenGLPFAAuxDepthStencil        =  57,	
    	NSOpenGLPFAColorFloat             =  58,	
    	NSOpenGLPFAMultisample            =  59,    
    	NSOpenGLPFASupersample            =  60,    
    	NSOpenGLPFASampleAlpha            =  61,    
    	NSOpenGLPFARendererID             =  70,	
    	NSOpenGLPFANoRecovery             =  72,	
    	NSOpenGLPFAAccelerated            =  73,	
    	NSOpenGLPFAClosestPolicy          =  74,	
    	NSOpenGLPFABackingStore           =  76,	
    	NSOpenGLPFAScreenMask             =  84,	
    	NSOpenGLPFAAllowOfflineRenderers  =  96,  
    	NSOpenGLPFAAcceleratedCompute     =  97,	
    	NSOpenGLPFAOpenGLProfile          =  99,  
    	NSOpenGLPFAVirtualScreenCount     = 128,	
    	NSOpenGLPFAStereo                 =   6,
    	NSOpenGLPFAOffScreen              =  53,
    	NSOpenGLPFAFullScreen             =  54,
    	NSOpenGLPFASingleRenderer         =  71,
    	NSOpenGLPFARobust                 =  75,
    	NSOpenGLPFAMPSafe                 =  78,
    	NSOpenGLPFAWindow                 =  80,
    	NSOpenGLPFAMultiScreen            =  81,
    	NSOpenGLPFACompliant              =  83,
    	NSOpenGLPFAPixelBuffer            =  90,
    	NSOpenGLPFARemotePixelBuffer      =  91,
};


typedef CGPoint NSPoint;
typedef CGRect NSRect;
extern id NSApp;
extern id const NSDefaultRunLoopMode;

#ifdef __arm64__
#define objc_msgSend_stret objc_msgSend
#define objc_msgSend_fpret objc_msgSend
#endif
#define objc_msgSend ((id(*)(id,SEL,...))objc_msgSend)

#ifdef JACK_IMPLEMENTATION

int windowCount = 0;
int width = 512;
int height = 256;
var refresh_ = 0;
var key = 0;
var is_wait = 0;
SEL allocSel = 0;
SEL initSel;
GLuint tex = 1;
id pool;
Class NSAutoreleasePoolClass;
id poolAlloc;
Class NSApplicationClass;
SEL sharedApplicationSel;
SEL setActivationPolicySel;
Class NSObjectClass;
Class AppDelegateClass;
Protocol* NSApplicationDelegateProtocol;
bool resultAddProtoc;
SEL applicationShouldTerminateSel;
bool resultAddMethod;
id dgAlloc;
id dg;
SEL autoreleaseSel;
SEL setDelegateSel;
SEL finishLaunchingSel;
Class NSMenuClass;
id menubarAlloc;
id menubar;
Class NSMenuItemClass;
id appMenuItemAlloc;
id appMenuItem;
SEL addItemSel;
SEL setMainMenuSel;
id appMenuAlloc;
id appMenu;
Class NSProcessInfoClass;
SEL processInfoSel;
id processInfo;
SEL processNameSel;
id appName;
Class NSStringClass;
SEL stringWithUTF8StringSel;
id quitTitlePrefixString;
SEL stringByAppendingStringSel;
id quitTitle;
id quitMenuItemKey;
id quitMenuItemAlloc;
SEL initWithTitleSel;
SEL terminateSel;
id quitMenuItem;
SEL setSubmenuSel;
NSRect rect = {{0, 0}, {512, 256}};
Class NSWindowClass;
id windowAlloc;
SEL initWithContentRectSel;
id window;
SEL setReleasedWhenClosedSel;
Class WindowDelegateClass;
Protocol* NSWindowDelegateProtocol;
SEL windowWillCloseSel;
id wdgAlloc;
id wdg;
SEL contentViewSel;
id contentView;
SEL setWantsBestResolutionOpenGLSurfaceSel;
NSPoint point = {20, 20};
SEL cascadeTopLeftFromPointSel;
id titleString;
SEL setTitleSel;
uint32_t glAttributes[] = { 
	NSOpenGLPFADoubleBuffer,
	NSOpenGLPFAColorSize, 24,
	NSOpenGLPFAAlphaSize, 8,
	0};
Class NSOpenGLPixelFormatClass;
id pixelFormatAlloc;
SEL initWithAttributesSel;
id pixelFormat;
Class NSOpenGLContextClass;
id openGLContextAlloc;
SEL initWithFormatSel;
id openGLContext;
SEL setViewSel;
SEL makeKeyAndOrderFrontSel;
SEL setAcceptsMouseMovedEventsSel;
Class NSColorClass;
id blackColor;
SEL setBackgroundColorSel;
SEL activateIgnoringOtherAppsSel;
Class NSDateClass;
SEL distantPastSel;
SEL nextEventMatchingMaskSel;
SEL frameSel;
SEL typeSel;
SEL buttonNumberSel;
SEL keyCodeSel;
SEL keyWindowSel;
SEL mouseLocationOutsideOfEventStreamSel;
SEL convertRectToBackingSel;
SEL scrollingDeltaXSel;
SEL scrollingDeltaYSel;
SEL hasPreciseScrollingDeltasSel;
SEL modifierFlagsSel;
SEL charactersSel;
SEL UTF8StringSel;
SEL sendEventSel;
SEL updateWindowsSel;
SEL updateSel;
SEL makeCurrentContextSel;
SEL flushBufferSel;
id distantPast;
id event;
NSUInteger eventType;
id currentWindow;
id currentWindowContentView;
NSRect adjustFrame;
NSPoint p;
NSRect r = {0, 0, 0, 0};
NSInteger number;
CGFloat deltaX;
CGFloat deltaY;
BOOL precisionScrolling;
NSUInteger modifiers;
id inputText;
const char * inputTextUTF8;
uint16_t keyCode;
int terminate = 0;

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
}

void deInit()
{
	objc_msgSend(pool, sel_registerName("drain"));
}

NSUInteger applicationShouldTerminate(id self, SEL _sel, id sender)
{
	deInit();
	return 1;
}

void windowWillClose(id self, SEL _sel, id notification)
{
	deInit();
	terminate = -1;
}

void init()
{
	if (allocSel) return;

	allocSel = sel_registerName("alloc");
	initSel = sel_registerName("init");

	NSAutoreleasePoolClass = objc_getClass("NSAutoreleasePool");
	poolAlloc = objc_msgSend((id)NSAutoreleasePoolClass, allocSel);
	pool = objc_msgSend(poolAlloc, initSel);

	NSApplicationClass = objc_getClass("NSApplication");
	sharedApplicationSel = sel_registerName("sharedApplication");
	objc_msgSend((id)NSApplicationClass, sharedApplicationSel);

	setActivationPolicySel = sel_registerName("setActivationPolicy:");
	objc_msgSend(NSApp, setActivationPolicySel, 0);

	NSObjectClass = objc_getClass("NSObject");
	AppDelegateClass = objc_allocateClassPair(
			NSObjectClass, "AppDelegate", 0);
	NSApplicationDelegateProtocol = objc_getProtocol(
			"NSApplicationDelegate");
	resultAddProtoc = class_addProtocol(
			AppDelegateClass, NSApplicationDelegateProtocol);
	applicationShouldTerminateSel = sel_registerName(
			"applicationShouldTerminate:");
	resultAddMethod = class_addMethod(
			AppDelegateClass, applicationShouldTerminateSel, 
			(IMP)applicationShouldTerminate, 
			EncodeNSUInteger "@:@");
	dgAlloc = objc_msgSend((id)AppDelegateClass, allocSel);
	dg = objc_msgSend(dgAlloc, initSel);

	autoreleaseSel = sel_registerName("autorelease");
	objc_msgSend(dg, autoreleaseSel);

	setDelegateSel = sel_registerName("setDelegate:");
	objc_msgSend(NSApp, setDelegateSel, dg);

	finishLaunchingSel = sel_registerName("finishLaunching");
	objc_msgSend(NSApp, finishLaunchingSel);

	NSMenuClass = objc_getClass("NSMenu");
	menubarAlloc = objc_msgSend((id)NSMenuClass, allocSel);
	menubar = objc_msgSend(menubarAlloc, initSel);
	objc_msgSend(menubar, autoreleaseSel);

	NSMenuItemClass = objc_getClass("NSMenuItem");
	appMenuItemAlloc = objc_msgSend((id)NSMenuItemClass, allocSel);
	appMenuItem = objc_msgSend(appMenuItemAlloc, initSel);
	objc_msgSend(appMenuItem, autoreleaseSel);

	addItemSel = sel_registerName("addItem:");
	objc_msgSend(menubar, addItemSel, appMenuItem);

	setMainMenuSel = sel_registerName("setMainMenu:");
	objc_msgSend(NSApp, setMainMenuSel, menubar);

	appMenuAlloc = objc_msgSend((id)NSMenuClass, allocSel);
	appMenu = objc_msgSend(appMenuAlloc, initSel);
	objc_msgSend(appMenu, autoreleaseSel);

	NSProcessInfoClass = objc_getClass("NSProcessInfo");
	processInfoSel = sel_registerName("processInfo");
	processInfo = objc_msgSend((id)NSProcessInfoClass, processInfoSel);
	processNameSel = sel_registerName("processName");
	appName = objc_msgSend(processInfo, processNameSel);

	NSStringClass = objc_getClass("NSString");
	stringWithUTF8StringSel = sel_registerName("stringWithUTF8String:");
	quitTitlePrefixString = objc_msgSend(
			(id)NSStringClass, stringWithUTF8StringSel, "Quit ");
	stringByAppendingStringSel = sel_registerName(
			"stringByAppendingString:");
	quitTitle = objc_msgSend(quitTitlePrefixString, 
			stringByAppendingStringSel, appName);

	quitMenuItemKey = objc_msgSend((id)NSStringClass, 
			stringWithUTF8StringSel, "q");
	quitMenuItemAlloc = objc_msgSend((id)NSMenuItemClass, allocSel);
	initWithTitleSel = sel_registerName(
			"initWithTitle:action:keyEquivalent:");
	terminateSel = sel_registerName("terminate:");
	quitMenuItem = objc_msgSend(quitMenuItemAlloc, 
			initWithTitleSel, quitTitle, 
			terminateSel, quitMenuItemKey);
	objc_msgSend(quitMenuItem, autoreleaseSel);

	objc_msgSend(appMenu, addItemSel, quitMenuItem);

	setSubmenuSel = sel_registerName("setSubmenu:");
	objc_msgSend(appMenuItem, setSubmenuSel, appMenu);

	NSWindowClass = objc_getClass("NSWindow");
	windowAlloc = objc_msgSend((id)NSWindowClass, allocSel);
	initWithContentRectSel = sel_registerName(
			"initWithContentRect:styleMask:backing:defer:");
	window = objc_msgSend(windowAlloc, initWithContentRectSel, 
			rect, 15, 2, NO);
	objc_msgSend(window, autoreleaseSel);

	setReleasedWhenClosedSel = sel_registerName("setReleasedWhenClosed:");
	objc_msgSend(window, setReleasedWhenClosedSel, NO);

	windowCount = 1;

	WindowDelegateClass = objc_allocateClassPair(
			NSObjectClass, "WindowDelegate", 0);
	NSWindowDelegateProtocol = objc_getProtocol("NSWindowDelegate");
	resultAddProtoc = class_addProtocol(
			WindowDelegateClass, NSWindowDelegateProtocol);
	windowWillCloseSel = sel_registerName("windowWillClose:");
	resultAddMethod = class_addMethod(
			WindowDelegateClass, windowWillCloseSel, 
			(IMP)windowWillClose,  "v@:@");
	wdgAlloc = objc_msgSend((id)WindowDelegateClass, allocSel);
	wdg = objc_msgSend(wdgAlloc, initSel);
	objc_msgSend(wdg, autoreleaseSel);

	objc_msgSend(window, setDelegateSel, wdg);

	contentViewSel = sel_registerName("contentView");
	contentView = objc_msgSend(window, contentViewSel);

	setWantsBestResolutionOpenGLSurfaceSel = sel_registerName(
			"setWantsBestResolutionOpenGLSurface:");
	objc_msgSend(contentView, 
			setWantsBestResolutionOpenGLSurfaceSel, YES);
	cascadeTopLeftFromPointSel = sel_registerName(
			"cascadeTopLeftFromPoint:");
	objc_msgSend(window, cascadeTopLeftFromPointSel, point);

	titleString = objc_msgSend((id)NSStringClass, 
			stringWithUTF8StringSel, "JACK Application");
	setTitleSel = sel_registerName("setTitle:");
	objc_msgSend(window, setTitleSel, titleString);

	NSOpenGLPixelFormatClass = objc_getClass("NSOpenGLPixelFormat");
	pixelFormatAlloc = objc_msgSend(
			(id)NSOpenGLPixelFormatClass, allocSel);
	initWithAttributesSel = sel_registerName("initWithAttributes:");
	pixelFormat = objc_msgSend(pixelFormatAlloc, 
			initWithAttributesSel, glAttributes);
	objc_msgSend(pixelFormat, autoreleaseSel);

	NSOpenGLContextClass = objc_getClass("NSOpenGLContext");
	openGLContextAlloc = objc_msgSend((id)NSOpenGLContextClass, allocSel);
	initWithFormatSel = sel_registerName("initWithFormat:shareContext:");
	openGLContext = objc_msgSend(openGLContextAlloc, 
			initWithFormatSel, pixelFormat, nil);
	objc_msgSend(openGLContext, autoreleaseSel);

	setViewSel = sel_registerName("setView:");
	objc_msgSend(openGLContext, setViewSel, contentView);

	makeKeyAndOrderFrontSel = sel_registerName("makeKeyAndOrderFront:");
	objc_msgSend(window, makeKeyAndOrderFrontSel, window);

	setAcceptsMouseMovedEventsSel = sel_registerName(
			"setAcceptsMouseMovedEvents:");
	objc_msgSend(window, setAcceptsMouseMovedEventsSel, YES);

	NSColorClass = objc_getClass("NSColor");
	blackColor = ((id (*)(Class, SEL))objc_msgSend)(
			NSColorClass, sel_registerName("blackColor"));
	setBackgroundColorSel = sel_registerName("setBackgroundColor:");
	objc_msgSend(window, setBackgroundColorSel, blackColor);

	activateIgnoringOtherAppsSel = sel_registerName(
			"activateIgnoringOtherApps:");
	objc_msgSend(NSApp, activateIgnoringOtherAppsSel, YES);


	NSDateClass = objc_getClass("NSDate");
	distantPastSel = sel_registerName("distantPast");
	nextEventMatchingMaskSel = sel_registerName(
			"nextEventMatchingMask:untilDate:inMode:dequeue:");
	frameSel = sel_registerName("frame");
	typeSel = sel_registerName("type");
	buttonNumberSel = sel_registerName("buttonNumber");
	keyCodeSel = sel_registerName("keyCode");
	keyWindowSel = sel_registerName("keyWindow");
	mouseLocationOutsideOfEventStreamSel = sel_registerName(
			"mouseLocationOutsideOfEventStream");
	convertRectToBackingSel = sel_registerName("convertRectToBacking:");
	scrollingDeltaXSel = sel_registerName("scrollingDeltaX");
	scrollingDeltaYSel = sel_registerName("scrollingDeltaY");
	hasPreciseScrollingDeltasSel = sel_registerName(
			"hasPreciseScrollingDeltas");
	modifierFlagsSel = sel_registerName("modifierFlags");
	charactersSel = sel_registerName("characters");
	UTF8StringSel = sel_registerName("UTF8String");
	sendEventSel = sel_registerName("sendEvent:");
	updateWindowsSel = sel_registerName("updateWindows");
	updateSel = sel_registerName("update");
	makeCurrentContextSel = sel_registerName("makeCurrentContext");
	flushBufferSel = sel_registerName("flushBuffer");
	return;
}

void initgl()
{

	objc_msgSend(NSApp, updateWindowsSel);

	objc_msgSend(openGLContext, updateSel);

	objc_msgSend(openGLContext, makeCurrentContextSel);

	rect = ((NSRect(*)(id,SEL))objc_msgSend_stret)(contentView, frameSel);

	rect = ((NSRect(*)(id,SEL,NSRect))objc_msgSend_stret)(
			contentView, convertRectToBackingSel, rect);

	glViewport(0, 0, rect.size.width, rect.size.height);
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
}

var getKey(var k)
{
	var key = 0;
	switch (k) {
	case kVK_LeftArrow:
		key = Keyboard__LEFT_ARROW();
		break;
	case kVK_RightArrow:
		key = Keyboard__RIGHT_ARROW();
		break;
	case kVK_UpArrow:
		key = Keyboard__UP_ARROW();
		break;
	case kVK_DownArrow:
		key = Keyboard__DOWN_ARROW();
		break;
	case kVK_Return:
		key = Keyboard__NEWLINE();
		break;
	case kVK_Delete:
		key = Keyboard__BACKSPACE();
		break;
	case kVK_Home:
		key = Keyboard__HOME();
		break;
	case kVK_PageUp:
		key = Keyboard__PAGE_UP();
		break;
	case kVK_PageDown:
		key = Keyboard__PAGE_DOWN();
		break;
	case kVK_Insert:
		key = Keyboard__INSERT();
		break;
	case kVK_ForwardDelete:
		key = Keyboard__DELETE();
		break;
	case kVK_Escape:
		key = Keyboard__ESC();
		break;
	case kVK_F1:
		key = Keyboard__F1();
		break;
	case kVK_F2:
		key = Keyboard__F2();
		break;
	case kVK_F3:
		key = Keyboard__F3();
		break;
	case kVK_F4:
		key = Keyboard__F4();
		break;
	case kVK_F5:
		key = Keyboard__F5();
		break;
	case kVK_F6:
		key = Keyboard__F6();
		break;
	case kVK_F7:
		key = Keyboard__F7();
		break;
	case kVK_F8:
		key = Keyboard__F8();
		break;
	case kVK_F9:
		key = Keyboard__F9();
		break;
	case kVK_F10:
		key = Keyboard__F10();
		break;
	case kVK_F11:
		key = Keyboard__F11();
		break;
	case kVK_F12:
		key = Keyboard__F12();
		break;
	}

	return key;	
}

int check_event()
{

	distantPast = objc_msgSend((id)NSDateClass, distantPastSel);
	event = objc_msgSend(NSApp, nextEventMatchingMaskSel, 
				NSUIntegerMax, distantPast, 
				NSDefaultRunLoopMode, YES);
	if (!event) return 0;
	eventType = (NSUInteger)objc_msgSend(event, typeSel);

	switch (eventType) {
	case NSEventTypeMouseMoved:
	case NSEventTypeLeftMouseDragged:
	case NSEventTypeRightMouseDragged:
	case NSEventTypeOtherMouseDragged:
		currentWindow = objc_msgSend(NSApp, keyWindowSel);
		currentWindowContentView = objc_msgSend(
				currentWindow, contentViewSel);
		adjustFrame = ((NSRect(*)(id,SEL))objc_msgSend_stret)(
				currentWindowContentView, frameSel);
		p = ((NSPoint(*)(id,SEL))objc_msgSend)(
				currentWindow, 
				mouseLocationOutsideOfEventStreamSel);
		if (p.x < 0) {
			p.x = 0;
		} else if (p.x > adjustFrame.size.width) {
			p.x = adjustFrame.size.width;
		}
		if (p.y < 0) {
			p.y = 0;
		} else if (p.y > adjustFrame.size.height) {
		       	p.y = adjustFrame.size.height;
		}
		r.origin.x = p.x;
		r.origin.y = p.y;
		r.size.width = 0;
		r.size.height = 0;
		r = ((NSRect(*)(id,SEL,NSRect))objc_msgSend_stret)(
				currentWindowContentView, 
				convertRectToBackingSel, r);
		p = r.origin;

		break;
	case NSEventTypeLeftMouseDown:
		break;
	case NSEventTypeLeftMouseUp:
		break;
	case NSEventTypeRightMouseDown:
		break;
	case NSEventTypeRightMouseUp:
		break;
	case NSEventTypeOtherMouseDown:
		number = (NSInteger)objc_msgSend(event, buttonNumberSel);
		break;
	case NSEventTypeOtherMouseUp:
		number = (NSInteger)objc_msgSend(event, buttonNumberSel);
		break;
	case NSEventTypeScrollWheel:
		deltaX = ((CGFloat(*)(id,SEL))objc_msgSend_fpret)(
				event, scrollingDeltaXSel);
		deltaY = ((CGFloat(*)(id,SEL))objc_msgSend_fpret)(
				event, scrollingDeltaYSel);
		precisionScrolling = (BOOL)objc_msgSend(
				event, hasPreciseScrollingDeltasSel);

		if (precisionScrolling) {
			deltaX *= 0.1f; 
			deltaY *= 0.1f;
		}
		break;
	case NSEventTypeFlagsChanged:
		modifiers = (NSUInteger)objc_msgSend(event, modifierFlagsSel);
		break;
	case NSEventTypeKeyDown:
		inputText = objc_msgSend(event, charactersSel);
		inputTextUTF8 = (const char*)objc_msgSend(
				inputText, UTF8StringSel);
		keyCode = (unsigned short)objc_msgSend(event, keyCodeSel);
		key = getKey(keyCode);

		if (!key && inputTextUTF8) {
			key = inputTextUTF8[0]; // FIXME
		}
		break;
	case NSEventTypeKeyUp:
		keyCode = (unsigned short)objc_msgSend(event, keyCodeSel);
		key = 0;
		if (!is_wait) {
			Memory__poke(24576, 0);
		}
		break;
	default:
		break;
	}

	objc_msgSend(NSApp, sendEventSel, event);
	initgl();
	return 1;
}

void update()
{

	objc_msgSend(NSApp, updateWindowsSel);

	objc_msgSend(openGLContext, updateSel);

	objc_msgSend(openGLContext, makeCurrentContextSel);

	rect = ((NSRect(*)(id,SEL))objc_msgSend_stret)(contentView, frameSel);

	rect = ((NSRect(*)(id,SEL,NSRect))objc_msgSend_stret)(
			contentView, convertRectToBackingSel, rect);

	glViewport(0, 0, rect.size.width, rect.size.height);
	screen2rgba(width, height);
	display();
	objc_msgSend(openGLContext, flushBufferSel);
}


var Screen__refresh() 
{
	if (refresh_) return 0;
	refresh_ = -1;
	init();
	return 0;
}

var Screen__processEvents(var iswait)
{
	static var nextk = 0;
	var k = nextk;
	is_wait = iswait;
	nextk = 0;
	init();
	key = 0;
	while (check_event()) {
		if (key) {
			if (k || iswait) {
				nextk = key;
			} else {
				k = key;
			}
			key = 0;
		}
	}
	if (terminate) {
		objc_msgSend(NSApp, terminateSel);
	}
	update();
	if (!k) {
		if (!iswait && refresh_) {
			usleep(1000);
		}
	} else {
		Memory__poke(24576, k);
	}
	refresh_ = 0;
	return k;
}


#endif // JACK_IMPLEMENTATION

#endif // __APPLE__
#endif // H


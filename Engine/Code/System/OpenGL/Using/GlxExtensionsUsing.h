// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:38)

#ifndef SYSTEM_OPENGL_GLX_EXTENSIONS_USING_H
#define SYSTEM_OPENGL_GLX_EXTENSIONS_USING_H

#include "System/SystemDll.h"

#include "GL11ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GlxExtensionsMacro.h"

extern "C"
{
#if defined(SYSTEM_PLATFORM_LINUX) 

	using GLXBool = Bool;

	// GLX 1.0
	using GLXDrawable = XID;
	using GLXPixmap = XID;

#ifdef SYSTEM_PLATFORM_SOLARIS
	using GLXContext = struct __glXContextRec*;
#else // !SYSTEM_PLATFORM_SOLARIS
	using GLXContext = struct __GLXcontextRec*;
#endif // SYSTEM_PLATFORM_SOLARIS

	using GLXVideoDeviceNV = unsigned int;

	// GLX 1.3
	using GLXFBConfig = struct __GLXFBConfigRec*;
	using GLXWindow = XID;
	using GLXPbuffer = XID;
	using GLXFBConfigID = XID;

	struct GLXPbufferClobberEvent
	{
		int event_type;
		int draw_type;
		unsigned long serial;
		GLXBool send_event;
		Display* display;
		GLXDrawable drawable;
		unsigned int buffer_mask;
		unsigned int aux_buffer;
		int x, y;
		int width, height;
		int count;
	};
	union GLXEvent
	{
		GLXPbufferClobberEvent glxpbufferclobber;
		long pad[24];
	};

	// GLX 1.4 
	extern void(*glXGetProcAddress(const GLubyte*))(void);

	// ARB ¿©’π

	// (ARB 02) GLX_ARB_get_proc_address

	extern void(*glXGetProcAddressARB(const GLubyte*))(void);

	// EXT ¿©’π
	// (EXT 047) GLX_EXT_import_context

	using GLXContextID = XID;

	// SGIX¿©’π

	// (SGIX 49) GLX_SGIX_fbconfig

	using GLXFBConfigIDSGIX = XID;
	using GLXFBConfigSGIX = struct __GLXFBConfigRec*;

	// (SGIX 50) GLX_SGIX_pbuffer

	using GLXPbufferSGIX = XID;
	struct GLXBufferClobberEventSGIX
	{
		int type;
		unsigned long serial;
		GLXBool send_event;
		Display* display;
		GLXDrawable drawable;
		int event_type;
		int draw_type;
		unsigned int mask;
		int x, y;
		int width, height;
		int count;
	};

	// (SGIX 307) GLX_SGIX_hyperpipe

	struct GLXHyperpipeNetworkSGIX
	{
		char pipeName[GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX];
		int  networkId;
	};

	struct GLXPipeRectLimits
	{
		char pipeName[GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX];
		int XOrigin;
		int YOrigin;
		int maxHeight;
		int maxWidth;
	};

	struct GLXHyperpipeConfigSGIX
	{
		char pipeName[GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX];
		int channel;
		unsigned int participationType;
		int timeSlice;
	};

	struct GLXPipeRect
	{
		char pipeName[GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX];
		int srcXOrigin;
		int srcYOrigin;
		int srcWidth;
		int srcHeight;
		int destXOrigin;
		int destYOrigin;
		int destWidth;
		int destHeight;
	};

#else // !SYSTEM_PLATFORM_LINUX

	using XID = int;

	using GLXDrawable = XID;
	using GLXPixmap = XID;

	struct __GLXcontextRec
	{

	};

	using GLXContext = __GLXcontextRec*;

	using GLXVideoDeviceNV = unsigned int;

	struct __GLXFBConfigRec
	{

	};

	using GLXFBConfig = __GLXFBConfigRec*;

	using GLXWindow = XID;
	using GLXPbuffer = XID;
	using GLXFBConfigID = XID;

	struct Display
	{

	};

	using GLXBool = bool;
	struct XVisualInfo
	{

	};

	struct Pixmap
	{

	};

	struct Font
	{

	};

	struct Window
	{

	};

	struct GLXPbufferClobberEvent
	{
		int event_type;
		int draw_type;
		unsigned long serial;
		GLXBool send_event;
		Display* display;
		GLXDrawable drawable;
		unsigned int buffer_mask;
		unsigned int aux_buffer;
		int x, y;
		int width, height;
		int count;
	};

	union GLXEvent
	{
		GLXPbufferClobberEvent glxpbufferclobber;
		long pad[24];
	};

	using GLXContextID = XID;

	using GLXFBConfigIDSGIX = XID;
	using GLXFBConfigSGIX = __GLXFBConfigRec*;

	using GLXPbufferSGIX = XID;
	struct GLXBufferClobberEventSGIX
	{
		int type;
		unsigned long serial;
		GLXBool send_event;
		Display* display;
		GLXDrawable drawable;
		int event_type;
		int draw_type;
		unsigned int mask;
		int x, y;
		int width, height;
		int count;
	};

	struct GLXHyperpipeNetworkSGIX
	{
		char pipeName[GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX];
		int  networkId;
	};

	struct GLXPipeRectLimits
	{
		char pipeName[GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX];
		int XOrigin;
		int YOrigin;
		int maxHeight;
		int maxWidth;
	};

	struct GLXHyperpipeConfigSGIX
	{
		char pipeName[GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX];
		int channel;
		unsigned int participationType;
		int timeSlice;
	};

	struct GLXPipeRect
	{
		char pipeName[GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX];
		int srcXOrigin;
		int srcYOrigin;
		int srcWidth;
		int srcHeight;
		int destXOrigin;
		int destYOrigin;
		int destWidth;
		int destHeight;
	};
#endif // SYSTEM_PLATFORM_LINUX
}  // extern "C"

#endif // SYSTEM_OPENGL_GLX_EXTENSIONS_USING_H

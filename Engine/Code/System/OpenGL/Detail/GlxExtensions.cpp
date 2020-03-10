// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:48)

#include "System/SystemExport.h"

#include "GlxExtensions.h"
#include "GLUtility.h" 
#include "GLExtensions.h"
#include "System/Helper/UnusedMacro.h" 
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h" 
#include "System/Helper/Detail/OpenGL/GlxExtensionsMacro.h" 

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26461)
namespace System
{
#if defined(SYSTEM_PLATFORM_LINUX)
	ExistsOpenGLExtensions g_ExistsGlx{ ExistsOpenGLExtensions::Exists };
#else // !SYSTEM_PLATFORM_LINUX
	ExistsOpenGLExtensions g_ExistsGlx{ ExistsOpenGLExtensions::NotExist };
#endif // SYSTEM_PLATFORM_LINUX
}

// GLX 1.0
namespace System
{
	ExistsOpenGLExtensions g_ExistsGlx10{ g_ExistsGlx };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlx10() noexcept
{
	return g_ExistsGlx10;
}

#undef glXQueryExtension
#undef glXQueryVersion
#undef glXGetConfig
#undef glXChooseVisual
#undef glXCreateGLXPixmap
#undef glXDestroyGLXPixmap
#undef glXCreateContext
#undef glXDestroyContext
#undef glXIsDirect
#undef glXCopyContext
#undef glXMakeCurrent
#undef glXGetCurrentContext
#undef glXGetCurrentDrawable
#undef glXWaitGL
#undef glXWaitX
#undef glXSwapBuffers
#undef glXUseXFont

#if defined(SYSTEM_PLATFORM_LINUX)

extern "C"
{
	OPENGL_EXTERN WindowBool glXQueryExtension(Display*, int*, int*);
	OPENGL_EXTERN WindowBool glXQueryVersion(Display*, int*, int*);
	OPENGL_EXTERN int glXGetConfig(Display*, XVisualInfo*, int, int*);
	OPENGL_EXTERN XVisualInfo* glXChooseVisual(Display*, int, int*);
	OPENGL_EXTERN GLXPixmap glXCreateGLXPixmap(Display*, XVisualInfo*, Pixmap);
	OPENGL_EXTERN void glXDestroyGLXPixmap(Display*, GLXPixmap);
	OPENGL_EXTERN GLXContext glXCreateContext(Display*, XVisualInfo*, GLXContext, WindowBool);
	OPENGL_EXTERN void glXDestroyContext(Display*, GLXContext);
	OPENGL_EXTERN WindowBool glXIsDirect(Display*, GLXContext);
	OPENGL_EXTERN void glXCopyContext(Display*, GLXContext, GLXContext, GLuint);
	OPENGL_EXTERN WindowBool glXMakeCurrent(Display*, GLXDrawable, GLXContext);
	OPENGL_EXTERN GLXContext glXGetCurrentContext(void);
	OPENGL_EXTERN GLXDrawable glXGetCurrentDrawable(void);
	OPENGL_EXTERN void glXWaitGL(void);
	OPENGL_EXTERN void glXWaitX(void);
	OPENGL_EXTERN void glXSwapBuffers(Display*, GLXDrawable);
	OPENGL_EXTERN void glXUseXFont(Font, int, int, int);
}  // extern "C"

#else // !SYSTEM_PLATFORM_LINUX

extern "C"
{
	GLXBool glXQueryExtension(Display*, int*, int*)
	{
		return false;
	}

	GLXBool glXQueryVersion(Display*, int*, int*)
	{
		return false;
	}

	int glXGetConfig(Display*, XVisualInfo*, int, int*)
	{
		return 0;
	}

	XVisualInfo* glXChooseVisual(Display*, int, int*)
	{
		return nullptr;
	}

	GLXPixmap glXCreateGLXPixmap(Display*, XVisualInfo*, Pixmap)
	{
		return GLXPixmap{};
	}

	void glXDestroyGLXPixmap(Display*, GLXPixmap)
	{

	}

	GLXContext glXCreateContext(Display*, XVisualInfo*, GLXContext, GLXBool)
	{
		return GLXContext{};
	}

	void glXDestroyContext(Display*, GLXContext)
	{
	}

	GLXBool glXIsDirect(Display*, GLXContext)
	{
		return false;
	}

	void glXCopyContext(Display*, GLXContext, GLXContext, GLuint)
	{
	}

	GLXBool glXMakeCurrent(Display*, GLXDrawable, GLXContext)
	{
		return false;
	}

	GLXContext glXGetCurrentContext(void)
	{
		return GLXContext{};
	}

	GLXDrawable glXGetCurrentDrawable(void)
	{
		return GLXDrawable{};
	}

	void glXWaitGL()
	{
	}

	void glXWaitX()
	{
	}

	void glXSwapBuffers(Display*, GLXDrawable)
	{
	}

	void glXUseXFont(Font, int, int, int)
	{
	}

}  // extern "C"

#endif //  SYSTEM_PLATFORM_LINUX

GLXBool System
	::GlXQueryExtension(Display* display, int* errorBase, int* eventBase) noexcept
{
	SYSTEM_PRE_BODY_A3_RESULT(glXQueryExtension, display, errorBase, eventBase, GLXBool);
}

GLXBool System
	::GlXQueryVersion(Display* display, int* major, int* minor) noexcept
{
	SYSTEM_PRE_BODY_A3_RESULT(glXQueryVersion, display, major, minor, GLXBool);
}

int System
	::GlXGetConfig(Display* display, XVisualInfo* visualInfo, int attribute, int* value) noexcept
{
	SYSTEM_PRE_BODY_A4_RESULT(glXGetConfig, display, visualInfo, attribute, value, int);
}

XVisualInfo* System
	::GlXChooseVisual(Display* display, int screen, int* attributeList) noexcept
{
	SYSTEM_PRE_BODY_A3_RESULT(glXChooseVisual, display, screen, attributeList, XVisualInfo*);
}

GLXPixmap System
	::GlXCreateGLXPixmap(Display* display, XVisualInfo* visualInfo, Pixmap pixmap) noexcept
{
	SYSTEM_PRE_BODY_A3_RESULT(glXCreateGLXPixmap, display, visualInfo, pixmap, GLXPixmap);
}

void System
	::GlXDestroyGLXPixmap(Display* display, GLXPixmap pixmap) noexcept
{
	SYSTEM_PRE_BODY_A2(glXDestroyGLXPixmap, display, pixmap);
}

GLXContext System
	::GlXCreateContext(Display* display, XVisualInfo* visualInfo, GLXContext shareList, GLXBool direct) noexcept
{
	SYSTEM_PRE_BODY_A4_RESULT(glXCreateContext, display, visualInfo, shareList, direct, GLXContext);
}

void System
	::GlXDestroyContext(Display* display, GLXContext context) noexcept
{
	SYSTEM_PRE_BODY_A2(glXDestroyContext, display, context);
}

GLXBool System
	::GlXIsDirect(Display* display, GLXContext context) noexcept
{
	SYSTEM_PRE_BODY_A2_RESULT(glXIsDirect, display, context, GLXBool);
}

void System
	::GlXCopyContext(Display* display, GLXContext srcContext, GLXContext dstContext, GLulong mask) noexcept
{
	SYSTEM_PRE_BODY_A4(glXCopyContext, display, srcContext, dstContext, mask);
}

GLXBool System
	::GlXMakeCurrent(Display* display, GLXDrawable drawable, GLXContext context) noexcept
{
	SYSTEM_PRE_BODY_A3_RESULT(glXMakeCurrent, display, drawable, context, GLXBool);
}

GLXContext System
	::GlXGetCurrentContext() noexcept
{
	SYSTEM_PRE_BODY_A0_RESULT(glXGetCurrentContext, GLXContext);
}

GLXDrawable System
	::GlXGetCurrentDrawable() noexcept
{
	SYSTEM_PRE_BODY_A0_RESULT(glXGetCurrentDrawable, GLXDrawable);
}

void System
	::GlXWaitGL() noexcept
{
	SYSTEM_PRE_BODY_A0(glXWaitGL);
}

void System
	::GlXWaitX() noexcept
{
	SYSTEM_PRE_BODY_A0(glXWaitX);
}

void System
	::GlXSwapBuffers(Display* display, GLXDrawable drawable) noexcept
{
	SYSTEM_PRE_BODY_A2(glXSwapBuffers, display, drawable);
}

void System
	::GlXUseXFont(Font font, int first, int count, int listBase) noexcept
{
	SYSTEM_PRE_BODY_A4(glXUseXFont, font, first, count, listBase);
}

// GLX 1.1

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlx11{ g_ExistsGlx };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlx11() noexcept
{
	return g_ExistsGlx11;
}

#undef glXQueryExtensionsString
#undef glXGetClientString
#undef glXQueryServerString

#if defined(SYSTEM_PLATFORM_LINUX)

extern "C"
{
	OPENGL_EXTERN const char* glXQueryExtensionsString(Display*, int);
	OPENGL_EXTERN const char* glXGetClientString(Display*, int);
	OPENGL_EXTERN const char* glXQueryServerString(Display*, int, int);
}  // extern "C"

#else // !SYSTEM_PLATFORM_LINUX

extern "C"
{
	const char* glXQueryExtensionsString(Display*, int)
	{
		return "";
	}

	const char* glXGetClientString(Display*, int)
	{
		return "";
	}

	const char* glXQueryServerString(Display*, int, int)
	{
		return "";
	}
}  // extern "C"

#endif // __LINUX__

const char* System
	::GlXQueryExtensionsString(Display* display, int screen) noexcept
{
	SYSTEM_PRE_BODY_A2_RESULT(glXQueryExtensionsString, display, screen, const char*);
}

const char* System
	::GlXGetClientString(Display* display, int name) noexcept
{
	SYSTEM_PRE_BODY_A2_RESULT(glXGetClientString, display, name, const char*);
}

const char* System
	::GlXQueryServerString(Display* display, int screen, int name) noexcept
{
	SYSTEM_PRE_BODY_A3_RESULT(glXQueryServerString, display, screen, name, const char*);
}

// GLX 1.2

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlx12{ g_ExistsGlx };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlx12() noexcept
{
	return g_ExistsGlx12;
}

#undef glXGetCurrentDisplay

#if defined(SYSTEM_PLATFORM_LINUX)

extern "C"
{
	OPENGL_EXTERN Display* glXGetCurrentDisplay();
}  // extern "C"

#else // __LINUX__

extern "C"
{
	Display* glXGetCurrentDisplay()
	{
		return nullptr;
	}
}

#endif // SYSTEM_PLATFORM_LINUX

Display* System
	::GlXGetCurrentDisplay() noexcept
{
	SYSTEM_PRE_BODY_A0_RESULT(glXGetCurrentDisplay, Display*);
}

// GLX 1.3

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlx13{ g_ExistsGlx };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlx13() noexcept
{
	return g_ExistsGlx13;
}

#undef glXGetFBConfigs
#undef glXChooseFBConfig
#undef glXGetFBConfigAttrib
#undef glXGetVisualFromFBConfig
#undef glXCreateWindow
#undef glXDestroyWindow
#undef glXCreatePixmap
#undef glXDestroyPixmap
#undef glXCreatePbuffer
#undef glXDestroyPbuffer
#undef glXQueryDrawable
#undef glXCreateNewContext
#undef glXMakeContextCurrent
#undef glXGetCurrentReadDrawable
#undef glXQueryContext
#undef glXSelectEvent
#undef glXGetSelectedEvent

#if defined(SYSTEM_PLATFORM_LINUX)
extern "C"
{
	OPENGL_EXTERN GLXFBConfig* glXGetFBConfigs(Display* display, int screen, int* numElements);
	OPENGL_EXTERN GLXFBConfig* glXChooseFBConfig(Display* display, int screen, const int* attributeList, int* numElements);
	OPENGL_EXTERN int glXGetFBConfigAttrib(Display* display, GLXFBConfig config, int attribute, int* value);
	OPENGL_EXTERN XVisualInfo* glXGetVisualFromFBConfig(Display* display, GLXFBConfig config);
	OPENGL_EXTERN GLXWindow glXCreateWindow(Display* display, GLXFBConfig config, Window window, const int* attributeList);
	OPENGL_EXTERN void glXDestroyWindow(Display* display, GLXWindow window);
	OPENGL_EXTERN GLXPixmap glXCreatePixmap(Display* display, GLXFBConfig config, Pixmap pixmap, const int* attributeList);
	OPENGL_EXTERN void glXDestroyPixmap(Display* display, GLXPixmap pixmap);
	OPENGL_EXTERN GLXPbuffer glXCreatePbuffer(Display* display, GLXFBConfig config, const int* attributeList);
	OPENGL_EXTERN void glXDestroyPbuffer(Display* display, GLXPbuffer buffer);
	OPENGL_EXTERN void glXQueryDrawable(Display* display, GLXDrawable drawable, int attribute, unsigned int* value);
	OPENGL_EXTERN GLXContext glXCreateNewContext(Display* display, GLXFBConfig config, int renderType, GLXContext shareList, GLXBool direct);
	OPENGL_EXTERN GLXBool glXMakeContextCurrent(Display* display, GLXDrawable draw, GLXDrawable read, GLXContext context);
	OPENGL_EXTERN GLXDrawable glXGetCurrentReadDrawable();
	OPENGL_EXTERN int glXQueryContext(Display* display, GLXContext context, int attribute, int* value);
	OPENGL_EXTERN void glXSelectEvent(Display* display, GLXDrawable drawable, unsigned long eventMask);
	OPENGL_EXTERN void glXGetSelectedEvent(Display* display, GLXDrawable drawable, unsigned long* eventMask);

}  // extern "C"

#else // !SYSTEM_PLATFORM_LINUX


extern "C"
{
	GLXFBConfig* glXGetFBConfigs(Display* display, int screen, int* numElements)
	{
		SYSTEM_UNUSED_ARG(display);
		SYSTEM_UNUSED_ARG(screen);
		SYSTEM_UNUSED_ARG(numElements);

		return nullptr;
	}

	GLXFBConfig* glXChooseFBConfig(Display* display, int screen, const int* attributeList, int* numElements)
	{
		SYSTEM_UNUSED_ARG(display);
		SYSTEM_UNUSED_ARG(screen);
		SYSTEM_UNUSED_ARG(attributeList);
		SYSTEM_UNUSED_ARG(numElements);

		return nullptr;
	}

	int glXGetFBConfigAttrib(Display* display, GLXFBConfig config, int attribute, int* value)
	{
		SYSTEM_UNUSED_ARG(display);
		SYSTEM_UNUSED_ARG(config);
		SYSTEM_UNUSED_ARG(attribute);
		SYSTEM_UNUSED_ARG(value);

		return 0;
	}

	XVisualInfo* glXGetVisualFromFBConfig(Display* display, GLXFBConfig config)
	{
		SYSTEM_UNUSED_ARG(display);
		SYSTEM_UNUSED_ARG(config);

		return nullptr;
	}

	GLXWindow glXCreateWindow(Display* display, GLXFBConfig config, Window window, const int* attributeList)
	{
		SYSTEM_UNUSED_ARG(display);
		SYSTEM_UNUSED_ARG(config);
		SYSTEM_UNUSED_ARG(window);
		SYSTEM_UNUSED_ARG(attributeList);

		return GLXWindow();
	}

	void glXDestroyWindow(Display* display, GLXWindow window)
	{
		SYSTEM_UNUSED_ARG(display);
		SYSTEM_UNUSED_ARG(window);
	}

	GLXPixmap glXCreatePixmap(Display* display, GLXFBConfig config, Pixmap pixmap, const int* attributeList)
	{
		SYSTEM_UNUSED_ARG(display);
		SYSTEM_UNUSED_ARG(config);
		SYSTEM_UNUSED_ARG(pixmap);
		SYSTEM_UNUSED_ARG(attributeList);

		return GLXPixmap();
	}

	void glXDestroyPixmap(Display* display, GLXPixmap pixmap)
	{
		SYSTEM_UNUSED_ARG(display);
		SYSTEM_UNUSED_ARG(pixmap);
	}

	GLXPbuffer glXCreatePbuffer(Display* display, GLXFBConfig config, const int* attributeList)
	{
		SYSTEM_UNUSED_ARG(display);
		SYSTEM_UNUSED_ARG(config);
		SYSTEM_UNUSED_ARG(attributeList);

		return GLXPbuffer();
	}

	void glXDestroyPbuffer(Display* display, GLXPbuffer buffer)
	{
		SYSTEM_UNUSED_ARG(display);
		SYSTEM_UNUSED_ARG(buffer);
	}

	void glXQueryDrawable(Display* display, GLXDrawable drawable, int attribute, unsigned int* value)
	{
		SYSTEM_UNUSED_ARG(display);
		SYSTEM_UNUSED_ARG(drawable);
		SYSTEM_UNUSED_ARG(attribute);
		SYSTEM_UNUSED_ARG(value);
	}

	GLXContext glXCreateNewContext(Display* display, GLXFBConfig config, int renderType, GLXContext shareList, GLXBool direct)
	{
		SYSTEM_UNUSED_ARG(display);
		SYSTEM_UNUSED_ARG(config);
		SYSTEM_UNUSED_ARG(renderType);
		SYSTEM_UNUSED_ARG(shareList);
		SYSTEM_UNUSED_ARG(direct);

		return GLXContext();
	}

	GLXBool glXMakeContextCurrent(Display* display, GLXDrawable draw, GLXDrawable read, GLXContext context)
	{
		SYSTEM_UNUSED_ARG(display);
		SYSTEM_UNUSED_ARG(draw);
		SYSTEM_UNUSED_ARG(read);
		SYSTEM_UNUSED_ARG(context);

		return false;
	}

	GLXDrawable glXGetCurrentReadDrawable()
	{
		return GLXDrawable();
	}

	int glXQueryContext(Display* display, GLXContext context, int attribute, int* value)
	{
		SYSTEM_UNUSED_ARG(display);
		SYSTEM_UNUSED_ARG(context);
		SYSTEM_UNUSED_ARG(attribute);
		SYSTEM_UNUSED_ARG(value);

		return 0;
	}

	void glXSelectEvent(Display* display, GLXDrawable drawable, unsigned long eventMask)
	{
		SYSTEM_UNUSED_ARG(display);
		SYSTEM_UNUSED_ARG(drawable);
		SYSTEM_UNUSED_ARG(eventMask);
	}

	void glXGetSelectedEvent(Display* display, GLXDrawable drawable, unsigned long* eventMask)
	{
		SYSTEM_UNUSED_ARG(display);
		SYSTEM_UNUSED_ARG(drawable);
		SYSTEM_UNUSED_ARG(eventMask);
	}

}  // extern "C"
#endif // SYSTEM_PLATFORM_LINUX

GLXFBConfig* System
	::GlXGetFBConfigs(Display* display, int screen, int* numElements) noexcept
{
	SYSTEM_PRE_BODY_A3_RESULT(glXGetFBConfigs, display, screen, numElements, GLXFBConfig*);
}

GLXFBConfig* System
	::GlXChooseFBConfig(Display* display, int screen, const int* attributeList, int* numElements) noexcept
{
	SYSTEM_PRE_BODY_A4_RESULT(glXChooseFBConfig, display, screen, attributeList, numElements, GLXFBConfig*);
}

int System
	::GlXGetFBConfigAttrib(Display* display, GLXFBConfig config, int attribute, int* value) noexcept
{
	SYSTEM_PRE_BODY_A4_RESULT(glXGetFBConfigAttrib, display, config, attribute, value, int);
}

XVisualInfo* System
	::GlXGetVisualFromFBConfig(Display* display, GLXFBConfig config) noexcept
{
	SYSTEM_PRE_BODY_A2_RESULT(glXGetVisualFromFBConfig, display, config, XVisualInfo*);
}

GLXWindow System
	::GlXCreateWindow(Display* display, GLXFBConfig config, Window window, const int* attributeList) noexcept
{
	SYSTEM_PRE_BODY_A4_RESULT(glXCreateWindow, display, config, window, attributeList, GLXWindow);
}

void System
	::GlXDestroyWindow(Display* display, GLXWindow window) noexcept
{
	SYSTEM_PRE_BODY_A2(glXDestroyWindow, display, window);
}

GLXPixmap System
	::GlXCreatePixmap(Display* display, GLXFBConfig config, Pixmap pixmap, const int* attributeList) noexcept
{
	SYSTEM_PRE_BODY_A4_RESULT(glXCreatePixmap, display, config, pixmap, attributeList, GLXPixmap);
}

void System
	::GlXDestroyPixmap(Display* display, GLXPixmap pixmap) noexcept
{
	SYSTEM_PRE_BODY_A2(glXDestroyPixmap, display, pixmap);
}

GLXPbuffer System
	::GlXCreatePbuffer(Display* display, GLXFBConfig config, const int* attributeList) noexcept
{
	SYSTEM_PRE_BODY_A3_RESULT(glXCreatePbuffer, display, config, attributeList, GLXPbuffer);
}

void System
	::GlXDestroyPbuffer(Display* display, GLXPbuffer buffer) noexcept
{
	SYSTEM_PRE_BODY_A2(glXDestroyPbuffer, display, buffer);
}

void System
	::GlXQueryDrawable(Display* display, GLXDrawable drawable, int attribute, unsigned int* value) noexcept
{
	SYSTEM_PRE_BODY_A4(glXQueryDrawable, display, drawable, attribute, value);
}

GLXContext System
	::GlXCreateNewContext(Display* display, GLXFBConfig config, int renderType, GLXContext shareList, GLXBool direct) noexcept
{
	SYSTEM_PRE_BODY_A5_RESULT(glXCreateNewContext, display, config, renderType, shareList, direct, GLXContext);
}

GLXBool System
	::GlXMakeContextCurrent(Display* display, GLXDrawable draw, GLXDrawable read, GLXContext context) noexcept
{
	SYSTEM_PRE_BODY_A4_RESULT(glXMakeContextCurrent, display, draw, read, context, GLXBool);
}

GLXDrawable System
	::GlXGetCurrentReadDrawable() noexcept
{
	SYSTEM_PRE_BODY_A0_RESULT(glXGetCurrentReadDrawable, GLXDrawable);
}

int System
	::GlXQueryContext(Display* display, GLXContext context, int attribute, int* value) noexcept
{
	SYSTEM_PRE_BODY_A4_RESULT(glXQueryContext, display, context, attribute, value, int);
}

void System
	::GlXSelectEvent(Display* display, GLXDrawable drawable, unsigned long eventMask) noexcept
{
	SYSTEM_PRE_BODY_A3(glXSelectEvent, display, drawable, eventMask);
}

void System
	::GlXGetSelectedEvent(Display* display, GLXDrawable drawable, unsigned long* eventMask) noexcept
{
	SYSTEM_PRE_BODY_A3(glXGetSelectedEvent, display, drawable, eventMask);
}

// GLX 1.4

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlx14{ g_ExistsGlx };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlx14() noexcept
{
	return g_ExistsGlx14;
}

// ARB ¿©’π

// (ARB 02) GLX_ARB_get_proc_address

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlxArbGetProcAddress{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlxArbGetProcAddress() noexcept
{
	return g_ExistsGlxArbGetProcAddress;
}

void System
	::InitGlxArbGetProcAddress() noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX)
	if (IsOpenGLSupportsExtension("GLX_ARB_get_proc_address"))
	{
		g_ExistsGlxArbGetProcAddress = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlxArbGetProcAddress = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_LINUX
	g_ExistsGlxArbGetProcAddress = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_LINUX
}

// (ARB 05) GLX_ARB_multisample

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlxArbMultisample{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
::IsExistsGlxArbMultisample() noexcept
{
	return g_ExistsGlxArbMultisample;
}

void System
	::InitGlxArbGetMultisample() noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX)
	if (IsOpenGLSupportsExtension("GLX_ARB_multisample"))
	{
		g_ExistsGlxArbMultisample = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlxArbMultisample = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_LINUX
	g_ExistsGlxArbMultisample = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_LINUX
}

// (ARB 28) GLX_ARB_vertex_buffer_object

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlxArbVertexBufferObject{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlxArbVertexBufferObject() noexcept
{
	return g_ExistsGlxArbVertexBufferObject;
}

void System
	::InitGlxArbVertexBufferObject() noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX)
	if (IsOpenGLSupportsExtension("GLX_ARB_vertex_buffer_object"))
	{
		g_ExistsGlxArbVertexBufferObject = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlxArbVertexBufferObject = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_LINUX
	g_ExistsGlxArbVertexBufferObject = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_LINUX
}

// (ARB 39) GLX_ARB_fbconfig_float

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlxArbFBConfigFloat{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlxArbFBConfigFloat() noexcept
{
	return g_ExistsGlxArbFBConfigFloat;
}

void System
	::InitGlxArbFBConfigFloat() noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX)
	if (IsOpenGLSupportsExtension("GLX_ARB_fbconfig_float"))
	{
		g_ExistsGlxArbFBConfigFloat = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlxArbFBConfigFloat = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_LINUX
	g_ExistsGlxArbFBConfigFloat = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_LINUX
}

// (ARB 46) GLX_ARB_framebuffer_sRGB

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlxArbFramebufferSRGB{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlxArbFramebufferSRGB() noexcept
{
	return g_ExistsGlxArbFramebufferSRGB;
}

void System
	::InitGlxArbFramebufferSRGB() noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX)
	if (IsOpenGLSupportsExtension("GLX_ARB_framebuffer_sRGB"))
	{
		g_ExistsGlxArbFramebufferSRGB = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlxArbFramebufferSRGB = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_LINUX
	g_ExistsGlxArbFramebufferSRGB = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_LINUX
}

// (ARB 56) GLX_ARB_create_context

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlxArbCreateContext{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlxArbCreateContext() noexcept
{
	return g_ExistsGlxArbCreateContext;
}

namespace System
{
	using PgglxCreateContextAttribsARB = GLXContext(*)(Display* dpy, GLXFBConfig config, GLXContext shareContext, GLXBool direct, const int* attribList);
}

namespace System
{
	PgglxCreateContextAttribsARB gglxCreateContextAttribsARB{ nullptr };
}

GLXContext System
	::GlXCreateContextAttribsARB(Display* dpy, GLXFBConfig config, GLXContext shareContext, GLXBool direct, const int* attribList) noexcept
{
	SYSTEM_BODY_A5_RESULT(gglxCreateContextAttribsARB, dpy, config, shareContext, direct, attribList, GLXContext, nullptr);
}

void System
	::InitGlxArbCreateContext() noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX)
	if (IsOpenGLSupportsExtension("GLX_ARB_create_context"))
	{
		g_ExistsGlxArbCreateContext = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglxCreateContextAttribsARB);
	}
	else
	{
		g_ExistsGlxArbCreateContext = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_LINUX
	g_ExistsGlxArbCreateContext = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_LINUX
}

// (ARB 75) GLX_ARB_create_context_profile

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlxArbCreateContextProfile{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlxArbCreateContextProfile() noexcept
{
	return g_ExistsGlxArbCreateContextProfile;
}

void System
	::InitGlxArbCreateContextProfile() noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX)
	if (IsOpenGLSupportsExtension("GLX_ARB_create_context_profile"))
	{
		g_ExistsGlxArbCreateContextProfile = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlxArbCreateContextProfile = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_LINUX
	g_ExistsGlxArbCreateContextProfile = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_LINUX
}

// (ARB 101) GLX_ARB_create_context_robustness

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlxArbCreateContextRobustness{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlxArbCreateContextRobustness() noexcept
{
	return g_ExistsGlxArbCreateContextRobustness;
}

void System
	::InitGlxArbCreateContextRobustness() noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX)
	if (IsOpenGLSupportsExtension("GLX_ARB_create_context_robustness"))
	{
		g_ExistsGlxArbCreateContextRobustness = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlxArbCreateContextRobustness = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_LINUX
	g_ExistsGlxArbCreateContextRobustness = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_LINUX
}

// (ARB 142) GLX_ARB_robustness_application_isolation

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlxArbRobustnessApplicationIsolation{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlxArbRobustnessApplicationIsolation() noexcept
{
	return g_ExistsGlxArbRobustnessApplicationIsolation;
}

void System
	::InitGlxArbRobustnessApplicationIsolation() noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX)
	if (IsOpenGLSupportsExtension("GLX_ARB_robustness_application_isolation"))
	{
		g_ExistsGlxArbRobustnessApplicationIsolation = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlxArbRobustnessApplicationIsolation = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_LINUX
	g_ExistsGlxArbRobustnessApplicationIsolation = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_LINUX
}

// (ARB 142) GLX_ARB_robustness_share_group_isolation

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlxArbRobustnessShareGroupIsolation{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlxArbRobustnessShareGroupIsolation() noexcept
{
	return g_ExistsGlxArbRobustnessShareGroupIsolation;
}

void System
	::InitGlxArbRobustnessShareGroupIsolation() noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX)
	if (IsOpenGLSupportsExtension("GLX_ARB_robustness_share_group_isolation"))
	{
		g_ExistsGlxArbRobustnessShareGroupIsolation = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlxArbRobustnessShareGroupIsolation = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_LINUX
	g_ExistsGlxArbRobustnessShareGroupIsolation = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_LINUX
}

// (ARB 168) GLX_ARB_context_flush_control

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlxArbContextFlushControl{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlxArbContextFlushControl() noexcept
{
	return g_ExistsGlxArbContextFlushControl;
}

void System
	::InitGlxArbContextFlushControl() noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX)
	if (IsOpenGLSupportsExtension("GLX_ARB_context_flush_control"))
	{
		g_ExistsGlxArbContextFlushControl = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlxArbContextFlushControl = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_LINUX
	g_ExistsGlxArbContextFlushControl = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_LINUX
}

// EXT ¿©’π

// (EXT 028) GLX_EXT_visual_info

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlxExtVisualInfo{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlxExtVisualInfo() noexcept
{
	return g_ExistsGlxExtVisualInfo;
}

void System
	::InitGlxExtVisualInfo() noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX)
	if (IsOpenGLSupportsExtension("GLX_EXT_visual_info"))
	{
		g_ExistsGlxExtVisualInfo = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlxExtVisualInfo = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_LINUX
	g_ExistsGlxExtVisualInfo = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_LINUX
}

// (EXT 040) GLX_EXT_swap_control

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlxExtSwapControl{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlxExtSwapControl() noexcept
{
	return g_ExistsGlxExtSwapControl;
}

namespace System
{
	using PgglXSwapIntervalEXT = void(*) (Display* dpy, GLXDrawable drawable, int interval);
}

namespace System
{
	PgglXSwapIntervalEXT gglXSwapIntervalEXT{ nullptr };
}

void System
	::GlXSwapIntervalEXT(Display* dpy, GLXDrawable drawable, int interval) noexcept

{
	SYSTEM_BODY_A3(gglXSwapIntervalEXT, dpy, drawable, interval);
}

void System
	::InitGlxExtSwapControl() noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX)
	if (IsOpenGLSupportsExtension("GLX_EXT_swap_control"))
	{
		g_ExistsGlxExtSwapControl = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglXSwapIntervalEXT);
	}
	else
	{
		g_ExistsGlxExtSwapControl = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_LINUX
	g_ExistsGlxExtSwapControl = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_LINUX
}

// (EXT 044) GLX_EXT_visual_rating

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlxExtVisualRating{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlxExtVisualRating() noexcept
{
	return g_ExistsGlxExtVisualRating;
}

void System
	::InitGlxExtVisualRating() noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX)
	if (IsOpenGLSupportsExtension("GLX_EXT_visual_rating"))
	{
		g_ExistsGlxExtVisualRating = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlxExtVisualRating = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_LINUX
	g_ExistsGlxExtVisualRating = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_LINUX
}

// (EXT 047) GLX_EXT_import_context

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlxExtImportContext{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlxExtImportContext() noexcept
{
	return g_ExistsGlxExtImportContext;
}

namespace System
{
	using PgglXGetCurrentDisplayEXT = Display * (*) (void);
	using PgglXQueryContextInfoEXT = int(*) (Display*, GLXContext, int, int*);
	using PgglXGetContextIDEXT = GLXContextID(*) (const GLXContext);
	using PgglXImportContextEXT = GLXContext(*) (Display*, GLXContextID);
	using PgglXFreeContextEXT = void(*) (Display*, GLXContext);
}

namespace System
{
	PgglXGetCurrentDisplayEXT gglXGetCurrentDisplayEXT{ nullptr };
	PgglXQueryContextInfoEXT gglXQueryContextInfoEXT{ nullptr };
	PgglXGetContextIDEXT gglXGetContextIDEXT{ nullptr };
	PgglXImportContextEXT gglXImportContextEXT{ nullptr };
	PgglXFreeContextEXT gglXFreeContextEXT{ nullptr };
}

Display* System
	::GlXGetCurrentDisplayEXT() noexcept
{
	SYSTEM_BODY_A0_RESULT(gglXGetCurrentDisplayEXT, Display*, nullptr);
}

int System
	::GlXQueryContextInfoEXT(Display* display, GLXContext context, int attribute, int* value) noexcept
{
	SYSTEM_BODY_A4_RESULT(gglXQueryContextInfoEXT, display, context, attribute, value, int, -1);
}

GLXContextID System
	::GlXGetContextIDEXT(const GLXContext context) noexcept
{
	SYSTEM_BODY_A1_RESULT(gglXGetContextIDEXT, context, GLXContextID, -1);
}

GLXContext System
	::GlXImportContextEXT(Display* display, GLXContextID contextID) noexcept
{
	SYSTEM_BODY_A2_RESULT(gglXImportContextEXT, display, contextID, GLXContext, nullptr);
}

void System
	::GlXFreeContextEXT(Display* display, GLXContext context) noexcept
{
	SYSTEM_BODY_A2(gglXFreeContextEXT, display, context);
}

void System
	::InitGlxExtImportContext() noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX)
	if (IsOpenGLSupportsExtension("GLX_EXT_import_context"))
	{
		g_ExistsGlxExtImportContext = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglXGetCurrentDisplayEXT);
		SYSTEM_GET_FUNCTION(gglXQueryContextInfoEXT);
		SYSTEM_GET_FUNCTION(gglXGetContextIDEXT);
		SYSTEM_GET_FUNCTION(gglXImportContextEXT);
		SYSTEM_GET_FUNCTION(gglXFreeContextEXT);
	}
	else
	{
		g_ExistsGlxExtImportContext = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_LINUX
	g_ExistsGlxExtImportContext = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_LINUX
}

// (EXT 120) GLX_EXT_scene_marker

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlxExtSceneMarker{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlxExtSceneMarker() noexcept
{
	return g_ExistsGlxExtSceneMarker;
}

void System
	::InitGlxExtSceneMarker() noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX)
	if (IsOpenGLSupportsExtension("GLX_EXT_scene_marker"))
	{
		g_ExistsGlxExtSceneMarker = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlxExtSceneMarker = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_LINUX
	g_ExistsGlxExtSceneMarker = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_LINUX
}

// (EXT 328) GLX_EXT_fbconfig_packed_float

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlxExtFbconfigPackedFloat{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlxExtFbconfigPackedFloat() noexcept
{
	return g_ExistsGlxExtFbconfigPackedFloat;
}

void System
	::InitGlxExtFbconfigPackedFloat() noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX)
	if (IsOpenGLSupportsExtension("GLX_EXT_fbconfig_packed_float"))
	{
		g_ExistsGlxExtFbconfigPackedFloat = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlxExtFbconfigPackedFloat = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_LINUX
	g_ExistsGlxExtFbconfigPackedFloat = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_LINUX
}

// (EXT 337) GLX_EXT_framebuffer_sRGB

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlxExtFramebufferSRGB{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlxExtFramebufferSRGB() noexcept
{
	return g_ExistsGlxExtFramebufferSRGB;
}

void System
	::InitGlxExtFramebufferSRGB() noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX)
	if (IsOpenGLSupportsExtension("GLX_EXT_framebuffer_sRGB"))
	{
		g_ExistsGlxExtFramebufferSRGB = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlxExtFramebufferSRGB = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_LINUX
	g_ExistsGlxExtFramebufferSRGB = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_LINUX
}

// (EXT 344) GLX_EXT_texture_from_pixmap

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlxExtTextureFromPixmap{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlxExtTextureFromPixmap() noexcept
{
	return g_ExistsGlxExtTextureFromPixmap;
}

namespace System
{
	using PgglXBindTexImageEXT = void(*) (Display* display, GLXDrawable drawable, int buffer, const int* attribList);
	using PgglXReleaseTexImageEXT = void(*) (Display* display, GLXDrawable drawable, int buffer);
}

namespace System
{
	PgglXBindTexImageEXT gglXBindTexImageEXT{ nullptr };
	PgglXReleaseTexImageEXT gglXReleaseTexImageEXT{ nullptr };
}

void System
	::GlXBindTexImageEXT(Display* display, GLXDrawable drawable, int buffer, const int* attribList) noexcept
{
	SYSTEM_BODY_A4(gglXBindTexImageEXT, display, drawable, buffer, attribList);
}

void System
	::GlXReleaseTexImageEXT(Display* display, GLXDrawable drawable, int buffer) noexcept
{
	SYSTEM_BODY_A3(gglXReleaseTexImageEXT, display, drawable, buffer);
}

void System
	::InitGlxExtTextureFromPixmap() noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX)
	if (IsOpenGLSupportsExtension("GLX_EXT_texture_from_pixmap"))
	{
		g_ExistsGlxExtTextureFromPixmap = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglXBindTexImageEXT);
		SYSTEM_GET_FUNCTION(gglXReleaseTexImageEXT);
	}
	else
	{
		g_ExistsGlxExtTextureFromPixmap = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_LINUX
	g_ExistsGlxExtTextureFromPixmap = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_LINUX
}

// (EXT 399) GLX_EXT_create_context_es2_profile

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlxExtCreateContextEs2Profile{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlxExtCreateContextEs2Profile() noexcept
{
	return g_ExistsGlxExtCreateContextEs2Profile;
}

void System
	::InitGlxExtCreateContextEs2Profile() noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX)
	if (IsOpenGLSupportsExtension("GLX_EXT_create_context_es2_profile"))
	{
		g_ExistsGlxExtCreateContextEs2Profile = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlxExtCreateContextEs2Profile = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_LINUX
	g_ExistsGlxExtCreateContextEs2Profile = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_LINUX
}

// (EXT 399) GLX_EXT_create_context_es_profile

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlxExtCreateContextEsProfile{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlxExtCreateContextEsProfile() noexcept
{
	return g_ExistsGlxExtCreateContextEsProfile;
}

void System
	::InitGlxExtCreateContextEsProfile() noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX)
	if (IsOpenGLSupportsExtension("GLX_EXT_create_context_es_profile"))
	{
		g_ExistsGlxExtCreateContextEsProfile = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlxExtCreateContextEsProfile = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_LINUX
	g_ExistsGlxExtCreateContextEsProfile = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_LINUX
}

// (EXT 414) GLX_EXT_swap_control_tear

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlxExtSwapControlTear{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlxExtSwapControlTear() noexcept
{
	return g_ExistsGlxExtSwapControlTear;
}

void System
	::InitGlxExtSwapControlTear() noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX)
	if (IsOpenGLSupportsExtension("GLX_EXT_swap_control_tear"))
	{
		g_ExistsGlxExtSwapControlTear = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlxExtSwapControlTear = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_LINUX
	g_ExistsGlxExtSwapControlTear = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_LINUX
}

// (EXT 427) GLX_EXT_buffer_age

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlxExtBufferAge{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlxExtBufferAge() noexcept
{
	return g_ExistsGlxExtBufferAge;
}

void System
	::InitGlxExtBufferAge() noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX)
	if (IsOpenGLSupportsExtension("GLX_EXT_buffer_age"))
	{
		g_ExistsGlxExtBufferAge = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlxExtBufferAge = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_LINUX
	g_ExistsGlxExtBufferAge = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_LINUX
}

// (EXT 452) GLX_EXT_stereo_tree

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlxExtStereoTree{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlxExtStereoTree() noexcept
{
	return g_ExistsGlxExtStereoTree;
}

void System
	::InitGlxExtStereoTree() noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX)
	if (IsOpenGLSupportsExtension("GLX_EXT_stereo_tree"))
	{
		g_ExistsGlxExtStereoTree = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlxExtStereoTree = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_LINUX
	g_ExistsGlxExtStereoTree = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_LINUX
}

// SGIX¿©’π

// (ARB 49) GLX_SGIX_fbconfig

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlxSgixFBConfig{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlxSgixFBConfig() noexcept
{
	return g_ExistsGlxSgixFBConfig;
}

namespace System
{
	using PgglXGetFBConfigAttribSGIX = int(*) (Display*, GLXFBConfigSGIX, int, int*);
	using PgglXChooseFBConfigSGIX = GLXFBConfigSGIX * (*) (Display*, int, int*, int*);
	using PgglXCreateGLXPixmapWithConfigSGIX = GLXPixmap(*) (Display*, GLXFBConfigSGIX, Pixmap);
	using PgglXCreateContextWithConfigSGIX = GLXContext(*) (Display*, GLXFBConfigSGIX, int, GLXContext, GLXBool);
	using PgglXGetVisualFromFBConfigSGIX = XVisualInfo * (*) (Display*, GLXFBConfigSGIX);
	using PgglXGetFBConfigFromVisualSGIX = GLXFBConfigSGIX(*) (Display*, XVisualInfo*);
}

namespace System
{
	PgglXGetFBConfigAttribSGIX gglXGetFBConfigAttribSGIX{ nullptr };
	PgglXChooseFBConfigSGIX gglXChooseFBConfigSGIX{ nullptr };
	PgglXCreateGLXPixmapWithConfigSGIX gglXCreateGLXPixmapWithConfigSGIX{ nullptr };
	PgglXCreateContextWithConfigSGIX gglXCreateContextWithConfigSGIX{ nullptr };
	PgglXGetVisualFromFBConfigSGIX gglXGetVisualFromFBConfigSGIX{ nullptr };
	PgglXGetFBConfigFromVisualSGIX gglXGetFBConfigFromVisualSGIX{ nullptr };
}

int System
	::GlXGetFBConfigAttribSGIX(Display* display, GLXFBConfigSGIX config, int attribute, int* value) noexcept
{
	SYSTEM_BODY_A4_RESULT(gglXGetFBConfigAttribSGIX, display, config, attribute, value, int, -1);
}

GLXFBConfigSGIX* System
	::GlXChooseFBConfigSGIX(Display* display, int screen, int* attributeList, int* numElements) noexcept
{
	SYSTEM_BODY_A4_RESULT(gglXChooseFBConfigSGIX, display, screen, attributeList, numElements, GLXFBConfigSGIX*, nullptr);
}

GLXPixmap System
	::GlXCreateGLXPixmapWithConfigSGIX(Display* display, GLXFBConfigSGIX config, Pixmap pixmap) noexcept
{
	SYSTEM_BODY_A3_RESULT(gglXCreateGLXPixmapWithConfigSGIX, display, config, pixmap, GLXPixmap, -1);
}

GLXContext System
	::GlXCreateContextWithConfigSGIX(Display* display, GLXFBConfigSGIX config, int renderType, GLXContext shareList, GLXBool direct) noexcept
{
	SYSTEM_BODY_A5_RESULT(gglXCreateContextWithConfigSGIX, display, config, renderType, shareList, direct, GLXContext, nullptr);
}

XVisualInfo* System
	::GlXGetVisualFromFBConfigSGIX(Display* display, GLXFBConfigSGIX config) noexcept
{
	SYSTEM_BODY_A2_RESULT(gglXGetVisualFromFBConfigSGIX, display, config, XVisualInfo*, nullptr);
}

GLXFBConfigSGIX System
	::GlXGetFBConfigFromVisualSGIX(Display* display, XVisualInfo* visualInfo) noexcept
{
	SYSTEM_BODY_A2_RESULT(gglXGetFBConfigFromVisualSGIX, display, visualInfo, GLXFBConfigSGIX, nullptr);
}

void System
	::InitGlxSgixFBConfig() noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX)

	if (IsOpenGLSupportsExtension("GLX_SGIX_fbconfig"))
	{
		g_ExistsGlxSgixFBConfig = ExistsOpenGLExtensions::Exists;
		SYSTEM_GET_FUNCTION(gglXGetFBConfigAttribSGIX);
		SYSTEM_GET_FUNCTION(gglXChooseFBConfigSGIX);
		SYSTEM_GET_FUNCTION(gglXCreateGLXPixmapWithConfigSGIX);
		SYSTEM_GET_FUNCTION(gglXCreateContextWithConfigSGIX);
		SYSTEM_GET_FUNCTION(gglXGetVisualFromFBConfigSGIX);
		SYSTEM_GET_FUNCTION(gglXGetFBConfigFromVisualSGIX);
	}
	else
	{
		g_ExistsGlxSgixFBConfig = ExistsOpenGLExtensions::NotExist;
	}

#else // !SYSTEM_PLATFORM_LINUX

	g_ExistsGlxSgixFBConfig = ExistsOpenGLExtensions::NotExist;

#endif // SYSTEM_PLATFORM_LINUX
}

// (ARB 50) GLX_SGIX_pbuffer

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlxSgixPBuffer{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlxSgixPBuffer() noexcept
{
	return g_ExistsGlxSgixPBuffer;
}

namespace System
{
	using PgglXCreateGLXPbufferSGIX = GLXPbufferSGIX(*) (Display*, GLXFBConfigSGIX, unsigned int, unsigned int, int*);
	using PgglXDestroyGLXPbufferSGIX = void(*) (Display*, GLXPbufferSGIX);
	using PgglXQueryGLXPbufferSGIX = int(*) (Display*, GLXPbufferSGIX, int, unsigned int*);
	using PgglXSelectEventSGIX = void(*) (Display*, GLXDrawable, unsigned long);
	using PgglXGetSelectedEventSGIX = void(*) (Display*, GLXDrawable, unsigned long*);
}

namespace System
{
	PgglXCreateGLXPbufferSGIX gglXCreateGLXPbufferSGIX{ nullptr };
	PgglXDestroyGLXPbufferSGIX gglXDestroyGLXPbufferSGIX{ nullptr };
	PgglXQueryGLXPbufferSGIX gglXQueryGLXPbufferSGIX{ nullptr };
	PgglXSelectEventSGIX gglXSelectEventSGIX{ nullptr };
	PgglXGetSelectedEventSGIX gglXGetSelectedEventSGIX{ nullptr };
}

GLXPbufferSGIX System
	::GlXCreateGLXPbufferSGIX(Display* display, GLXFBConfigSGIX config, unsigned int width, unsigned int height, int* attributeList) noexcept
{
	SYSTEM_BODY_A5_RESULT(gglXCreateGLXPbufferSGIX, display, config, width, height, attributeList, GLXPbufferSGIX, -1);
}

void System
	::GlXDestroyGLXPbufferSGIX(Display* display, GLXPbufferSGIX buffer) noexcept
{
	SYSTEM_BODY_A2(gglXDestroyGLXPbufferSGIX, display, buffer);
}

int System
	::GlXQueryGLXPbufferSGIX(Display* display, GLXPbufferSGIX buffer, int attribute, unsigned int* value) noexcept
{
	SYSTEM_BODY_A4_RESULT(gglXQueryGLXPbufferSGIX, display, buffer, attribute, value, int, -1);
}

void System
	::GlXSelectEventSGIX(Display* display, GLXDrawable drawable, unsigned long mask) noexcept
{
	SYSTEM_BODY_A3(gglXSelectEventSGIX, display, drawable, mask);
}

void System
	::GlXGetSelectedEventSGIX(Display* display, GLXDrawable drawable, unsigned long* mask) noexcept
{
	SYSTEM_BODY_A3(gglXGetSelectedEventSGIX, display, drawable, mask);
}

void System
	::InitGlxSgixPBuffer() noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX)
	if (IsOpenGLSupportsExtension("GLX_SGIX_pbuffer"))
	{
		g_ExistsGlxSgixPBuffer = ExistsOpenGLExtensions::Exists;
		SYSTEM_GET_FUNCTION(gglXCreateGLXPbufferSGIX);
		SYSTEM_GET_FUNCTION(gglXDestroyGLXPbufferSGIX);
		SYSTEM_GET_FUNCTION(gglXQueryGLXPbufferSGIX);
		SYSTEM_GET_FUNCTION(gglXSelectEventSGIX);
		SYSTEM_GET_FUNCTION(gglXGetSelectedEventSGIX);
	}
	else
	{
		g_ExistsGlxSgixPBuffer = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_LINUX
	g_ExistsGlxSgixPBuffer = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_LINUX
}

// (SGIX 83)  GLX_SGIX_video_resize

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlxSgixVideoResize{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlxSgixVideoResize() noexcept
{
	return g_ExistsGlxSgixVideoResize;
}

namespace System
{
	using PgglxBindChannelToWindowSGIX = int(*) (Display* display, int screen, int channel, Window window);
	using PgglxChannelRectSGIX = int(*) (Display* display, int screen, int channel, int x, int y, int w, int h);
	using PgglxChannelRectSyncSGIX = int(*)(Display* display, int screen, int channel, GLenum synctype);
	using PgglxQueryChannelDeltasSGIX = int(*) (Display* display, int screen, int channel, int* x, int* y, int* w, int* h);
	using PgglxQueryChannelRectSGIX = int(*) (Display* display, int screen, int channel, int* dx, int* dy, int* dw, int* dh);
}

namespace System
{
	PgglxBindChannelToWindowSGIX gglxBindChannelToWindowSGIX{ nullptr };
	PgglxChannelRectSGIX gglxChannelRectSGIX{ nullptr };
	PgglxChannelRectSyncSGIX gglxChannelRectSyncSGIX{ nullptr };
	PgglxQueryChannelDeltasSGIX gglxQueryChannelDeltasSGIX{ nullptr };
	PgglxQueryChannelRectSGIX gglxQueryChannelRectSGIX{ nullptr };
}

int System
	::GlXBindChannelToWindowSGIX(Display* display, int screen, int channel, Window window) noexcept
{
	SYSTEM_BODY_A4_RESULT(gglxBindChannelToWindowSGIX, display, screen, channel, window, int, -1);
}

int System
	::GlXChannelRectSGIX(Display* display, int screen, int channel, int x, int y, int w, int h) noexcept
{
	SYSTEM_BODY_A7_RESULT(gglxChannelRectSGIX, display, screen, channel, x, y, w, h, int, -1);
}

int System
	::GlXChannelRectSyncSGIX(Display* display, int screen, int channel, GLenum synctype) noexcept
{
	SYSTEM_BODY_A4_RESULT(gglxChannelRectSyncSGIX, display, screen, channel, synctype, int, -1);
}

int System
	::GlXQueryChannelDeltasSGIX(Display* display, int screen, int channel, int* x, int* y, int* w, int* h) noexcept
{
	SYSTEM_BODY_A7_RESULT(gglxQueryChannelDeltasSGIX, display, screen, channel, x, y, w, h, int, -1);
}

int System
	::GlXQueryChannelRectSGIX(Display* display, int screen, int channel, int* dx, int* dy, int* dw, int* dh) noexcept
{
	SYSTEM_BODY_A7_RESULT(gglxQueryChannelRectSGIX, display, screen, channel, dx, dy, dw, dh, int, -1);
}

void System
	::InitGlxSgixVideoResize() noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX)
	if (IsOpenGLSupportsExtension("GLX_SGIX_video_resize"))
	{
		g_ExistsGlxSgixVideoResize = ExistsOpenGLExtensions::Exists;
		SYSTEM_GET_FUNCTION(gglxBindChannelToWindowSGIX);
		SYSTEM_GET_FUNCTION(gglxChannelRectSGIX);
		SYSTEM_GET_FUNCTION(gglxChannelRectSyncSGIX);
		SYSTEM_GET_FUNCTION(gglxQueryChannelDeltasSGIX);
		SYSTEM_GET_FUNCTION(gglxQueryChannelRectSGIX);
	}
	else
	{
		g_ExistsGlxSgixVideoResize = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_LINUX
	g_ExistsGlxSgixVideoResize = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_LINUX
}

// (SGIX 91) GLX_SGIX_swap_group

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlxSgixSwapGroup{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlxSgixSwapGroup() noexcept
{
	return g_ExistsGlxSgixSwapGroup;
}

namespace System
{
	using PgglXJoinSwapGroupSGIX = void(*) (Display* dpy, GLXDrawable drawable, GLXDrawable member);
}

namespace System
{
	PgglXJoinSwapGroupSGIX gglXJoinSwapGroupSGIX{ nullptr };
}

void System
	::GlXJoinSwapGroupSGIX(Display* dpy, GLXDrawable drawable, GLXDrawable member) noexcept
{
	SYSTEM_BODY_A3(gglXJoinSwapGroupSGIX, dpy, drawable, member);
}

void System
	::InitGlxSgixSwapGroup() noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX)
	if (IsOpenGLSupportsExtension("GLX_SGIX_swap_group"))
	{
		g_ExistsGlxSgixSwapGroup = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglXJoinSwapGroupSGIX);
	}
	else
	{
		g_ExistsGlxSgixSwapGroup = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_LINUX
	g_ExistsGlxSgixSwapGroup = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_LINUX
}

// (SGIX 92) GLX_SGIX_swap_barrier

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlxSgixSwapBarrier{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlxSgixSwapBarrier() noexcept
{
	return g_ExistsGlxSgixSwapBarrier;
}

namespace System
{
	using PgglXBindSwapBarrierSGIX = void(*) (Display*  dpy, GLXDrawable drawable, int barrier);
	using PgglXQueryMaxSwapBarriersSGIX = GLXBool(*) (Display* dpy, int screen, int* max);
}

namespace System
{
	PgglXBindSwapBarrierSGIX gglXBindSwapBarrierSGIX{ nullptr };
	PgglXQueryMaxSwapBarriersSGIX gglXQueryMaxSwapBarriersSGIX{ nullptr };
}

void System
	::GlXBindSwapBarrierSGIX(Display*  dpy, GLXDrawable drawable, int barrier) noexcept
{
	SYSTEM_BODY_A3(gglXBindSwapBarrierSGIX, dpy, drawable, barrier);
}

GLXBool System
	::GlXQueryMaxSwapBarriersSGIX(Display* dpy, int screen, int* max) noexcept
{
	SYSTEM_BODY_A3_RESULT(gglXQueryMaxSwapBarriersSGIX, dpy, screen, max, GLXBool, false);
}

void System
	::InitGlxSgixSwapBarrier() noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX)
	if (IsOpenGLSupportsExtension("GLX_SGIX_swap_barrier"))
	{
		g_ExistsGlxSgixSwapBarrier = ExistsOpenGLExtensions::Exists;
		SYSTEM_GET_FUNCTION(gglXBindSwapBarrierSGIX);
		SYSTEM_GET_FUNCTION(gglXQueryMaxSwapBarriersSGIX);
	}
	else
	{
		g_ExistsGlxSgixSwapBarrier = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_LINUX
	g_ExistsGlxSgixSwapBarrier = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_LINUX
}

// (SGIX 234) GLX_SGIX_visual_select_group

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlxSgixVisualSelectGroup{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlxSgixVisualSelectGroup() noexcept
{
	return g_ExistsGlxSgixVisualSelectGroup;
}

void System
	::InitGlxSgixVisualSelectGroup() noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX)
	if (IsOpenGLSupportsExtension("GLX_SGIX_visual_select_group"))
	{
		g_ExistsGlxSgixVisualSelectGroup = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlxSgixVisualSelectGroup = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_LINUX
	g_ExistsGlxSgixVisualSelectGroup = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_LINUX
}

// (SGIX 307) GLX_SGIX_hyperpipe

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlxSgixHyperpipe{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlxSgixHyperpipe() noexcept
{
	return g_ExistsGlxSgixHyperpipe;
}

namespace System
{
	using PgglXBindHyperpipeSGIX = int(*) (Display* dpy, int hpID);
	using PgglXDestroyHyperpipeConfigSGIX = int(*) (Display* dpy, int hpID);
	using PgglXHyperpipeAttribSGIX = int(*) (Display* dpy, int timeSlice, int attrib, int size, void* attribList);
	using PgglXHyperpipeConfigSGIX = int(*) (Display* dpy, int networkId, int npipes, GLXHyperpipeConfigSGIX* cfg, int* hpID);
	using PgglXQueryHyperpipeAttribSGIX = int(*) (Display* dpy, int timeSlice, int attrib, int size, void* returnAttribList);
	using PgglXQueryHyperpipeBestAttribSGIX = int(*)(Display* dpy, int timeSlice, int attrib, int size, void* attribList, void* returnAttribList);
	using PgglXQueryHyperpipeConfigSGIX = GLXHyperpipeConfigSGIX * (*) (Display* dpy, int hpID, int* npipes);
	using PgglXQueryHyperpipeNetworkSGIX = GLXHyperpipeNetworkSGIX * (*) (Display* dpy, int* npipes);
}

namespace System
{
	PgglXBindHyperpipeSGIX gglXBindHyperpipeSGIX{ nullptr };
	PgglXDestroyHyperpipeConfigSGIX gglXDestroyHyperpipeConfigSGIX{ nullptr };
	PgglXHyperpipeAttribSGIX gglXHyperpipeAttribSGIX{ nullptr };
	PgglXHyperpipeConfigSGIX gglXHyperpipeConfigSGIX{ nullptr };
	PgglXQueryHyperpipeAttribSGIX gglXQueryHyperpipeAttribSGIX{ nullptr };
	PgglXQueryHyperpipeBestAttribSGIX gglXQueryHyperpipeBestAttribSGIX{ nullptr };
	PgglXQueryHyperpipeConfigSGIX gglXQueryHyperpipeConfigSGIX{ nullptr };
	PgglXQueryHyperpipeNetworkSGIX gglXQueryHyperpipeNetworkSGIX{ nullptr };
}

int System
	::GlXBindHyperpipeSGIX(Display* dpy, int hpID) noexcept
{
	SYSTEM_BODY_A2_RESULT(gglXBindHyperpipeSGIX, dpy, hpID, int, 0);
}

int System
	::GlXDestroyHyperpipeConfigSGIX(Display* dpy, int hpID) noexcept
{
	SYSTEM_BODY_A2_RESULT(gglXDestroyHyperpipeConfigSGIX, dpy, hpID, int, 0);
}

int System
	::GlXHyperpipeAttribSGIX(Display* dpy, int timeSlice, int attrib, int size, void* attribList) noexcept
{
	SYSTEM_BODY_A5_RESULT(gglXHyperpipeAttribSGIX, dpy, timeSlice, attrib, size, attribList, int, -1);
}

int System
	::GlXHyperpipeConfigSGIX(Display* dpy, int networkId, int npipes, GLXHyperpipeConfigSGIX* cfg, int* hpID) noexcept
{
	SYSTEM_BODY_A5_RESULT(gglXHyperpipeConfigSGIX, dpy, networkId, npipes, cfg, hpID, int, -1);
}

int System
	::GlXQueryHyperpipeAttribSGIX(Display* dpy, int timeSlice, int attrib, int size, void* returnAttribList) noexcept
{
	SYSTEM_BODY_A5_RESULT(gglXQueryHyperpipeAttribSGIX, dpy, timeSlice, attrib, size, returnAttribList, int, -1);
}

int System
	::GlXQueryHyperpipeBestAttribSGIX(Display* dpy, int timeSlice, int attrib, int size, void* attribList, void* returnAttribList) noexcept
{
	SYSTEM_BODY_A6_RESULT(gglXQueryHyperpipeBestAttribSGIX, dpy, timeSlice, attrib, size, attribList, returnAttribList, int, -1);
}

GLXHyperpipeConfigSGIX* System
	::GlXQueryHyperpipeConfigSGIX(Display* dpy, int hpID, int* npipes) noexcept
{
	SYSTEM_BODY_A3_RESULT(gglXQueryHyperpipeConfigSGIX, dpy, hpID, npipes, GLXHyperpipeConfigSGIX*, nullptr);
}

GLXHyperpipeNetworkSGIX* System
	::GlXQueryHyperpipeNetworkSGIX(Display* dpy, int* npipes) noexcept
{
	SYSTEM_BODY_A2_RESULT(gglXQueryHyperpipeNetworkSGIX, dpy, npipes, GLXHyperpipeNetworkSGIX*, nullptr);
}

void System
	::InitGlxSgixHyperpipe() noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX)
	if (IsOpenGLSupportsExtension("GLX_SGIX_hyperpipe"))
	{
		g_ExistsGlxSgixHyperpipe = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglXBindHyperpipeSGIX);
		SYSTEM_GET_FUNCTION(gglXDestroyHyperpipeConfigSGIX);
		SYSTEM_GET_FUNCTION(gglXHyperpipeAttribSGIX);
		SYSTEM_GET_FUNCTION(gglXHyperpipeConfigSGIX);
		SYSTEM_GET_FUNCTION(gglXQueryHyperpipeAttribSGIX);
		SYSTEM_GET_FUNCTION(gglXQueryHyperpipeBestAttribSGIX);
		SYSTEM_GET_FUNCTION(gglXQueryHyperpipeConfigSGIX);
		SYSTEM_GET_FUNCTION(gglXQueryHyperpipeNetworkSGIX);
	}
	else
	{
		g_ExistsGlxSgixHyperpipe = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_LINUX
	g_ExistsGlxSgixHyperpipe = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_LINUX
}

bool System
	::InitGLX(bool printInfo) noexcept
{
	if (!InitGL(printInfo))
		return false;

	InitGlxArbGetProcAddress();
	InitGlxArbGetMultisample();
	InitGlxArbVertexBufferObject();
	InitGlxArbFBConfigFloat();
	InitGlxArbFramebufferSRGB();
	InitGlxArbCreateContext();
	InitGlxArbCreateContextProfile();
	InitGlxArbCreateContextRobustness();
	InitGlxArbRobustnessApplicationIsolation();
	InitGlxArbRobustnessShareGroupIsolation();
	InitGlxArbContextFlushControl();

	InitGlxExtVisualInfo();
	InitGlxExtSwapControl();
	InitGlxExtVisualRating();
	InitGlxExtImportContext();
	InitGlxExtSceneMarker();
	InitGlxExtFbconfigPackedFloat();
	InitGlxExtFramebufferSRGB();
	InitGlxExtTextureFromPixmap();
	InitGlxExtCreateContextEs2Profile();
	InitGlxExtCreateContextEsProfile();
	InitGlxExtSwapControlTear();
	InitGlxExtBufferAge();
	InitGlxExtStereoTree();

	InitGlxSgixFBConfig();
	InitGlxSgixPBuffer();
	InitGlxSgixVideoResize();
	InitGlxSgixSwapGroup();
	InitGlxSgixSwapBarrier();
	InitGlxSgixVisualSelectGroup();
	InitGlxSgixHyperpipe();

	return true;
}

#include STSTEM_WARNING_POP 



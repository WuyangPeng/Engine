// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 15:48)

#include "System/SystemExport.h"

#include "WglExtensions.h"
#include "GLUtility.h" 
#include "GLExtensions.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h" 
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h" 
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"
#include "System/Helper/Detail/OpenGL/GlxExtensionsMacro.h" 
#include "System/OpenGL/OpenGLUtility.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/CharacterString/FormatString.h"
#include "System/UserInterface/OpenGLWglPrototypes.h"

#include <vector>
#include <iostream>

using std::vector;
using std::cout;

namespace System
{
#if defined(SYSTEM_PLATFORM_WIN32)
	ExistsOpenGLExtensions g_ExistsWgl{ ExistsOpenGLExtensions::Exists };
#else // !SYSTEM_PLATFORM_WIN32
	ExistsOpenGLExtensions g_ExistsWgl{ ExistsOpenGLExtensions::NotExist };
#endif // SYSTEM_PLATFORM_WIN32
}

// ARB 扩展

// (ARB 04) WGL_ARB_buffer_region
namespace System
{
	ExistsOpenGLExtensions g_ExistsWglArbBufferRegion{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsWglArbBufferRegion() noexcept
{
	return g_ExistsWglArbBufferRegion;
}

namespace System
{
	using PgwglCreateBufferRegionARB = WglHandle(OPENGL_STDCALL*) (WglHDC, int, WglUInt);
	using PgwglDeleteBufferRegionARB = void (OPENGL_STDCALL*) (WglHandle);
	using PgwglSaveBufferRegionARB = WglBool(OPENGL_STDCALL*) (WglHandle, int, int, int, int);
	using PgwglRestoreBufferRegionARB = WglBool(OPENGL_STDCALL*) (WglHandle, int, int, int, int, int, int);
}

namespace System
{
	PgwglCreateBufferRegionARB gwglCreateBufferRegionARB{ nullptr };
	PgwglDeleteBufferRegionARB gwglDeleteBufferRegionARB{ nullptr };
	PgwglSaveBufferRegionARB gwglSaveBufferRegionARB{ nullptr };
	PgwglRestoreBufferRegionARB gwglRestoreBufferRegionARB{ nullptr };
}

WglHandle System
	::WglCreateBufferRegionARB(WglHDC hdc, int layerPlane, WglUInt type) noexcept
{
	SYSTEM_BODY_A3_RESULT(gwglCreateBufferRegionARB, hdc, layerPlane, type, WglHandle, nullptr);
}

VOID System
	::WglDeleteBufferRegionARB(WglHandle region) noexcept
{
	SYSTEM_BODY_A1(gwglDeleteBufferRegionARB, region);
}

WglBool System
	::WglSaveBufferRegionARB(WglHandle region, int x, int y, int width, int height) noexcept
{
	SYSTEM_BODY_A5_RESULT(gwglSaveBufferRegionARB, region, x, y, width, height, WglBool, g_False);
}

WglBool System
	::WglRestoreBufferRegionARB(WglHandle region, int x, int y, int width, int height, int xSrc, int ySrc) noexcept
{
	SYSTEM_BODY_A7_RESULT(gwglRestoreBufferRegionARB, region, x, y, width, height, xSrc, ySrc, WglBool, g_False);
}

void System
	::InitWglArbBufferRegion() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
	if (SupportsWglExtension("WGL_ARB_buffer_region") || IsOpenGLSupportsExtension("WGL_ARB_buffer_region"))
	{
		g_ExistsWglArbBufferRegion = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gwglCreateBufferRegionARB);
		SYSTEM_GET_FUNCTION(gwglDeleteBufferRegionARB);
		SYSTEM_GET_FUNCTION(gwglSaveBufferRegionARB);
		SYSTEM_GET_FUNCTION(gwglRestoreBufferRegionARB);
	}
	else
	{
		g_ExistsWglArbBufferRegion = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_WIN32
	g_ExistsWglArbBufferRegion = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_WIN32
}

// (ARB 05) WGL_ARB_multisample

namespace System
{
	ExistsOpenGLExtensions g_ExistsWglArbMultisample{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsWglArbMultisample() noexcept
{
	return g_ExistsWglArbMultisample;
}

void System
	::InitWglArbMultisample() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
	if (SupportsWglExtension("WGL_ARB_multisample") || IsOpenGLSupportsExtension("WGL_ARB_multisample"))
	{
		g_ExistsWglArbMultisample = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsWglArbMultisample = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_WIN32
	g_ExistsWglArbMultisample = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_WIN32
}

// (ARB 08) WGL_ARB_extensions_string

namespace System
{
	ExistsOpenGLExtensions g_ExistsWglArbExtensionsString{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsWglArbExtensionsString() noexcept
{
	return g_ExistsWglArbExtensionsString;
}

namespace System
{
	using PgwglGetExtensionsStringARB = const char* (OPENGL_STDCALL*)(WglHDC);
}

namespace System
{
	PgwglGetExtensionsStringARB gwglGetExtensionsStringARB{ nullptr };
}

const char* System
	::WglGetExtensionsStringARB(WglHDC hdc) noexcept
{
	SYSTEM_BODY_A1_RESULT(gwglGetExtensionsStringARB, hdc, const char*, nullptr);
}

void System
	::InitWglArbExtensionsString() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
	const char* acString{ "wglGetExtensionsStringARB" };

	gwglGetExtensionsStringARB = static_cast<PgwglGetExtensionsStringARB>(GetOpenGLFunctionPointer(acString));

	if (gwglGetExtensionsStringARB != nullptr)
	{
		g_ExistsWglArbExtensionsString = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsWglArbExtensionsString = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_WIN32
	g_ExistsWglArbExtensionsString = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_WIN32
}

// (ARB 09) WGL_ARB_pixel_format

namespace System
{
	ExistsOpenGLExtensions g_ExistsWglArbPixelFormat{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsWglArbPixelFormat() noexcept
{
	return g_ExistsWglArbPixelFormat;
}

namespace System
{
	using PgwglGetPixelFormatAttribivARB = WglBool(OPENGL_STDCALL*) (WglHDC, int, int, WglUInt, const int*, int*);
	using PgwglGetPixelFormatAttribfvARB = WglBool(OPENGL_STDCALL*) (WglHDC, int, int, WglUInt, const int*, WglFloat*);
	using PgwglChoosePixelFormatARB = WglBool(OPENGL_STDCALL*) (WglHDC, const int*, const WglFloat*, WglUInt, int*, WglUInt*);
}

namespace System
{
	PgwglGetPixelFormatAttribivARB gwglGetPixelFormatAttribivARB{ nullptr };
	PgwglGetPixelFormatAttribfvARB gwglGetPixelFormatAttribfvARB{ nullptr };
	PgwglChoosePixelFormatARB gwglChoosePixelFormatARB{ nullptr };
}

WglBool System
	::WglGetPixelFormatAttribivARB(WglHDC hdc, int pixelFormat, int layerPlane, WglUInt numAttributes, const int* attribute, int* value) noexcept
{
	SYSTEM_BODY_A6_RESULT(gwglGetPixelFormatAttribivARB, hdc, pixelFormat, layerPlane, numAttributes, attribute, value, WglBool, g_False);
}

WglBool System
	::WglGetPixelFormatAttribfvARB(WglHDC hdc, int pixelFormat, int layerPlane, WglUInt numAttributes, const int* attribute, WglFloat* value) noexcept
{
	SYSTEM_BODY_A6_RESULT(gwglGetPixelFormatAttribfvARB, hdc, pixelFormat, layerPlane, numAttributes, attribute, value, WglBool, g_False);
}

WglBool System
	::WglChoosePixelFormatARB(WglHDC hdc, const int* attribIList, const WglFloat* attribFList, WglUInt maxFormats, int* format, WglUInt* numFormats) noexcept
{
	SYSTEM_BODY_A6_RESULT(gwglChoosePixelFormatARB, hdc, attribIList, attribFList, maxFormats, format, numFormats, WglBool, g_False);
}

void System
	::InitWglArbPixelFormat() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
	if (SupportsWglExtension("WGL_ARB_pixel_format") || IsOpenGLSupportsExtension("WGL_ARB_pixel_format"))
	{
		g_ExistsWglArbPixelFormat = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gwglGetPixelFormatAttribivARB);
		SYSTEM_GET_FUNCTION(gwglGetPixelFormatAttribfvARB);
		SYSTEM_GET_FUNCTION(gwglChoosePixelFormatARB);
	}
	else
	{
		g_ExistsWglArbPixelFormat = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_WIN32
	g_ExistsWglArbPixelFormat = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_WIN32
}

// (ARB 10) WGL_ARB_make_current_read

namespace System
{
	ExistsOpenGLExtensions g_ExistsWglArbMakeCurrentRead{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsWglArbMakeCurrentRead() noexcept
{
	return g_ExistsWglArbMakeCurrentRead;
}

namespace System
{
	using PgwglMakeContextCurrentARB = WglBool(OPENGL_STDCALL*) (WglHDC, WglHDC, WglHGLRC);
	using PgwglGetCurrentReadDCARB = WglHDC(OPENGL_STDCALL*) ();
}

namespace System
{
	PgwglMakeContextCurrentARB gwglMakeContextCurrentARB{ nullptr };
	PgwglGetCurrentReadDCARB gwglGetCurrentReadDCARB{ nullptr };
}

WglBool System
	::WglMakeContextCurrentARB(WglHDC drawDC, WglHDC readDC, WglHGLRC windowRC) noexcept
{
	SYSTEM_BODY_A3_RESULT(gwglMakeContextCurrentARB, drawDC, readDC, windowRC, WglBool, g_False);
}

WglHDC System
	::WglGetCurrentReadDCARB() noexcept
{
	SYSTEM_BODY_A0_RESULT(gwglGetCurrentReadDCARB, WglHDC, nullptr);
}

void System
	::InitWglArbMakeCurrentRead() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
	if (SupportsWglExtension("WGL_ARB_make_current_read") || IsOpenGLSupportsExtension("WGL_ARB_make_current_read"))
	{
		g_ExistsWglArbMakeCurrentRead = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gwglMakeContextCurrentARB);
		SYSTEM_GET_FUNCTION(gwglGetCurrentReadDCARB);
	}
	else
	{
		g_ExistsWglArbMakeCurrentRead = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_WIN32
	g_ExistsWglArbMakeCurrentRead = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_WIN32
}

// (ARB 11) WGL_ARB_pbuffer

namespace System
{
	ExistsOpenGLExtensions g_ExistsWglArbPBuffer{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsWglArbPBuffer() noexcept
{
	return g_ExistsWglArbPBuffer;
}

namespace System
{
	using PgwglCreatePbufferARB = WglHPBufferARB(OPENGL_STDCALL*) (WglHDC, int, int, int, const int*);
	using PgwglGetPbufferDCARB = WglHDC(OPENGL_STDCALL*) (WglHPBufferARB);
	using PgwglReleasePbufferDCARB = int (OPENGL_STDCALL*) (WglHPBufferARB, WglHDC);
	using PgwglDestroyPbufferARB = WglBool(OPENGL_STDCALL*) (WglHPBufferARB);
	using PgwglQueryPbufferARB = WglBool(OPENGL_STDCALL*) (WglHPBufferARB, int, int*);
}

namespace System
{
	PgwglCreatePbufferARB gwglCreatePbufferARB{ nullptr };
	PgwglGetPbufferDCARB gwglGetPbufferDCARB{ nullptr };
	PgwglReleasePbufferDCARB gwglReleasePbufferDCARB{ nullptr };
	PgwglDestroyPbufferARB gwglDestroyPbufferARB{ nullptr };
	PgwglQueryPbufferARB gwglQueryPbufferARB{ nullptr };
}

WglHPBufferARB System
	::WglCreatePbufferARB(WglHDC hdc, int pixelFormat, int width, int height, const int* attribList) noexcept
{
	SYSTEM_BODY_A5_RESULT(gwglCreatePbufferARB, hdc, pixelFormat, width, height, attribList, WglHPBufferARB, nullptr);
}

WglHDC System
	::WglGetPbufferDCARB(WglHPBufferARB buffer) noexcept
{
	SYSTEM_BODY_A1_RESULT(gwglGetPbufferDCARB, buffer, WglHDC, nullptr);
}

int System
	::WglReleasePbufferDCARB(WglHPBufferARB buffer, WglHDC hdc) noexcept
{
	SYSTEM_BODY_A2_RESULT(gwglReleasePbufferDCARB, buffer, hdc, int, -1);
}

WglBool System
	::WglDestroyPbufferARB(WglHPBufferARB buffer) noexcept
{
	SYSTEM_BODY_A1_RESULT(gwglDestroyPbufferARB, buffer, WglBool, g_False);
}

WglBool System
	::WglQueryPbufferARB(WglHPBufferARB buffer, int attribute, int* value) noexcept
{
	SYSTEM_BODY_A3_RESULT(gwglQueryPbufferARB, buffer, attribute, value, WglBool, g_False);
}

void System
	::InitWglArbPBuffer() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
	if (SupportsWglExtension("WGL_ARB_pbuffer") || IsOpenGLSupportsExtension("WGL_ARB_pbuffer"))
	{
		g_ExistsWglArbPBuffer = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gwglCreatePbufferARB);
		SYSTEM_GET_FUNCTION(gwglGetPbufferDCARB);
		SYSTEM_GET_FUNCTION(gwglReleasePbufferDCARB);
		SYSTEM_GET_FUNCTION(gwglDestroyPbufferARB);
		SYSTEM_GET_FUNCTION(gwglQueryPbufferARB);
	}
	else
	{
		g_ExistsWglArbPBuffer = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_WIN32
	g_ExistsWglArbPBuffer = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_WIN32
}

// (ARB 20) WGL_ARB_render_texture

namespace System
{
	ExistsOpenGLExtensions g_ExistsWglArbRenderTexture{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsWglArbRenderTexture() noexcept
{
	return g_ExistsWglArbRenderTexture;
}

namespace System
{
	using PgwglBindTexImageARB = WglBool(OPENGL_STDCALL*) (WglHPBufferARB, int);
	using PgwglReleaseTexImageARB = WglBool(OPENGL_STDCALL*) (WglHPBufferARB, int);
	using PgwglSetPbufferAttribARB = WglBool(OPENGL_STDCALL*) (WglHPBufferARB, const int*);
}

namespace System
{
	PgwglBindTexImageARB gwglBindTexImageARB{ nullptr };
	PgwglReleaseTexImageARB gwglReleaseTexImageARB{ nullptr };
	PgwglSetPbufferAttribARB gwglSetPbufferAttribARB{ nullptr };
}

WglBool System
	::WglBindTexImageARB(WglHPBufferARB buffer, int bufferIndex) noexcept
{
	SYSTEM_BODY_A2_RESULT(gwglBindTexImageARB, buffer, bufferIndex, WglBool, g_False);
}

WglBool System
	::WglReleaseTexImageARB(WglHPBufferARB buffer, int bufferIndex) noexcept
{
	SYSTEM_BODY_A2_RESULT(gwglReleaseTexImageARB, buffer, bufferIndex, WglBool, g_False);
}

WglBool System
	::WglSetPbufferAttribARB(WglHPBufferARB buffer, const int* attribList) noexcept
{
	SYSTEM_BODY_A2_RESULT(gwglSetPbufferAttribARB, buffer, attribList, WglBool, g_False);
}

void System
	::InitWglArbRenderTexture() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
	if (SupportsWglExtension("WGL_ARB_render_texture") || IsOpenGLSupportsExtension("WGL_ARB_render_texture"))
	{
		g_ExistsWglArbRenderTexture = ExistsOpenGLExtensions::Exists;
		SYSTEM_GET_FUNCTION(gwglBindTexImageARB);
		SYSTEM_GET_FUNCTION(gwglReleaseTexImageARB);
		SYSTEM_GET_FUNCTION(gwglSetPbufferAttribARB);
	}
	else
	{
		g_ExistsWglArbRenderTexture = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_WIN32
	g_ExistsWglArbRenderTexture = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_WIN32
}

// (ARB 39) WGL_ARB_pixel_format_float

namespace System
{
	ExistsOpenGLExtensions g_ExistsWglArbPixelFormatFloat{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsWglArbPixelFormatFloat() noexcept
{
	return g_ExistsWglArbPixelFormatFloat;
}

void System
	::InitWglArbPixelFormatFloat() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
	if (SupportsWglExtension("WGL_ARB_pixel_format_float") || IsOpenGLSupportsExtension("WGL_ARB_pixel_format_float"))
	{
		g_ExistsWglArbPixelFormatFloat = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsWglArbPixelFormatFloat = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_WIN32
	g_ExistsWglArbPixelFormatFloat = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_WIN32
}

// (ARB 46) WGL_ARB_framebuffer_sRGB

namespace System
{
	ExistsOpenGLExtensions g_ExistsWglArbFramebufferSRGB{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsWglArbFramebufferSRGB() noexcept
{
	return g_ExistsWglArbFramebufferSRGB;
}

void System::InitWglArbFramebufferSRGB() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
	if (SupportsWglExtension("WGL_ARB_framebuffer_sRGB") || IsOpenGLSupportsExtension("WGL_ARB_framebuffer_sRGB"))
	{
		g_ExistsWglArbFramebufferSRGB = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsWglArbFramebufferSRGB = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_WIN32
	g_ExistsWglArbFramebufferSRGB = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_WIN32
}

// (ARB 55) WGL_ARB_create_context

namespace System
{
	ExistsOpenGLExtensions g_ExistsWglArbCreateContext{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsWglArbCreateContext() noexcept
{
	return g_ExistsWglArbCreateContext;
}

namespace System
{
	using PgwglCreateContextAttribsARB = WglHGLRC(OPENGL_STDCALL*) (WglHDC hdc, WglHGLRC shareContext, const int* attribList);
}

namespace System
{
	PgwglCreateContextAttribsARB gwglCreateContextAttribsARB{ nullptr };
}

WglHGLRC System
	::WglCreateContextAttribsARB(WglHDC hdc, WglHGLRC shareContext, const int* attribList) noexcept
{
	SYSTEM_BODY_A3_RESULT(gwglCreateContextAttribsARB, hdc, shareContext, attribList, WglHGLRC, nullptr);
}

void System
	::InitWglArbCreateContext() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
	if (SupportsWglExtension("WGL_ARB_create_context") || IsOpenGLSupportsExtension("WGL_ARB_create_context"))
	{
		g_ExistsWglArbCreateContext = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gwglCreateContextAttribsARB);
	}
	else
	{
		g_ExistsWglArbCreateContext = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_WIN32
	g_ExistsWglArbCreateContext = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_WIN32
}

// (ARB 74) WGL_ARB_create_context_profile

namespace System
{
	ExistsOpenGLExtensions g_ExistsWglArbCreateContextProfile{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsWglArbCreateContextProfile() noexcept
{
	return g_ExistsWglArbCreateContextProfile;
}

void System
	::InitWglArbCreateContextProfile() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
	if (SupportsWglExtension("WGL_ARB_create_context_profile") || IsOpenGLSupportsExtension("WGL_ARB_create_context_profile"))
	{
		g_ExistsWglArbCreateContextProfile = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsWglArbCreateContextProfile = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_WIN32
	g_ExistsWglArbCreateContextProfile = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_WIN32
}

// (ARB 102) WGL_ARB_create_context_robustness

namespace System
{
	ExistsOpenGLExtensions g_ExistsWglArbCreateContextRobustness{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsWglArbCreateContextRobustness() noexcept
{
	return g_ExistsWglArbCreateContextRobustness;
}

void System
	::InitWglArbCreateContextRobustness() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
	if (SupportsWglExtension("WGL_ARB_create_context_robustness") || IsOpenGLSupportsExtension("WGL_ARB_create_context_robustness"))
	{
		g_ExistsWglArbCreateContextRobustness = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsWglArbCreateContextRobustness = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_WIN32
	g_ExistsWglArbCreateContextRobustness = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_WIN32
}

// (ARB 143) WGL_ARB_robustness_application_isolation

namespace System
{
	ExistsOpenGLExtensions g_ExistsWglArbRobustnessApplicationIsolation{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsWglArbRobustnessApplicationIsolation() noexcept
{
	return g_ExistsWglArbRobustnessApplicationIsolation;
}

void System
	::InitWglArbRobustnessApplicationIsolation() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
	if (SupportsWglExtension("WGL_ARB_robustness_application_isolation") || IsOpenGLSupportsExtension("WGL_ARB_robustness_application_isolation"))
	{
		g_ExistsWglArbRobustnessApplicationIsolation = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsWglArbRobustnessApplicationIsolation = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_WIN32
	g_ExistsWglArbRobustnessApplicationIsolation = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_WIN32
}

// (ARB 143) WGL_ARB_robustness_share_group_isolation

namespace System
{
	ExistsOpenGLExtensions g_ExistsWglArbRobustnessShareGroupIsolation{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsWglArbRobustnessShareGroupIsolation() noexcept
{
	return g_ExistsWglArbRobustnessShareGroupIsolation;
}

void System
	::InitWglArbRobustnessShareGroupIsolation() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
	if (SupportsWglExtension("WGL_ARB_robustness_share_group_isolation") || IsOpenGLSupportsExtension("WGL_ARB_robustness_share_group_isolation"))
	{
		g_ExistsWglArbRobustnessShareGroupIsolation = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsWglArbRobustnessShareGroupIsolation = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_WIN32
	g_ExistsWglArbRobustnessShareGroupIsolation = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_WIN32
}

// (ARB 168) WGL_ARB_context_flush_control

namespace System
{
	ExistsOpenGLExtensions g_ExistsWglArbContextFlushControl{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsWglArbContextFlushControl() noexcept
{
	return g_ExistsWglArbContextFlushControl;
}

void System
	::InitWglArbContextFlushControl() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
	if (SupportsWglExtension("WGL_ARB_context_flush_control") || IsOpenGLSupportsExtension("WGL_ARB_context_flush_control"))
	{
		g_ExistsWglArbContextFlushControl = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsWglArbContextFlushControl = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_WIN32
	g_ExistsWglArbContextFlushControl = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_WIN32
}

// EXT 扩展

// (EXT 167) WGL_EXT_display_color_table

namespace System
{
	ExistsOpenGLExtensions g_ExistsWglExtDisplayColorTable{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsWglExtDisplayColorTable() noexcept
{
	return g_ExistsWglExtDisplayColorTable;
}

namespace System
{
	using PgwglCreateDisplayColorTableEXT = GLboolean(OPENGL_STDCALL*) (GLushort);
	using PgwglLoadDisplayColorTableEXT = GLboolean(OPENGL_STDCALL*) (const GLushort*, GLuint);
	using PgwglBindDisplayColorTableEXT = GLboolean(OPENGL_STDCALL*) (GLushort);
	using PgwglDestroyDisplayColorTableEXT = VOID(OPENGL_STDCALL*) (GLushort);
}

namespace System
{
	PgwglCreateDisplayColorTableEXT gwglCreateDisplayColorTableEXT{ nullptr };
	PgwglLoadDisplayColorTableEXT gwglLoadDisplayColorTableEXT{ nullptr };
	PgwglBindDisplayColorTableEXT gwglBindDisplayColorTableEXT{ nullptr };
	PgwglDestroyDisplayColorTableEXT gwglDestroyDisplayColorTableEXT{ nullptr };
}

GLboolean System
	::WglCreateDisplayColorTableEXT(GLushort id) noexcept
{
	SYSTEM_BODY_A1_RESULT(gwglCreateDisplayColorTableEXT, id, GLboolean, g_False);
}

GLboolean System
	::WglLoadDisplayColorTableEXT(const GLushort* table, GLuint length) noexcept
{
	SYSTEM_BODY_A2_RESULT(gwglLoadDisplayColorTableEXT, table, length, GLboolean, g_False);
}

GLboolean System
	::WglBindDisplayColorTableEXT(GLushort id) noexcept
{
	SYSTEM_BODY_A1_RESULT(gwglBindDisplayColorTableEXT, id, GLboolean, g_False);
}

void System
	::WglDestroyDisplayColorTableEXT(GLushort id) noexcept
{
	SYSTEM_BODY_A1(gwglDestroyDisplayColorTableEXT, id);
}

void System
	::InitWglExtDisplayColorTable() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
	if (SupportsWglExtension("WGL_EXT_display_color_table") || IsOpenGLSupportsExtension("WGL_EXT_display_color_table"))
	{
		g_ExistsWglExtDisplayColorTable = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gwglCreateDisplayColorTableEXT);
		SYSTEM_GET_FUNCTION(gwglLoadDisplayColorTableEXT);
		SYSTEM_GET_FUNCTION(gwglBindDisplayColorTableEXT);
		SYSTEM_GET_FUNCTION(gwglDestroyDisplayColorTableEXT);
	}
	else
	{
		g_ExistsWglExtDisplayColorTable = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_WIN32
	g_ExistsWglExtDisplayColorTable = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_WIN32
}

// (EXT 168) WGL_EXT_extensions_string

namespace System
{
	ExistsOpenGLExtensions g_ExistsWglExtExtensionsString{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsWglExtExtensionsString() noexcept
{
	return g_ExistsWglExtExtensionsString;
}

namespace System
{
	using PgwglGetExtensionsStringEXT = const char* (OPENGL_STDCALL*)();
}

namespace System
{
	PgwglGetExtensionsStringEXT gwglGetExtensionsStringEXT{ nullptr };
}

const char* System
	::WglGetExtensionsStringEXT() noexcept
{
	SYSTEM_BODY_A0_RESULT(gwglGetExtensionsStringEXT, const char*, nullptr);
}

void System
	::InitWglExtExtensionsString() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
	const char* acString{ "wglGetExtensionsStringEXT" };

	gwglGetExtensionsStringEXT = static_cast<PgwglGetExtensionsStringEXT>(GetOpenGLFunctionPointer(acString));

	if (gwglGetExtensionsStringEXT != nullptr)
	{
		g_ExistsWglExtExtensionsString = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsWglExtExtensionsString = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_WIN32
	g_ExistsWglExtExtensionsString = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_WIN32
}

// (EXT 169) WGL_EXT_make_current_read

namespace System
{
	ExistsOpenGLExtensions g_ExistsWglExtMakeCurrentRead{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsWglExtMakeCurrentRead() noexcept
{
	return g_ExistsWglExtMakeCurrentRead;
}

namespace System
{
	using PgwglMakeContextCurrentEXT = WglBool(OPENGL_STDCALL*) (WglHDC, WglHDC, WglHGLRC);
	using PgwglGetCurrentReadDCEXT = WglHDC(OPENGL_STDCALL*) ();
}

namespace System
{
	PgwglMakeContextCurrentEXT gwglMakeContextCurrentEXT{ nullptr };
	PgwglGetCurrentReadDCEXT gwglGetCurrentReadDCEXT{ nullptr };
}

WglBool System
	::WglMakeContextCurrentEXT(WglHDC drawDC, WglHDC readDC, WglHGLRC windowRC) noexcept
{
	SYSTEM_BODY_A3_RESULT(gwglMakeContextCurrentEXT, drawDC, readDC, windowRC, WglBool, g_False);
}

WglHDC System
	::WglGetCurrentReadDCEXT() noexcept
{
	SYSTEM_BODY_A0_RESULT(gwglGetCurrentReadDCEXT, WglHDC, nullptr);
}

void System
	::InitWglExtMakeCurrentRead() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
	if (SupportsWglExtension("WGL_EXT_make_current_read") || IsOpenGLSupportsExtension("WGL_EXT_make_current_read"))
	{
		g_ExistsWglExtMakeCurrentRead = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gwglMakeContextCurrentEXT);
		if (g_SystemExtOverride && gwglMakeContextCurrentARB == nullptr)
		{
			gwglMakeContextCurrentARB = gwglMakeContextCurrentEXT;
		}

		SYSTEM_GET_FUNCTION(gwglGetCurrentReadDCEXT);
		if (g_SystemExtOverride && gwglGetCurrentReadDCARB == nullptr)
		{
			gwglGetCurrentReadDCARB = gwglGetCurrentReadDCEXT;
		}
	}
	else
	{
		g_ExistsWglExtMakeCurrentRead = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_WIN32
	g_ExistsWglExtMakeCurrentRead = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_WIN32
}

// (EXT 170) WGL_EXT_pixel_format

namespace System
{
	ExistsOpenGLExtensions g_ExistsWglExtPixelFormat{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsWglExtPixelFormat() noexcept
{
	return g_ExistsWglExtPixelFormat;
}

namespace System
{
	using PgwglGetPixelFormatAttribivEXT = WglBool(OPENGL_STDCALL*) (WglHDC, int, int, WglUInt, const int*, int*);
	using PgwglGetPixelFormatAttribfvEXT = WglBool(OPENGL_STDCALL*) (WglHDC, int, int, WglUInt, const int*, WglFloat*);
	using PgwglChoosePixelFormatEXT = WglBool(OPENGL_STDCALL*) (WglHDC, const int*, const WglFloat*, WglUInt, int*, WglUInt*);
}

namespace System
{
	PgwglGetPixelFormatAttribivEXT gwglGetPixelFormatAttribivEXT{ nullptr };
	PgwglGetPixelFormatAttribfvEXT gwglGetPixelFormatAttribfvEXT{ nullptr };
	PgwglChoosePixelFormatEXT gwglChoosePixelFormatEXT{ nullptr };
}

WglBool System
	::WglGetPixelFormatAttribivEXT(WglHDC hdc, int pixelFormat, int layerPlane, WglUInt numAttributes, const int* attribute, int* value) noexcept
{
	SYSTEM_BODY_A6_RESULT(gwglGetPixelFormatAttribivEXT, hdc, pixelFormat, layerPlane, numAttributes, attribute, value, WglBool, g_False);
}

WglBool System
	::WglGetPixelFormatAttribfvEXT(WglHDC hdc, int pixelFormat, int layerPlane, WglUInt numAttributes, const int* attribute, WglFloat* value) noexcept
{
	SYSTEM_BODY_A6_RESULT(gwglGetPixelFormatAttribfvEXT, hdc, pixelFormat, layerPlane, numAttributes, attribute, value, WglBool, g_False);
}

WglBool System
	::WglChoosePixelFormatEXT(WglHDC hdc, const int* attribIList, const WglFloat* attribFList, WglUInt maxFormats, int* format, WglUInt* numFormats) noexcept
{
	SYSTEM_BODY_A6_RESULT(gwglChoosePixelFormatEXT, hdc, attribIList, attribFList, maxFormats, format, numFormats, WglBool, g_False);
}

void System
	::InitWglExtPixelFormat() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
	if (SupportsWglExtension("WGL_EXT_pixel_format") || IsOpenGLSupportsExtension("WGL_EXT_pixel_format"))
	{
		g_ExistsWglExtPixelFormat = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gwglGetPixelFormatAttribivEXT);
		if (g_SystemExtOverride && gwglGetPixelFormatAttribivARB == nullptr)
		{
			gwglGetPixelFormatAttribivARB = gwglGetPixelFormatAttribivEXT;
		}

		SYSTEM_GET_FUNCTION(gwglGetPixelFormatAttribfvEXT);
		if (g_SystemExtOverride && gwglGetPixelFormatAttribfvARB == nullptr)
		{
			gwglGetPixelFormatAttribfvARB = gwglGetPixelFormatAttribfvEXT;
		}

		SYSTEM_GET_FUNCTION(gwglChoosePixelFormatEXT);
		if (g_SystemExtOverride && gwglChoosePixelFormatARB == nullptr)
		{
			gwglChoosePixelFormatARB = gwglChoosePixelFormatEXT;
		}
	}
	else
	{
		g_ExistsWglExtPixelFormat = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_WIN32
	g_ExistsWglExtPixelFormat = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_WIN32
}

// (EXT 171) WGL_EXT_pbuffer

namespace System
{
	ExistsOpenGLExtensions g_ExistsWglExtPBuffer{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsWglExtPBuffer() noexcept
{
	return g_ExistsWglExtPBuffer;
}

namespace System
{
	using PgwglCreatePbufferEXT = WglHPBufferEXT(OPENGL_STDCALL*) (WglHDC, int, int, int, const int*);
	using PgwglGetPbufferDCEXT = WglHDC(OPENGL_STDCALL*) (WglHPBufferEXT);
	using PgwglReleasePbufferDCEXT = int (OPENGL_STDCALL*) (WglHPBufferEXT, WglHDC);
	using PgwglDestroyPbufferEXT = WglBool(OPENGL_STDCALL*) (WglHPBufferEXT);
	using PgwglQueryPbufferEXT = WglBool(OPENGL_STDCALL*) (WglHPBufferEXT, int, int*);
}

namespace System
{
	PgwglCreatePbufferEXT gwglCreatePbufferEXT{ nullptr };
	PgwglGetPbufferDCEXT gwglGetPbufferDCEXT{ nullptr };
	PgwglReleasePbufferDCEXT gwglReleasePbufferDCEXT{ nullptr };
	PgwglDestroyPbufferEXT gwglDestroyPbufferEXT{ nullptr };
	PgwglQueryPbufferEXT gwglQueryPbufferEXT{ nullptr };
}

WglHPBufferEXT System
	::WglCreatePbufferEXT(WglHDC hdc, int pixelFormat, int width, int height, const int* attribList) noexcept
{
	SYSTEM_BODY_A5_RESULT(gwglCreatePbufferEXT, hdc, pixelFormat, width, height, attribList, WglHPBufferEXT, nullptr);
}

WglHDC System
	::WglGetPbufferDCEXT(WglHPBufferEXT buffer) noexcept
{
	SYSTEM_BODY_A1_RESULT(gwglGetPbufferDCEXT, buffer, WglHDC, nullptr);
}

int System
	::WglReleasePbufferDCEXT(WglHPBufferEXT buffer, WglHDC hdc) noexcept
{
	SYSTEM_BODY_A2_RESULT(gwglReleasePbufferDCEXT, buffer, hdc, int, -1);
}

WglBool System
	::WglDestroyPbufferEXT(WglHPBufferEXT buffer) noexcept
{
	SYSTEM_BODY_A1_RESULT(gwglDestroyPbufferEXT, buffer, WglBool, g_False);
}

WglBool System
	::WglQueryPbufferEXT(WglHPBufferEXT buffer, int attribute, int* value) noexcept
{
	SYSTEM_BODY_A3_RESULT(gwglQueryPbufferEXT, buffer, attribute, value, WglBool, g_False);
}

void System
	::InitWglExtPBuffer() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
	if (SupportsWglExtension("WGL_EXT_pbuffer") || IsOpenGLSupportsExtension("WGL_EXT_pbuffer"))
	{
		g_ExistsWglExtPBuffer = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gwglCreatePbufferEXT);
		if (g_SystemExtOverride && gwglCreatePbufferARB == nullptr)
		{
			gwglCreatePbufferARB = static_cast<PgwglCreatePbufferARB>(gwglCreatePbufferEXT);
		}

		SYSTEM_GET_FUNCTION(gwglGetPbufferDCEXT);
		if (g_SystemExtOverride && gwglGetPbufferDCARB == nullptr)
		{
			gwglGetPbufferDCARB = static_cast<PgwglGetPbufferDCARB>(gwglGetPbufferDCEXT);
		}

		SYSTEM_GET_FUNCTION(gwglReleasePbufferDCEXT);
		if (g_SystemExtOverride && gwglReleasePbufferDCARB == nullptr)
		{
			gwglReleasePbufferDCARB = static_cast<PgwglReleasePbufferDCARB>(gwglReleasePbufferDCEXT);
		}

		SYSTEM_GET_FUNCTION(gwglDestroyPbufferEXT);
		if (g_SystemExtOverride && gwglDestroyPbufferARB == nullptr)
		{
			gwglDestroyPbufferARB = static_cast<PgwglDestroyPbufferARB>(gwglDestroyPbufferEXT);
		}

		SYSTEM_GET_FUNCTION(gwglQueryPbufferEXT);
		if (g_SystemExtOverride && gwglQueryPbufferARB == nullptr)
		{
			gwglQueryPbufferARB = static_cast<PgwglQueryPbufferARB>(gwglQueryPbufferEXT);
		}
	}
	else
	{
		g_ExistsWglExtPBuffer = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_WIN32
	g_ExistsWglExtPBuffer = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_WIN32
}

// (EXT 172) WGL_EXT_swap_control

namespace System
{
	ExistsOpenGLExtensions g_ExistsWglExtSwapControl{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsWglExtSwapControl() noexcept
{
	return g_ExistsWglExtSwapControl;
}

namespace System
{
	using PgwglSwapIntervalEXT = WglBool(OPENGL_STDCALL*) (int);
	using PgwglGetSwapIntervalEXT = int (OPENGL_STDCALL*) ();
}

namespace System
{
	PgwglSwapIntervalEXT gwglSwapIntervalEXT{ nullptr };
	PgwglGetSwapIntervalEXT gwglGetSwapIntervalEXT{ nullptr };
}

WglBool System
	::WglSwapIntervalEXT(int iInterval) noexcept
{
	WglBool result = g_False;

	SYSTEM_ENTER_FUNCTION(gwglSwapIntervalEXT);
	if (gwglSwapIntervalEXT != nullptr)
	{
		// 应用程序能运行在垂直同步禁用。
		SYSTEM_NONNULL_FUNCTION(gwglSwapIntervalEXT);
		result = gwglSwapIntervalEXT(iInterval);
	}
	else
	{
		// 应用程序必须运行在垂直同步启用，这里不使用宏SYSTEM_NULL_FUNCTION(gwglSwapIntervalEXT)
		result = g_False;
	}
	SYSTEM_EXIT_FUNCTION(gwglSwapIntervalEXT);

	return result;
}

int System
	::WglGetSwapIntervalEXT() noexcept
{
	SYSTEM_BODY_A0_RESULT(gwglGetSwapIntervalEXT, int, -1);
}

void System
	::InitWglExtSwapControl() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
	if (SupportsWglExtension("WGL_EXT_swap_control") || IsOpenGLSupportsExtension("WGL_EXT_swap_control"))
	{
		g_ExistsWglExtSwapControl = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gwglSwapIntervalEXT);
		SYSTEM_GET_FUNCTION(gwglGetSwapIntervalEXT);
	}
	else
	{
		g_ExistsWglExtSwapControl = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_WIN32
	g_ExistsWglExtSwapControl = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_WIN32
}

// (EXT 177) WGL_EXT_depth_float

namespace System
{
	ExistsOpenGLExtensions g_ExistsWglExtDepthFloat{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsWglExtDepthFloat() noexcept
{
	return g_ExistsWglExtDepthFloat;
}

void System
	::InitWglExtDepthFloat() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
	if (SupportsWglExtension("WGL_EXT_depth_float") || IsOpenGLSupportsExtension("WGL_EXT_depth_float"))
	{
		g_ExistsWglExtDepthFloat = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsWglExtDepthFloat = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_WIN32
	g_ExistsWglExtDepthFloat = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_WIN32
}

// (EXT 209) WGL_EXT_multisample

namespace System
{
	ExistsOpenGLExtensions g_ExistsWglExtMultisample{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsWglExtMultisample() noexcept
{
	return g_ExistsWglExtMultisample;
}

void System
	::InitWglExtMultisample() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
	if (SupportsWglExtension("WGL_EXT_multisample") || IsOpenGLSupportsExtension("WGL_EXT_multisample"))
	{
		g_ExistsWglExtMultisample = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsWglExtMultisample = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_WIN32
	g_ExistsWglExtMultisample = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_WIN32
}

// (EXT 328) WGL_EXT_pixel_format_packed_float

namespace System
{
	ExistsOpenGLExtensions g_ExistsWglExtPixelFormatPackedFloat{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsWglExtPixelFormatPackedFloat() noexcept
{
	return g_ExistsWglExtPixelFormatPackedFloat;
}

void System
	::InitWglExtPixelFormatPackedFloat() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
	if (SupportsWglExtension("WGL_EXT_pixel_format_packed_float") || IsOpenGLSupportsExtension("WGL_EXT_pixel_format_packed_float"))
	{
		g_ExistsWglExtPixelFormatPackedFloat = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsWglExtPixelFormatPackedFloat = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_WIN32
	g_ExistsWglExtPixelFormatPackedFloat = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_WIN32
}

// (EXT 337) WGL_EXT_framebuffer_sRGB

namespace System
{
	ExistsOpenGLExtensions g_ExistsWglExtFramebufferSRGB{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsWglExtFramebufferSRGB() noexcept
{
	return g_ExistsWglExtFramebufferSRGB;
}

void System
	::InitWglExtFramebufferSRGB() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
	if (SupportsWglExtension("WGL_EXT_framebuffer_sRGB") || IsOpenGLSupportsExtension("WGL_EXT_framebuffer_sRGB"))
	{
		g_ExistsWglExtFramebufferSRGB = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsWglExtFramebufferSRGB = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_WIN32
	g_ExistsWglExtFramebufferSRGB = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_WIN32
}

// (EXT 400) WGL_EXT_create_context_es2_profile

namespace System
{
	ExistsOpenGLExtensions g_ExistsWglExtCreateContextEs2Profile{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsWglExtCreateContextEs2Profile() noexcept
{
	return g_ExistsWglExtCreateContextEs2Profile;
}

void System
	::InitWglExtCreateContextEs2Profile() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
	if (SupportsWglExtension("WGL_EXT_create_context_es2_profile") || IsOpenGLSupportsExtension("WGL_EXT_create_context_es2_profile"))
	{
		g_ExistsWglExtCreateContextEs2Profile = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsWglExtCreateContextEs2Profile = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_WIN32
	g_ExistsWglExtCreateContextEs2Profile = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_WIN32
}

// (EXT 400) WGL_EXT_create_context_es_profile

namespace System
{
	ExistsOpenGLExtensions g_ExistsWglExtCreateContextEsProfile{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsWglExtCreateContextEsProfile() noexcept
{
	return g_ExistsWglExtCreateContextEsProfile;
}

void System
	::InitWglExtCreateContextEsProfile() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
	if (SupportsWglExtension("WGL_EXT_create_context_es_profile") || IsOpenGLSupportsExtension("WGL_EXT_create_context_es_profile"))
	{
		g_ExistsWglExtCreateContextEsProfile = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsWglExtCreateContextEsProfile = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_WIN32
	g_ExistsWglExtCreateContextEsProfile = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_WIN32
}

// (EXT 415) WGL_EXT_swap_control_tear

namespace System
{
	ExistsOpenGLExtensions g_ExistsWglExtSwapControlTear{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsWglExtSwapControlTear() noexcept
{
	return g_ExistsWglExtSwapControlTear;
}

void System
	::InitWglExtSwapControlTear() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
	if (SupportsWglExtension("WGL_EXT_swap_control_tear") || IsOpenGLSupportsExtension("WGL_EXT_swap_control_tear"))
	{
		g_ExistsWglExtSwapControlTear = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsWglExtSwapControlTear = ExistsOpenGLExtensions::NotExist;
	}
#else // !SYSTEM_PLATFORM_WIN32
	g_ExistsWglExtSwapControlTear = ExistsOpenGLExtensions::NotExist;
#endif // SYSTEM_PLATFORM_WIN32
}

// 初始化 WGL 系统

void System
	::PrintWglExtensionsInfo()
{
	auto wglExtensions = GetWglExtensionString();

	if (wglExtensions != nullptr)
	{
		cout << "WGLextensions =\n";

		const auto length = Strlen(wglExtensions) + 1;
		vector<char> ext(length);
		Strcpy(ext.data(), length, wglExtensions);

		char* next{ nullptr };
		auto token = Strtok(ext.data(), " \t\n", &next);
		while (token != nullptr)
		{
			cout << "    " << token << "\n";
			token = Strtok(nullptr, " \t\n", &next);
		}
	}
	else
	{
		cout << "WGLextensions = <null>\n";
	}
}

bool System
	::InitWGL(bool printInfo)
{
	if (!InitGL(printInfo))
		return false;

	InitWglArbExtensionsString();
	InitWglExtExtensionsString();

	if (printInfo)
	{
		PrintWglExtensionsInfo();
	}

	InitWglArbBufferRegion();
	InitWglArbMultisample();
	InitWglArbPixelFormat();
	InitWglArbMakeCurrentRead();
	InitWglArbPBuffer();
	InitWglArbRenderTexture();
	InitWglArbPixelFormatFloat();
	InitWglArbFramebufferSRGB();
	InitWglArbCreateContext();
	InitWglArbCreateContextProfile();
	InitWglArbCreateContextRobustness();
	InitWglArbRobustnessApplicationIsolation();
	InitWglArbRobustnessShareGroupIsolation();
	InitWglArbContextFlushControl();

	InitWglExtDisplayColorTable();
	InitWglExtMakeCurrentRead();
	InitWglExtPixelFormat();
	InitWglExtPBuffer();
	InitWglExtSwapControl();
	InitWglExtDepthFloat();
	InitWglExtMultisample();
	InitWglExtPixelFormatPackedFloat();
	InitWglExtFramebufferSRGB();
	InitWglExtCreateContextEs2Profile();
	InitWglExtCreateContextEsProfile();
	InitWglExtSwapControlTear();

	return true;
}

const char* System
	::GetWglExtensionString() noexcept
{
	if (g_ExistsWglExtExtensionsString == ExistsOpenGLExtensions::Exists && g_SystemExtOverride)
	{
		return WglGetExtensionsStringEXT();
	}
	else if (g_ExistsWglArbExtensionsString == ExistsOpenGLExtensions::Exists)
	{
		return WglGetExtensionsStringARB(GetWglCurrentDC());
	}
	else
	{
		return nullptr;
	}
}

bool System
	::SupportsWglExtension(const char* wglExtension) noexcept
{
	if (wglExtension == nullptr)
	{
		return false;
	}

	auto wglExtensionString = GetWglExtensionString();
	if (wglExtensionString == nullptr)
	{
		return false;
	}

	auto begin = Strstr(wglExtensionString, wglExtension);
	if (begin == nullptr)
	{
		return false;
	}

	// 扩展被发现,但确保它不是另一个扩展的合适子串。
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
	const auto end = *(begin + Strlen(wglExtension));
#include STSTEM_WARNING_POP

	return end == ' ' || end == 0 || end == '\t' || end == '\n';
}

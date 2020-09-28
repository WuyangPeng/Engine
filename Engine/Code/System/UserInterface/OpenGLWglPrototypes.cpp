// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:34)

#include "System/SystemExport.h"

#include "OpenGLWglPrototypes.h"

#include "System/Helper/WindowsMacro.h"

System::OpenGLHdc System
	::GetWglCurrentDC() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::wglGetCurrentDC();
#else // !SYSTEM_PLATFORM_WIN32
	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::CopyWglContext(OpenGLHglrc arg1, OpenGLHglrc arg2, WindowUInt arg3) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::wglCopyContext(arg1, arg2, arg3) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	
	
	

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::OpenGLHglrc System
	::CreateWglContext(OpenGLHdc arg1) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::wglCreateContext(arg1);
#else // !SYSTEM_PLATFORM_WIN32
	

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

bool SYSTEM_DEFAULT_DECLARE System
	::DeleteWglContext(OpenGLHglrc arg1) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::wglDeleteContext(arg1) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::OpenGLHglrc System
	::GetWglCurrentContext() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::wglGetCurrentContext();
#else // !SYSTEM_PLATFORM_WIN32
	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::MakeWglCurrent(OpenGLHdc arg1, OpenGLHglrc arg2) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::wglMakeCurrent(arg1, arg2) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::ShareWglLists(OpenGLHglrc arg1, OpenGLHglrc arg2) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::wglShareLists(arg1, arg2) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	
	

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SwapWglLayerBuffers(OpenGLHdc arg1, WindowUInt arg2) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::wglSwapLayerBuffers(arg1, arg2) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	
	

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::SwapWglMultipleBuffers(WindowUInt arg1, const WglSwap* arg2) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

	return ::wglSwapMultipleBuffers(arg1, arg2);

#else // !SYSTEM_PLATFORM_WIN32
	
	

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

int System
	::ChooseWindowPixelFormat(OpenGLHdc hdc, const PixelFormatDescriptor* pixelFormatDescriptor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

	return ::ChoosePixelFormat(hdc, pixelFormatDescriptor);

#else // !SYSTEM_PLATFORM_WIN32
	
	

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetWindowPixelFormat(OpenGLHdc hdc, int format, const PixelFormatDescriptor* pixelFormatDescriptor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetPixelFormat(hdc, format, pixelFormatDescriptor) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	
	
	

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::OpenGLProc System
	::GetWglProcAddress(const char* glFunction) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::wglGetProcAddress(glFunction);
#else // !SYSTEM_PLATFORM_WIN32
	

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}
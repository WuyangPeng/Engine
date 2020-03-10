// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:34)

#ifndef SYSTEM_USER_INTERFACE_OPENGL_WGL_PROTOTYPES_FWD 
#define SYSTEM_USER_INTERFACE_OPENGL_WGL_PROTOTYPES_FWD 

#include "System/Window/Using/WindowUsing.h"
#include "System/UserInterface/Using/OpenGLWglPrototypesUsing.h"

namespace System
{
	OpenGLHdc GetWglCurrentDC() noexcept;
	bool CopyWglContext(OpenGLHglrc arg1, OpenGLHglrc arg2, WindowUInt arg3) noexcept;
	OpenGLHglrc CreateWglContext(OpenGLHdc arg1) noexcept;
	bool DeleteWglContext(OpenGLHglrc arg1) noexcept;
	OpenGLHglrc GetWglCurrentContext() noexcept;
	bool MakeWglCurrent(OpenGLHdc arg1, OpenGLHglrc arg2) noexcept;
	bool ShareWglLists(OpenGLHglrc arg1, OpenGLHglrc arg2) noexcept;

	bool SwapWglLayerBuffers(OpenGLHdc arg1, WindowUInt arg2) noexcept;
	WindowDWord SwapWglMultipleBuffers(WindowUInt arg1, const WglSwap* arg2) noexcept;

	int ChooseWindowPixelFormat(OpenGLHdc hdc, const PixelFormatDescriptor* pixelFormatDescriptor) noexcept;
	bool  SetWindowPixelFormat(OpenGLHdc hdc, int format, const PixelFormatDescriptor* pixelFormatDescriptor) noexcept;

	OpenGLProc GetWglProcAddress(const char* glFunction) noexcept;
}

#endif // SYSTEM_USER_INTERFACE_OPENGL_WGL_PROTOTYPES_FWD
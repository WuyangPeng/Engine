// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:34)

#ifndef SYSTEM_WINDOW_OPENGL_WGL_PROTOTYPES_H
#define SYSTEM_WINDOW_OPENGL_WGL_PROTOTYPES_H

#include "System/SystemDll.h"

#include "Using/OpenGLWglPrototypesUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	OpenGLHdc SYSTEM_DEFAULT_DECLARE GetWglCurrentDC() noexcept;
	bool SYSTEM_DEFAULT_DECLARE CopyWglContext(OpenGLHglrc arg1, OpenGLHglrc arg2, WindowUInt arg3) noexcept;
	OpenGLHglrc SYSTEM_DEFAULT_DECLARE CreateWglContext(OpenGLHdc arg1) noexcept;
	bool SYSTEM_DEFAULT_DECLARE DeleteWglContext(OpenGLHglrc arg1) noexcept;
	OpenGLHglrc SYSTEM_DEFAULT_DECLARE GetWglCurrentContext() noexcept;
	bool SYSTEM_DEFAULT_DECLARE MakeWglCurrent(OpenGLHdc arg1, OpenGLHglrc arg2) noexcept;
	bool SYSTEM_DEFAULT_DECLARE ShareWglLists(OpenGLHglrc arg1, OpenGLHglrc arg2) noexcept;

	bool SYSTEM_DEFAULT_DECLARE SwapWglLayerBuffers(OpenGLHdc arg1, WindowUInt arg2) noexcept;
	WindowDWord SYSTEM_DEFAULT_DECLARE SwapWglMultipleBuffers(WindowUInt arg1, const WglSwap* arg2) noexcept;

	int SYSTEM_DEFAULT_DECLARE ChooseWindowPixelFormat(OpenGLHdc hdc, const PixelFormatDescriptor* pixelFormatDescriptor) noexcept;
	bool  SYSTEM_DEFAULT_DECLARE SetWindowPixelFormat(OpenGLHdc hdc, int format, const PixelFormatDescriptor* pixelFormatDescriptor) noexcept;

	OpenGLProc SYSTEM_DEFAULT_DECLARE GetWglProcAddress(const char* glFunction) noexcept;
}

#endif // SYSTEM_WINDOW_OPENGL_WGL_PROTOTYPES_H

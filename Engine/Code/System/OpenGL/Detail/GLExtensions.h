// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:34)

#ifndef SYSTEM_GL_EXTENSIONS_H
#define SYSTEM_GL_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/GLExtensionsMacro.h"

namespace System
{
	SYSTEM_HIDDEN_DECLARE const char* GetVendorString() noexcept;
	SYSTEM_HIDDEN_DECLARE const char* GetRendererString() noexcept;
	SYSTEM_HIDDEN_DECLARE const char* GetVersionString() noexcept;
	SYSTEM_HIDDEN_DECLARE const char* GetExtensionString() noexcept;
	SYSTEM_HIDDEN_DECLARE bool InitGL(bool printInfo = true) noexcept;
	SYSTEM_HIDDEN_DECLARE void PrintOpenGLInfo();
}

#endif // SYSTEM_GL_EXTENSIONS_H

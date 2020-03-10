// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:37)

#ifndef SYSTEM_OPENGL_OPENGL_UTILITY_FWD_H
#define SYSTEM_OPENGL_OPENGL_UTILITY_FWD_H  

#include "OpenGLFlagsFwd.h"

#include <string>

namespace System
{
	OpenGLSystemVersion GetOpenGLVersion() noexcept;

	bool IsOpenGLSupportsExtension(const char* acExtension) noexcept;

	void* GetFunctionPointer(const char* glFunction) noexcept;

	std::string GetOpenGLErrorDescription(OpenGLErrorCode code);
}

#endif // SYSTEM_OPENGL_OPENGL_UTILITY_FWD_H
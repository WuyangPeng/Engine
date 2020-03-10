// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 15:35)

#ifndef SYSTEM_OPENGL_GL_UTILITY_H
#define SYSTEM_OPENGL_GL_UTILITY_H

#include "System/SystemDll.h"

#include "System/OpenGL/Using/GL11ExtensionsUsing.h"

namespace System
{
	enum class OpenGLSystemVersion;
	enum class OpenGLErrorCode;

	// 错误检查。
	const char* SYSTEM_HIDDEN_DECLARE GetOpenGLErrorString(OpenGLErrorCode code) noexcept;

	OpenGLSystemVersion SYSTEM_HIDDEN_DECLARE GetOpenGLVersion(char major, char minor) noexcept;
	int SYSTEM_HIDDEN_DECLARE ToIndex(char index) noexcept;
}

extern "C"
{
	// 每个平台必须实现这个函数。
	void* SYSTEM_HIDDEN_DECLARE GetOpenGLFunctionPointer(const char* glFunction) noexcept;
}

#endif // SYSTEM_OPENGL_GL_UTILITY_H

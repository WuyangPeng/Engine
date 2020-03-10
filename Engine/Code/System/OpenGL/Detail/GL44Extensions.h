// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 15:34)

#ifndef SYSTEM_OPENGL_GL_44_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_44_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/Detail/OpenGL/GL44ExtensionsMacro.h"

namespace System
{
	// OpenGL 4.4
	enum class ExistsOpenGLExtensions;

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsOpenGL44() noexcept;

	void InitOpenGL44() noexcept;
}

#endif // SYSTEM_OPENGL_GL_44_EXTENSIONS_H

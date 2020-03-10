// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:37)

#ifndef SYSTEM_OPENGL_GL_11_TEST_H
#define SYSTEM_OPENGL_GL_11_TEST_H

#include "System/SystemDll.h"

#include "System/OpenGL/Using/GLTestUsing.h" 
#include "System/OpenGL/Using/GL11ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/TestFlags/GL11Flags.h"

namespace System
{
	bool SYSTEM_DEFAULT_DECLARE GL11Test(GL11Flags gl11, const Parameter& parameter);
	GLboolean SYSTEM_DEFAULT_DECLARE GL11TestReturnBoolean(GL11Flags gl11, const Parameter& parameter);
	SYSTEM_DEFAULT_DECLARE const GLubyte* GL11TestReturnConstGLubytePtr(GL11Flags gl11, const Parameter& parameter);
	GLint SYSTEM_DEFAULT_DECLARE GL11TestReturnGLint(GL11Flags gl11, const Parameter& parameter);
}

#endif // SYSTEM_OPENGL_GL_11_TEST_H

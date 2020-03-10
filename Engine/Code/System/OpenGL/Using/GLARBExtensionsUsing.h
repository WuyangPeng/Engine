// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:38)

#ifndef SYSTEM_OPENGL_GL_ARB_EXTENSIONS_USING_H
#define SYSTEM_OPENGL_GL_ARB_EXTENSIONS_USING_H

#include "GL11ExtensionsUsing.h"
#include "GL20ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"

extern "C"
{
	// (ARB 28) GL_ARB_vertex_buffer_object

	using GLintptrARB = ptrdiff_t;
	using GLsizeiptrARB = ptrdiff_t;

	// (ARB 30) GL_ARB_shader_objects

	using GLcharARB = char;
	using GLhandleARB = unsigned int;

	// (ARB 66) GL_ARB_sync 

	using GLsync = struct __GLsync*;

	// (ARB 103) GL_ARB_cl_event

	using cl_context = struct _cl_context*;
	using cl_event = struct _cl_event*;
}

namespace System
{
	// (ARB 104) GL_ARB_debug_output

	using GlDebugProcARB = void(*)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, GLvoid* userParam);
}

#endif // SYSTEM_OPENGL_GL_ARB_EXTENSIONS_USING_H

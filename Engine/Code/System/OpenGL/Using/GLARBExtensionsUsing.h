//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 13:15)

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

    using GlDebugProcARB = void (*)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, GLvoid* userParam);
}

#endif  // SYSTEM_OPENGL_GL_ARB_EXTENSIONS_USING_H

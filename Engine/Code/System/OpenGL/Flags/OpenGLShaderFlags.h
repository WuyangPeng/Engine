///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.6 (2021/06/27 1:57)

#ifndef SYSTEM_OPENGL_OPENGL_SHADER_FLAGS_H
#define SYSTEM_OPENGL_OPENGL_SHADER_FLAGS_H

#include "System/Helper/EnumMacro.h"
#include "System/Helper/GLExtensionsMacro.h"

namespace System
{
    enum class ShaderType
    {
        Vertex = GL_VERTEX_SHADER,
        Fragment = GL_FRAGMENT_SHADER,
        Geometry = GL_GEOMETRY_SHADER,
        Compute = GL_COMPUTE_SHADER,
    };

    enum class ShaderStatus
    {
        Delete = GL_DELETE_STATUS,
        Compile = GL_COMPILE_STATUS,
    };

    enum class ShaderAttributes
    {
        ShaderType = GL_SHADER_TYPE,
        InfoLogLength = GL_INFO_LOG_LENGTH,
        ShaderSourceLength = GL_SHADER_SOURCE_LENGTH,
    };
}

#endif  // SYSTEM_OPENGL_OPENGL_SHADER_FLAGS_H

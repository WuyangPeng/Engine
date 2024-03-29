/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/03/01 16:57)

#ifndef SYSTEM_OPENGL_OPENGL_SHADER_FLAGS_H
#define SYSTEM_OPENGL_OPENGL_SHADER_FLAGS_H

#include "System/Helper/EnumOperator.h"
#include "System/Helper/GLExtensionsMacro.h"

namespace System
{
    enum class ShaderType
    {
        Vertex = GL_VERTEX_SHADER,
        Fragment = GL_FRAGMENT_SHADER,
        Geometry = GL_GEOMETRY_SHADER,
        Compute = GL_COMPUTE_SHADER,
        TessControl = GL_TESS_CONTROL_SHADER,
        TessEvaluation = GL_TESS_EVALUATION_SHADER,
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

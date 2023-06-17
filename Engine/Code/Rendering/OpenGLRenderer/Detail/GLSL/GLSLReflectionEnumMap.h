///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:21)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_ENUM_MAP_H
#define RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_ENUM_MAP_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

#include <array>
#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE GLSLReflectionEnumMap
    {
    public:
        using ClassType = GLSLReflectionEnumMap;
        using OpenGLEnum = System::OpenGLEnum;
        using GLSLReflectionEnumType = System::GLSLReflectionEnumType;

    public:
        GLSLReflectionEnumMap(GLSLReflectionEnumType inValue, const std::string& inName, const std::string& inShaderName, int inRows, int inCols, int inSize);

        CLASS_INVARIANT_DECLARE;

        NODISCARD GLSLReflectionEnumType GetValue() const noexcept;
        NODISCARD std::string GetName() const;
        NODISCARD std::string GetShaderName() const;
        NODISCARD int GetRows() const noexcept;
        NODISCARD int GetCols() const noexcept;
        NODISCARD int GetSize() const noexcept;

    private:
        GLSLReflectionEnumType value;
        std::string name;
        std::string shaderName;
        int rows;
        int cols;
        int size;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_ENUM_MAP_H
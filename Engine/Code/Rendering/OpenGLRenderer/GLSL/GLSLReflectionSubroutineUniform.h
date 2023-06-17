///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:20)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_SUBROUTINE_UNIFORM_H
#define RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_SUBROUTINE_UNIFORM_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

#include <vector>
#include <string>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(GLSLReflectionSubroutineUniform, GLSLReflectionSubroutineUniformImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE GLSLReflectionSubroutineUniform
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(GLSLReflectionSubroutineUniform);
        using OpenGLInt = System::OpenGLInt;
        using CompatibleSubroutines = std::vector<OpenGLInt>;

    public:
        explicit GLSLReflectionSubroutineUniform(const std::string& name);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetName() const;
        void SetName(const std::string& aName);

        NODISCARD OpenGLInt GetLocation() const noexcept;
        void SetLocation(OpenGLInt aLocation) noexcept;

        NODISCARD OpenGLInt GetArraySize() const noexcept;
        void SetArraySize(OpenGLInt aArraySize) noexcept;

        NODISCARD OpenGLInt GetCompatibleSubroutines(int index) const;
        void SetCompatibleSubroutines(int index, OpenGLInt aCompatibleSubroutines);
        void SetCompatibleSubroutines(const CompatibleSubroutines& aCompatibleSubroutines);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_SUBROUTINE_UNIFORM_H
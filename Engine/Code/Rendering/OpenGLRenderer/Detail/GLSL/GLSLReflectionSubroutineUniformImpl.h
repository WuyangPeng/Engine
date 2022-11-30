///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/29 21:54)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_SUBROUTINE_UNIFORM_IMPL_H
#define RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_SUBROUTINE_UNIFORM_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"

#include <string>
#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE GLSLReflectionSubroutineUniformImpl
    {
    public:
        using ClassType = GLSLReflectionSubroutineUniformImpl;
        using OpenGLInt = System::OpenGLInt;
        using CompatibleSubroutines = std::vector<OpenGLInt>;

    public:
        GLSLReflectionSubroutineUniformImpl() noexcept;
        explicit GLSLReflectionSubroutineUniformImpl(const std::string& name);

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
        std::string name;
        OpenGLInt location;
        OpenGLInt arraySize;
        CompatibleSubroutines compatibleSubroutines;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_SUBROUTINE_UNIFORM_IMPL_H
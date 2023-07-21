///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:21)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_SUBROUTINE_UNIFORM_IMPL_H
#define RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_SUBROUTINE_UNIFORM_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Shaders/Detail/ReflectionSubroutineUniformImpl.h"

#include <string>
#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE GLSLReflectionSubroutineUniform : public ReflectionSubroutineUniformImpl
    {
    public:
        using ClassType = GLSLReflectionSubroutineUniform;
        using ParentType = ReflectionSubroutineUniformImpl;

        using OpenGLInt = System::OpenGLInt;
        using CompatibleSubroutines = std::vector<OpenGLInt>;

    public:
        GLSLReflectionSubroutineUniform() noexcept;
        explicit GLSLReflectionSubroutineUniform(const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ReflectionSubroutineUniformSharedPtr Clone() const override;

        NODISCARD std::string GetName() const override;
        void SetName(const std::string& aName) override;

        NODISCARD OpenGLInt GetLocation() const noexcept override;
        void SetLocation(OpenGLInt aLocation) noexcept override;

        NODISCARD OpenGLInt GetArraySize() const noexcept override;
        void SetArraySize(OpenGLInt aArraySize) noexcept override;

        NODISCARD OpenGLInt GetCompatibleSubroutines(int index) const override;
        void SetCompatibleSubroutines(int index, OpenGLInt aCompatibleSubroutines) override;
        void SetCompatibleSubroutines(const CompatibleSubroutines& aCompatibleSubroutines) override;

    private:
        std::string name;
        OpenGLInt location;
        OpenGLInt arraySize;
        CompatibleSubroutines compatibleSubroutines;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_SUBROUTINE_UNIFORM_IMPL_H
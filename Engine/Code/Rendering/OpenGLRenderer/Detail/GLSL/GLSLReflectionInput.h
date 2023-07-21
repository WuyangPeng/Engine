///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:21)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_INPUT_IMPL_H
#define RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_INPUT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Shaders/Detail/ReflectionInputImpl.h"

#include <array>
#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE GLSLReflectionInput : public ReflectionInputImpl
    {
    public:
        using ClassType = GLSLReflectionInput;
        using ParentType = ReflectionInputImpl;

    public:
        GLSLReflectionInput() noexcept;
        explicit GLSLReflectionInput(const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ReflectionInputSharedPtr Clone() const override;

        NODISCARD std::string GetName() const override;
        void SetName(std::string aName) override;

        NODISCARD GLSLReflectionEnumType GetType() const noexcept override;
        void SetType(GLSLReflectionEnumType aType) noexcept override;

        NODISCARD OpenGLInt GetLocation() const noexcept override;
        void SetLocation(OpenGLInt aLocation) noexcept override;

        NODISCARD OpenGLInt GetArraySize() const noexcept override;
        void SetArraySize(OpenGLInt aArraySize) noexcept override;

        NODISCARD ReferencedBy GetReferencedBy() const noexcept override;
        NODISCARD OpenGLInt GetReferencedBy(int index) const override;
        void SetReferencedBy(int index, OpenGLInt aReferencedBy) override;

        NODISCARD OpenGLInt GetIsPerPatch() const noexcept override;
        void SetIsPerPatch(OpenGLInt aIsPerPatch) noexcept override;

        NODISCARD OpenGLInt GetLocationComponent() const noexcept override;
        void SetLocationComponent(OpenGLInt aLocationComponent) noexcept override;

    private:
        std::string name;
        GLSLReflectionEnumType type;
        OpenGLInt location;
        OpenGLInt arraySize;
        ReferencedBy referencedBy;
        OpenGLInt isPerPatch;
        OpenGLInt locationComponent;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_INPUT_IMPL_H
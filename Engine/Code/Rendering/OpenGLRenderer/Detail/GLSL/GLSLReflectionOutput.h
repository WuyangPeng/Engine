/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/09 16:55)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_OUTPUT_IMPL_H
#define RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_OUTPUT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Shaders/Detail/ReflectionOutputImpl.h"

#include <array>
#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE GLSLReflectionOutput : public ReflectionOutputImpl
    {
    public:
        using ClassType = GLSLReflectionOutput;
        using ParentType = ReflectionOutputImpl;

    public:
        GLSLReflectionOutput() noexcept;
        explicit GLSLReflectionOutput(const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ReflectionOutputSharedPtr Clone() const override;

        NODISCARD std::string GetName() const override;
        void SetName(const std::string& aName) override;

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

        NODISCARD OpenGLInt GetLocationIndex() const noexcept override;
        void SetLocationIndex(OpenGLInt aLocationIndex) noexcept override;

    private:
        std::string name;
        GLSLReflectionEnumType type;
        OpenGLInt location;
        OpenGLInt arraySize;
        ReferencedBy referencedBy;
        OpenGLInt isPerPatch;
        OpenGLInt locationComponent;
        OpenGLInt locationIndex;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_OUTPUT_IMPL_H
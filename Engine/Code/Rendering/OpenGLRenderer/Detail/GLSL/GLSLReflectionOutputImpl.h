///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:21)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_OUTPUT_IMPL_H
#define RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_OUTPUT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/OpenGLUsing.h"

#include <array>
#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE GLSLReflectionOutputImpl
    {
    public:
        using ClassType = GLSLReflectionOutputImpl;
        using OpenGLInt = System::OpenGLInt;
        using ReferencedBy = std::array<OpenGLInt, 6>;
        using GLSLReflectionEnumType = System::GLSLReflectionEnumType;

    public:
        GLSLReflectionOutputImpl() noexcept;
        explicit GLSLReflectionOutputImpl(const std::string& name);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetName() const;
        void SetName(const std::string& aName);

        NODISCARD GLSLReflectionEnumType GetType() const noexcept;
        void SetType(GLSLReflectionEnumType aType) noexcept;

        NODISCARD OpenGLInt GetLocation() const noexcept;
        void SetLocation(OpenGLInt aLocation) noexcept;

        NODISCARD OpenGLInt GetArraySize() const noexcept;
        void SetArraySize(OpenGLInt aArraySize) noexcept;

        NODISCARD ReferencedBy GetReferencedBy() const noexcept;
        NODISCARD OpenGLInt GetReferencedBy(int index) const;
        void SetReferencedBy(int index, OpenGLInt aReferencedBy);

        NODISCARD OpenGLInt GetIsPerPatch() const noexcept;
        void SetIsPerPatch(OpenGLInt aIsPerPatch) noexcept;

        NODISCARD OpenGLInt GetLocationComponent() const noexcept;
        void SetLocationComponent(OpenGLInt aLocationComponent) noexcept;

        NODISCARD OpenGLInt GetLocationIndex() const noexcept;
        void SetLocationIndex(OpenGLInt aLocationIndex) noexcept;

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
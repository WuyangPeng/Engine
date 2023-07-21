///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.1 (2023/07/05 11:29)

#ifndef RENDERING_SHADERS_REFLECTION_OUTPUT_H
#define RENDERING_SHADERS_REFLECTION_OUTPUT_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

#include <string>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(ReflectionOutput, ReflectionOutputImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ReflectionOutput
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ReflectionOutput);

        using OpenGLInt = System::OpenGLInt;
        using ReferencedBy = std::array<OpenGLInt, 6>;
        using GLSLReflectionEnumType = System::GLSLReflectionEnumType;

    public:
        explicit ReflectionOutput(const std::string& name);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetName() const;
        void SetName(const std::string& name);

        NODISCARD GLSLReflectionEnumType GetType() const noexcept;
        void SetType(GLSLReflectionEnumType type) noexcept;

        NODISCARD OpenGLInt GetLocation() const noexcept;
        void SetLocation(OpenGLInt location) noexcept;

        NODISCARD OpenGLInt GetArraySize() const noexcept;
        void SetArraySize(OpenGLInt arraySize) noexcept;

        NODISCARD ReferencedBy GetReferencedBy() const noexcept;
        NODISCARD OpenGLInt GetReferencedBy(int index) const;
        void SetReferencedBy(int index, OpenGLInt referencedBy);

        NODISCARD OpenGLInt GetIsPerPatch() const noexcept;
        void SetIsPerPatch(OpenGLInt isPerPatch) noexcept;

        NODISCARD OpenGLInt GetLocationComponent() const noexcept;
        void SetLocationComponent(OpenGLInt locationComponent) noexcept;

        NODISCARD OpenGLInt GetLocationIndex() const noexcept;
        void SetLocationIndex(OpenGLInt locationIndex) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SHADERS_REFLECTION_OUTPUT_H
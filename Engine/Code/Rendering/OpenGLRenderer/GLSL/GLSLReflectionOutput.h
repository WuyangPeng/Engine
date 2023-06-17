///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:20)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_OUTPUT_H
#define RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_OUTPUT_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

#include <string>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(GLSLReflectionOutput, GLSLReflectionOutputImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE GLSLReflectionOutput
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(GLSLReflectionOutput);
        using OpenGLInt = System::OpenGLInt;
        using ReferencedBy = std::array<OpenGLInt, 6>;
        using GLSLReflectionEnumType = System::GLSLReflectionEnumType;

    public:
        explicit GLSLReflectionOutput(const std::string& name);

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
        PackageType impl;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_OUTPUT_H
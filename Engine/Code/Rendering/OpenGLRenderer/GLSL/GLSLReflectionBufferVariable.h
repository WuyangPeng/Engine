///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:20)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_BUFFER_VARIABLE_H
#define RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_BUFFER_VARIABLE_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

#include <string>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(GLSLReflectionBufferVariable, GLSLReflectionBufferVariableImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE GLSLReflectionBufferVariable
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(GLSLReflectionBufferVariable);
        using OpenGLInt = System::OpenGLInt;
        using ReferencedBy = std::array<OpenGLInt, 6>;
        using GLSLReflectionEnumType = System::GLSLReflectionEnumType;

    public:
        explicit GLSLReflectionBufferVariable(const std::string& name);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetFullName() const;
        void SetFullName(const std::string& aFullName);

        NODISCARD std::string GetName() const;
        void SetName(const std::string& aName);

        NODISCARD GLSLReflectionEnumType GetType() const noexcept;
        void SetType(GLSLReflectionEnumType aType) noexcept;

        NODISCARD OpenGLInt GetArraySize() const noexcept;
        void SetArraySize(OpenGLInt aArraySize) noexcept;

        NODISCARD OpenGLInt GetOffset() const noexcept;
        void SetOffset(OpenGLInt aOffset) noexcept;

        NODISCARD OpenGLInt GetBlockIndex() const noexcept;
        void SetBlockIndex(OpenGLInt aBlockIndex) noexcept;

        NODISCARD OpenGLInt GetArrayStride() const noexcept;
        void SetArrayStride(OpenGLInt aArrayStride) noexcept;

        NODISCARD OpenGLInt GetMatrixStride() const noexcept;
        void SetMatrixStride(OpenGLInt aMatrixStride) noexcept;

        NODISCARD OpenGLInt GetIsRowMajor() const noexcept;
        void SetIsRowMajor(OpenGLInt aIsRowMajor) noexcept;

        NODISCARD OpenGLInt GetTopLevelArraySize() const noexcept;
        void SetTopLevelArraySize(OpenGLInt aTopLevelArraySize) noexcept;

        NODISCARD OpenGLInt GetTopLevelArrayStride() const noexcept;
        void SetTopLevelArrayStride(OpenGLInt aTopLevelArrayStride) noexcept;

        NODISCARD ReferencedBy GetReferencedBy() const noexcept;
        NODISCARD OpenGLInt GetReferencedBy(int index) const;
        void SetReferencedBy(int index, OpenGLInt aReferencedBy);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_BUFFER_VARIABLE_H
///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.3 (2022/10/30 14:31)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_UNIFORM_H
#define RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_UNIFORM_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

#include <string>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(GLSLReflectionUniform, GLSLReflectionUniformImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE GLSLReflectionUniform
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(GLSLReflectionUniform);
        using OpenGLInt = System::OpenGLInt;
        using ReferencedBy = std::array<OpenGLInt, 6>;
        using GLSLReflectionEnumType = System::GLSLReflectionEnumType;

    public:
        explicit GLSLReflectionUniform(const std::string& name);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetFullName() const;
        void SetFullName(const std::string& aFullName);

        NODISCARD std::string GetName() const;
        void SetName(const std::string& aName);

        NODISCARD GLSLReflectionEnumType GetType() const noexcept;
        void SetType(GLSLReflectionEnumType aType) noexcept;

        NODISCARD OpenGLInt GetLocation() const noexcept;
        void SetLocation(OpenGLInt aLocation) noexcept;

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

        NODISCARD OpenGLInt GetAtomicCounterBufferIndex() const noexcept;
        void SetAtomicCounterBufferIndex(OpenGLInt aAtomicCounterBufferIndex) noexcept;

        NODISCARD ReferencedBy GetReferencedBy() const noexcept;
        NODISCARD OpenGLInt GetReferencedBy(int index) const;
        void SetReferencedBy(int index, OpenGLInt aReferencedBy);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_UNIFORM_H
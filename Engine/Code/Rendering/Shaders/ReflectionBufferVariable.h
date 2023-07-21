﻿///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/05 11:29)

#ifndef RENDERING_SHADERS_REFLECTION_BUFFER_VARIABLE_H
#define RENDERING_SHADERS_REFLECTION_BUFFER_VARIABLE_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

#include <string>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(ReflectionBufferVariable, ReflectionBufferVariableImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ReflectionBufferVariable
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ReflectionBufferVariable);

        using OpenGLInt = System::OpenGLInt;
        using ReferencedBy = std::array<OpenGLInt, 6>;
        using GLSLReflectionEnumType = System::GLSLReflectionEnumType;

    public:
        explicit ReflectionBufferVariable(const std::string& name);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetFullName() const;
        void SetFullName(const std::string& fullName);

        NODISCARD std::string GetName() const;
        void SetName(const std::string& name);

        NODISCARD GLSLReflectionEnumType GetType() const noexcept;
        void SetType(GLSLReflectionEnumType type) noexcept;

        NODISCARD OpenGLInt GetArraySize() const noexcept;
        void SetArraySize(OpenGLInt arraySize) noexcept;

        NODISCARD OpenGLInt GetOffset() const noexcept;
        void SetOffset(OpenGLInt offset) noexcept;

        NODISCARD OpenGLInt GetBlockIndex() const noexcept;
        void SetBlockIndex(OpenGLInt blockIndex) noexcept;

        NODISCARD OpenGLInt GetArrayStride() const noexcept;
        void SetArrayStride(OpenGLInt arrayStride) noexcept;

        NODISCARD OpenGLInt GetMatrixStride() const noexcept;
        void SetMatrixStride(OpenGLInt matrixStride) noexcept;

        NODISCARD OpenGLInt GetIsRowMajor() const noexcept;
        void SetIsRowMajor(OpenGLInt isRowMajor) noexcept;

        NODISCARD OpenGLInt GetTopLevelArraySize() const noexcept;
        void SetTopLevelArraySize(OpenGLInt topLevelArraySize) noexcept;

        NODISCARD OpenGLInt GetTopLevelArrayStride() const noexcept;
        void SetTopLevelArrayStride(OpenGLInt topLevelArrayStride) noexcept;

        NODISCARD ReferencedBy GetReferencedBy() const noexcept;
        NODISCARD OpenGLInt GetReferencedBy(int index) const;
        void SetReferencedBy(int index, OpenGLInt referencedBy);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SHADERS_REFLECTION_BUFFER_VARIABLE_H

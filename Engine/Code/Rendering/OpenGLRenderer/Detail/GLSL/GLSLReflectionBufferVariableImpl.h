///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/29 21:54)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_BUFFER_VARIABLE_IMPL_H
#define RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_BUFFER_VARIABLE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/OpenGLUsing.h"

#include <array>
#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE GLSLReflectionBufferVariableImpl
    {
    public:
        using ClassType = GLSLReflectionBufferVariableImpl;
        using OpenGLInt = System::OpenGLInt;
        using ReferencedBy = std::array<OpenGLInt, 6>;
        using GLSLReflectionEnumType = System::GLSLReflectionEnumType;

    public:
        GLSLReflectionBufferVariableImpl() noexcept;
        explicit GLSLReflectionBufferVariableImpl(const std::string& name);

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
        std::string fullName;
        std::string name;
        GLSLReflectionEnumType type;
        OpenGLInt arraySize;
        OpenGLInt offset;
        OpenGLInt blockIndex;
        OpenGLInt arrayStride;
        OpenGLInt matrixStride;
        OpenGLInt isRowMajor;
        OpenGLInt topLevelArraySize;
        OpenGLInt topLevelArrayStride;
        ReferencedBy referencedBy;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_BUFFER_VARIABLE_IMPL_H
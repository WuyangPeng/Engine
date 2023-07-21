///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:21)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_BUFFER_VARIABLE_H
#define RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_BUFFER_VARIABLE_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Shaders/Detail/ReflectionBufferVariableImpl.h"

#include <array>
#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE GLSLReflectionBufferVariable : public ReflectionBufferVariableImpl
    {
    public:
        using ClassType = GLSLReflectionBufferVariable;
        using ParentType = ReflectionBufferVariableImpl;

    public:
        GLSLReflectionBufferVariable() noexcept;
        explicit GLSLReflectionBufferVariable(const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ReflectionBufferVariableSharedPtr Clone() const override;

        NODISCARD std::string GetFullName() const override;
        void SetFullName(const std::string& aFullName) override;

        NODISCARD std::string GetName() const override;
        void SetName(const std::string& aName) override;

        NODISCARD GLSLReflectionEnumType GetType() const noexcept override;
        void SetType(GLSLReflectionEnumType aType) noexcept override;

        NODISCARD OpenGLInt GetArraySize() const noexcept override;
        void SetArraySize(OpenGLInt aArraySize) noexcept override;

        NODISCARD OpenGLInt GetOffset() const noexcept override;
        void SetOffset(OpenGLInt aOffset) noexcept override;

        NODISCARD OpenGLInt GetBlockIndex() const noexcept override;
        void SetBlockIndex(OpenGLInt aBlockIndex) noexcept override;

        NODISCARD OpenGLInt GetArrayStride() const noexcept override;
        void SetArrayStride(OpenGLInt aArrayStride) noexcept override;

        NODISCARD OpenGLInt GetMatrixStride() const noexcept override;
        void SetMatrixStride(OpenGLInt aMatrixStride) noexcept override;

        NODISCARD OpenGLInt GetIsRowMajor() const noexcept override;
        void SetIsRowMajor(OpenGLInt aIsRowMajor) noexcept override;

        NODISCARD OpenGLInt GetTopLevelArraySize() const noexcept override;
        void SetTopLevelArraySize(OpenGLInt aTopLevelArraySize) noexcept override;

        NODISCARD OpenGLInt GetTopLevelArrayStride() const noexcept override;
        void SetTopLevelArrayStride(OpenGLInt aTopLevelArrayStride) noexcept override;

        NODISCARD ReferencedBy GetReferencedBy() const noexcept override;
        NODISCARD OpenGLInt GetReferencedBy(int index) const override;
        void SetReferencedBy(int index, OpenGLInt aReferencedBy) override;

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

#endif  // RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_BUFFER_VARIABLE_H
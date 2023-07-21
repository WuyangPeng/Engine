///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/03 15:25)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_UNIFORM_H
#define RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_UNIFORM_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Shaders/Detail/ReflectionUniformImpl.h"

#include <array>
#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE GLSLReflectionUniform : public ReflectionUniformImpl
    {
    public:
        using ClassType = GLSLReflectionUniform;
        using ParentType = ReflectionUniformImpl;

    public:
        GLSLReflectionUniform() noexcept;
        explicit GLSLReflectionUniform(const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ReflectionUniformSharedPtr Clone() const override;

        NODISCARD std::string GetFullName() const override;
        void SetFullName(const std::string& aFullName) override;

        NODISCARD std::string GetName() const override;
        void SetName(const std::string& aName) override;

        NODISCARD GLSLReflectionEnumType GetType() const noexcept override;
        void SetType(GLSLReflectionEnumType aType) noexcept override;

        NODISCARD OpenGLInt GetLocation() const noexcept override;
        void SetLocation(OpenGLInt aLocation) noexcept override;

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

        NODISCARD OpenGLInt GetAtomicCounterBufferIndex() const noexcept override;
        void SetAtomicCounterBufferIndex(OpenGLInt aAtomicCounterBufferIndex) noexcept override;

        NODISCARD ReferencedBy GetReferencedBy() const noexcept override;
        NODISCARD OpenGLInt GetReferencedBy(int index) const override;
        void SetReferencedBy(int index, OpenGLInt aReferencedBy) override;

    private:
        std::string fullName;
        std::string name;
        GLSLReflectionEnumType type;
        OpenGLInt location;
        OpenGLInt arraySize;
        OpenGLInt offset;
        OpenGLInt blockIndex;
        OpenGLInt arrayStride;
        OpenGLInt matrixStride;
        OpenGLInt isRowMajor;
        OpenGLInt atomicCounterBufferIndex;
        ReferencedBy referencedBy;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_UNIFORM_H
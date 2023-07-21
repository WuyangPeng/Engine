///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/05 11:25)

#ifndef RENDERING_SHADERS_REFLECTION_UNIFORM_IMPL_H
#define RENDERING_SHADERS_REFLECTION_UNIFORM_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Shaders/ShadersInternalFwd.h"

#include <memory>
#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ReflectionUniformImpl
    {
    public:
        using ClassType = ReflectionUniformImpl;
        using FactoryType = ReflectionUniformFactory;

        using OpenGLInt = System::OpenGLInt;
        using ReferencedBy = std::array<OpenGLInt, 6>;
        using GLSLReflectionEnumType = System::GLSLReflectionEnumType;
        using ReflectionUniformSharedPtr = std::shared_ptr<ReflectionUniformImpl>;

    public:
        ReflectionUniformImpl() noexcept;
        virtual ~ReflectionUniformImpl() noexcept = default;
        ReflectionUniformImpl(const ReflectionUniformImpl& rhs) noexcept = default;
        ReflectionUniformImpl& operator=(const ReflectionUniformImpl& rhs) noexcept = default;
        ReflectionUniformImpl(ReflectionUniformImpl&& rhs) noexcept = default;
        ReflectionUniformImpl& operator=(ReflectionUniformImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual ReflectionUniformSharedPtr Clone() const = 0;

        NODISCARD virtual std::string GetFullName() const = 0;
        virtual void SetFullName(const std::string& aFullName) = 0;

        NODISCARD virtual std::string GetName() const = 0;
        virtual void SetName(const std::string& aName) = 0;

        NODISCARD virtual GLSLReflectionEnumType GetType() const noexcept = 0;
        virtual void SetType(GLSLReflectionEnumType aType) noexcept = 0;

        NODISCARD virtual OpenGLInt GetLocation() const noexcept = 0;
        virtual void SetLocation(OpenGLInt aLocation) noexcept = 0;

        NODISCARD virtual OpenGLInt GetArraySize() const noexcept = 0;
        virtual void SetArraySize(OpenGLInt aArraySize) noexcept = 0;

        NODISCARD virtual OpenGLInt GetOffset() const noexcept = 0;
        virtual void SetOffset(OpenGLInt aOffset) noexcept = 0;

        NODISCARD virtual OpenGLInt GetBlockIndex() const noexcept = 0;
        virtual void SetBlockIndex(OpenGLInt aBlockIndex) noexcept = 0;

        NODISCARD virtual OpenGLInt GetArrayStride() const noexcept = 0;
        virtual void SetArrayStride(OpenGLInt aArrayStride) noexcept = 0;

        NODISCARD virtual OpenGLInt GetMatrixStride() const noexcept = 0;
        virtual void SetMatrixStride(OpenGLInt aMatrixStride) noexcept = 0;

        NODISCARD virtual OpenGLInt GetIsRowMajor() const noexcept = 0;
        virtual void SetIsRowMajor(OpenGLInt aIsRowMajor) noexcept = 0;

        NODISCARD virtual OpenGLInt GetAtomicCounterBufferIndex() const noexcept = 0;
        virtual void SetAtomicCounterBufferIndex(OpenGLInt aAtomicCounterBufferIndex) noexcept = 0;

        NODISCARD virtual ReferencedBy GetReferencedBy() const noexcept = 0;
        NODISCARD virtual OpenGLInt GetReferencedBy(int index) const = 0;
        virtual void SetReferencedBy(int index, OpenGLInt aReferencedBy) = 0;
    };
}

#endif  // RENDERING_SHADERS_REFLECTION_UNIFORM_IMPL_H

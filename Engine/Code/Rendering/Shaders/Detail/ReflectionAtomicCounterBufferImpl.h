///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/05 11:19)

#ifndef RENDERING_SHADERS_REFLECTION_ATOMIC_COUNTER_BUFFER_IMPL_H
#define RENDERING_SHADERS_REFLECTION_ATOMIC_COUNTER_BUFFER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Shaders/ShadersInternalFwd.h"

#include <array>
#include <memory>
#include <string>
#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ReflectionAtomicCounterBufferImpl
    {
    public:
        using ClassType = ReflectionAtomicCounterBufferImpl;
        using FactoryType = ReflectionAtomicCounterBufferFactory;

        using OpenGLInt = System::OpenGLInt;
        using ReferencedBy = std::array<OpenGLInt, 6>;
        using ActiveVariables = std::vector<OpenGLInt>;
        using ReflectionAtomicCounterBufferSharedPtr = std::shared_ptr<ReflectionAtomicCounterBufferImpl>;

    public:
        ReflectionAtomicCounterBufferImpl() noexcept;
        virtual ~ReflectionAtomicCounterBufferImpl() noexcept = default;
        ReflectionAtomicCounterBufferImpl(const ReflectionAtomicCounterBufferImpl& rhs) noexcept = default;
        ReflectionAtomicCounterBufferImpl& operator=(const ReflectionAtomicCounterBufferImpl& rhs) noexcept = default;
        ReflectionAtomicCounterBufferImpl(ReflectionAtomicCounterBufferImpl&& rhs) noexcept = default;
        ReflectionAtomicCounterBufferImpl& operator=(ReflectionAtomicCounterBufferImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual ReflectionAtomicCounterBufferSharedPtr Clone() const = 0;

        NODISCARD virtual OpenGLInt GetBufferBinding() const noexcept = 0;
        virtual void SetBufferBinding(OpenGLInt aBufferBinding) noexcept = 0;

        NODISCARD virtual OpenGLInt GetBufferDataSize() const noexcept = 0;
        virtual void SetBufferDataSize(OpenGLInt aBufferDataSize) noexcept = 0;

        NODISCARD virtual ReferencedBy GetReferencedBy() const noexcept = 0;
        NODISCARD virtual OpenGLInt GetReferencedBy(int index) const = 0;
        virtual void SetReferencedBy(int index, OpenGLInt aReferencedBy) = 0;

        NODISCARD virtual int GetActiveVariablesCount() const = 0;
        NODISCARD virtual OpenGLInt GetActiveVariables(int index) const = 0;
        virtual void SetActiveVariables(int index, OpenGLInt aActiveVariables) = 0;
        virtual void SetActiveVariables(const ActiveVariables& aActiveVariables) = 0;
    };
}

#endif  // RENDERING_SHADERS_REFLECTION_ATOMIC_COUNTER_BUFFER_IMPL_H
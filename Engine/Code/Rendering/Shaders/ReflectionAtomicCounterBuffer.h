///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/05 11:29)

#ifndef RENDERING_SHADERS_REFLECTION_ATOMIC_COUNTER_BUFFER_H
#define RENDERING_SHADERS_REFLECTION_ATOMIC_COUNTER_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

#include <vector>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(ReflectionAtomicCounterBuffer, ReflectionAtomicCounterBufferImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ReflectionAtomicCounterBuffer
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ReflectionAtomicCounterBuffer);

        using OpenGLInt = System::OpenGLInt;
        using ReferencedBy = std::array<OpenGLInt, 6>;
        using ActiveVariables = std::vector<OpenGLInt>;

    public:
        explicit ReflectionAtomicCounterBuffer(OpenGLInt bufferBinding);

        CLASS_INVARIANT_DECLARE;

        NODISCARD OpenGLInt GetBufferBinding() const noexcept;
        void SetBufferBinding(OpenGLInt bufferBinding) noexcept;

        NODISCARD OpenGLInt GetBufferDataSize() const noexcept;
        void SetBufferDataSize(OpenGLInt bufferDataSize) noexcept;

        NODISCARD ReferencedBy GetReferencedBy() const noexcept;
        NODISCARD OpenGLInt GetReferencedBy(int index) const;
        void SetReferencedBy(int index, OpenGLInt referencedBy);

        NODISCARD int GetActiveVariablesCount() const;
        NODISCARD OpenGLInt GetActiveVariables(int index) const;
        void SetActiveVariables(int index, OpenGLInt activeVariables);
        void SetActiveVariables(const ActiveVariables& activeVariables);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SHADERS_REFLECTION_ATOMIC_COUNTER_BUFFER_H

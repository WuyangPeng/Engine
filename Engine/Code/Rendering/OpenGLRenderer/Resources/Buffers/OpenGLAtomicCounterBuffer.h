/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/08 14:51)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_ATOMIC_COUNTER_BUFFER_H
#define RENDERING_OPENGL_RENDERER_OPENGL_ATOMIC_COUNTER_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "OpenGLBuffer.h"
#include "Rendering/Resources/Buffers/RawBuffer.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLAtomicCounterBuffer : public OpenGLBuffer
    {
    public:
        using ClassType = OpenGLAtomicCounterBuffer;
        using ParentType = OpenGLBuffer;

        using OpenGLInt = System::OpenGLInt;

    public:
        OpenGLAtomicCounterBuffer(const RawBufferSharedPtr& buffer, const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void AttachToUnit(OpenGLInt atomicCounterBufferUnit) noexcept;

        NODISCARD ConstRawBufferSharedPtr GetRawBuffer() const;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_ATOMIC_COUNTER_BUFFER_H
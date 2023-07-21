///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/05 11:18)

#ifndef RENDERING_SHADERS_REFLECTION_ATOMIC_COUNTER_BUFFER_FACTORY_H
#define RENDERING_SHADERS_REFLECTION_ATOMIC_COUNTER_BUFFER_FACTORY_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Shaders/ShadersInternalFwd.h"

#include <memory>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ReflectionAtomicCounterBufferFactory
    {
    public:
        using ClassType = ReflectionAtomicCounterBufferFactory;

        using OpenGLInt = System::OpenGLInt;
        using ReflectionAtomicCounterBufferSharedPtr = std::shared_ptr<ReflectionAtomicCounterBufferImpl>;

    public:
        NODISCARD static ReflectionAtomicCounterBufferSharedPtr Create(OpenGLInt bufferBinding);
        NODISCARD static ReflectionAtomicCounterBufferSharedPtr Create();

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // RENDERING_SHADERS_REFLECTION_ATOMIC_COUNTER_BUFFER_FACTORY_H

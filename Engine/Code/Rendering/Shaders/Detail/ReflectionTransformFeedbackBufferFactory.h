﻿///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/05 11:24)

#ifndef RENDERING_SHADERS_REFLECTION_TRANSFORM_FEEDBACK_BUFFER_FACTORY_H
#define RENDERING_SHADERS_REFLECTION_TRANSFORM_FEEDBACK_BUFFER_FACTORY_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Shaders/ShadersInternalFwd.h"

#include <memory>
#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ReflectionTransformFeedbackBufferFactory
    {
    public:
        using ClassType = ReflectionTransformFeedbackBufferFactory;
        using ReflectionTransformFeedbackBufferSharedPtr = std::shared_ptr<ReflectionTransformFeedbackBufferImpl>;

        using OpenGLInt = System::OpenGLInt;

    public:
        NODISCARD static ReflectionTransformFeedbackBufferSharedPtr Create(OpenGLInt bufferBinding);
        NODISCARD static ReflectionTransformFeedbackBufferSharedPtr Create();

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // RENDERING_SHADERS_REFLECTION_TRANSFORM_FEEDBACK_BUFFER_FACTORY_H
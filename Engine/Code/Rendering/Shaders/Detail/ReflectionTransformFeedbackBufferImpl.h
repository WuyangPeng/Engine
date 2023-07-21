///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/05 11:24)

#ifndef RENDERING_SHADERS_REFLECTION_TRANSFORM_FEEDBACK_BUFFER_IMPL_H
#define RENDERING_SHADERS_REFLECTION_TRANSFORM_FEEDBACK_BUFFER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Shaders/ShadersInternalFwd.h"

#include <memory>
#include <string>
#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ReflectionTransformFeedbackBufferImpl
    {
    public:
        using ClassType = ReflectionTransformFeedbackBufferImpl;
        using FactoryType = ReflectionTransformFeedbackBufferFactory;

        using OpenGLInt = System::OpenGLInt;
        using ActiveVariables = std::vector<OpenGLInt>;
        using ReflectionTransformFeedbackBufferSharedPtr = std::shared_ptr<ReflectionTransformFeedbackBufferImpl>;

    public:
        ReflectionTransformFeedbackBufferImpl() noexcept;
        virtual ~ReflectionTransformFeedbackBufferImpl() noexcept = default;
        ReflectionTransformFeedbackBufferImpl(const ReflectionTransformFeedbackBufferImpl& rhs) noexcept = default;
        ReflectionTransformFeedbackBufferImpl& operator=(const ReflectionTransformFeedbackBufferImpl& rhs) noexcept = default;
        ReflectionTransformFeedbackBufferImpl(ReflectionTransformFeedbackBufferImpl&& rhs) noexcept = default;
        ReflectionTransformFeedbackBufferImpl& operator=(ReflectionTransformFeedbackBufferImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual ReflectionTransformFeedbackBufferSharedPtr Clone() const = 0;

        NODISCARD virtual OpenGLInt GetBufferBinding() const noexcept = 0;
        virtual void SetBufferBinding(OpenGLInt aBufferBinding) noexcept = 0;

        NODISCARD virtual OpenGLInt GetTransformFeedbackBufferStride() const noexcept = 0;
        virtual void SetTransformFeedbackBufferStride(OpenGLInt aTransformFeedbackBufferStride) noexcept = 0;

        NODISCARD virtual OpenGLInt GetActiveVariables(int index) const = 0;
        virtual void SetActiveVariables(int index, OpenGLInt aActiveVariables) = 0;
        virtual void SetActiveVariables(const ActiveVariables& aActiveVariables) = 0;
    };
}

#endif  // RENDERING_SHADERS_REFLECTION_TRANSFORM_FEEDBACK_BUFFER_IMPL_H
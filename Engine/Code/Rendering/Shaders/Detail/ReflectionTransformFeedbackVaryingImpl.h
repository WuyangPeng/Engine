///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/05 11:25)

#ifndef RENDERING_SHADERS_REFLECTION_TRANSFORM_FEEDBACK_VARYING_IMPL_H
#define RENDERING_SHADERS_REFLECTION_TRANSFORM_FEEDBACK_VARYING_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Shaders/ShadersInternalFwd.h"

#include <array>
#include <memory>
#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ReflectionTransformFeedbackVaryingImpl
    {
    public:
        using ClassType = ReflectionTransformFeedbackVaryingImpl;
        using FactoryType = ReflectionTransformFeedbackVaryingFactory;

        using OpenGLInt = System::OpenGLInt;
        using ReflectionTransformFeedbackVaryingSharedPtr = std::shared_ptr<ReflectionTransformFeedbackVaryingImpl>;

    public:
        ReflectionTransformFeedbackVaryingImpl() noexcept;
        virtual ~ReflectionTransformFeedbackVaryingImpl() noexcept = default;
        ReflectionTransformFeedbackVaryingImpl(const ReflectionTransformFeedbackVaryingImpl& rhs) noexcept = default;
        ReflectionTransformFeedbackVaryingImpl& operator=(const ReflectionTransformFeedbackVaryingImpl& rhs) noexcept = default;
        ReflectionTransformFeedbackVaryingImpl(ReflectionTransformFeedbackVaryingImpl&& rhs) noexcept = default;
        ReflectionTransformFeedbackVaryingImpl& operator=(ReflectionTransformFeedbackVaryingImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual ReflectionTransformFeedbackVaryingSharedPtr Clone() const = 0;

        NODISCARD virtual std::string GetName() const = 0;
        virtual void SetName(const std::string& aName) = 0;
        NODISCARD virtual OpenGLInt GetType() const noexcept = 0;
        virtual void SetType(OpenGLInt aType) noexcept = 0;
        NODISCARD virtual OpenGLInt GetArraySize() const noexcept = 0;
        virtual void SetArraySize(OpenGLInt aArraySize) noexcept = 0;
        NODISCARD virtual OpenGLInt GetOffset() const noexcept = 0;
        virtual void SetOffset(OpenGLInt aOffset) noexcept = 0;
        NODISCARD virtual OpenGLInt GetTransformFeedbackBufferIndex() const noexcept = 0;
        virtual void SetTransformFeedbackBufferIndex(OpenGLInt aTransformFeedbackBufferIndex) noexcept = 0;
    };
}

#endif  // RENDERING_SHADERS_REFLECTION_TRANSFORM_FEEDBACK_VARYING_IMPL_H
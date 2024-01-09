/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/09 16:55)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_TRANSFORM_FEEDBACK_BUFFER_IMPL_H
#define RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_TRANSFORM_FEEDBACK_BUFFER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Shaders/Detail/ReflectionTransformFeedbackBufferImpl.h"

#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE GLSLReflectionTransformFeedbackBuffer : public ReflectionTransformFeedbackBufferImpl
    {
    public:
        using ClassType = GLSLReflectionTransformFeedbackBuffer;
        using ParentType = ReflectionTransformFeedbackBufferImpl;

        using OpenGLInt = System::OpenGLInt;
        using ActiveVariables = std::vector<OpenGLInt>;

    public:
        GLSLReflectionTransformFeedbackBuffer() noexcept;
        explicit GLSLReflectionTransformFeedbackBuffer(OpenGLInt aBufferBinding) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ReflectionTransformFeedbackBufferSharedPtr Clone() const override;

        NODISCARD OpenGLInt GetBufferBinding() const noexcept override;
        void SetBufferBinding(OpenGLInt aBufferBinding) noexcept override;

        NODISCARD OpenGLInt GetTransformFeedbackBufferStride() const noexcept override;
        void SetTransformFeedbackBufferStride(OpenGLInt aTransformFeedbackBufferStride) noexcept override;

        NODISCARD OpenGLInt GetActiveVariables(int index) const override;
        void SetActiveVariables(int index, OpenGLInt aActiveVariables) override;
        void SetActiveVariables(const ActiveVariables& aActiveVariables) override;

    private:
        OpenGLInt bufferBinding;
        OpenGLInt transformFeedbackBufferStride;
        ActiveVariables activeVariables;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_TRANSFORM_FEEDBACK_BUFFER_IMPL_H
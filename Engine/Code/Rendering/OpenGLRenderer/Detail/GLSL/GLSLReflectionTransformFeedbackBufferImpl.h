///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.3 (2022/10/29 21:54)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_TRANSFORM_FEEDBACK_BUFFER_IMPL_H
#define RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_TRANSFORM_FEEDBACK_BUFFER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"

#include <string>
#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE GLSLReflectionTransformFeedbackBufferImpl
    {
    public:
        using ClassType = GLSLReflectionTransformFeedbackBufferImpl;
        using OpenGLInt = System::OpenGLInt;
        using ActiveVariables = std::vector<OpenGLInt>;

    public:
        GLSLReflectionTransformFeedbackBufferImpl() noexcept;
        explicit GLSLReflectionTransformFeedbackBufferImpl(OpenGLInt aBufferBinding) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD OpenGLInt GetBufferBinding() const noexcept;
        void SetBufferBinding(OpenGLInt aBufferBinding) noexcept;

        NODISCARD OpenGLInt GetTransformFeedbackBufferStride() const noexcept;
        void SetTransformFeedbackBufferStride(OpenGLInt aTransformFeedbackBufferStride) noexcept;

        NODISCARD OpenGLInt GetActiveVariables(int index) const;
        void SetActiveVariables(int index, OpenGLInt aActiveVariables);
        void SetActiveVariables(const ActiveVariables& aActiveVariables);

    private:
        OpenGLInt bufferBinding;
        OpenGLInt transformFeedbackBufferStride;
        ActiveVariables activeVariables;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_TRANSFORM_FEEDBACK_BUFFER_IMPL_H
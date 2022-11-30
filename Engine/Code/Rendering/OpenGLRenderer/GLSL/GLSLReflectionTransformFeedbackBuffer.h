///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/31 14:31)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_TRANSFORM_FEEDBACK_BUFFER_H
#define RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_TRANSFORM_FEEDBACK_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

#include <vector>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(GLSLReflectionTransformFeedbackBuffer, GLSLReflectionTransformFeedbackBufferImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE GLSLReflectionTransformFeedbackBuffer
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(GLSLReflectionTransformFeedbackBuffer);
        using OpenGLInt = System::OpenGLInt;
        using ActiveVariables = std::vector<OpenGLInt>;

    public:
        explicit GLSLReflectionTransformFeedbackBuffer(OpenGLInt aBufferBinding);

        CLASS_INVARIANT_DECLARE;

        NODISCARD OpenGLInt GetBufferBinding() const noexcept;
        void SetBufferBinding(OpenGLInt aBufferBinding) noexcept;

        NODISCARD OpenGLInt GetTransformFeedbackBufferStride() const noexcept;
        void SetTransformFeedbackBufferStride(OpenGLInt aTransformFeedbackBufferStride) noexcept;

        NODISCARD OpenGLInt GetActiveVariables(int index) const;
        void SetActiveVariables(int index, OpenGLInt aActiveVariables);
        void SetActiveVariables(const ActiveVariables& aActiveVariables);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_TRANSFORM_FEEDBACK_BUFFER_H
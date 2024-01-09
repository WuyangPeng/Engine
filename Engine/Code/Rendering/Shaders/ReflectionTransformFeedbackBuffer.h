/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 15:04)

#ifndef RENDERING_SHADERS_REFLECTION_TRANSFORM_FEEDBACK_BUFFER_H
#define RENDERING_SHADERS_REFLECTION_TRANSFORM_FEEDBACK_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

#include <vector>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(ReflectionTransformFeedbackBuffer, ReflectionTransformFeedbackBufferImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ReflectionTransformFeedbackBuffer
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ReflectionTransformFeedbackBuffer);

        using OpenGLInt = System::OpenGLInt;
        using ActiveVariables = std::vector<OpenGLInt>;

    public:
        explicit ReflectionTransformFeedbackBuffer(OpenGLInt bufferBinding);

        CLASS_INVARIANT_DECLARE;

        NODISCARD OpenGLInt GetBufferBinding() const noexcept;
        void SetBufferBinding(OpenGLInt bufferBinding) noexcept;

        NODISCARD OpenGLInt GetTransformFeedbackBufferStride() const noexcept;
        void SetTransformFeedbackBufferStride(OpenGLInt transformFeedbackBufferStride) noexcept;

        NODISCARD OpenGLInt GetActiveVariables(int index) const;
        void SetActiveVariables(int index, OpenGLInt activeVariables);
        void SetActiveVariables(const ActiveVariables& activeVariables);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SHADERS_REFLECTION_TRANSFORM_FEEDBACK_BUFFER_H
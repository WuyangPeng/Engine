///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/05 11:33)

#ifndef RENDERING_SHADERS_REFLECTION_TRANSFORM_FEEDBACK_VARYING_H
#define RENDERING_SHADERS_REFLECTION_TRANSFORM_FEEDBACK_VARYING_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

#include <string>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(ReflectionTransformFeedbackVarying, ReflectionTransformFeedbackVaryingImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ReflectionTransformFeedbackVarying
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ReflectionTransformFeedbackVarying);
        using OpenGLInt = System::OpenGLInt;

    public:
        explicit ReflectionTransformFeedbackVarying(const std::string& name);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetName() const;
        void SetName(const std::string& name);
        NODISCARD OpenGLInt GetType() const noexcept;
        void SetType(OpenGLInt type) noexcept;
        NODISCARD OpenGLInt GetArraySize() const noexcept;
        void SetArraySize(OpenGLInt arraySize) noexcept;
        NODISCARD OpenGLInt GetOffset() const noexcept;
        void SetOffset(OpenGLInt offset) noexcept;
        NODISCARD OpenGLInt GetTransformFeedbackBufferIndex() const noexcept;
        void SetTransformFeedbackBufferIndex(OpenGLInt transformFeedbackBufferIndex) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SHADERS_REFLECTION_TRANSFORM_FEEDBACK_VARYING_H
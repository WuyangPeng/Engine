///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.3 (2022/10/29 21:54)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_TRANSFORM_FEEDBACK_VARYING_H
#define RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_TRANSFORM_FEEDBACK_VARYING_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

#include <string>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(GLSLReflectionTransformFeedbackVarying, GLSLReflectionTransformFeedbackVaryingImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE GLSLReflectionTransformFeedbackVarying
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(GLSLReflectionTransformFeedbackVarying);
        using OpenGLInt = System::OpenGLInt;

    public:
        explicit GLSLReflectionTransformFeedbackVarying(const std::string& name);

        CLASS_INVARIANT_DECLARE;

        std::string GetName() const;
        void SetName(const std::string& aName);
        OpenGLInt GetType() const noexcept;
        void SetType(OpenGLInt aType) noexcept;
        OpenGLInt GetArraySize() const noexcept;
        void SetArraySize(OpenGLInt aArraySize) noexcept;
        OpenGLInt GetOffset() const noexcept;
        void SetOffset(OpenGLInt aOffset) noexcept;
        OpenGLInt GetTransformFeedbackBufferIndex() const noexcept;
        void SetTransformFeedbackBufferIndex(OpenGLInt aTransformFeedbackBufferIndex) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_TRANSFORM_FEEDBACK_VARYING_H
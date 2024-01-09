/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/09 16:55)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_TRANSFORM_FEEDBACK_VARYING_IMPL_H
#define RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_TRANSFORM_FEEDBACK_VARYING_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Shaders/Detail/ReflectionTransformFeedbackVaryingImpl.h"

#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE GLSLReflectionTransformFeedbackVarying : public ReflectionTransformFeedbackVaryingImpl
    {
    public:
        using ClassType = GLSLReflectionTransformFeedbackVarying;
        using ParentType = ReflectionTransformFeedbackVaryingImpl;

        using OpenGLInt = System::OpenGLInt;

    public:
        GLSLReflectionTransformFeedbackVarying() noexcept;
        explicit GLSLReflectionTransformFeedbackVarying(const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ReflectionTransformFeedbackVaryingSharedPtr Clone() const override;

        std::string GetName() const override;
        void SetName(const std::string& aName) override;
        OpenGLInt GetType() const noexcept override;
        void SetType(OpenGLInt aType) noexcept override;
        OpenGLInt GetArraySize() const noexcept override;
        void SetArraySize(OpenGLInt aArraySize) noexcept override;
        OpenGLInt GetOffset() const noexcept override;
        void SetOffset(OpenGLInt aOffset) noexcept override;
        OpenGLInt GetTransformFeedbackBufferIndex() const noexcept override;
        void SetTransformFeedbackBufferIndex(OpenGLInt aTransformFeedbackBufferIndex) noexcept override;

    private:
        std::string name;
        OpenGLInt type;
        OpenGLInt arraySize;
        OpenGLInt offset;
        OpenGLInt transformFeedbackBufferIndex;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_TRANSFORM_FEEDBACK_VARYING_IMPL_H
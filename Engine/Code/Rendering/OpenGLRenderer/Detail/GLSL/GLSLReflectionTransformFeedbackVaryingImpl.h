///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/29 21:54)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_TRANSFORM_FEEDBACK_VARYING_IMPL_H
#define RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_TRANSFORM_FEEDBACK_VARYING_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"

#include <array>
#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE GLSLReflectionTransformFeedbackVaryingImpl
    {
    public:
        using ClassType = GLSLReflectionTransformFeedbackVaryingImpl;
        using OpenGLInt = System::OpenGLInt;

    public:
        GLSLReflectionTransformFeedbackVaryingImpl() noexcept;
        explicit GLSLReflectionTransformFeedbackVaryingImpl(const std::string& name);

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
        std::string name;
        OpenGLInt type;
        OpenGLInt arraySize;
        OpenGLInt offset;
        OpenGLInt transformFeedbackBufferIndex;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_TRANSFORM_FEEDBACK_VARYING_IMPL_H
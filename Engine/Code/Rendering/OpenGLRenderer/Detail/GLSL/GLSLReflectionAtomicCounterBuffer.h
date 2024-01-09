/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2024/01/09 16:54)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_ATOMIC_COUNTER_BUFFER_H
#define RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_ATOMIC_COUNTER_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Shaders/Detail/ReflectionAtomicCounterBufferImpl.h"

#include <array>
#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE GLSLReflectionAtomicCounterBuffer : public ReflectionAtomicCounterBufferImpl
    {
    public:
        using ClassType = GLSLReflectionAtomicCounterBuffer;
        using ParentType = ReflectionAtomicCounterBufferImpl;

    public:
        GLSLReflectionAtomicCounterBuffer() noexcept;
        explicit GLSLReflectionAtomicCounterBuffer(OpenGLInt bufferBinding) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ReflectionAtomicCounterBufferSharedPtr Clone() const override;

        NODISCARD OpenGLInt GetBufferBinding() const noexcept override;
        void SetBufferBinding(OpenGLInt aBufferBinding) noexcept override;

        NODISCARD OpenGLInt GetBufferDataSize() const noexcept override;
        void SetBufferDataSize(OpenGLInt aBufferDataSize) noexcept override;

        NODISCARD ReferencedBy GetReferencedBy() const noexcept override;
        NODISCARD OpenGLInt GetReferencedBy(int index) const override;
        void SetReferencedBy(int index, OpenGLInt aReferencedBy) override;

        NODISCARD int GetActiveVariablesCount() const override;
        NODISCARD OpenGLInt GetActiveVariables(int index) const override;
        void SetActiveVariables(int index, OpenGLInt aActiveVariables) override;
        void SetActiveVariables(const ActiveVariables& aActiveVariables) override;

    private:
        OpenGLInt bufferBinding;
        OpenGLInt bufferDataSize;
        ReferencedBy referencedBy;
        ActiveVariables activeVariables;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_ATOMIC_COUNTER_BUFFER_H
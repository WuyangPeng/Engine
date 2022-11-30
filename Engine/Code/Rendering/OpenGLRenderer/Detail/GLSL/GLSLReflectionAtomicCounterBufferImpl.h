///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.3 (2022/10/30 15:25)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_ATOMIC_COUNTER_BUFFER_IMPL_H
#define RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_ATOMIC_COUNTER_BUFFER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"

#include <array>
#include <string>
#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE GLSLReflectionAtomicCounterBufferImpl
    {
    public:
        using ClassType = GLSLReflectionAtomicCounterBufferImpl;
        using OpenGLInt = System::OpenGLInt;
        using ReferencedBy = std::array<OpenGLInt, 6>;
        using ActiveVariables = std::vector<OpenGLInt>;

    public:
        GLSLReflectionAtomicCounterBufferImpl() noexcept;
        explicit GLSLReflectionAtomicCounterBufferImpl(OpenGLInt bufferBinding) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD OpenGLInt GetBufferBinding() const noexcept;
        void SetBufferBinding(OpenGLInt aBufferBinding) noexcept;

        NODISCARD OpenGLInt GetBufferDataSize() const noexcept;
        void SetBufferDataSize(OpenGLInt aBufferDataSize) noexcept;

        NODISCARD ReferencedBy GetReferencedBy() const noexcept;
        NODISCARD OpenGLInt GetReferencedBy(int index) const;
        void SetReferencedBy(int index, OpenGLInt aReferencedBy);

        NODISCARD int GetActiveVariablesCount() const;
        NODISCARD OpenGLInt GetActiveVariables(int index) const;
        void SetActiveVariables(int index, OpenGLInt aActiveVariables);
        void SetActiveVariables(const ActiveVariables& aActiveVariables);

    private:
        OpenGLInt bufferBinding;
        OpenGLInt bufferDataSize;
        ReferencedBy referencedBy;
        ActiveVariables activeVariables;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_ATOMIC_COUNTER_BUFFER_IMPL_H
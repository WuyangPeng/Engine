/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 15:00)

#ifndef RENDERING_SHADERS_REFLECTION_IMPL_H
#define RENDERING_SHADERS_REFLECTION_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Shaders/ReflectionAtomicCounterBuffer.h"
#include "Rendering/Shaders/ReflectionBufferVariable.h"
#include "Rendering/Shaders/ReflectionDataBlock.h"
#include "Rendering/Shaders/ReflectionInput.h"
#include "Rendering/Shaders/ReflectionOutput.h"
#include "Rendering/Shaders/ReflectionSubroutineUniform.h"
#include "Rendering/Shaders/ReflectionTransformFeedbackBuffer.h"
#include "Rendering/Shaders/ReflectionTransformFeedbackVarying.h"
#include "Rendering/Shaders/ReflectionUniform.h"
#include "Rendering/Shaders/ShadersInternalFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ReflectionImpl
    {
    public:
        using ClassType = ReflectionImpl;
        using FactoryType = ReflectionFactory;

        using OpenGLInt = System::OpenGLInt;
        using OpenGLUInt = System::OpenGLUInt;
        using InputContainer = std::vector<ReflectionInput>;
        using OutputContainer = std::vector<ReflectionOutput>;
        using UniformContainer = std::vector<ReflectionUniform>;
        using DataBlockContainer = std::vector<ReflectionDataBlock>;
        using BufferVariableContainer = std::vector<ReflectionBufferVariable>;
        using AtomicCounterBufferContainer = std::vector<ReflectionAtomicCounterBuffer>;
        using SubroutineUniformContainer = std::vector<ReflectionSubroutineUniform>;
        using TransformFeedbackVaryingContainer = std::vector<ReflectionTransformFeedbackVarying>;
        using TransformFeedbackBufferContainer = std::vector<ReflectionTransformFeedbackBuffer>;
        using NumThreads = std::array<OpenGLInt, 3>;
        using ReflectionSharedPtr = std::shared_ptr<ReflectionImpl>;

    public:
        ReflectionImpl() noexcept;
        virtual ~ReflectionImpl() noexcept = default;
        ReflectionImpl(const ReflectionImpl& rhs) noexcept = default;
        ReflectionImpl& operator=(const ReflectionImpl& rhs) noexcept = default;
        ReflectionImpl(ReflectionImpl&& rhs) noexcept = default;
        ReflectionImpl& operator=(ReflectionImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual ReflectionSharedPtr Clone() const = 0;

        NODISCARD virtual OpenGLUInt GetProgramHandle() const noexcept = 0;

        NODISCARD virtual InputContainer GetInputs() const = 0;
        NODISCARD virtual OutputContainer GetOutputs() const = 0;
        NODISCARD virtual UniformContainer GetUniforms() const = 0;
        NODISCARD virtual DataBlockContainer GetUniformBlocks() const = 0;
        NODISCARD virtual BufferVariableContainer GetBufferVariables() const = 0;
        NODISCARD virtual DataBlockContainer GetBufferBlocks() const = 0;
        NODISCARD virtual AtomicCounterBufferContainer GetAtomicCounterBuffers() const = 0;
        NODISCARD virtual NumThreads GetComputeShaderWorkGroupSize() const noexcept = 0;

        virtual void Print(std::ofstream& output) const = 0;
    };
}

#endif  // RENDERING_SHADERS_REFLECTION_IMPL_H
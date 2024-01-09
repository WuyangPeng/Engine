/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 15:04)

#ifndef RENDERING_SHADERS_REFLECTION_H
#define RENDERING_SHADERS_REFLECTION_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Rendering/OpenGLRenderer/InputLayout/OpenGLInputLayout.h"
#include "Rendering/Shaders/ShadersFwd.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(Reflection, ReflectionImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Reflection
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(Reflection);

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
        using ResultsType = std::vector<OpenGLInt>;

    public:
        NODISCARD static Reflection Create();
        explicit Reflection(OpenGLUInt handle);

        CLASS_INVARIANT_DECLARE;

        NODISCARD OpenGLUInt GetProgramHandle() const noexcept;

        NODISCARD InputContainer GetInputs() const;
        NODISCARD OutputContainer GetOutputs() const;
        NODISCARD UniformContainer GetUniforms() const;
        NODISCARD DataBlockContainer GetUniformBlocks() const;
        NODISCARD BufferVariableContainer GetBufferVariables() const;
        NODISCARD DataBlockContainer GetBufferBlocks() const;
        NODISCARD AtomicCounterBufferContainer GetAtomicCounterBuffers() const;
        NODISCARD NumThreads GetComputeShaderWorkGroupSize() const noexcept;

        void Print(std::ofstream& output) const;

    private:
        explicit Reflection(CoreTools::DisableNotThrow disableNotThrow);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SHADERS_REFLECTION_H
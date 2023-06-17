///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:20)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_H
#define RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "Rendering/OpenGLRenderer/GLSL/GLSLReflectionAtomicCounterBuffer.h"
#include "Rendering/OpenGLRenderer/GLSL/GLSLReflectionBufferVariable.h"
#include "Rendering/OpenGLRenderer/GLSL/GLSLReflectionDataBlock.h"
#include "Rendering/OpenGLRenderer/GLSL/GLSLReflectionInput.h"
#include "Rendering/OpenGLRenderer/GLSL/GLSLReflectionOutput.h"
#include "Rendering/OpenGLRenderer/GLSL/GLSLReflectionSubroutineUniform.h"
#include "Rendering/OpenGLRenderer/GLSL/GLSLReflectionTransformFeedbackBuffer.h"
#include "Rendering/OpenGLRenderer/GLSL/GLSLReflectionTransformFeedbackVarying.h"
#include "Rendering/OpenGLRenderer/GLSL/GLSLReflectionUniform.h"

#include <array>
#include <map>
#include <vector>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(GLSLReflection, GLSLReflectionImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE GLSLReflection
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(GLSLReflection);
        using OpenGLInt = System::OpenGLInt;
        using OpenGLUInt = System::OpenGLUInt;
        using OpenGLEnum = System::OpenGLEnum;
        using ShaderType = System::ShaderType;
        using GLSLReflectionEnumType = System::GLSLReflectionEnumType;
        using InputContainer = std::vector<GLSLReflectionInput>;
        using OutputContainer = std::vector<GLSLReflectionOutput>;
        using UniformContainer = std::vector<GLSLReflectionUniform>;
        using DataBlockContainer = std::vector<GLSLReflectionDataBlock>;
        using BufferVariableContainer = std::vector<GLSLReflectionBufferVariable>;
        using AtomicCounterBufferContainer = std::vector<GLSLReflectionAtomicCounterBuffer>;
        using SubroutineUniformContainer = std::vector<GLSLReflectionSubroutineUniform>;
        using TransformFeedbackVaryingContainer = std::vector<GLSLReflectionTransformFeedbackVarying>;
        using TransformFeedbackBufferContainer = std::vector<GLSLReflectionTransformFeedbackBuffer>;
        using NumThreads = std::array<OpenGLInt, 3>;
        using ResultsType = std::vector<OpenGLInt>;

    public:
        explicit GLSLReflection(OpenGLUInt handle);

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
        PackageType impl;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_H
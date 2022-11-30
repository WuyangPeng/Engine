///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/31 14:53)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_IMPL_H
#define RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_IMPL_H

#include "Rendering/RenderingDll.h"

#include "GLSLReflectionEnumMap.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
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

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE GLSLReflectionImpl
    {
    public:
        using ClassType = GLSLReflectionImpl;
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
        explicit GLSLReflectionImpl(OpenGLUInt handle);

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
        using SubroutinesType = std::vector<std::string>;
        using ShaderTypeMap = std::map<System::ShaderType, int>;
        using ReferencedBy = std::array<OpenGLInt, 6>;
        using ProgramInterface = System::ProgramInterface;

    private:
        void ReflectProgramInputs();
        void ReflectProgramOutputs();
        void ReflectUniforms();
        void ReflectDataBlocks(ProgramInterface programInterface, DataBlockContainer& blocks);
        void ReflectAtomicCounterBuffers();
        void ReflectSubroutines(ProgramInterface programInterface, SubroutinesType& subroutines);
        void ReflectSubroutineUniforms(ProgramInterface programInterface, SubroutineUniformContainer& subUniforms);
        void ReflectBufferVariables();
        void ReflectTransformFeedbackVaryings();
        void ReflectTransformFeedbackBuffers();

        void IntelWorkaround(const std::string& name, ResultsType& results);

        NODISCARD static const GLSLReflectionEnumMap& GetGLSLReflectionEnumMap(int index);

        NODISCARD static int GetEnumSize(GLSLReflectionEnumType value, OpenGLInt arraySize, OpenGLInt arrayStride, OpenGLInt matrixStride, OpenGLInt isRowMajor);
        NODISCARD static std::string GetEnumName(GLSLReflectionEnumType value);
        NODISCARD static std::string GetEnumShaderName(GLSLReflectionEnumType value);
        NODISCARD static std::string GetReferencedByShaderList(const ReferencedBy& referencedBy);

    private:
        OpenGLUInt handle;
        InputContainer inputs;
        OutputContainer outputs;
        UniformContainer uniforms;
        DataBlockContainer uniformBlocks;
        DataBlockContainer shaderStorageBlocks;
        AtomicCounterBufferContainer atomicCounterBuffers;
        SubroutinesType vertexSubroutines;
        SubroutinesType geometrySubroutines;
        SubroutinesType pixelSubroutines;
        SubroutinesType computeSubroutines;
        SubroutinesType tessControlSubroutines;
        SubroutinesType tessEvaluationSubroutines;
        SubroutineUniformContainer vertexSubroutineUniforms;
        SubroutineUniformContainer geometrySubroutineUniforms;
        SubroutineUniformContainer pixelSubroutineUniforms;
        SubroutineUniformContainer computeSubroutineUniforms;
        SubroutineUniformContainer tessControlSubroutineUniforms;
        SubroutineUniformContainer tessEvaluationSubroutineUniforms;
        BufferVariableContainer bufferVariables;
        TransformFeedbackVaryingContainer transformFeedbackVaryings;
        TransformFeedbackBufferContainer transformFeedbackBuffers;

        bool vendorIsIntel;
        ShaderTypeMap shaderTypeMap;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_IMPL_H
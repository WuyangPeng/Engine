///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:21)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_IMPL_H
#define RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_IMPL_H

#include "Rendering/RenderingDll.h"

#include "GLSLReflectionEnumMap.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Shaders/Detail/ReflectionImpl.h"
#include "Rendering/Shaders/ReflectionAtomicCounterBuffer.h"
#include "Rendering/Shaders/ReflectionBufferVariable.h"
#include "Rendering/Shaders/ReflectionDataBlock.h"
#include "Rendering/Shaders/ReflectionInput.h"
#include "Rendering/Shaders/ReflectionOutput.h"
#include "Rendering/Shaders/ReflectionSubroutineUniform.h"
#include "Rendering/Shaders/ReflectionTransformFeedbackBuffer.h"
#include "Rendering/Shaders/ReflectionTransformFeedbackVarying.h"
#include "Rendering/Shaders/ReflectionUniform.h"

#include <array>
#include <map>
#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE GLSLReflection : public ReflectionImpl
    {
    public:
        using ClassType = GLSLReflection;

        using OpenGLEnum = System::OpenGLEnum;
        using ShaderType = System::ShaderType;
        using ResultsType = std::vector<OpenGLInt>;
        using GLSLReflectionEnumType = System::GLSLReflectionEnumType;

    public:
        GLSLReflection() noexcept;
        explicit GLSLReflection(OpenGLUInt handle);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ReflectionSharedPtr Clone() const override;

        NODISCARD OpenGLUInt GetProgramHandle() const noexcept override;

        NODISCARD InputContainer GetInputs() const override;
        NODISCARD OutputContainer GetOutputs() const override;
        NODISCARD UniformContainer GetUniforms() const override;
        NODISCARD DataBlockContainer GetUniformBlocks() const override;
        NODISCARD BufferVariableContainer GetBufferVariables() const override;
        NODISCARD DataBlockContainer GetBufferBlocks() const override;
        NODISCARD AtomicCounterBufferContainer GetAtomicCounterBuffers() const override;
        NODISCARD NumThreads GetComputeShaderWorkGroupSize() const noexcept override;

        void Print(std::ofstream& output) const override;

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
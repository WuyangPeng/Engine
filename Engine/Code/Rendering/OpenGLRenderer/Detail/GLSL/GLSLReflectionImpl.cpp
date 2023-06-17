///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:41)

#include "Rendering/RenderingExport.h"

#include "GLSLReflectionImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Flags/OpenGLProgramFlags.h"
#include "System/OpenGL/Flags/OpenGLShaderFlags.h"
#include "System/OpenGL/OpenGLInit.h"
#include "System/OpenGL/OpenGLProgram.h"
#include "System/OpenGL/OpenGLShader.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Rendering/OpenGLRenderer/Flags/ReferenceType.h"

#include <fstream>

Rendering::GLSLReflectionImpl::GLSLReflectionImpl(OpenGLUInt handle)
    : handle{ handle },
      inputs{},
      outputs{},
      uniforms{},
      uniformBlocks{},
      shaderStorageBlocks{},
      atomicCounterBuffers{},
      vertexSubroutines{},
      geometrySubroutines{},
      pixelSubroutines{},
      computeSubroutines{},
      tessControlSubroutines{},
      tessEvaluationSubroutines{},
      vertexSubroutineUniforms{},
      geometrySubroutineUniforms{},
      pixelSubroutineUniforms{},
      computeSubroutineUniforms{},
      tessControlSubroutineUniforms{},
      tessEvaluationSubroutineUniforms{},
      bufferVariables{},
      transformFeedbackVaryings{},
      transformFeedbackBuffers{},
      vendorIsIntel{ System::GetOpenGLVendorString() == "Intel" },
      shaderTypeMap{ { ShaderType::Vertex, 3 },
                     { ShaderType::Geometry, 4 },
                     { ShaderType::Fragment, 5 },
                     { ShaderType::Compute, 6 },
                     { ShaderType::TessControl, 7 },
                     { ShaderType::TessEvaluation, 8 } }
{
    if (0 < handle)
    {
        ReflectProgramInputs();
        ReflectProgramOutputs();
        ReflectDataBlocks(ProgramInterface::UniformBlock, uniformBlocks);
        ReflectUniforms();
        ReflectDataBlocks(ProgramInterface::ShaderStorageBlock, shaderStorageBlocks);
        ReflectAtomicCounterBuffers();
        ReflectSubroutines(ProgramInterface::VertexSubroutine, vertexSubroutines);
        ReflectSubroutines(ProgramInterface::GeometrySubroutine, geometrySubroutines);
        ReflectSubroutines(ProgramInterface::FragmentSubroutine, pixelSubroutines);
        ReflectSubroutines(ProgramInterface::ComputeSubroutine, computeSubroutines);
        ReflectSubroutines(ProgramInterface::TessControlSubroutine, tessControlSubroutines);
        ReflectSubroutines(ProgramInterface::TessEvaluationSubroutine, tessEvaluationSubroutines);
        ReflectSubroutineUniforms(ProgramInterface::VertexSubroutineUniform, vertexSubroutineUniforms);
        ReflectSubroutineUniforms(ProgramInterface::GeometrySubroutineUniform, geometrySubroutineUniforms);
        ReflectSubroutineUniforms(ProgramInterface::FragmentSubroutineUniform, pixelSubroutineUniforms);
        ReflectSubroutineUniforms(ProgramInterface::ComputeSubroutineUniform, computeSubroutineUniforms);
        ReflectSubroutineUniforms(ProgramInterface::TessControlSubroutineUniform, tessControlSubroutineUniforms);
        ReflectSubroutineUniforms(ProgramInterface::TessEvaluationSubroutineUniform, tessEvaluationSubroutineUniforms);
        ReflectBufferVariables();
        ReflectTransformFeedbackVaryings();
        ReflectTransformFeedbackBuffers();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("程序句柄无效。"s));
    }

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, GLSLReflectionImpl)

Rendering::GLSLReflectionImpl::OpenGLUInt Rendering::GLSLReflectionImpl::GetProgramHandle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return handle;
}

Rendering::GLSLReflectionImpl::InputContainer Rendering::GLSLReflectionImpl::GetInputs() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return inputs;
}

Rendering::GLSLReflectionImpl::OutputContainer Rendering::GLSLReflectionImpl::GetOutputs() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return outputs;
}

Rendering::GLSLReflectionImpl::UniformContainer Rendering::GLSLReflectionImpl::GetUniforms() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return uniforms;
}

Rendering::GLSLReflectionImpl::DataBlockContainer Rendering::GLSLReflectionImpl::GetUniformBlocks() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return uniformBlocks;
}

Rendering::GLSLReflectionImpl::BufferVariableContainer Rendering::GLSLReflectionImpl::GetBufferVariables() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return bufferVariables;
}

Rendering::GLSLReflectionImpl::DataBlockContainer Rendering::GLSLReflectionImpl::GetBufferBlocks() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return shaderStorageBlocks;
}

Rendering::GLSLReflectionImpl::AtomicCounterBufferContainer Rendering::GLSLReflectionImpl::GetAtomicCounterBuffers() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return atomicCounterBuffers;
}

Rendering::GLSLReflectionImpl::NumThreads Rendering::GLSLReflectionImpl::GetComputeShaderWorkGroupSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    NumThreads workGroupSize{};

    System::GetGLProgram(handle, System::ProgramAttributes::ComputeWorkGroupSize, workGroupSize);

    return workGroupSize;
}

void Rendering::GLSLReflectionImpl::Print(std::ofstream& output) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    output << "Description:" << std::endl;
    output << "OpenGL version = " << System::GetOpenGLVersionString() << std::endl;
    output << "GLSL version = " << System::GetOpenGLShadingLanguageVersion() << std::endl;
    output << "Vendor = " << System::GetOpenGLVendorString() << std::endl;
    output << "Renderer = " << System::GetOpenGLRendererString() << std::endl;
    output << std::endl;

    output << "General:" << std::endl;
    output << "num inputs = " << inputs.size() << std::endl;
    output << "num outputs = " << outputs.size() << std::endl;
    output << "num uniform blocks = " << uniformBlocks.size() << std::endl;
    output << "num atomic counter buffers = " << atomicCounterBuffers.size() << std::endl;
    output << "num uniforms = " << uniforms.size() << std::endl;
    output << "num shader storage blocks = " << shaderStorageBlocks.size() << std::endl;
    output << "num buffer variables = " << bufferVariables.size() << std::endl;
    output << std::endl;

    for (auto i = 0u; i < inputs.size(); ++i)
    {
        const auto& input = inputs.at(i);

        output << "Input[" << i << "]:" << std::endl;
        output << "name = " << input.GetName() << std::endl;
        output << "type = " << GetEnumName(input.GetType()) << std::endl;
        output << "shader type = " << GetEnumShaderName(input.GetType()) << std::endl;
        output << "location = " << input.GetLocation() << std::endl;
        output << "array Size = " << input.GetArraySize() << std::endl;
        output << "referenced by shaders = " << GetReferencedByShaderList(input.GetReferencedBy()) << std::endl;
        output << "is per patch = " << input.GetIsPerPatch() << std::endl;
        output << "location component = " << input.GetLocationComponent() << std::endl;
        output << std::endl;
    }

    for (auto i = 0u; i < outputs.size(); ++i)
    {
        const auto& out = outputs.at(i);

        output << "Output[" << i << "]:" << std::endl;
        output << "name = " << out.GetName() << std::endl;
        output << "type = " << GetEnumName(out.GetType()) << std::endl;
        output << "shader type = " << GetEnumShaderName(out.GetType()) << std::endl;
        output << "location = " << out.GetLocation() << std::endl;
        output << "array Size = " << out.GetArraySize() << std::endl;
        output << "referenced by shaders = " << GetReferencedByShaderList(out.GetReferencedBy()) << std::endl;
        output << "is per patch = " << out.GetIsPerPatch() << std::endl;
        output << "location component = " << out.GetLocationComponent() << std::endl;
        output << "location index = " << out.GetLocationIndex() << std::endl;
        output << std::endl;
    }

    for (auto i = 0u; i < uniformBlocks.size(); ++i)
    {
        const auto& block = uniformBlocks.at(i);

        output << "UniformBlock[" << i << "]:" << std::endl;
        output << "name = " << block.GetName() << std::endl;
        output << "buffer binding = " << block.GetBufferBinding() << std::endl;
        output << "buffer data size = " << block.GetBufferDataSize() << std::endl;
        output << "referenced by shaders = " << GetReferencedByShaderList(block.GetReferencedBy()) << std::endl;
        output << "active variables = " << block.GetActiveVariablesCount() << std::endl;

        output << "declaration = " << std::endl;
        output << "  uniform " << block.GetName() << std::endl;
        output << "  {" << std::endl;
        for (auto v = 0; v < block.GetActiveVariablesCount(); ++v)
        {
            const auto& uniform = uniforms.at(block.GetActiveVariables(v));

            output << "      " << GetEnumShaderName(uniform.GetType()) << " " << uniform.GetName();
            if (uniform.GetArraySize() > 1)
            {
                output << "[" << uniform.GetArraySize() << "]";
            }
            output << "; //";
            output << " offset=" << uniform.GetOffset();
            output << " size=" << GetEnumSize(uniform.GetType(), uniform.GetArraySize(), uniform.GetArrayStride(), uniform.GetMatrixStride(), uniform.GetIsRowMajor());
            if (uniform.GetArrayStride() > 0)
            {
                output << " arrayStride=" << uniform.GetArrayStride();
            }
            if (uniform.GetMatrixStride() > 0)
            {
                output << " matrixStride=" << uniform.GetMatrixStride();
                output << " rowMajor=" << uniform.GetIsRowMajor();
            }
            output << std::endl;
        }
        output << "  };" << std::endl;
        output << std::endl;
    }

    for (auto i = 0u; i < atomicCounterBuffers.size(); ++i)
    {
        const auto& acBuffer = atomicCounterBuffers.at(i);

        output << "AtomicCounterBuffer[" << i << "]:" << std::endl;
        output << "buffer binding = " << acBuffer.GetBufferBinding() << std::endl;
        output << "buffer data size = " << acBuffer.GetBufferBinding() << std::endl;
        output << "referenced by shaders = " << GetReferencedByShaderList(acBuffer.GetReferencedBy()) << std::endl;
        output << "active variables = " << acBuffer.GetActiveVariablesCount() << std::endl;
        output << std::endl;
    }

    for (auto i = 0u; i < uniforms.size(); ++i)
    {
        const auto& uniform = uniforms.at(i);

        output << "Uniform[" << i << "]:" << std::endl;
        output << "name = " << uniform.GetFullName() << std::endl;
        output << "type = " << GetEnumName(uniform.GetType()) << std::endl;
        output << "shader type = " << GetEnumShaderName(uniform.GetType()) << std::endl;
        output << "referenced by shaders = " << GetReferencedByShaderList(uniform.GetReferencedBy()) << std::endl;

        if (uniform.GetBlockIndex() >= 0)
        {
            output << "array size = " << uniform.GetArraySize() << std::endl;
            output << "offset = " << uniform.GetOffset() << std::endl;
            output << "uniform block index = " << uniform.GetBlockIndex() << std::endl;
            output << "array stride = " << uniform.GetArrayStride() << std::endl;
            output << "matrix stride = " << uniform.GetMatrixStride() << std::endl;
            output << "is row major = " << uniform.GetIsRowMajor() << std::endl;
            output << "size=" << GetEnumSize(uniform.GetType(), uniform.GetArraySize(), uniform.GetArrayStride(), uniform.GetMatrixStride(), uniform.GetIsRowMajor()) << std::endl;
        }

        else if (uniform.GetAtomicCounterBufferIndex() >= 0)
        {
            output << "atomic counter buffer index = " << uniform.GetAtomicCounterBufferIndex() << std::endl;

            const auto& acBuffer = atomicCounterBuffers.at(uniform.GetAtomicCounterBufferIndex());
            output << "declaration = " << std::endl;
            output << "  layout(binding = " << acBuffer.GetBufferBinding() << ", offset = " << uniform.GetOffset();
            output << ") uniform " << GetEnumShaderName(uniform.GetType()) << " " << uniform.GetName() << ";" << std::endl;
        }
        else
        {
            output << "declaration = " << std::endl;
            output << "  uniform " << GetEnumShaderName(uniform.GetType()) << " " << uniform.GetName() << ";" << std::endl;
        }

        output << std::endl;
    }

    for (auto i = 0u; i < shaderStorageBlocks.size(); ++i)
    {
        const auto& block = shaderStorageBlocks.at(i);

        output << "ShaderStorageBlock[" << i << "]:" << std::endl;
        output << "name = " << block.GetName() << std::endl;
        output << "buffer binding = " << block.GetBufferBinding() << std::endl;
        output << "buffer data size = " << block.GetBufferBinding() << std::endl;
        output << "referenced by shaders = " << GetReferencedByShaderList(block.GetReferencedBy()) << std::endl;
        output << "active variables = " << block.GetActiveVariablesCount() << std::endl;

        output << "declaration = " << std::endl;
        output << "  buffer " << block.GetName() << std::endl;
        output << "  {" << std::endl;
        auto topLevelArrayStride = 0;
        auto topLevelArrayOffset = 0;
        for (auto v = 0, vp1 = 1; v < block.GetActiveVariablesCount(); ++v, ++vp1)
        {
            const auto& bufferVar = bufferVariables.at(block.GetActiveVariables(v));

            if (bufferVar.GetTopLevelArrayStride() != topLevelArrayStride)
            {
                if (topLevelArrayStride > 0)
                {
                    output << "      "
                           << "} [];"
                           << std::endl;
                }
                else
                {
                    output << "      struct //";
                    output << " offset="
                           << bufferVar.GetOffset();
                    output << " structSize="
                           << bufferVar.GetTopLevelArrayStride();
                    output << std::endl;
                    output << "      {"
                           << std::endl;
                }
                topLevelArrayStride = bufferVar.GetTopLevelArrayStride();
                topLevelArrayOffset = bufferVar.GetOffset();
            }

            if (topLevelArrayStride > 0)
            {
                output << "    ";
            }
            output << "      " << GetEnumShaderName(bufferVar.GetType()) << " " << bufferVar.GetName();
            if (bufferVar.GetArrayStride() > 0)
            {
                auto arraySize = bufferVar.GetArraySize();
                if (0 == arraySize)
                {
                    GLint nextOffset = block.GetBufferDataSize();
                    if (vp1 < block.GetActiveVariablesCount())
                    {
                        nextOffset = bufferVariables.at(block.GetActiveVariables(vp1)).GetOffset();
                    }
                    arraySize = (nextOffset - bufferVar.GetOffset()) / bufferVar.GetArrayStride();
                }
                output << '[' << arraySize << ']';
            }

            output << "; //";
            const auto size = GetEnumSize(bufferVar.GetType(), bufferVar.GetArraySize(), bufferVar.GetArrayStride(), bufferVar.GetMatrixStride(), bufferVar.GetIsRowMajor());
            if (size > 0)
            {
                output << " size=" << size;
            }
            if (topLevelArrayStride > 0)
            {
                output << " structOffset=" << (bufferVar.GetOffset() - topLevelArrayOffset);
            }
            output << " bufferOffset=" << bufferVar.GetOffset();
            if (bufferVar.GetArrayStride() > 0)
            {
                output << " arrayStride=" << bufferVar.GetArrayStride();
            }
            if (bufferVar.GetMatrixStride() > 0)
            {
                output << " matrixStride=" << bufferVar.GetMatrixStride();
                output << " rowMajor=" << bufferVar.GetIsRowMajor();
            }
            output << std::endl;
        }
        if (topLevelArrayStride > 0)
        {
            output << "      "
                   << "} [];"
                   << std::endl;
        }
        output << "  };" << std::endl;
        output << std::endl;
    }

    for (auto i = 0u; i < bufferVariables.size(); ++i)
    {
        const auto& bufferVar = bufferVariables.at(i);

        output << "BufferVariable[" << i << "]:" << std::endl;
        output << "name = " << bufferVar.GetFullName() << std::endl;
        output << "type = " << GetEnumName(bufferVar.GetType()) << std::endl;
        output << "shader type = " << GetEnumShaderName(bufferVar.GetType()) << std::endl;
        output << "referenced by shaders = " << GetReferencedByShaderList(bufferVar.GetReferencedBy()) << std::endl;

        if (bufferVar.GetBlockIndex() >= 0)
        {
            output << "array size = " << bufferVar.GetArraySize() << std::endl;
            output << "offset = " << bufferVar.GetOffset() << std::endl;
            output << "buffer block index = " << bufferVar.GetBlockIndex() << std::endl;
            output << "array stride = " << bufferVar.GetArrayStride() << std::endl;
            output << "matrix stride = " << bufferVar.GetMatrixStride() << std::endl;
            output << "is row major = " << bufferVar.GetIsRowMajor() << std::endl;
            output << "top level array size = " << bufferVar.GetTopLevelArraySize() << std::endl;
            output << "top level array stride = " << bufferVar.GetTopLevelArrayStride() << std::endl;
            auto const size = GetEnumSize(bufferVar.GetType(), bufferVar.GetArraySize(), bufferVar.GetArrayStride(), bufferVar.GetMatrixStride(), bufferVar.GetIsRowMajor());
            if (size > 0)
            {
                output << "size=" << size << std::endl;
            }
        }
        else
        {
            output << "declaration = " << std::endl;
            output << "  buffer " << GetEnumShaderName(bufferVar.GetType()) << " " << bufferVar.GetName() << ";" << std::endl;
        }

        output << std::endl;
    }
}

void Rendering::GLSLReflectionImpl::ReflectProgramInputs()
{
    const auto numResources = System::GetGLProgramInterface(handle, ProgramInterface::ProgramInput, System::ProgramInterfaceName::ActiveResources);

    if (numResources > 0)
    {
        inputs.resize(numResources, GLSLReflectionInput{ "" });

        enum
        {
            NameLength,
            Type,
            Location,
            ArraySize,
            ReferencedByVertexShader,
            ReferencedByGeometryShader,
            ReferencedByFragmentShader,
            ReferencedByComputeShader,
            ReferencedByTessControlShader,
            ReferencedByTessEvaluationShader,
            IsPerPatch,
            LocationComponent
        };

        static const std::vector<OpenGLEnum> properties{ EnumCastUnderlying(System::ProgramProperties::NameLength),
                                                         EnumCastUnderlying(System::ProgramProperties::Type),
                                                         EnumCastUnderlying(System::ProgramProperties::Location),
                                                         EnumCastUnderlying(System::ProgramProperties::ArraySize),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByVertexShader),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByGeometryShader),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByFragmentShader),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByComputeShader),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByTessControlShader),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByTessEvaluationShader),
                                                         EnumCastUnderlying(System::ProgramProperties::IsPerPatch),
                                                         EnumCastUnderlying(System::ProgramProperties::LocationComponent) };

        const auto numProperties = boost::numeric_cast<System::OpenGLSize>(properties.size());

        std::vector<OpenGLInt> results(properties.size(), 0);
        for (auto i = 0; i < numResources; ++i)
        {
            System::GetGLProgramResource(handle, ProgramInterface::ProgramInput, i, numProperties, properties.data(), numProperties, nullptr, results.data());

            const auto numBytes = boost::numeric_cast<System::OpenGLSize>(results.at(NameLength) + 1);
            std::vector<System::OpenGLChar> name(numBytes);
            System::GetGLProgramResourceName(handle, ProgramInterface::ProgramInput, i, numBytes, nullptr, name.data());

            auto& info = inputs.at(i);
            info.SetName(name.data());
            info.SetType(System::UnderlyingCastEnum<GLSLReflectionEnumType>(results.at(Type)));
            info.SetLocation(results.at(Location));
            info.SetArraySize(results.at(ArraySize));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::Vertex), results.at(ReferencedByVertexShader));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::Geometry), results.at(ReferencedByGeometryShader));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::Pixel), results.at(ReferencedByFragmentShader));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::Compute), results.at(ReferencedByComputeShader));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::TessControl), results.at(ReferencedByTessControlShader));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::TessEvaluation), results.at(ReferencedByTessEvaluationShader));
            info.SetIsPerPatch(results.at(IsPerPatch));
            info.SetLocationComponent(results.at(LocationComponent));
        }
    }
}

void Rendering::GLSLReflectionImpl::ReflectProgramOutputs()
{
    const auto numResources = System::GetGLProgramInterface(handle, ProgramInterface::ProgramOutput, System::ProgramInterfaceName::ActiveResources);

    if (numResources > 0)
    {
        outputs.resize(numResources, GLSLReflectionOutput{ "" });

        enum
        {
            NameLength,
            Type,
            Location,
            ArraySize,
            ReferencedByVertexShader,
            ReferencedByGeometryShader,
            ReferencedByFragmentShader,
            ReferencedByComputeShader,
            ReferencedByTessControlShader,
            ReferencedByTessEvaluationShader,
            IsPerPatch,
            LocationComponent,
            LocationIndex
        };

        static const std::vector<OpenGLEnum> properties{ EnumCastUnderlying(System::ProgramProperties::NameLength),
                                                         EnumCastUnderlying(System::ProgramProperties::Type),
                                                         EnumCastUnderlying(System::ProgramProperties::Location),
                                                         EnumCastUnderlying(System::ProgramProperties::ArraySize),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByVertexShader),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByGeometryShader),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByFragmentShader),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByComputeShader),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByTessControlShader),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByTessEvaluationShader),
                                                         EnumCastUnderlying(System::ProgramProperties::IsPerPatch),
                                                         EnumCastUnderlying(System::ProgramProperties::LocationComponent),
                                                         EnumCastUnderlying(System::ProgramProperties::LocationIndex) };

        const auto numProperties = boost::numeric_cast<System::OpenGLSize>(properties.size());

        std::vector<OpenGLInt> results(properties.size(), 0);
        for (auto i = 0; i < numResources; ++i)
        {
            System::GetGLProgramResource(handle, ProgramInterface::ProgramOutput, i, numProperties, properties.data(), numProperties, nullptr, results.data());

            const auto numBytes = boost::numeric_cast<System::OpenGLSize>(results.at(NameLength) + 1);
            std::vector<System::OpenGLChar> name(numBytes);

            System::GetGLProgramResourceName(handle, ProgramInterface::ProgramOutput, i, numBytes, nullptr, name.data());

            auto& info = outputs.at(i);
            info.SetName(name.data());
            info.SetType(System::UnderlyingCastEnum<GLSLReflectionEnumType>(results.at(Type)));
            info.SetLocation(results.at(Location));
            info.SetArraySize(results.at(ArraySize));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::Vertex), results.at(ReferencedByVertexShader));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::Geometry), results.at(ReferencedByGeometryShader));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::Pixel), results.at(ReferencedByFragmentShader));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::Compute), results.at(ReferencedByComputeShader));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::TessControl), results.at(ReferencedByTessControlShader));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::TessEvaluation), results.at(ReferencedByTessEvaluationShader));
            info.SetIsPerPatch(results.at(IsPerPatch));
            info.SetLocationComponent(results.at(LocationComponent));
            info.SetLocationIndex(results.at(LocationIndex));
        }
    }
}

void Rendering::GLSLReflectionImpl::ReflectUniforms()
{
    const auto numResources = System::GetGLProgramInterface(handle, ProgramInterface::Uniform, System::ProgramInterfaceName::ActiveResources);

    if (numResources > 0)
    {
        uniforms.clear();

        enum
        {
            NameLength,
            Type,
            Location,
            ArraySize,
            Offset,
            BlockIndex,
            ArrayStride,
            MatrixStride,
            IsRowMajor,
            AtomicCounterBufferIndex,
            ReferencedByVertexShader,
            ReferencedByGeometryShader,
            ReferencedByFragmentShader,
            ReferencedByComputeShader,
            ReferencedByTessControlShader,
            ReferencedByTessEvaluationShader
        };

        static const std::vector<OpenGLEnum> properties{ EnumCastUnderlying(System::ProgramProperties::NameLength),
                                                         EnumCastUnderlying(System::ProgramProperties::Type),
                                                         EnumCastUnderlying(System::ProgramProperties::Location),
                                                         EnumCastUnderlying(System::ProgramProperties::ArraySize),
                                                         EnumCastUnderlying(System::ProgramProperties::Offset),
                                                         EnumCastUnderlying(System::ProgramProperties::BlockIndex),
                                                         EnumCastUnderlying(System::ProgramProperties::ArrayStride),
                                                         EnumCastUnderlying(System::ProgramProperties::MatrixStride),
                                                         EnumCastUnderlying(System::ProgramProperties::IsRowMajor),
                                                         EnumCastUnderlying(System::ProgramProperties::AtomicCounterBufferIndex),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByVertexShader),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByGeometryShader),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByFragmentShader),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByComputeShader),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByTessControlShader),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByTessEvaluationShader) };

        const auto numProperties = boost::numeric_cast<System::OpenGLSize>(properties.size());

        std::vector<OpenGLInt> results(properties.size(), 0);
        for (auto i = 0; i < numResources; ++i)
        {
            System::GetGLProgramResource(handle, ProgramInterface::Uniform, i, numProperties, properties.data(), numProperties, nullptr, results.data());

            const auto numBytes = boost::numeric_cast<System::OpenGLSize>(results.at(NameLength) + 1);
            std::vector<System::OpenGLChar> name(numBytes);
            System::GetGLProgramResourceName(handle, ProgramInterface::Uniform, i, numBytes, nullptr, name.data());

            GLSLReflectionUniform info{ name.data() };

            info.SetType(System::UnderlyingCastEnum<GLSLReflectionEnumType>(results.at(Type)));
            info.SetLocation(results.at(Location));
            info.SetArraySize(results.at(ArraySize));
            info.SetOffset(results.at(Offset));
            info.SetBlockIndex(results.at(BlockIndex));
            info.SetArrayStride(results.at(ArrayStride));
            info.SetMatrixStride(results.at(MatrixStride));
            info.SetIsRowMajor(results.at(IsRowMajor));
            info.SetAtomicCounterBufferIndex(results.at(AtomicCounterBufferIndex));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::Vertex), results.at(ReferencedByVertexShader));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::Geometry), results.at(ReferencedByGeometryShader));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::Pixel), results.at(ReferencedByFragmentShader));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::Compute), results.at(ReferencedByComputeShader));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::TessControl), results.at(ReferencedByTessControlShader));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::TessEvaluation), results.at(ReferencedByTessEvaluationShader));

            if (System::invalidGLIndex == info.GetBlockIndex())
            {
                info.SetLocation(System::GetGLUniformLocation(handle, info.GetName().c_str()));
            }

            info.SetFullName(info.GetName());

            if (info.GetArraySize() > 1)
            {
                auto index = info.GetName().find('[');
                if (index != std::string::npos)
                {
                    auto index2 = info.GetName().find('[', index + 1);
                    if (index2 != std::string::npos)
                    {
                        THROW_EXCEPTION(SYSTEM_TEXT("GLSL uniforms只支持一维数组。"));
                    }

                    info.SetName(info.GetName().substr(0, index));
                }
                else
                {
                    THROW_EXCEPTION(SYSTEM_TEXT("意外情况。"));
                }
            }

            uniforms.emplace_back(info);
        }
    }
}

void Rendering::GLSLReflectionImpl::ReflectDataBlocks(ProgramInterface programInterface, DataBlockContainer& blocks)
{
    const auto numResources = System::GetGLProgramInterface(handle, programInterface, System::ProgramInterfaceName::ActiveResources);

    if (numResources > 0)
    {
        blocks.resize(numResources, GLSLReflectionDataBlock{ "" });

        enum
        {
            NameLength,
            BufferBinding,
            BufferDataSize,
            ReferencedByVertexShader,
            ReferencedByGeometryShader,
            ReferencedByFragmentShader,
            ReferencedByComputeShader,
            ReferencedByTessControlShader,
            ReferencedByTessEvaluationShader,
            NumActiveVariables
        };

        static const std::vector<OpenGLEnum> properties{ EnumCastUnderlying(System::ProgramProperties::NameLength),
                                                         EnumCastUnderlying(System::ProgramProperties::BufferBinding),
                                                         EnumCastUnderlying(System::ProgramProperties::BufferDataSize),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByVertexShader),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByGeometryShader),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByFragmentShader),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByComputeShader),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByTessControlShader),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByTessEvaluationShader),
                                                         EnumCastUnderlying(System::ProgramProperties::NumActiveVariables) };

        const auto numProperties = boost::numeric_cast<System::OpenGLSize>(properties.size());

        std::vector<OpenGLInt> results(properties.size(), 0);
        for (auto i = 0; i < numResources; ++i)
        {
            System::GetGLProgramResource(handle, programInterface, i, numProperties, properties.data(), numProperties, nullptr, results.data());

            const auto numBytes = boost::numeric_cast<System::OpenGLSize>(results.at(NameLength) + 1);
            std::vector<System::OpenGLChar> name(numBytes);
            System::GetGLProgramResourceName(handle, programInterface, i, numBytes, nullptr, name.data());

            auto& info = blocks.at(i);
            info.SetName(name.data());

            if (vendorIsIntel && programInterface == ProgramInterface::ShaderStorageBlock)
            {
                IntelWorkaround(info.GetName(), results);
            }

            info.SetBufferBinding(results.at(BufferBinding));
            info.SetBufferDataSize(results.at(BufferDataSize));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::Vertex), results.at(ReferencedByVertexShader));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::Geometry), results.at(ReferencedByGeometryShader));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::Pixel), results.at(ReferencedByFragmentShader));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::Compute), results.at(ReferencedByComputeShader));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::TessControl), results.at(ReferencedByTessControlShader));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::TessEvaluation), results.at(ReferencedByTessEvaluationShader));

            info.SetBufferBinding(System::GetGLProgramResourceIndex(handle, programInterface, info.GetName().c_str()));

            auto numActiveVariables = results.at(NumActiveVariables);
            if (numActiveVariables > 0)
            {
                std::vector<OpenGLInt> activeVariables(numActiveVariables);
                auto varProperty = EnumCastUnderlying<OpenGLEnum>(System::ProgramProperties::ActiveVariables);
                System::GetGLProgramResource(handle, programInterface, i, 1, &varProperty, numActiveVariables, nullptr, activeVariables.data());

                info.SetActiveVariables(activeVariables);
            }
        }
    }
}

void Rendering::GLSLReflectionImpl::ReflectAtomicCounterBuffers()
{
    const auto numResources = System::GetGLProgramInterface(handle, ProgramInterface::AtomicCounterBuffer, System::ProgramInterfaceName::ActiveResources);

    if (numResources > 0)
    {
        atomicCounterBuffers.resize(numResources, GLSLReflectionAtomicCounterBuffer{ 0 });

        enum
        {
            BufferBinding,
            BufferDataSize,
            ReferencedByVertexShader,
            ReferencedByGeometryShader,
            ReferencedByFragmentShader,
            ReferencedByComputeShader,
            ReferencedByTessControlShader,
            ReferencedByTessEvaluationShader,
            NumActiveVariables
        };

        static const std::vector<OpenGLEnum> properties{ EnumCastUnderlying(System::ProgramProperties::BufferBinding),
                                                         EnumCastUnderlying(System::ProgramProperties::BufferDataSize),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByVertexShader),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByGeometryShader),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByFragmentShader),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByComputeShader),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByTessControlShader),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByTessEvaluationShader),
                                                         EnumCastUnderlying(System::ProgramProperties::NumActiveVariables) };

        const auto numProperties = boost::numeric_cast<System::OpenGLSize>(properties.size());

        std::vector<OpenGLInt> results(properties.size(), 0);
        for (auto i = 0; i < numResources; ++i)
        {
            System::GetGLProgramResource(handle, ProgramInterface::AtomicCounterBuffer, i, numProperties, properties.data(), numProperties, nullptr, results.data());

            auto& info = atomicCounterBuffers.at(i);
            info.SetBufferBinding(results.at(BufferBinding));
            info.SetBufferDataSize(results.at(BufferDataSize));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::Vertex), results.at(ReferencedByVertexShader));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::Geometry), results.at(ReferencedByGeometryShader));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::Pixel), results.at(ReferencedByFragmentShader));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::Compute), results.at(ReferencedByComputeShader));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::TessControl), results.at(ReferencedByTessControlShader));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::TessEvaluation), results.at(ReferencedByTessEvaluationShader));

            auto numActiveVariables = results.at(NumActiveVariables);
            if (numActiveVariables > 0)
            {
                std::vector<OpenGLInt> activeVariables(numActiveVariables);
                auto varProperty = EnumCastUnderlying<OpenGLEnum>(System::ProgramProperties::ActiveVariables);
                System::GetGLProgramResource(handle, ProgramInterface::AtomicCounterBuffer, i, 1, &varProperty, numActiveVariables, nullptr, activeVariables.data());

                info.SetActiveVariables(activeVariables);
            }
        }
    }
}

void Rendering::GLSLReflectionImpl::ReflectSubroutines(ProgramInterface programInterface, SubroutinesType& subroutines)
{
    const auto numResources = System::GetGLProgramInterface(handle, programInterface, System::ProgramInterfaceName::ActiveResources);

    if (numResources > 0)
    {
        subroutines.resize(numResources);

        auto nameLengthProperty = EnumCastUnderlying<OpenGLEnum>(System::ProgramProperties::NameLength);
        for (auto i = 0; i < numResources; ++i)
        {
            OpenGLInt result{};
            System::GetGLProgramResource(handle, programInterface, i, 1, &nameLengthProperty, 1, nullptr, &result);

            const auto numBytes = boost::numeric_cast<System::OpenGLSize>(result + 1);
            std::vector<System::OpenGLChar> name(numBytes);

            System::GetGLProgramResourceName(handle, programInterface, i, numBytes, nullptr, name.data());
            subroutines.at(i) = name.data();
        }
    }
}

void Rendering::GLSLReflectionImpl::ReflectSubroutineUniforms(ProgramInterface programInterface, SubroutineUniformContainer& subUniforms)
{
    const auto numResources = System::GetGLProgramInterface(handle, programInterface, System::ProgramInterfaceName::ActiveResources);

    if (numResources > 0)
    {
        subUniforms.resize(numResources, GLSLReflectionSubroutineUniform{ "" });

        enum
        {
            NameLength,
            Location,
            ArraySize,
            NumActiveVariables
        };
        static const std::vector<OpenGLEnum> properties{ EnumCastUnderlying(System::ProgramProperties::NameLength),
                                                         EnumCastUnderlying(System::ProgramProperties::Location),
                                                         EnumCastUnderlying(System::ProgramProperties::ArraySize),
                                                         EnumCastUnderlying(System::ProgramProperties::NumActiveVariables) };

        const auto numProperties = boost::numeric_cast<System::OpenGLSize>(properties.size());

        std::vector<OpenGLInt> results(properties.size(), 0);
        for (auto i = 0; i < numResources; ++i)
        {
            System::GetGLProgramResource(handle, programInterface, i, numProperties, properties.data(), numProperties, nullptr, results.data());

            const auto numBytes = boost::numeric_cast<System::OpenGLSize>(results.at(NameLength) + 1);
            std::vector<System::OpenGLChar> name(numBytes);
            System::GetGLProgramResourceName(handle, programInterface, i, numBytes, nullptr, name.data());

            auto& info = subUniforms.at(i);
            info.SetName(name.data());
            info.SetLocation(results.at(NameLength));
            info.SetArraySize(results.at(ArraySize));

            auto numCompatibleSubroutines = results.at(NumActiveVariables);
            if (numCompatibleSubroutines > 0)
            {
                std::vector<OpenGLInt> compatibleSubroutines(numCompatibleSubroutines);
                auto subProperty = EnumCastUnderlying<OpenGLEnum>(System::ProgramProperties::CompatibleSubroutines);
                System::GetGLProgramResource(handle, programInterface, i, 1, &subProperty, numCompatibleSubroutines, nullptr, compatibleSubroutines.data());
                info.SetCompatibleSubroutines(compatibleSubroutines);
            }
        }
    }
}

void Rendering::GLSLReflectionImpl::ReflectBufferVariables()
{
    const auto numResources = System::GetGLProgramInterface(handle, ProgramInterface::BufferVariable, System::ProgramInterfaceName::ActiveResources);

    if (numResources > 0)
    {
        bufferVariables.resize(numResources, GLSLReflectionBufferVariable{ "" });

        enum
        {
            NameLength,
            Type,
            ArraySize,
            Offset,
            BlockIndex,
            ArrayStride,
            MatrixStride,
            IsRowMajor,
            TopLevelArraySize,
            TopLevelArrayStride,
            ReferencedByVertexShader,
            ReferencedByGeometryShader,
            ReferencedByFragmentShader,
            ReferencedByComputeShader,
            ReferencedByTessControlShader,
            ReferencedByTessEvaluationShader
        };

        static const std::vector<OpenGLEnum> properties{ EnumCastUnderlying(System::ProgramProperties::NameLength),
                                                         EnumCastUnderlying(System::ProgramProperties::Type),
                                                         EnumCastUnderlying(System::ProgramProperties::ArraySize),
                                                         EnumCastUnderlying(System::ProgramProperties::Offset),
                                                         EnumCastUnderlying(System::ProgramProperties::BlockIndex),
                                                         EnumCastUnderlying(System::ProgramProperties::ArrayStride),
                                                         EnumCastUnderlying(System::ProgramProperties::MatrixStride),
                                                         EnumCastUnderlying(System::ProgramProperties::IsRowMajor),
                                                         EnumCastUnderlying(System::ProgramProperties::TopLevelArraySize),
                                                         EnumCastUnderlying(System::ProgramProperties::TopLevelArrayStride),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByVertexShader),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByGeometryShader),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByFragmentShader),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByComputeShader),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByTessControlShader),
                                                         EnumCastUnderlying(System::ProgramProperties::ReferencedByTessEvaluationShader) };

        const auto numProperties = boost::numeric_cast<System::OpenGLSize>(properties.size());

        std::vector<OpenGLInt> results(properties.size(), 0);
        for (auto i = 0; i < numResources; ++i)
        {
            System::GetGLProgramResource(handle, ProgramInterface::BufferVariable, i, numProperties, properties.data(), numProperties, nullptr, results.data());

            const auto numBytes = boost::numeric_cast<System::OpenGLSize>(results.at(NameLength) + 1);
            std::vector<System::OpenGLChar> name(numBytes);
            System::GetGLProgramResourceName(handle, ProgramInterface::BufferVariable, i, numBytes, nullptr, name.data());

            auto& info = bufferVariables.at(i);
            info.SetName(name.data());
            info.SetType(System::UnderlyingCastEnum<GLSLReflectionEnumType>(results.at(Type)));
            info.SetArraySize(results.at(ArraySize));
            info.SetBlockIndex(results.at(BlockIndex));
            info.SetArrayStride(results.at(ArrayStride));
            info.SetMatrixStride(results.at(MatrixStride));
            info.SetIsRowMajor(results.at(IsRowMajor));
            info.SetTopLevelArraySize(results.at(TopLevelArraySize));
            info.SetTopLevelArrayStride(results.at(TopLevelArrayStride));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::Vertex), results.at(ReferencedByVertexShader));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::Geometry), results.at(ReferencedByGeometryShader));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::Pixel), results.at(ReferencedByFragmentShader));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::Compute), results.at(ReferencedByComputeShader));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::TessControl), results.at(ReferencedByTessControlShader));
            info.SetReferencedBy(System::EnumCastUnderlying(ReferenceType::TessEvaluation), results.at(ReferencedByTessEvaluationShader));

            info.SetFullName(info.GetName());

            const auto bufferBlockName = shaderStorageBlocks.at(info.GetBlockIndex()).GetName() + '.';

            if (0 == info.GetName().find(bufferBlockName))
            {
                info.SetName(info.GetName().substr(bufferBlockName.length()));
            }

            if (info.GetTopLevelArrayStride() > 1)
            {
                auto index = info.GetName().find_last_of('.');
                if (index != std::string::npos)
                {
                    info.SetName(info.GetName().substr(index + 1));
                }

                index = info.GetName().find_last_of(']');
                if (index == info.GetName().length() - 1)
                {
                    index = info.GetName().find_last_of('[');
                    if (index != std::string::npos)
                    {
                        info.SetName(info.GetName().substr(0, index));
                    }
                }
            }
        }
    }
}

void Rendering::GLSLReflectionImpl::ReflectTransformFeedbackVaryings()
{
    const auto numResources = System::GetGLProgramInterface(handle, ProgramInterface::TransformFeedbackVarying, System::ProgramInterfaceName::ActiveResources);

    if (numResources > 0)
    {
        inputs.resize(numResources, GLSLReflectionInput{ "" });

        enum
        {
            NameLength,
            Type,
            ArraySize,
            Offset,
            TransformFeedbackBufferIndex,
        };

        static const std::vector<OpenGLEnum> properties{ EnumCastUnderlying(System::ProgramProperties::NameLength),
                                                         EnumCastUnderlying(System::ProgramProperties::Type),
                                                         EnumCastUnderlying(System::ProgramProperties::ArraySize),
                                                         EnumCastUnderlying(System::ProgramProperties::Offset),
                                                         EnumCastUnderlying(System::ProgramProperties::TransformFeedbackBufferIndex) };

        const auto numProperties = boost::numeric_cast<System::OpenGLSize>(properties.size());

        std::vector<OpenGLInt> results(properties.size(), 0);
        for (auto i = 0; i < numResources; ++i)
        {
            System::GetGLProgramResource(handle, ProgramInterface::TransformFeedbackVarying, i, numProperties, properties.data(), numProperties, nullptr, results.data());

            const auto numBytes = boost::numeric_cast<System::OpenGLSize>(results.at(NameLength) + 1);
            std::vector<System::OpenGLChar> name(numBytes);
            System::GetGLProgramResourceName(handle, ProgramInterface::TransformFeedbackVarying, i, numBytes, nullptr, name.data());

            auto& info = transformFeedbackVaryings.at(i);
            info.SetName(name.data());
            info.SetType(results.at(Type));
            info.SetArraySize(results.at(ArraySize));
            info.SetOffset(results.at(Offset));
            info.SetTransformFeedbackBufferIndex(results.at(TransformFeedbackBufferIndex));
        }
    }
}

void Rendering::GLSLReflectionImpl::ReflectTransformFeedbackBuffers()
{
    const auto numResources = System::GetGLProgramInterface(handle, ProgramInterface::TransformFeedbackBuffer, System::ProgramInterfaceName::ActiveResources);

    if (numResources > 0)
    {
        transformFeedbackBuffers.resize(numResources, GLSLReflectionTransformFeedbackBuffer{ 0 });

        enum
        {
            BufferBinding,
            TransformFeedbackBufferStride,
            NumActiveVariables
        };

        static const std::vector<OpenGLEnum> properties{ EnumCastUnderlying(System::ProgramProperties::BufferBinding),
                                                         EnumCastUnderlying(System::ProgramProperties::TransformFeedbackBufferStride),
                                                         EnumCastUnderlying(System::ProgramProperties::NumActiveVariables) };

        const auto numProperties = boost::numeric_cast<System::OpenGLSize>(properties.size());

        std::vector<OpenGLInt> results(properties.size(), 0);
        for (auto i = 0; i < numResources; ++i)
        {
            System::GetGLProgramResource(handle, ProgramInterface::TransformFeedbackBuffer, i, numProperties, properties.data(), numProperties, nullptr, results.data());

            auto& info = transformFeedbackBuffers.at(i);
            info.SetBufferBinding(results.at(BufferBinding));
            info.SetTransformFeedbackBufferStride(results.at(TransformFeedbackBufferStride));

            auto numActiveVariables = results.at(NumActiveVariables);
            if (numActiveVariables > 0)
            {
                std::vector<OpenGLInt> activeVariables(numActiveVariables);
                auto varProperty = EnumCastUnderlying<OpenGLEnum>(System::ProgramProperties::ActiveVariables);

                System::GetGLProgramResource(handle, ProgramInterface::TransformFeedbackBuffer, i, 1, &varProperty, numActiveVariables, nullptr, activeVariables.data());
                info.SetActiveVariables(activeVariables);
            }
        }
    }
}

void Rendering::GLSLReflectionImpl::IntelWorkaround(const std::string& name, ResultsType& results)
{
    const auto maxCount = System::GetGLProgram(handle, System::ProgramAttributes::AttachedShaders);

    if (maxCount < 0)
    {
        return;
    }

    std::vector<OpenGLUInt> shaders(maxCount);
    System::OpenGLSize count{};
    System::GetAttachedGLShaders(handle, maxCount, &count, shaders.data());
    if (count != maxCount)
    {
        return;
    }

    for (auto shader : shaders)
    {
        const auto type = System::GetGLShader(shader, System::ShaderAttributes::ShaderType);

        const auto iter = shaderTypeMap.find(System::UnderlyingCastEnum<System::ShaderType>(type));
        if (iter != shaderTypeMap.end())
        {
            auto index = iter->second;
            if (results.at(index) == 0)
            {
                const auto length = System::GetGLShader(shader, System::ShaderAttributes::ShaderSourceLength);

                if (length <= 0)
                {
                    return;
                }

                std::vector<System::OpenGLChar> rawSource(length);
                System::GetGLShaderSource(shader, length, nullptr, rawSource.data());
                std::string source(rawSource.data());

                auto beginInstance = source.find("buffer " + name);
                if (beginInstance == std::string::npos)
                {
                    return;
                }

                beginInstance = source.find('}', beginInstance);
                if (beginInstance == std::string::npos)
                {
                    return;
                }

                if (++beginInstance >= source.length())
                {
                    return;
                }

                if (source.at(beginInstance) == ';')
                {
                    return;
                }

                beginInstance = source.find_first_not_of(" \t", beginInstance);
                if (beginInstance == std::string::npos)
                {
                    return;
                }

                const auto endInstance = source.find_first_of(" ;\t", beginInstance);
                auto instance = source.substr(beginInstance, endInstance - beginInstance);

                if (source.find(instance, endInstance) != std::string::npos)
                {
                    results.at(index) = 1;
                }
            }
        }
    }
}

const Rendering::GLSLReflectionEnumMap& Rendering::GLSLReflectionImpl::GetGLSLReflectionEnumMap(int index)
{
    using Container = std::array<const GLSLReflectionEnumMap, 113>;

    static Container result{ GLSLReflectionEnumMap{ GLSLReflectionEnumType::Float, "GL_FLOAT", "float", 1, 0, 4 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::FloatVec2, "GL_FLOAT_VEC2", "vec2", 2, 0, 4 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::FloatVec3, "GL_FLOAT_VEC3", "vec3", 3, 0, 4 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::FloatVec4, "GL_FLOAT_VEC4", "vec4", 4, 0, 4 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::Double, "GL_DOUBLE", "double", 1, 0, 8 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::DoubleVec2, "GL_DOUBLE_VEC2", "dvec2", 2, 0, 8 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::DoubleVec3, "GL_DOUBLE_VEC3", "dvec3", 3, 0, 8 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::DoubleVec2, "GL_DOUBLE_VEC4", "dvec4", 4, 0, 8 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::Int, "GL_INT", "int32_t", 1, 0, 4 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::IntVec2, "GL_INT_VEC2", "ivec2", 2, 0, 4 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::IntVec3, "GL_INT_VEC3", "ivec3", 3, 0, 4 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::IntVec4, "GL_INT_VEC4", "ivec4", 4, 0, 4 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::UnsignedInt, "GL_UNSIGNED_INT", "uint", 1, 0, 4 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::UnsignedIntVec2, "GL_UNSIGNED_INT_VEC2", "uvec2", 2, 0, 4 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::UnsignedIntVec3, "GL_UNSIGNED_INT_VEC3", "uvec3", 3, 0, 4 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::UnsignedIntVec4, "GL_UNSIGNED_INT_VEC4", "uvec4", 4, 0, 4 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::Bool, "GL_BOOL", "bool", 1, 0, 4 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::BoolVec2, "GL_BOOL_VEC2", "bvec2", 2, 0, 4 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::BoolVec3, "GL_BOOL_VEC3", "bvec3", 3, 0, 4 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::BoolVec4, "GL_BOOL_VEC4", "bvec4", 4, 0, 4 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::FloatMat2, "GL_FLOAT_MAT2", "mat2", 2, 2, 4 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::FloatMat3, "GL_FLOAT_MAT3", "mat3", 3, 3, 4 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::FloatMat4, "GL_FLOAT_MAT4", "mat4", 4, 4, 4 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::FloatMat2x3, "GL_FLOAT_MAT2x3", "mat2x3", 2, 3, 4 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::FloatMat2x4, "GL_FLOAT_MAT2x4", "mat2x4", 2, 4, 4 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::FloatMat3x2, "GL_FLOAT_MAT3x2", "mat3x2", 3, 2, 4 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::FloatMat3x4, "GL_FLOAT_MAT3x4", "mat3x4", 3, 4, 4 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::FloatMat4x2, "GL_FLOAT_MAT4x2", "mat4x2", 4, 2, 4 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::FloatMat4x3, "GL_FLOAT_MAT4x3", "mat4x3", 4, 3, 4 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::DoubleMat2, "GL_DOUBLE_MAT2", "dmat2", 2, 2, 8 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::DoubleMat3, "GL_DOUBLE_MAT3", "dmat3", 3, 3, 8 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::DoubleMat4, "GL_DOUBLE_MAT4", "dmat4", 4, 4, 8 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::DoubleMat2x3, "GL_DOUBLE_MAT2x3", "dmat2x3", 2, 3, 8 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::DoubleMat2x4, "GL_DOUBLE_MAT2x4", "dmat2x4", 2, 4, 8 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::DoubleMat3x2, "GL_DOUBLE_MAT3x2", "dmat3x2", 3, 2, 8 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::DoubleMat3x4, "GL_DOUBLE_MAT3x4", "dmat3x4", 3, 4, 8 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::DoubleMat4x2, "GL_DOUBLE_MAT4x2", "dmat4x2", 4, 2, 8 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::DoubleMat4x3, "GL_DOUBLE_MAT4x3", "dmat4x3", 4, 3, 8 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::Sampler1D, "GL_SAMPLER_1D", "sampler1D", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::Sampler2D, "GL_SAMPLER_2D", "sampler2D", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::Sampler3D, "GL_SAMPLER_3D", "sampler3D", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::SamplerCube, "GL_SAMPLER_CUBE", "samplerCube", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::Sampler1DShadow, "GL_SAMPLER_1D_SHADOW", "sampler1DShadow", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::Sampler2DShadow, "GL_SAMPLER_2D_SHADOW", "sampler2DShadow", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::Sampler1DArray, "GL_SAMPLER_1D_ARRAY", "sampler1DArray", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::Sampler2DArray, "GL_SAMPLER_2D_ARRAY", "sampler2DArray", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::Sampler1DArrayShadow, "GL_SAMPLER_1D_ARRAY_SHADOW", "sampler1DArrayShadow", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::Sampler2DArrayShadow, "GL_SAMPLER_2D_ARRAY_SHADOW", "sampler2DArrayShadow", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::Sampler2DMultisample, "GL_SAMPLER_2D_MULTISAMPLE", "sampler2DMS", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::Sampler2DMultisampleArray, "GL_SAMPLER_2D_MULTISAMPLE_ARRAY", "sampler2DMSArray", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::SamplerCubeShadow, "GL_SAMPLER_CUBE_SHADOW", "samplerCubeShadow", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::SamplerCubeMapArray, "GL_SAMPLER_CUBE_MAP_ARRAY", "samplerCubeArray", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::SamplerCubeMapArrayShadow, "GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW", "samplerCubeArrayShadow", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::SamplerBuffer, "GL_SAMPLER_BUFFER", "samplerBuffer", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::Sampler2DRect, "GL_SAMPLER_2D_RECT", "sampler2DRect", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::Sampler2DRectShadow, "GL_SAMPLER_2D_RECT_SHADOW", "sampler2DRectShadow", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::IntSampler1D, "GL_INT_SAMPLER_1D", "isampler1D", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::IntSampler2D, "GL_INT_SAMPLER_2D", "isampler2D", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::IntSampler3D, "GL_INT_SAMPLER_3D", "isampler3D", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::IntSamplerCube, "GL_INT_SAMPLER_CUBE", "isamplerCube", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::IntSampler1DArray, "GL_INT_SAMPLER_1D_ARRAY", "isampler1DArray", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::IntSampler2DArray, "GL_INT_SAMPLER_2D_ARRAY", "isampler2DArray", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::IntSampler2DMultisample, "GL_INT_SAMPLER_2D_MULTISAMPLE", "isampler2DMS", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::IntSampler2DMultisampleArray, "GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY", "isampler2DMSArray", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::IntSamplerCubeMapArray, "GL_INT_SAMPLER_CUBE_MAP_ARRAY", "isamplerCubeArray", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::IntSamplerBuffer, "GL_INT_SAMPLER_BUFFER", "isamplerBuffer", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::IntSampler2DRect, "GL_INT_SAMPLER_2D_RECT", "isampler2DRect", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::UnsignedIntSampler1D, "GL_UNSIGNED_INT_SAMPLER_1D", "usampler1D", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::UnsignedIntSampler2D, "GL_UNSIGNED_INT_SAMPLER_2D", "usampler2D", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::UnsignedIntSampler3D, "GL_UNSIGNED_INT_SAMPLER_3D", "usampler3D", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::UnsignedIntSamplerCube, "GL_UNSIGNED_INT_SAMPLER_CUBE", "usamplerCube", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::UnsignedIntSampler1DArray, "GL_UNSIGNED_INT_SAMPLER_1D_ARRAY", "usampler2DArray", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::UnsignedIntSampler2DArray, "GL_UNSIGNED_INT_SAMPLER_2D_ARRAY", "usampler2DArray", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::UnsignedIntSampler2DMultisample, "GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE", "usampler2DMS", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::UnsignedIntSampler2DMultisampleArray, "GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY", "usampler2DMSArray", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::UnsignedIntSamplerCubeMapArray, "GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY", "usamplerCubeArray", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::UnsignedIntSamplerBuffer, "GL_UNSIGNED_INT_SAMPLER_BUFFER", "usamplerBuffer", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::UnsignedIntSampler2DRect, "GL_UNSIGNED_INT_SAMPLER_2D_RECT", "usampler2DRect", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::Image1D, "GL_IMAGE_1D", "image1D", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::Image2D, "GL_IMAGE_2D", "image2D", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::Image3D, "GL_IMAGE_3D", "image3D", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::ImageCube, "GL_IMAGE_CUBE", "imageCube", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::Image1DArray, "GL_IMAGE_1D_ARRAY", "image1DArray", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::Image2DArray, "GL_IMAGE_2D_ARRAY", "image2DArray", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::Image2DMultisample, "GL_IMAGE_2D_MULTISAMPLE", "image2DMS", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::Image2DMultisampleArray, "GL_IMAGE_2D_MULTISAMPLE_ARRAY", "image2DMSArray", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::ImageCubeMapArray, "GL_IMAGE_CUBE_MAP_ARRAY", "imageCubeArray", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::ImageBuffer, "GL_IMAGE_BUFFER", "imageBuffer", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::Image2DRect, "GL_IMAGE_2D_RECT", "image2DRect", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::IntImage1D, "GL_INT_IMAGE_1D", "iimage1D", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::IntImage2D, "GL_INT_IMAGE_2D", "iimage2D", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::IntImage3D, "GL_INT_IMAGE_3D", "iimage3D", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::IntImageCube, "GL_INT_IMAGE_CUBE", "iimageCube", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::IntImage1DArray, "GL_INT_IMAGE_1D_ARRAY", "iimage1DArray", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::IntImage2DArray, "GL_INT_IMAGE_2D_ARRAY", "iimage2DArray", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::IntImage2DMultisample, "GL_INT_IMAGE_2D_MULTISAMPLE", "iimage2DMS", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::IntImage2DMultisampleArray, "GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY", "iimage2DMSArray", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::IntImageCubeMapArray, "GL_INT_IMAGE_CUBE_MAP_ARRAY", "iimageCubeArray", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::IntImageBuffer, "GL_INT_IMAGE_BUFFER", "iimageBuffer", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::IntImage2DRect, "GL_INT_IMAGE_2D_RECT", "iimage2DRect", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::UnsignedIntImage1D, "GL_UNSIGNED_INT_IMAGE_1D", "uimage1D", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::UnsignedIntImage2D, "GL_UNSIGNED_INT_IMAGE_2D", "uimage2D", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::UnsignedIntImage3D, "GL_UNSIGNED_INT_IMAGE_3D", "uimage3D", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::UnsignedIntImageCube, "GL_UNSIGNED_INT_IMAGE_CUBE", "uimageCube", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::UnsignedIntImage1DArray, "GL_UNSIGNED_INT_IMAGE_1D_ARRAY", "uimage2DArray", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::UnsignedIntImage2DArray, "GL_UNSIGNED_INT_IMAGE_2D_ARRAY", "uimage2DArray", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::UnsignedIntImage2DMultisample, "GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE", "uimage2DMS", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::UnsignedIntImage2DMultisampleArray, "GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY", "uimage2DMSArray", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::UnsignedIntImageCubeMapArray, "GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY", "uimageCubeArray", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::UnsignedIntImageBuffer, "GL_UNSIGNED_INT_IMAGE_BUFFER", "uimageBuffer", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::UnsignedIntImage2DRect, "GL_UNSIGNED_INT_IMAGE_2D_RECT", "uimage2DRect", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::UnsignedIntAtomicCounter, "GL_UNSIGNED_INT_ATOMIC_COUNTER", "atomic_uint", 0, 0, 0 },
                             GLSLReflectionEnumMap{ GLSLReflectionEnumType::None, "", "", 0, 0, 0 } };

    return result.at(index);
}

int Rendering::GLSLReflectionImpl::GetEnumSize(GLSLReflectionEnumType value, OpenGLInt arraySize, OpenGLInt arrayStride, OpenGLInt matrixStride, OpenGLInt isRowMajor)
{
    for (auto i = 0; GetGLSLReflectionEnumMap(i).GetValue() != GLSLReflectionEnumType::None; ++i)
    {
        const auto& item = GetGLSLReflectionEnumMap(i);
        if (item.GetValue() == value)
        {
            if (arrayStride > 0)
            {
                return arrayStride * arraySize;
            }
            else if (matrixStride > 0)
            {
                if (isRowMajor)
                {
                    return item.GetRows() * matrixStride;
                }
                else
                {
                    return item.GetCols() * matrixStride;
                }
            }
            else if (item.GetRows() > 0)
            {
                return item.GetRows() * item.GetSize();
            }
            return 0;
        }
    }

    return 0;
}

std::string Rendering::GLSLReflectionImpl::GetEnumName(GLSLReflectionEnumType value)
{
    for (auto i = 0; GetGLSLReflectionEnumMap(i).GetValue() != GLSLReflectionEnumType::None; ++i)
    {
        const auto& item = GetGLSLReflectionEnumMap(i);
        if (item.GetValue() == value)
        {
            return item.GetName();
        }
    }

    return std::string{ "unknown(type=" } + std::to_string(EnumCastUnderlying(value)) + ")";
}

std::string Rendering::GLSLReflectionImpl::GetEnumShaderName(GLSLReflectionEnumType value)
{
    for (auto i = 0; GetGLSLReflectionEnumMap(i).GetValue() != GLSLReflectionEnumType::None; ++i)
    {
        const auto& item = GetGLSLReflectionEnumMap(i);
        if (item.GetValue() == value)
        {
            return item.GetShaderName();
        }
    }

    return std::string{ "unknown(type=" } + std::to_string(EnumCastUnderlying(value)) + ")";
}

std::string Rendering::GLSLReflectionImpl::GetReferencedByShaderList(const ReferencedBy& referencedBy)
{
    std::string strList{};

    if (referencedBy.at(System::EnumCastUnderlying(ReferenceType::Vertex)))
        strList += "vertex ";
    if (referencedBy.at(System::EnumCastUnderlying(ReferenceType::Geometry)))
        strList += "geometry ";
    if (referencedBy.at(System::EnumCastUnderlying(ReferenceType::Pixel)))
        strList += "pixel ";
    if (referencedBy.at(System::EnumCastUnderlying(ReferenceType::Compute)))
        strList += "compute ";
    if (referencedBy.at(System::EnumCastUnderlying(ReferenceType::TessControl)))
        strList += "tessControl ";
    if (referencedBy.at(System::EnumCastUnderlying(ReferenceType::TessEvaluation)))
        strList += "tessEvaluation ";

    return strList;
}

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:46)

#include "OpenGLProgramResourceTestingBase.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/OpenGL/Flags/OpenGLProgramFlags.h"
#include "System/OpenGL/OpenGLShader.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLProgramResourceTestingBase::OpenGLProgramResourceTestingBase(const OStreamShared& stream)
    : ParentType{ stream },
      code{ "#version 400\n",
            "uniform ProjectionViewWorldMatrix\n",
            "{\n",
            "     mat4 projectionViewWorldMatrix;\n",
            "};\n",

            "in vec3 modelPosition;\n",
            "in vec3 inPosition;\n",

            "void main()\n",
            "{\n",
            "     gl_Position = projectionViewWorldMatrix * vec4(modelPosition, 1.0f) * vec4(inPosition, 1.0f);\n",
            "}\n" },
      programInterfaces{ ProgramInterface::Uniform,
                         ProgramInterface::UniformBlock,
                         ProgramInterface::AtomicCounterBuffer,
                         ProgramInterface::ProgramInput,
                         ProgramInterface::ProgramOutput,
                         ProgramInterface::VertexSubroutine,
                         ProgramInterface::TessControlSubroutine,
                         ProgramInterface::TessEvaluationSubroutine,
                         ProgramInterface::GeometrySubroutine,
                         ProgramInterface::FragmentSubroutine,
                         ProgramInterface::ComputeSubroutine,
                         ProgramInterface::VertexSubroutineUniform,
                         ProgramInterface::TessControlSubroutineUniform,
                         ProgramInterface::TessEvaluationSubroutineUniform,
                         ProgramInterface::GeometrySubroutineUniform,
                         ProgramInterface::FragmentSubroutineUniform,
                         ProgramInterface::ComputeSubroutineUniform,
                         ProgramInterface::TransformFeedbackVarying,
                         ProgramInterface::BufferVariable,
                         ProgramInterface::ShaderStorageBlock,
                         ProgramInterface::TransformFeedbackBuffer },
      programInterfaceNames{ ProgramInterfaceName::ActiveResources,
                             ProgramInterfaceName::MaxNameLength,
                             ProgramInterfaceName::MaxNumActiveVariables,
                             ProgramInterfaceName::MaxNumCompatibleSubroutines }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLProgramResourceTestingBase)

bool System::OpenGLProgramResourceTestingBase::IsProgramInterfaceInvalid(ProgramInterface programInterface, ProgramInterfaceName programInterfaceName) noexcept
{
    if (programInterfaceName == ProgramInterfaceName::MaxNameLength)
    {
        return programInterface == ProgramInterface::AtomicCounterBuffer ||
               programInterface == ProgramInterface::TransformFeedbackBuffer;
    }
    else if (programInterfaceName == ProgramInterfaceName::MaxNumActiveVariables)
    {
        return programInterface != ProgramInterface::UniformBlock &&
               programInterface != ProgramInterface::AtomicCounterBuffer &&
               programInterface != ProgramInterface::ShaderStorageBlock;
    }
    else if (programInterfaceName == ProgramInterfaceName::MaxNumCompatibleSubroutines)
    {
        return programInterface != ProgramInterface::VertexSubroutineUniform &&
               programInterface != ProgramInterface::TessControlSubroutineUniform &&
               programInterface != ProgramInterface::TessEvaluationSubroutineUniform &&
               programInterface != ProgramInterface::GeometrySubroutineUniform &&
               programInterface != ProgramInterface::FragmentSubroutineUniform &&
               programInterface != ProgramInterface::ComputeSubroutineUniform;
    }

    return false;
}

void System::OpenGLProgramResourceTestingBase::ShaderSourceTest(OpenGLUnsignedInt shaderHandle) const
{
    SetGLShaderSource(shaderHandle, boost::numeric_cast<OpenGLSize>(code.size()), code.data(), nullptr);
}

System::ProgramInterface System::OpenGLProgramResourceTestingBase::GetProgramInterface(int index) const
{
    const auto correctIndex = index % programInterfaces.size();

    return programInterfaces.at(correctIndex);
}

System::ProgramInterfaceName System::OpenGLProgramResourceTestingBase::GetProgramInterfaceName(int index) const
{
    const auto correctIndex = index % programInterfaceNames.size();

    return programInterfaceNames.at(correctIndex);
}

int System::OpenGLProgramResourceTestingBase::GetProgramInterfaceCount() const
{
    return boost::numeric_cast<int>(programInterfaces.size());
}

int System::OpenGLProgramResourceTestingBase::GetProgramInterfaceNameCount() const
{
    return boost::numeric_cast<int>(programInterfaceNames.size());
}

///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/05 14:34)

#include "Rendering/RenderingExport.h"

#include "Reflection.h"
#include "Detail/ReflectionFactory.h"
#include "Detail/ReflectionImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Shaders/ReflectionAtomicCounterBuffer.h"
#include "Rendering/Shaders/ReflectionBufferVariable.h"
#include "Rendering/Shaders/ReflectionDataBlock.h"
#include "Rendering/Shaders/ReflectionUniform.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Rendering, Reflection)

Rendering::Reflection Rendering::Reflection::Create()
{
    return Reflection{ CoreTools::DisableNotThrow::Disable };
}

Rendering::Reflection::Reflection(CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseFactory::Default }
{
    System::UnusedFunction(disableNotThrow);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::Reflection::Reflection(OpenGLUInt handle)
    : impl{ CoreTools::ImplCreateUseFactory::Default, handle }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, Reflection)

Rendering::Reflection::OpenGLUInt Rendering::Reflection::GetProgramHandle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetProgramHandle();
}

Rendering::Reflection::InputContainer Rendering::Reflection::GetInputs() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetInputs();
}

Rendering::Reflection::OutputContainer Rendering::Reflection::GetOutputs() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetOutputs();
}

Rendering::Reflection::UniformContainer Rendering::Reflection::GetUniforms() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetUniforms();
}

Rendering::Reflection::DataBlockContainer Rendering::Reflection::GetUniformBlocks() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetUniformBlocks();
}

Rendering::Reflection::BufferVariableContainer Rendering::Reflection::GetBufferVariables() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetBufferVariables();
}

Rendering::Reflection::DataBlockContainer Rendering::Reflection::GetBufferBlocks() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetBufferBlocks();
}

Rendering::Reflection::AtomicCounterBufferContainer Rendering::Reflection::GetAtomicCounterBuffers() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetAtomicCounterBuffers();
}

Rendering::Reflection::NumThreads Rendering::Reflection::GetComputeShaderWorkGroupSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetComputeShaderWorkGroupSize();
}

void Rendering::Reflection::Print(std::ofstream& output) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->Print(output);
}

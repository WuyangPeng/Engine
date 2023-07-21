///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/05 14:34)

#include "Rendering/RenderingExport.h"

#include "ComputeProgram.h"
#include "Reflection.h"
#include "Detail/ComputeProgramFactory.h"
#include "Detail/ComputeProgramImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Rendering, ComputeProgram)

Rendering::ComputeProgram Rendering::ComputeProgram::Create()
{
    return ComputeProgram{ CoreTools::DisableNotThrow::Disable };
}

Rendering::ComputeProgram::ComputeProgram(CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseFactory::Default }
{
    System::UnusedFunction(disableNotThrow);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ComputeProgram::ComputeProgram(OpenGLUInt programHandle, OpenGLUInt computeShaderHandle)
    : impl{ CoreTools::ImplCreateUseFactory::Default, programHandle, computeShaderHandle }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ComputeProgram)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ComputeProgram, GetComputeShader, Rendering::ComputeProgram::ConstShaderSharedPtr)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, ComputeProgram, SetComputeShader, ShaderSharedPtr, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ComputeProgram, GetReflector, Rendering::Reflection)
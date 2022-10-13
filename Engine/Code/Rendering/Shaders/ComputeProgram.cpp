///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/20 16:17)

#include "Rendering/RenderingExport.h"

#include "ComputeProgram.h"
#include "Detail/ComputeProgramImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, ComputeProgram)

Rendering::ComputeProgram::ComputeProgram(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ComputeProgram)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ComputeProgram, GetComputeShader, Rendering::ComputeProgram::ConstShaderSharedPtr)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, ComputeProgram, SetComputeShader, ShaderSharedPtr, void)

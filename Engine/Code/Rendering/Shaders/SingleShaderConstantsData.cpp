///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:54)

#include "Rendering/RenderingExport.h"

#include "SingleShaderConstantsData.h"
#include "Detail/SingleShaderConstantsDataImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"

Rendering::SingleShaderConstantsData::SingleShaderConstantsData(const std::string& name, int numRegistersUsed)
    : impl{ name, numRegistersUsed }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::SingleShaderConstantsData::SingleShaderConstantsData(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, SingleShaderConstantsData)

void Rendering::SingleShaderConstantsData::SetConstant(const std::string& name, int numRegistersUsed)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetConstant(name, numRegistersUsed);
}

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, SingleShaderConstantsData)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderConstantsData, GetConstantName, std::string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SingleShaderConstantsData, GetNumRegistersUsed, int)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderConstantsData, Load, CoreTools::BufferSource&, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderConstantsData, Save, CoreTools::BufferTarget&, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderConstantsData, GetStreamingSize, int)

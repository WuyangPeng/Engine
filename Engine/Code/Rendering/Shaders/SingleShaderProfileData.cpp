///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:54)

#include "Rendering/RenderingExport.h"

#include "SingleShaderProfileData.h"
#include "Detail/SingleShaderProfileDataImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Rendering::SingleShaderProfileData::SingleShaderProfileData(int numConstants, int numSamplers)
    : impl{ numConstants, numSamplers }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::SingleShaderProfileData::SingleShaderProfileData(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : impl{ 0, 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, SingleShaderProfileData)

void Rendering::SingleShaderProfileData::SetBaseRegister(int index, int baseRegister)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetBaseRegister(index, baseRegister);
}

void Rendering::SingleShaderProfileData::SetTextureUnit(int index, int textureUnit)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetTextureUnit(index, textureUnit);
}

void Rendering::SingleShaderProfileData::ResetData(int numConstants, int numSamplers)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->ResetData(numConstants, numSamplers);
}

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, SingleShaderProfileData)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, SingleShaderProfileData, SetProgram, std::string, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderProfileData, GetBaseRegister, int, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderProfileData, GetTextureUnit, int, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderProfileData, GetProgram, std::string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderProfileData, GetBaseRegisterSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderProfileData, GetTextureUnitSize, int)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderProfileData, Load, CoreTools::BufferSource&, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderProfileData, Save, CoreTools::BufferTarget&, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderProfileData, GetStreamingSize, int)

// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/24 17:13)

#include "Rendering/RenderingExport.h"

#include "SingleShaderProfileData.h"
#include "Detail/SingleShaderProfileDataImpl.h"

#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
using std::make_shared;
using std::string;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
Rendering::SingleShaderProfileData ::SingleShaderProfileData(int numConstants, int numSamplers)
    : impl{ numConstants, numSamplers }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::SingleShaderProfileData ::SingleShaderProfileData()
    : impl{ 0, 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, SingleShaderProfileData)

void Rendering::SingleShaderProfileData ::SetBaseRegister(int index, int baseRegister)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetBaseRegister(index, baseRegister);
}

void Rendering::SingleShaderProfileData ::SetTextureUnit(int index, int textureUnit)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetTextureUnit(index, textureUnit);
}

void Rendering::SingleShaderProfileData ::ResetData(int numConstants, int numSamplers)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->ResetData(numConstants, numSamplers);
}
COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, SingleShaderProfileData)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, SingleShaderProfileData, SetProgram, string, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderProfileData, GetBaseRegister, int, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderProfileData, GetTextureUnit, int, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderProfileData, GetProgram, const string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderProfileData, GetBaseRegisterSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderProfileData, GetTextureUnitSize, int)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderProfileData, Load, CoreTools::BufferSource&, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderProfileData, Save, CoreTools::BufferTarget&, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderProfileData, GetStreamingSize, int)
#include STSTEM_WARNING_POP
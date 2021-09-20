// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/24 17:12)

#include "Rendering/RenderingExport.h"

#include "SingleShaderConstantsData.h"
#include "Detail/SingleShaderConstantsDataImpl.h"

#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
using std::make_shared;
using std::string;
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
Rendering::SingleShaderConstantsData ::SingleShaderConstantsData(const string& name, int numRegistersUsed)
    : impl{ name, numRegistersUsed }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::SingleShaderConstantsData ::SingleShaderConstantsData()
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, SingleShaderConstantsData)

void Rendering::SingleShaderConstantsData ::SetConstant(const string& name, int numRegistersUsed)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetConstant(name, numRegistersUsed);
}
COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, SingleShaderConstantsData)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderConstantsData, GetConstantName, const string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SingleShaderConstantsData, GetNumRegistersUsed, int)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, SingleShaderConstantsData, Load, CoreTools::BufferSourceSharedPtr, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, SingleShaderConstantsData, Save, CoreTools::BufferTargetSharedPtr, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderConstantsData, GetStreamingSize, int)
#include STSTEM_WARNING_POP
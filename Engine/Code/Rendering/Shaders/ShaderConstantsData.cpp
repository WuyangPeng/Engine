// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/24 17:03)

#include "Rendering/RenderingExport.h"

#include "ShaderConstantsData.h"
#include "Detail/ShaderConstantsDataImpl.h"
#include "Detail/SingleShaderBaseDataImpl.h"
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
Rendering::ShaderConstantsData ::ShaderConstantsData(int numConstants)
    : impl{ numConstants }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ShaderConstantsData ::ShaderConstantsData()
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}
COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, ShaderConstantsData)
CLASS_INVARIANT_STUB_DEFINE(Rendering, ShaderConstantsData)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderConstantsData, Resize, int, void)

void Rendering::ShaderConstantsData ::SetConstant(int index, const string& name, int numRegistersUsed)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetConstant(index, name, numRegistersUsed);
}

void Rendering::ShaderConstantsData ::InsertData(const string& name, int numRegistersUsed)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->InsertData(name, numRegistersUsed);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderConstantsData, GetNumConstants, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderConstantsData, GetConstantName, int, const string)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderConstantsData, GetNumRegistersUsed, int, int)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, ShaderConstantsData, Load, CoreTools::BufferSourceSharedPtr, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, ShaderConstantsData, Save, CoreTools::BufferTargetSharedPtr, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderConstantsData, GetStreamingSize, int)

#include STSTEM_WARNING_POP
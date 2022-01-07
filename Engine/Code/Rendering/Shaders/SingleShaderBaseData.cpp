// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/24 17:10)

#include "Rendering/RenderingExport.h"

#include "SingleShaderBaseData.h"
#include "Detail/SingleShaderBaseDataImpl.h"

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
Rendering::SingleShaderBaseData ::SingleShaderBaseData(const string& name, ShaderFlags::VariableType type, ShaderFlags::VariableSemantic semantic)
    : impl{ name, type, semantic }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::SingleShaderBaseData ::SingleShaderBaseData()
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, SingleShaderBaseData)
COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, SingleShaderBaseData)
void Rendering::SingleShaderBaseData ::SetData(const string& name, ShaderFlags::VariableType type, ShaderFlags::VariableSemantic semantic)
{
    RENDERING_CLASS_IS_VALID_1;

    impl->SetData(name, type, semantic);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderBaseData, GetName, const string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SingleShaderBaseData, GetType, Rendering::ShaderFlags::VariableType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SingleShaderBaseData, GetSemantic, Rendering::ShaderFlags::VariableSemantic)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderBaseData, Load, CoreTools::BufferSource&, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderBaseData, Save, CoreTools::BufferTarget&, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderBaseData, GetStreamingSize, int)
#include STSTEM_WARNING_POP
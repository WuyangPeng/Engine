// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/24 17:01)

#include "Rendering/RenderingExport.h"

#include "ShaderBaseData.h"
#include "Detail/ShaderBaseDataImpl.h"
#include "Detail/SingleShaderBaseDataImpl.h"

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
Rendering::ShaderBaseData ::ShaderBaseData(int number)
    : impl{ number }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}
COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, ShaderBaseData)
Rendering::ShaderBaseData ::ShaderBaseData()
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ShaderBaseData)

void Rendering::ShaderBaseData ::SetData(int index, const string& name, ShaderFlags::VariableType type, ShaderFlags::VariableSemantic semantic)
{
    RENDERING_CLASS_IS_VALID_1;

    impl->SetData(index, name, type, semantic);
}

void Rendering::ShaderBaseData ::InsertData(const string& name, ShaderFlags::VariableType type,
                                            ShaderFlags::VariableSemantic semantic)
{
    RENDERING_CLASS_IS_VALID_1;

    impl->InsertData(name, type, semantic);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderBaseData, GetNumber, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderBaseData, GetName, int, const string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderBaseData, GetType, int, Rendering::ShaderFlags::VariableType)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderBaseData, GetSemantic, int, Rendering::ShaderFlags::VariableSemantic)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderBaseData, Resize, int, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderBaseData, Load, CoreTools::BufferSource&, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderBaseData, Save, CoreTools::BufferTarget&, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderBaseData, GetStreamingSize, int)

#include STSTEM_WARNING_POP
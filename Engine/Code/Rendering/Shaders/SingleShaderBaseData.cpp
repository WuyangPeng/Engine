///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/13 16:38)

#include "Rendering/RenderingExport.h"

#include "SingleShaderBaseData.h"
#include "Detail/SingleShaderBaseDataImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"

using std::make_shared;
using std::string;

Rendering::SingleShaderBaseData::SingleShaderBaseData(const string& name, ShaderFlags::VariableType type, ShaderFlags::VariableSemantic semantic)
    : impl{ name, type, semantic }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::SingleShaderBaseData::SingleShaderBaseData(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, SingleShaderBaseData)
COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, SingleShaderBaseData)

void Rendering::SingleShaderBaseData::SetData(const string& name, ShaderFlags::VariableType type, ShaderFlags::VariableSemantic semantic)
{
    RENDERING_CLASS_IS_VALID_1;

    impl->SetData(name, type, semantic);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderBaseData, GetName, string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SingleShaderBaseData, GetType, Rendering::ShaderFlags::VariableType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SingleShaderBaseData, GetSemantic, Rendering::ShaderFlags::VariableSemantic)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderBaseData, Load, CoreTools::BufferSource&, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderBaseData, Save, CoreTools::BufferTarget&, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderBaseData, GetStreamingSize, int)

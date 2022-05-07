///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/13 15:06)

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

Rendering::ShaderBaseData::ShaderBaseData(int number)
    : impl{ number }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}
COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, ShaderBaseData)

CLASS_INVARIANT_STUB_DEFINE(Rendering, ShaderBaseData)

void Rendering::ShaderBaseData::SetData(int index, const string& name, ShaderFlags::VariableType type, ShaderFlags::VariableSemantic semantic)
{
    RENDERING_CLASS_IS_VALID_1;

    impl->SetData(index, name, type, semantic);
}

void Rendering::ShaderBaseData::InsertData(const string& name, ShaderFlags::VariableType type,
                                           ShaderFlags::VariableSemantic semantic)
{
    RENDERING_CLASS_IS_VALID_1;

    impl->InsertData(name, type, semantic);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderBaseData, GetNumber, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderBaseData, GetName, int, string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderBaseData, GetType, int, Rendering::ShaderFlags::VariableType)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderBaseData, GetSemantic, int, Rendering::ShaderFlags::VariableSemantic)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderBaseData, Resize, int, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderBaseData, Load, CoreTools::BufferSource&, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderBaseData, Save, CoreTools::BufferTarget&, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderBaseData, GetStreamingSize, int)

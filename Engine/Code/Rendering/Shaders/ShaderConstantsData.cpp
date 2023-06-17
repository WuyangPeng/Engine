///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:52)

#include "Rendering/RenderingExport.h"

#include "ShaderConstantsData.h"
#include "Detail/ShaderConstantsDataImpl.h"
#include "Detail/SingleShaderBaseDataImpl.h"
#include "Detail/SingleShaderConstantsDataImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"

Rendering::ShaderConstantsData::ShaderConstantsData(int numConstants)
    : impl{ numConstants }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, ShaderConstantsData)
CLASS_INVARIANT_STUB_DEFINE(Rendering, ShaderConstantsData)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderConstantsData, Resize, int, void)

void Rendering::ShaderConstantsData::SetConstant(int index, const std::string& name, int numRegistersUsed)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetConstant(index, name, numRegistersUsed);
}

void Rendering::ShaderConstantsData::InsertData(const std::string& name, int numRegistersUsed)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->InsertData(name, numRegistersUsed);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderConstantsData, GetNumConstants, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderConstantsData, GetConstantName, int, std::string)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderConstantsData, GetNumRegistersUsed, int, int)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderConstantsData, Load, CoreTools::BufferSource&, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderConstantsData, Save, CoreTools::BufferTarget&, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderConstantsData, GetStreamingSize, int)

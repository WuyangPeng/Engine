///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:54)

#include "Rendering/RenderingExport.h"

#include "SingleShaderSamplerData.h"
#include "Detail/SingleShaderSamplerDataImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Rendering/DataTypes/SpecializedIO.h"

Rendering::SingleShaderSamplerData::SingleShaderSamplerData(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, SingleShaderSamplerData)

void Rendering::SingleShaderSamplerData::SetSampler(const std::string& name, ShaderFlags::SamplerType type)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetSampler(name, type);
}

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, SingleShaderSamplerData)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderSamplerData, SetFilter, ShaderFlags::SamplerFilter, void)

void Rendering::SingleShaderSamplerData::SetCoordinate(int dimension, ShaderFlags::SamplerCoordinate coordinate)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetCoordinate(dimension, coordinate);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderSamplerData, SetLodBias, float, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderSamplerData, SetAnisotropy, float, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, SingleShaderSamplerData, SetBorderColor, Colour, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderSamplerData, GetSamplerName, std::string)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SingleShaderSamplerData, GetSamplerType, Rendering::ShaderFlags::SamplerType)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SingleShaderSamplerData, GetFilter, Rendering::ShaderFlags::SamplerFilter)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderSamplerData, GetCoordinate, int, Rendering::ShaderFlags::SamplerCoordinate)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SingleShaderSamplerData, GetLodBias, float)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SingleShaderSamplerData, GetAnisotropy, float)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SingleShaderSamplerData, GetBorderColor, Rendering::SingleShaderSamplerDataImpl::Colour)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderSamplerData, Load, CoreTools::BufferSource&, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderSamplerData, Save, CoreTools::BufferTarget&, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderSamplerData, GetStreamingSize, int)

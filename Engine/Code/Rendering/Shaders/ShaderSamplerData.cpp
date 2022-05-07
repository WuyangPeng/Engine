///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/13 16:35)

#include "Rendering/RenderingExport.h"

#include "ShaderSamplerData.h"
#include "Detail/ShaderSamplerDataImpl.h"
#include "Detail/SingleShaderBaseDataImpl.h"
#include "Detail/SingleShaderSamplerDataImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Rendering/DataTypes/SpecializedIO.h"

using std::make_shared;
using std::string;

Rendering::ShaderSamplerData::ShaderSamplerData(int numSamplers)
    : impl{ numSamplers }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, ShaderSamplerData)
CLASS_INVARIANT_STUB_DEFINE(Rendering, ShaderSamplerData)

void Rendering::ShaderSamplerData::SetSampler(int index, const string& name, ShaderFlags::SamplerType type)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetSampler(index, name, type);
}

void Rendering::ShaderSamplerData::SetFilter(int index, ShaderFlags::SamplerFilter filter)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetFilter(index, filter);
}

void Rendering::ShaderSamplerData::SetCoordinate(int index, int dimension, ShaderFlags::SamplerCoordinate coordinate)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetCoordinate(index, dimension, coordinate);
}

void Rendering::ShaderSamplerData::SetLodBias(int index, float lodBias)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetLodBias(index, lodBias);
}

void Rendering::ShaderSamplerData::SetAnisotropy(int index, float anisotropy)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetAnisotropy(index, anisotropy);
}

void Rendering::ShaderSamplerData::SetBorderColor(int index, const Colour& borderColor)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetBorderColor(index, borderColor);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderSamplerData, GetNumSamplers, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderSamplerData, GetSamplerName, int, string)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderSamplerData, GetSamplerType, int, Rendering::ShaderFlags::SamplerType)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderSamplerData, GetFilter, int, Rendering::ShaderFlags::SamplerFilter)

Rendering::ShaderFlags::SamplerCoordinate
    Rendering::ShaderSamplerData::GetCoordinate(int index, int dimension) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetCoordinate(index, dimension);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderSamplerData, GetLodBias, int, float)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderSamplerData, GetAnisotropy, int, float)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderSamplerData, GetBorderColor, int, Rendering::ShaderSamplerData::Colour)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderSamplerData, Load, CoreTools::BufferSource&, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderSamplerData, Save, CoreTools::BufferTarget&, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderSamplerData, GetStreamingSize, int)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderSamplerData, Resize, int, void)

// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/24 17:14)

#include "Rendering/RenderingExport.h"

#include "SingleShaderSamplerData.h"
#include "Detail/SingleShaderSamplerDataImpl.h"

#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Rendering/DataTypes/SpecializedIO.h"
using std::make_shared;
using std::string;
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
Rendering::SingleShaderSamplerData ::SingleShaderSamplerData()
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, SingleShaderSamplerData)

void Rendering::SingleShaderSamplerData ::SetSampler(const string& name, ShaderFlags::SamplerType type)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetSampler(name, type);
}

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, SingleShaderSamplerData)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderSamplerData, SetFilter, ShaderFlags::SamplerFilter, void)

void Rendering::SingleShaderSamplerData ::SetCoordinate(int dimension, ShaderFlags::SamplerCoordinate coordinate)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetCoordinate(dimension, coordinate);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderSamplerData, SetLodBias, float, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderSamplerData, SetAnisotropy, float, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, SingleShaderSamplerData, SetBorderColor, Colour, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderSamplerData, GetSamplerName, const string)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderSamplerData, GetSamplerType, Rendering::ShaderFlags::SamplerType)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderSamplerData, GetFilter, Rendering::ShaderFlags::SamplerFilter)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderSamplerData, GetCoordinate, int, Rendering::ShaderFlags::SamplerCoordinate)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderSamplerData, GetLodBias, float)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderSamplerData, GetAnisotropy, float)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderSamplerData, GetBorderColor, Rendering::SingleShaderSamplerDataImpl::Colour)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderSamplerData, Load, CoreTools::BufferSource&, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderSamplerData, Save, CoreTools::BufferTarget&, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderSamplerData, GetStreamingSize, int)
#include STSTEM_WARNING_POP
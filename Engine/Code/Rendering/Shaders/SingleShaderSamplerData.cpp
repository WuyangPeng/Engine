// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 17:14)

#include "Rendering/RenderingExport.h"

#include "SingleShaderSamplerData.h"
#include "Detail/SingleShaderSamplerDataImpl.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;
using std::make_shared;

Rendering::SingleShaderSamplerData
	::SingleShaderSamplerData()
	:m_Impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Rendering, SingleShaderSamplerData)

DELAY_COPY_CONSTRUCTION_DEFINE(Rendering,SingleShaderSamplerData);

void Rendering::SingleShaderSamplerData
	::SetSampler( const string& name, ShaderFlags::SamplerType type )
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetSampler(name, type);
}

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderSamplerData,SetFilter,ShaderFlags::SamplerFilter,void)


void Rendering::SingleShaderSamplerData
	::SetCoordinate( int dimension, ShaderFlags::SamplerCoordinate coordinate )
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetCoordinate(dimension, coordinate);
}

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderSamplerData,SetLodBias,float,void)

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderSamplerData,SetAnisotropy,float,void)
 
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, SingleShaderSamplerData,SetBorderColor,Colour,void) 

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderSamplerData,GetSamplerName,const string)
 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderSamplerData,GetSamplerType,Rendering::ShaderFlags::SamplerType)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderSamplerData,GetFilter,Rendering::ShaderFlags::SamplerFilter)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderSamplerData,GetCoordinate,int,Rendering::ShaderFlags::SamplerCoordinate)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderSamplerData,GetLodBias,float)
 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderSamplerData,GetAnisotropy,float)
 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, SingleShaderSamplerData,GetBorderColor,Rendering::SingleShaderSamplerDataImpl::Colour)
 
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SingleShaderSamplerData,Load,BufferSource&,void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,SingleShaderSamplerData,Save,BufferTarget&,void)  
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,SingleShaderSamplerData,GetStreamingSize,int) 
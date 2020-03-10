// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 17:09)

#include "Rendering/RenderingExport.h"

#include "ShaderSamplerData.h"
#include "Detail/ShaderSamplerDataImpl.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;
using std::make_shared;

Rendering::ShaderSamplerData
	::ShaderSamplerData( int numSamplers )
	:m_Impl{ make_shared<ImplType>(numSamplers) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ShaderSamplerData
	::ShaderSamplerData()
	:m_Impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

DELAY_COPY_CONSTRUCTION_DEFINE(Rendering, ShaderSamplerData);

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Rendering, ShaderSamplerData)

void Rendering::ShaderSamplerData
	::SetSampler( int index, const string& name,ShaderFlags::SamplerType type )
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetSampler(index, name, type);
}

void Rendering::ShaderSamplerData
	::SetFilter( int index, ShaderFlags::SamplerFilter filter )
{	
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetFilter(index, filter);
}


void Rendering::ShaderSamplerData
	::SetCoordinate( int index, int dimension, ShaderFlags::SamplerCoordinate coordinate )
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetCoordinate(index, dimension,coordinate);
}

void Rendering::ShaderSamplerData
	::SetLodBias( int index, float lodBias )
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetLodBias(index, lodBias);
}


void Rendering::ShaderSamplerData
	::SetAnisotropy( int index, float anisotropy )
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetAnisotropy(index, anisotropy);
}

void Rendering::ShaderSamplerData
	::SetBorderColor( int index, const Colour& borderColor )
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetBorderColor(index, borderColor);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderSamplerData,GetNumSamplers, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderSamplerData,GetSamplerName,int, const string)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderSamplerData,GetSamplerType,int, Rendering::ShaderFlags::SamplerType)
 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderSamplerData,GetFilter,int, Rendering::ShaderFlags::SamplerFilter)
 
 
Rendering::ShaderFlags::SamplerCoordinate 
	Rendering::ShaderSamplerData
	::GetCoordinate( int index, int dimension ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1; 

	return m_Impl->GetCoordinate(index, dimension);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderSamplerData,GetLodBias,int, float)
 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderSamplerData,GetAnisotropy,int, float) 
 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderSamplerData,GetBorderColor,int, Rendering::ShaderSamplerData::Colour) 
 
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Rendering,ShaderSamplerData,Load,BufferSource&,void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,ShaderSamplerData,Save,BufferTarget&,void)  
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,ShaderSamplerData,GetStreamingSize,int) 

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderSamplerData,Resize,int,void)
// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 16:30)

#include "Rendering/RenderingExport.h"

#include "SingleShaderSamplerDataImpl.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;

Rendering::SingleShaderSamplerDataImpl
	::SingleShaderSamplerDataImpl()
	:m_SamplerName{},m_SamplerType{ ShaderFlags::SamplerType::None },m_Filter{ ShaderFlags::SamplerFilter::Nearest },
	 m_LodBias{ 0.0f },m_Anisotropy{ 1.0f },m_BorderColor{ 0.0f,0.0f,0.0f,0.0f }
{
	m_Coordinate.fill(ShaderFlags::SamplerCoordinate::ClampEdge);

	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, SingleShaderSamplerDataImpl)

void Rendering::SingleShaderSamplerDataImpl
	::SetSampler( const string& name,ShaderFlags::SamplerType type )
{
	RENDERING_CLASS_IS_VALID_9; 

	m_SamplerName = name;
	m_SamplerType = type;
}

void Rendering::SingleShaderSamplerDataImpl
	::SetFilter(  ShaderFlags::SamplerFilter filter )
{	
	RENDERING_CLASS_IS_VALID_9; 

	m_Filter = filter;
}

void Rendering::SingleShaderSamplerDataImpl
	::SetCoordinate( int dimension, ShaderFlags::SamplerCoordinate coordinate )
{
	RENDERING_CLASS_IS_VALID_9;
	RENDERING_ASSERTION_0(0 <= dimension && dimension < sm_SamplerCoordinateSize, "À˜“˝¥ÌŒÛ");

	m_Coordinate[dimension] = coordinate;
}

void Rendering::SingleShaderSamplerDataImpl
	::SetLodBias( float lodBias )
{
	RENDERING_CLASS_IS_VALID_9;

	m_LodBias = lodBias;
}

void Rendering::SingleShaderSamplerDataImpl
	::SetAnisotropy( float anisotropy )
{
	RENDERING_CLASS_IS_VALID_9; 

	m_Anisotropy = anisotropy;
}

void Rendering::SingleShaderSamplerDataImpl
	::SetBorderColor( const Colour& borderColor )
{
	RENDERING_CLASS_IS_VALID_9;

	m_BorderColor = borderColor;
}

 
const std::string Rendering::SingleShaderSamplerDataImpl
	::GetSamplerName() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_SamplerName;
}

Rendering::ShaderFlags::SamplerType Rendering::SingleShaderSamplerDataImpl
	::GetSamplerType() const
{
	RENDERING_CLASS_IS_VALID_CONST_9; 

	return m_SamplerType;
}

Rendering::ShaderFlags::SamplerFilter Rendering::SingleShaderSamplerDataImpl
	::GetFilter() const
{
	RENDERING_CLASS_IS_VALID_CONST_9; 

	return m_Filter;
}

Rendering::ShaderFlags::SamplerCoordinate Rendering::SingleShaderSamplerDataImpl
	::GetCoordinate(int dimension) const
{
	RENDERING_CLASS_IS_VALID_CONST_9; 
	RENDERING_ASSERTION_0(0 <= dimension && dimension < sm_SamplerCoordinateSize, "À˜“˝¥ÌŒÛ");

	return m_Coordinate[dimension];
}

float Rendering::SingleShaderSamplerDataImpl
	::GetLodBias() const
{
	RENDERING_CLASS_IS_VALID_CONST_9; 

	return m_LodBias;
}

float Rendering::SingleShaderSamplerDataImpl
	::GetAnisotropy() const
{
	RENDERING_CLASS_IS_VALID_CONST_9; 

	return m_Anisotropy;
}

Rendering::SingleShaderSamplerDataImpl::Colour Rendering::SingleShaderSamplerDataImpl
	::GetBorderColor() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_BorderColor;
}

void Rendering::SingleShaderSamplerDataImpl
	::Load( BufferSource& source )
{
	RENDERING_CLASS_IS_VALID_9;

	m_SamplerName = source.ReadString();
	source.ReadEnum(m_SamplerType);
	source.ReadEnum(m_Filter);
	source.ReadEnum(m_Coordinate[0]);
	source.ReadEnum(m_Coordinate[1]);
	source.ReadEnum(m_Coordinate[2]);
	source.Read(m_LodBias);
	source.Read(m_Anisotropy);
	source.ReadAggregate(m_BorderColor);
}

void Rendering::SingleShaderSamplerDataImpl
	::Save( BufferTarget& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	target.WriteString(m_SamplerName);
	target.WriteEnum(m_SamplerType);
	target.WriteEnum(m_Filter);
	target.WriteEnum(m_Coordinate[0]);
	target.WriteEnum(m_Coordinate[1]);
	target.WriteEnum(m_Coordinate[2]);
	target.Write(m_LodBias);
	target.Write(m_Anisotropy);
	target.WriteAggregate(m_BorderColor);
}

int Rendering::SingleShaderSamplerDataImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	auto size = CORE_TOOLS_STREAM_SIZE(m_SamplerName); 

	size += CORE_TOOLS_STREAM_SIZE(m_SamplerType);
	size += CORE_TOOLS_STREAM_SIZE(m_Filter);
	size += CORE_TOOLS_STREAM_SIZE(m_Coordinate[0]) * sm_SamplerCoordinateSize;
	size += CORE_TOOLS_STREAM_SIZE(m_LodBias);
	size += CORE_TOOLS_STREAM_SIZE(m_Anisotropy);
	size += CORE_TOOLS_STREAM_SIZE(m_BorderColor);

	return size;
}



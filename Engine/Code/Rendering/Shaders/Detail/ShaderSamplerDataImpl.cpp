// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 16:23)

#include "Rendering/RenderingExport.h"

#include "ShaderSamplerDataImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

#include <algorithm>

using std::string;

Rendering::ShaderSamplerDataImpl
	::ShaderSamplerDataImpl( int numSamplers )
	:m_SingleShaderSamplerData{ numSamplers }
{ 
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ShaderSamplerDataImpl
	::ShaderSamplerDataImpl()
	:m_SingleShaderSamplerData{}
{ 
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,ShaderSamplerDataImpl)

void Rendering::ShaderSamplerDataImpl
	::SetSampler( int index, const string& name, ShaderFlags::SamplerType type )
{
	RENDERING_CLASS_IS_VALID_9;
	RENDERING_ASSERTION_0(0 <= index && index < GetNumSamplers(), "À˜“˝¥ÌŒÛ");

	m_SingleShaderSamplerData[index].SetSampler(name, type);
}

void Rendering::ShaderSamplerDataImpl
	::SetFilter( int index, ShaderFlags::SamplerFilter filter )
{	
	RENDERING_CLASS_IS_VALID_9;
	RENDERING_ASSERTION_0(0 <= index && index < GetNumSamplers(), "À˜“˝¥ÌŒÛ");

	m_SingleShaderSamplerData[index].SetFilter(filter);
}

void Rendering::ShaderSamplerDataImpl
	::SetCoordinate( int index, int dimension,ShaderFlags::SamplerCoordinate coordinate )
{
	RENDERING_CLASS_IS_VALID_9;
	RENDERING_ASSERTION_0(0 <= index && index < GetNumSamplers(), "À˜“˝¥ÌŒÛ"); 

	m_SingleShaderSamplerData[index].SetCoordinate(dimension, coordinate);
}

void Rendering::ShaderSamplerDataImpl
	::SetLodBias( int index, float lodBias )
{
	RENDERING_CLASS_IS_VALID_9;
	RENDERING_ASSERTION_0(0 <= index && index < GetNumSamplers(), "À˜“˝¥ÌŒÛ");

	m_SingleShaderSamplerData[index].SetLodBias(lodBias);
}


void Rendering::ShaderSamplerDataImpl
	::SetAnisotropy( int index, float anisotropy )
{
	RENDERING_CLASS_IS_VALID_9;
	RENDERING_ASSERTION_0(0 <= index && index < GetNumSamplers(), "À˜“˝¥ÌŒÛ");

	m_SingleShaderSamplerData[index].SetAnisotropy(anisotropy);
}

void Rendering::ShaderSamplerDataImpl
	::SetBorderColor( int index, const Colour& borderColor )
{
	RENDERING_CLASS_IS_VALID_9;
	RENDERING_ASSERTION_0(0 <= index && index < GetNumSamplers(), "À˜“˝¥ÌŒÛ");

	m_SingleShaderSamplerData[index].SetBorderColor(borderColor);
}

int Rendering::ShaderSamplerDataImpl
	::GetNumSamplers() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(m_SingleShaderSamplerData.size());
}

const string Rendering::ShaderSamplerDataImpl
	::GetSamplerName( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= index && index < GetNumSamplers(), "À˜“˝¥ÌŒÛ");

	return m_SingleShaderSamplerData[index].GetSamplerName();
}

Rendering::ShaderFlags::SamplerType Rendering::ShaderSamplerDataImpl
	::GetSamplerType( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= index && index < GetNumSamplers(), "À˜“˝¥ÌŒÛ");

	return m_SingleShaderSamplerData[index].GetSamplerType();
}

Rendering::ShaderFlags::SamplerFilter Rendering::ShaderSamplerDataImpl
	::GetFilter( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= index && index < GetNumSamplers(), "À˜“˝¥ÌŒÛ");

	return m_SingleShaderSamplerData[index].GetFilter();
}

Rendering::ShaderFlags::SamplerCoordinate Rendering::ShaderSamplerDataImpl
	::GetCoordinate(int index, int dimension) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= index && index < GetNumSamplers(), "À˜“˝¥ÌŒÛ");

	return m_SingleShaderSamplerData[index].GetCoordinate(dimension);
}

float Rendering::ShaderSamplerDataImpl
	::GetLodBias( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= index && index < GetNumSamplers(), "À˜“˝¥ÌŒÛ");

	return m_SingleShaderSamplerData[index].GetLodBias();
}

float Rendering::ShaderSamplerDataImpl
	::GetAnisotropy( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= index && index < GetNumSamplers(), "À˜“˝¥ÌŒÛ");

	return m_SingleShaderSamplerData[index].GetAnisotropy();
}

Rendering::ShaderSamplerDataImpl::Colour Rendering::ShaderSamplerDataImpl
	::GetBorderColor( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= index && index < GetNumSamplers(), "À˜“˝¥ÌŒÛ");

	return m_SingleShaderSamplerData[index].GetBorderColor();
}

void Rendering::ShaderSamplerDataImpl
	::Load( BufferSource& source )
{
	RENDERING_CLASS_IS_VALID_9;

	uint32_t number{ 0 };
	source.Read(number);
	m_SingleShaderSamplerData.resize(number);
	 
	for_each(m_SingleShaderSamplerData.begin(), m_SingleShaderSamplerData.end(), std::bind(&SingleShaderSamplerData::Load,std::placeholders::_1,std::ref(source)));	 
}

void Rendering::ShaderSamplerDataImpl
	::Save( BufferTarget& target ) const
{
	target.Write(boost::numeric_cast<uint32_t>(m_SingleShaderSamplerData.size()));

	for_each(m_SingleShaderSamplerData.begin(), m_SingleShaderSamplerData.end(), std::bind(&SingleShaderSamplerData::Save, std::placeholders::_1,std::ref(target)));
}

int Rendering::ShaderSamplerDataImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	auto size = CORE_TOOLS_STREAM_SIZE(uint32_t());
	for(const auto& data: m_SingleShaderSamplerData)
	{
		size += data.GetStreamingSize();
	}

	return size;
}

void Rendering::ShaderSamplerDataImpl
	::Resize(int number)
{
	RENDERING_CLASS_IS_VALID_9;

	m_SingleShaderSamplerData.resize(number);
}


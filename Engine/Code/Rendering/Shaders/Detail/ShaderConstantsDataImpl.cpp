// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/24 16:11)

#include "Rendering/RenderingExport.h"

#include "ShaderConstantsDataImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

#include <boost/numeric/conversion/cast.hpp>
#include <algorithm>

using std::string;

Rendering::ShaderConstantsDataImpl
	::ShaderConstantsDataImpl( int number )
	:m_SingleShaderConstantsData{ number }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ShaderConstantsDataImpl
	::ShaderConstantsDataImpl()
	:m_SingleShaderConstantsData()
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ShaderConstantsDataImpl)

void Rendering::ShaderConstantsDataImpl
	::SetConstant (int index, const string& name,int numRegistersUsed)
{
	RENDERING_CLASS_IS_VALID_9;
	RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_SingleShaderConstantsData.size()), "Ë÷Òý´íÎó");

	m_SingleShaderConstantsData[index].SetConstant(name, numRegistersUsed);
}


void Rendering::ShaderConstantsDataImpl
	::InsertData(const string& name, int numRegistersUsed)
{
	RENDERING_CLASS_IS_VALID_9;
	 
	m_SingleShaderConstantsData.emplace_back(name, numRegistersUsed);
}


int Rendering::ShaderConstantsDataImpl
	::GetNumConstants() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(m_SingleShaderConstantsData.size());
}

const string Rendering::ShaderConstantsDataImpl
	::GetConstantName( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_SingleShaderConstantsData.size()), "Ë÷Òý´íÎó");

	return m_SingleShaderConstantsData[index].GetConstantName();
}

int Rendering::ShaderConstantsDataImpl
	::GetNumRegistersUsed(int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_SingleShaderConstantsData.size()), "Ë÷Òý´íÎó");

	return m_SingleShaderConstantsData[index].GetNumRegistersUsed();
}
 
void Rendering::ShaderConstantsDataImpl
	::Load( BufferSource& source )
{
	RENDERING_CLASS_IS_VALID_9;

	uint32_t number{ 0 };
	source.Read(number);
	m_SingleShaderConstantsData.resize(number);
	 
	for_each(m_SingleShaderConstantsData.begin(), m_SingleShaderConstantsData.end(),std::bind(&SingleShaderConstantsData::Load,std::placeholders::_1,std::ref(source)));	 
}

void Rendering::ShaderConstantsDataImpl
	::Save( BufferTarget& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	uint32_t size = boost::numeric_cast<uint32_t>(m_SingleShaderConstantsData.size());
	target.Write(size);

	for_each(m_SingleShaderConstantsData.begin(), m_SingleShaderConstantsData.end(),std::bind(&SingleShaderConstantsData::Save, std::placeholders::_1,std::ref(target)));
}

int Rendering::ShaderConstantsDataImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	auto size = CORE_TOOLS_STREAM_SIZE(uint32_t());
	for(const auto& data: m_SingleShaderConstantsData)
	{
		size += data.GetStreamingSize();
	}

	return size;
}

void Rendering::ShaderConstantsDataImpl
	::Resize(int number)
{
	RENDERING_CLASS_IS_VALID_9;

	m_SingleShaderConstantsData.resize(number);
}


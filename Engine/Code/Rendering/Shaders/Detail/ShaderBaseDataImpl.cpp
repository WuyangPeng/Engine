// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 16:01)

#include "Rendering/RenderingExport.h"

#include "ShaderBaseDataImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include <algorithm>

using std::string;
using std::for_each;

Rendering::ShaderBaseDataImpl
	::ShaderBaseDataImpl( int number )
	:m_SingleShaderBaseData(number)
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ShaderBaseDataImpl
	::ShaderBaseDataImpl()
	:m_SingleShaderBaseData() 
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,ShaderBaseDataImpl)

void Rendering::ShaderBaseDataImpl
	::SetData( int index, const string& name,ShaderFlags::VariableType type, ShaderFlags::VariableSemantic semantic )
{
	RENDERING_CLASS_IS_VALID_9;
	RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_SingleShaderBaseData.size()), "��������");

	m_SingleShaderBaseData[index].SetData(name, type, semantic);
}


void Rendering::ShaderBaseDataImpl
	::InsertData(const string& name, ShaderFlags::VariableType type,ShaderFlags::VariableSemantic semantic)
{
	RENDERING_CLASS_IS_VALID_9;
	 
	m_SingleShaderBaseData.push_back(SingleShaderBaseData(name, type, semantic));
}


int Rendering::ShaderBaseDataImpl
	::GetNumber() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(m_SingleShaderBaseData.size());
}

const string Rendering::ShaderBaseDataImpl
	::GetName( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_SingleShaderBaseData.size()), "��������");

	return m_SingleShaderBaseData[index].GetName();
}

Rendering::ShaderFlags::VariableType Rendering::ShaderBaseDataImpl
	::GetType( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_SingleShaderBaseData.size()), "��������");

	return m_SingleShaderBaseData[index].GetType();
}

Rendering::ShaderFlags::VariableSemantic Rendering::ShaderBaseDataImpl
	::GetSemantic( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_SingleShaderBaseData.size()), "��������");

	return m_SingleShaderBaseData[index].GetSemantic();
}

void Rendering::ShaderBaseDataImpl
	::Load( BufferSource& source )
{
	RENDERING_CLASS_IS_VALID_9;

	uint32_t number{ 0 };
	source.Read(number);
	m_SingleShaderBaseData.resize(number);
	 
	for_each(m_SingleShaderBaseData.begin(),m_SingleShaderBaseData.end(),std::bind(&SingleShaderBaseData::Load,std::placeholders::_1,std::ref(source)));	 
}

void Rendering::ShaderBaseDataImpl
	::Save( BufferTarget& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	uint32_t size = boost::numeric_cast<uint32_t>(m_SingleShaderBaseData.size());
	target.Write(size);

	for_each(m_SingleShaderBaseData.begin(),m_SingleShaderBaseData.end(),std::bind(&SingleShaderBaseData::Save, std::placeholders::_1, std::ref(target)));
}

int Rendering::ShaderBaseDataImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	auto size = CORE_TOOLS_STREAM_SIZE(uint32_t());
	for(const auto& data: m_SingleShaderBaseData)
	{
		size += data.GetStreamingSize();
	}

	return size;
}

void Rendering::ShaderBaseDataImpl
	::Resize(int number)
{
	RENDERING_CLASS_IS_VALID_9;

	m_SingleShaderBaseData.resize(number);
}


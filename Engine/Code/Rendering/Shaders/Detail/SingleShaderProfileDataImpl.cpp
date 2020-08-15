// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/24 16:27)

#include "Rendering/RenderingExport.h"

#include "SingleShaderProfileDataImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h" 
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
Rendering::SingleShaderProfileDataImpl
	::SingleShaderProfileDataImpl(int numConstants,int numSamplers)	
	:m_BaseRegister(numConstants),m_TextureUnit(numSamplers),m_Program{}
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,SingleShaderProfileDataImpl)

void Rendering::SingleShaderProfileDataImpl
    ::SetBaseRegister( int index, int baseRegister )
{
	RENDERING_CLASS_IS_VALID_9;
	RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_BaseRegister.size()),"Ë÷Òý´íÎó");

	m_BaseRegister[index] = baseRegister;
}

void Rendering::SingleShaderProfileDataImpl
	::SetTextureUnit( int index, int textureUnit )
{
	RENDERING_CLASS_IS_VALID_9;
	RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_TextureUnit.size()),  "Ë÷Òý´íÎó");

	m_TextureUnit[index] = textureUnit;
}

void Rendering::SingleShaderProfileDataImpl
	::SetProgram( const string& program )
{
	RENDERING_CLASS_IS_VALID_9;

	m_Program = program;
}

int Rendering::SingleShaderProfileDataImpl
	::GetBaseRegister( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_BaseRegister.size()),"Ë÷Òý´íÎó");

	return m_BaseRegister[index];	
}

int Rendering::SingleShaderProfileDataImpl
	::GetTextureUnit( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_TextureUnit.size()), "Ë÷Òý´íÎó");

	return m_TextureUnit[index];	
}

const std::string Rendering::SingleShaderProfileDataImpl
	::GetProgram() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Program;
}

int Rendering::SingleShaderProfileDataImpl
	::GetBaseRegisterSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(m_BaseRegister.size());
}

int Rendering::SingleShaderProfileDataImpl
	::GetTextureUnitSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(m_TextureUnit.size());
}

void Rendering::SingleShaderProfileDataImpl
	::ResetData(int numConstants, int numSamplers)
{
	RENDERING_CLASS_IS_VALID_9;

	m_BaseRegister.resize(numConstants);
	m_TextureUnit.resize(numSamplers);
}

void Rendering::SingleShaderProfileDataImpl
	::Load( BufferSource& source )
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	source.Read(m_BaseRegister);
	source.Read(m_TextureUnit);
	m_Program = source.ReadString();
}

void Rendering::SingleShaderProfileDataImpl
	::Save( BufferTarget& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	target.Write(m_BaseRegister);
	target.Write(m_TextureUnit);
	target.WriteString(m_Program);
}

int Rendering::SingleShaderProfileDataImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	auto size =  CORE_TOOLS_STREAM_SIZE(m_BaseRegister);

	size += CORE_TOOLS_STREAM_SIZE(m_TextureUnit);
	size += CORE_TOOLS_STREAM_SIZE(m_Program);

	return size;
}

#include STSTEM_WARNING_POP
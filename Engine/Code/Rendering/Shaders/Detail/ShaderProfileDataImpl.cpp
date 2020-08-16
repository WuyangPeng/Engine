// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 16:21)

#include "Rendering/RenderingExport.h"

#include "ShaderProfileDataImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

#include <algorithm>

using std::string;
using std::for_each;
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
#if defined(TCRE_USE_MSVC)
    #pragma warning(disable : 28020)
#endif  // TCRE_USE_MSVC
Rendering::ShaderProfileDataImpl
	::ShaderProfileDataImpl(int numConstants,int numSamplers)	
	:m_ShaderProfileData{}, m_NumConstants{ numConstants },m_NumSamplers{ numSamplers }
{
	for_each(m_ShaderProfileData.begin(), m_ShaderProfileData.end(),std::bind(&SingleShaderProfileData::ResetData,std::placeholders::_1, numConstants, numSamplers));
	 
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ShaderProfileDataImpl
	::ShaderProfileDataImpl() noexcept
	:m_ShaderProfileData{}, m_NumConstants{ 0 }, m_NumSamplers{ 0 }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,ShaderProfileDataImpl)

void Rendering::ShaderProfileDataImpl
    ::SetBaseRegister( int profile, int index, int baseRegister )
{
	RENDERING_CLASS_IS_VALID_9;
	RENDERING_ASSERTION_0(0 <= profile && profile < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles),"索引错误");

	m_ShaderProfileData[profile].SetBaseRegister(index, baseRegister);
}

void Rendering::ShaderProfileDataImpl
	::SetTextureUnit( int profile, int index, int textureUnit )
{
	RENDERING_CLASS_IS_VALID_9;
	RENDERING_ASSERTION_0(0 <= profile && profile < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles),"索引错误");

	m_ShaderProfileData[profile].SetTextureUnit(index, textureUnit);
}

void Rendering::ShaderProfileDataImpl
	::SetProgram( int profile, const std::string& program )
{
	RENDERING_CLASS_IS_VALID_9;
	RENDERING_ASSERTION_0(0 <= profile && profile < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles),"索引错误");

	m_ShaderProfileData[profile].SetProgram(program);
}

int Rendering::ShaderProfileDataImpl
	::GetBaseRegister( int profile, int index ) const
{
	RENDERING_CLASS_IS_VALID_9;
	RENDERING_ASSERTION_0(0 <= profile && profile < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles),"索引错误");

	return m_ShaderProfileData[profile].GetBaseRegister(index);
}

int Rendering::ShaderProfileDataImpl
	::GetTextureUnit( int profile, int index ) const
{
	RENDERING_CLASS_IS_VALID_9;
	RENDERING_ASSERTION_0(0 <= profile && profile < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles),"索引错误");

	return m_ShaderProfileData[profile].GetTextureUnit(index);
}

const std::string Rendering::ShaderProfileDataImpl
	::GetProgram( int profile ) const
{
	RENDERING_CLASS_IS_VALID_9;
	RENDERING_ASSERTION_0(0 <= profile && profile < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles),"索引错误");

	return m_ShaderProfileData[profile].GetProgram();
}

int Rendering::ShaderProfileDataImpl ::GetBaseRegisterSize() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_NumConstants;
}

int Rendering::ShaderProfileDataImpl ::GetTextureUnitSize() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_NumSamplers;
}

void Rendering::ShaderProfileDataImpl
	::Load( BufferSource& source )
{
	RENDERING_CLASS_IS_VALID_9;

	// 测试是否修改MaxProfiles。
	int maxProfiles{ 0 };
	source.Read(maxProfiles);

	RENDERING_ASSERTION_2(maxProfiles == System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles),"你改变了MaxProfiles的值，并加载了旧的数据集。");

	for (auto i = 0; i < maxProfiles; ++i)
	{
		m_ShaderProfileData[i].Load(source);
	}	 

	source.Read(m_NumConstants);
	source.Read(m_NumSamplers);
}

void Rendering::ShaderProfileDataImpl
	::Save( BufferTarget& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	target.Write(System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles));

	for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
	{
		m_ShaderProfileData[i].Save(target);
	}

	target.Write(m_NumConstants);
	target.Write(m_NumSamplers);
}

int Rendering::ShaderProfileDataImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	auto size = CORE_TOOLS_STREAM_SIZE(System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles));
	 
	for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
	{
		 size += m_ShaderProfileData[i].GetStreamingSize();
	}

	size += CORE_TOOLS_STREAM_SIZE(m_NumConstants);
	size += CORE_TOOLS_STREAM_SIZE(m_NumSamplers);

	return size;
}

#include STSTEM_WARNING_POP
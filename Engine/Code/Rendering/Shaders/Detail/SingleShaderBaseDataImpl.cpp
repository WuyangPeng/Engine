// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 16:25)

#include "Rendering/RenderingExport.h"

#include "SingleShaderBaseDataImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;
#include STSTEM_WARNING_PUSH 
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
Rendering::SingleShaderBaseDataImpl
	::SingleShaderBaseDataImpl( const string& name,ShaderFlags::VariableType type,ShaderFlags::VariableSemantic semantic )
	:m_Name{ name },m_Type{ type },m_Semantic{ semantic }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::SingleShaderBaseDataImpl
	::SingleShaderBaseDataImpl() noexcept
	:m_Name{},m_Type{ ShaderFlags::VariableType::None },m_Semantic{ ShaderFlags::VariableSemantic::None }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,SingleShaderBaseDataImpl)

void Rendering::SingleShaderBaseDataImpl
	::SetData( const std::string& name,ShaderFlags::VariableType type, ShaderFlags::VariableSemantic semantic )
{
	RENDERING_CLASS_IS_VALID_9; 

	m_Name = name;
	m_Type = type;
	m_Semantic = semantic;
}

const string Rendering::SingleShaderBaseDataImpl
	::GetName() const
{
	RENDERING_CLASS_IS_VALID_CONST_9; 

	return m_Name;
}

Rendering::ShaderFlags::VariableType Rendering::SingleShaderBaseDataImpl::GetType() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Type;
}

Rendering::ShaderFlags::VariableSemantic Rendering::SingleShaderBaseDataImpl::GetSemantic() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Semantic;
}

void Rendering::SingleShaderBaseDataImpl::Load(CoreTools::BufferSource& source)
{
	RENDERING_CLASS_IS_VALID_9;

	m_Name = source.ReadString();
	source.ReadEnum(m_Type);
	source.ReadEnum(m_Semantic);
}

void Rendering::SingleShaderBaseDataImpl
	::Save( CoreTools::BufferTarget& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	target.Write(m_Name);
        target.WriteEnum(m_Type);
        target.WriteEnum(m_Semantic);
}

int Rendering::SingleShaderBaseDataImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	auto size = CORE_TOOLS_STREAM_SIZE(m_Name);
	size += CORE_TOOLS_STREAM_SIZE(m_Type); 
	size += CORE_TOOLS_STREAM_SIZE(m_Semantic);

	return size;
}

#include STSTEM_WARNING_POP
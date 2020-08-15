// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 16:27)

#include "Rendering/RenderingExport.h"

#include "SingleShaderConstantsDataImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;

Rendering::SingleShaderConstantsDataImpl
	::SingleShaderConstantsDataImpl( const string& name,int numRegistersUsed )
	:m_Name{ name }, m_NumRegistersUsed{ numRegistersUsed }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::SingleShaderConstantsDataImpl ::SingleShaderConstantsDataImpl() noexcept
    : m_Name{}, m_NumRegistersUsed{ 0 }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::SingleShaderConstantsDataImpl
	::IsValid() const noexcept
{
	if(0 <= m_NumRegistersUsed)
	    return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

void Rendering::SingleShaderConstantsDataImpl
	::SetConstant( const std::string& name, int numRegistersUsed )
{
	RENDERING_CLASS_IS_VALID_1;

	m_Name = name;
	m_NumRegistersUsed = numRegistersUsed;
}

const string Rendering::SingleShaderConstantsDataImpl
	::GetConstantName() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;	

	return m_Name;
}

int Rendering::SingleShaderConstantsDataImpl ::GetNumRegistersUsed() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_NumRegistersUsed;
}

void Rendering::SingleShaderConstantsDataImpl
	::Load( BufferSource& source )
{
	RENDERING_CLASS_IS_VALID_1;

	m_Name = source.ReadString();
	source.Read(m_NumRegistersUsed);
}

void Rendering::SingleShaderConstantsDataImpl
	::Save( BufferTarget& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	target.WriteString(m_Name);
	target.Write(m_NumRegistersUsed);
}

int Rendering::SingleShaderConstantsDataImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto size = CORE_TOOLS_STREAM_SIZE(m_Name);
	size += CORE_TOOLS_STREAM_SIZE(m_NumRegistersUsed);

	return size;
}



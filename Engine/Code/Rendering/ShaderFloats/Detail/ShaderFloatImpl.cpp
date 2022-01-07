// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 17:34)

#include "Rendering/RenderingExport.h"

#include "ShaderFloatImpl.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Rendering/DataTypes/ColourDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26451)
#include SYSTEM_WARNING_DISABLE(26446)

#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
Rendering::ShaderFloatImpl
	::ShaderFloatImpl()
	:m_Data{},m_AllowUpdater{ true }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ShaderFloatImpl
	::ShaderFloatImpl( int numRegisters )
	:m_Data{},m_AllowUpdater{ true }
{
	SetNumRegisters(numRegisters);

	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ShaderFloatImpl
	::ShaderFloatImpl(const FloatVector& data)
	:m_Data{ data }, m_AllowUpdater{ true }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::ShaderFloatImpl
	::IsValid() const noexcept
{
	if (m_Data.size() % sm_FloatingPointSize == 0)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT


int Rendering::ShaderFloatImpl
	::GetNumRegisters() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return boost::numeric_cast<int>(m_Data.size() / sm_FloatingPointSize);
}

void Rendering::ShaderFloatImpl
	::SetNumRegisters( int numRegisters )
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_2(0 < numRegisters, "寄存器的数量必须为正数。\n");

	m_Data.resize(numRegisters * sm_FloatingPointSize);
}

const float* Rendering::ShaderFloatImpl
	::GetData() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(!m_Data.empty(),"寄存器的数量为零。\n");

	return &m_Data[0];
}

float* Rendering::ShaderFloatImpl
	::GetData()
{
	RENDERING_CLASS_IS_VALID_1;

	return NON_CONST_MEMBER_CALL_CONST_MEMBER(float*,GetData);
}

void Rendering::ShaderFloatImpl
	::SetRegister( int index, const FloatVector& data )
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= index && index < GetNumRegisters(), "无效寄存器！\n");
	RENDERING_ASSERTION_0(data.size() == 4, "传入的值大小错误！\n");

	for(auto targetIndex = 0;targetIndex < sm_FloatingPointSize;++targetIndex)
	{
		m_Data[sm_FloatingPointSize * index + targetIndex] = data[targetIndex];
	}	 
}

void Rendering::ShaderFloatImpl
	::SetRegister(int index, const AVector& vector)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= index && index < GetNumRegisters(), "无效寄存器！\n");

	for (auto targetIndex = 0; targetIndex < sm_FloatingPointSize - 1; ++targetIndex)
	{
		m_Data[sm_FloatingPointSize * index + targetIndex] = vector[targetIndex];
	}

	m_Data[sm_FloatingPointSize * index + sm_FloatingPointSize - 1] = 0.0f;
}

void Rendering::ShaderFloatImpl
	::SetRegister(int index, const APoint& point)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= index && index < GetNumRegisters(), "无效寄存器！\n");

	for (auto targetIndex = 0; targetIndex < sm_FloatingPointSize - 1; ++targetIndex)
	{
		m_Data[sm_FloatingPointSize * index + targetIndex] = point[targetIndex];
	}

	m_Data[sm_FloatingPointSize * index + sm_FloatingPointSize - 1] = 1.0f;
}

void Rendering::ShaderFloatImpl
	::SetRegister( int index, const Colour& colour )
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= index && index < GetNumRegisters(), "无效寄存器！\n");

	m_Data[sm_FloatingPointSize * index] = colour.GetRed();
	m_Data[sm_FloatingPointSize * index + 1] = colour.GetGreen();
	m_Data[sm_FloatingPointSize * index + 2] = colour.GetBlue();
	m_Data[sm_FloatingPointSize * index + 3] = colour.GetAlpha();
}

void Rendering::ShaderFloatImpl
	::SetRegisters( const Matrix& matrix )
{
	RENDERING_CLASS_IS_VALID_1;

	RENDERING_ASSERTION_0(sm_FloatingPointSize == GetNumRegisters(), "无效寄存器！\n");

	for (auto outer = 0;outer < sm_FloatingPointSize;++outer)
	{
		for (auto inner = 0;inner < sm_FloatingPointSize;++inner)
		{
			m_Data[sm_FloatingPointSize * outer + inner] =  matrix(outer,inner);
		}
	}
}

void Rendering::ShaderFloatImpl
	::SetRegisters( const FloatVector& data )
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_2(data.size() == m_Data.size(), "传入的值大小错误！\n");

	m_Data = data;
}

const Rendering::ShaderFloatImpl::FloatVector Rendering::ShaderFloatImpl
	::GetRegister( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= index && index < GetNumRegisters(), "无效寄存器！\n");

	FloatVector data{ m_Data.begin() + sm_FloatingPointSize * index, m_Data.begin() + sm_FloatingPointSize * index + sm_FloatingPointSize };

	return data; 
}

const Rendering::ShaderFloatImpl::FloatVector Rendering::ShaderFloatImpl
	::GetRegisters() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Data;
}

const float& Rendering::ShaderFloatImpl
	::operator[]( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_Data.size()), "无效索引！\n");

	return m_Data[index];
}

float& Rendering::ShaderFloatImpl
	::operator[]( int index )
{
	RENDERING_CLASS_IS_VALID_1;

	return OPERATOR_SQUARE_BRACKETS(float,index);
}

void Rendering::ShaderFloatImpl
	::EnableUpdater()
{
	RENDERING_CLASS_IS_VALID_1;

	m_AllowUpdater = true;
}

void Rendering::ShaderFloatImpl
	::DisableUpdater()
{
	RENDERING_CLASS_IS_VALID_1;

	m_AllowUpdater = false;
}

bool Rendering::ShaderFloatImpl
	::AllowUpdater() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_AllowUpdater;
}

void Rendering::ShaderFloatImpl ::Load(CoreTools::BufferSource& source)
{
	RENDERING_CLASS_IS_VALID_1;
	 
//	source.Read(m_Data);
	m_AllowUpdater = source.ReadBool();
}

void Rendering::ShaderFloatImpl
	::Save (CoreTools::BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	
	target.WriteContainerWithNumber(m_Data);
	target.Write(m_AllowUpdater);
}

int Rendering::ShaderFloatImpl
	::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto size = CORE_TOOLS_STREAM_SIZE(m_Data); 
	size += CORE_TOOLS_STREAM_SIZE(m_AllowUpdater);

	return size;
}
#include STSTEM_WARNING_POP
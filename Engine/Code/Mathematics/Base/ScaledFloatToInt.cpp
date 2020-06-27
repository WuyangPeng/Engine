// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/19 09:43)

#include "Mathematics/MathematicsExport.h"

#include "ScaledFloatToInt.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <algorithm>

using std::pow;

Mathematics::ScaledFloatToInt
	::ScaledFloatToInt(float value, int power)
	:m_FloatValue{ value }, m_IntegerValue{ *reinterpret_cast<int32_t*>(&m_FloatValue) },
	 m_Power{ power }, m_Shift{ 150 - m_Power - ((m_IntegerValue >> 23) & 0xFF) }, m_Result{ 0 }
{
	Scaled();

	MATHEMATICS_SELF_CLASS_IS_VALID_5;
}

// private
void Mathematics::ScaledFloatToInt
	::Scaled()
{
	if (m_Shift < 24)
	{
		ShiftIntegerValue();
		CorrectResult();
	}
}

// private
void Mathematics::ScaledFloatToInt
	::ShiftIntegerValue()
{
	// ����������1.0f����ʱ��m_Shift���ܻ����-1��
	if (0 <= m_Shift)
		m_Result = ((m_IntegerValue & 0x007FFFFF) | 0x00800000) >> m_Shift;
	else
		m_Result = ((m_IntegerValue & 0x007FFFFF) | 0x00800000) << -m_Shift;
}

void Mathematics::ScaledFloatToInt
	::CorrectResult()
{
	if (m_Result == (1 << m_Power))
	{
		--m_Result;
	}
}

#ifdef OPEN_CLASS_INVARIANT
// m_FloatValue������Ϊ[0,1]��
// m_Power������Ϊ[0,24]��
// m_Result������Ϊ[0,2^power - 1]��
bool Mathematics::ScaledFloatToInt
	::IsValid() const noexcept
{
	if (0 <= m_FloatValue && m_FloatValue <= 1 && 0 <= m_Power && m_Power <= 24 && 0 <= m_Result && m_Result <= pow(2.0, m_Power) - 1)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

int Mathematics::ScaledFloatToInt
	::GetScaledResult() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_5;

	return m_Result;
}


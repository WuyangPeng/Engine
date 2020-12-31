///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/10/30 15:39)

#include "Mathematics/MathematicsExport.h"

#include "ScaledFloatToInt.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <algorithm>

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
Mathematics::ScaledFloatToInt::ScaledFloatToInt(float value, int power) noexcept
    : m_FloatValue{ value }, m_IntegerValue{ *reinterpret_cast<int32_t*>(&m_FloatValue) },
      m_Power{ power }, m_Shift{ 150 - m_Power - ((m_IntegerValue >> 23) & 0xFF) }, m_Result{ 0 }
{
    Scaled();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

// private
void Mathematics::ScaledFloatToInt::Scaled() noexcept
{
    if (m_Shift < 24)
    {
        ShiftIntegerValue();
        CorrectResult();
    }
}

// private
void Mathematics::ScaledFloatToInt::ShiftIntegerValue() noexcept
{
    // 当将浮点数1.0f传入时，m_Shift可能会等于-1。
    if (0 <= m_Shift)
        m_Result = ((m_IntegerValue & 0x007FFFFF) | 0x00800000) >> m_Shift;
    else
        m_Result = ((m_IntegerValue & 0x007FFFFF) | 0x00800000) << -m_Shift;
}

void Mathematics::ScaledFloatToInt::CorrectResult() noexcept
{
    if (m_Result == (1 << m_Power))
    {
        --m_Result;
    }
}

#ifdef OPEN_CLASS_INVARIANT
// m_FloatValue的区间为[0,1]。
// m_Power的区间为[0,24]。
// m_Result的区间为[0,2^power - 1]。
bool Mathematics::ScaledFloatToInt::IsValid() const noexcept
{
    if (0 <= m_FloatValue && m_FloatValue <= 1 && 0 <= m_Power && m_Power <= 24 && 0 <= m_Result && m_Result <= pow(2.0, m_Power) - 1)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

int32_t Mathematics::ScaledFloatToInt::GetScaledResult() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Result;
}

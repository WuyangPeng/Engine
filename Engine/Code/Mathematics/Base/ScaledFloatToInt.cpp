///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/01/29 11:18)

#include "Mathematics/MathematicsExport.h"

#include "ScaledFloatToInt.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <algorithm>

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

Mathematics::ScaledFloatToInt::ScaledFloatToInt(float value, int power) noexcept
    : floatValue{ value },
      integerValue{ *reinterpret_cast<int32_t*>(&floatValue) },
      power{ power },
      shift{ 150 - power - ((integerValue >> 23) & 0xFF) },
      result{ 0 }
{
    Scaled();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#include STSTEM_WARNING_POP

// private
void Mathematics::ScaledFloatToInt::Scaled() noexcept
{
    if (shift < 24)
    {
        ShiftIntegerValue();
        CorrectResult();
    }
}

// private
void Mathematics::ScaledFloatToInt::ShiftIntegerValue() noexcept
{
    // ����������1.0f����ʱ��m_Shift���ܻ����-1��
    if (0 <= shift)
        result = ((integerValue & 0x007FFFFF) | 0x00800000) >> shift;
    else
        result = ((integerValue & 0x007FFFFF) | 0x00800000) << -shift;
}

void Mathematics::ScaledFloatToInt::CorrectResult() noexcept
{
    if (result == (1 << power))
    {
        --result;
    }
}

#ifdef OPEN_CLASS_INVARIANT

// m_FloatValue������Ϊ[0,1]��
// m_Power������Ϊ[0,24]��
// m_Result������Ϊ[0,2^power - 1]��
bool Mathematics::ScaledFloatToInt::IsValid() const noexcept
{
    if (0 <= floatValue && floatValue <= 1 && 0 <= power && power <= 24 && 0 <= result && result <= pow(2.0, power) - 1)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

int32_t Mathematics::ScaledFloatToInt::GetScaledResult() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return result;
}

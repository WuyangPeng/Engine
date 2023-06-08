///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/05/30 14:59)

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

void Mathematics::ScaledFloatToInt::Scaled() noexcept
{
    if (shift < 24)
    {
        ShiftIntegerValue();
        CorrectResult();
    }
}

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

// floatValue������Ϊ[0,1]��
// power������Ϊ[0,24]��
// result������Ϊ[0,2^power - 1]��
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

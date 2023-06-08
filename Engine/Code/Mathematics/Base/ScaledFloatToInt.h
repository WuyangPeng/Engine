///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/05/30 14:59)

#ifndef MATHEMATICS_BASE_SCALED_FLOAT_TO_INT_H
#define MATHEMATICS_BASE_SCALED_FLOAT_TO_INT_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
    class MATHEMATICS_HIDDEN_DECLARE ScaledFloatToInt final
    {
    public:
        using ClassType = ScaledFloatToInt;

    public:
        ScaledFloatToInt(float value, int power) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int32_t GetScaledResult() const noexcept;

    private:
        void Scaled() noexcept;
        void ShiftIntegerValue() noexcept;
        void CorrectResult() noexcept;

    private:
        float floatValue;
        int32_t integerValue;
        int power;
        int shift;
        int32_t result;
    };
}

#endif  // MATHEMATICS_BASE_SCALED_FLOAT_TO_INT_H

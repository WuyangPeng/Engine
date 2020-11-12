///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/10/30 14:29)

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

        [[nodiscard]] int32_t GetScaledResult() const noexcept;

    private:
        void Scaled() noexcept;
        void ShiftIntegerValue() noexcept;
        void CorrectResult() noexcept;

    private:
        float m_FloatValue;
        int32_t m_IntegerValue;
        int m_Power;
        int m_Shift;
        int32_t m_Result;
    };
}

#endif  // MATHEMATICS_BASE_SCALED_FLOAT_TO_INT_H

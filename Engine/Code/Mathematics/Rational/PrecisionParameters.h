/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/07 15:43)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_PRECISION_PARAMETERS_H
#define MATHEMATICS_RATIONAL_RATIONAL_PRECISION_PARAMETERS_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE PrecisionParameters
    {
    public:
        using ClassType = PrecisionParameters;

    public:
        PrecisionParameters() noexcept;
        PrecisionParameters(int minExponent, int maxExponent, int maxBits) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetMinExponent() const noexcept;
        void SetMinExponent(int aMinExponent) noexcept;

        NODISCARD int GetMaxExponent() const noexcept;
        void SetMaxExponent(int aMaxExponent) noexcept;

        NODISCARD int GetMaxBits() const noexcept;
        void SetMaxBits(int aMaxBits) noexcept;

        NODISCARD int GetMaxWords() const noexcept;

    private:
        NODISCARD constexpr static int GetMaxWords(int maxBits) noexcept
        {
            return maxBits / 32 + ((maxBits % 32) > 0 ? 1 : 0);
        }

    private:
        int minExponent;
        int maxExponent;
        int maxBits;
        int maxWords;
    };
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_PRECISION_PARAMETERS_H

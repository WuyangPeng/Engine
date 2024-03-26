/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/07 15:43)

#include "Mathematics/MathematicsExport.h"

#include "PrecisionParameters.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

Mathematics::PrecisionParameters::PrecisionParameters() noexcept
    : minExponent{ 0 }, maxExponent{ 0 }, maxBits{ 0 }, maxWords{ 0 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::PrecisionParameters::PrecisionParameters(int minExponent, int maxExponent, int maxBits) noexcept
    : minExponent{ minExponent }, maxExponent{ maxExponent }, maxBits{ maxBits }, maxWords{ GetMaxWords(maxBits) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, PrecisionParameters)

int Mathematics::PrecisionParameters::GetMinExponent() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return minExponent;
}

void Mathematics::PrecisionParameters::SetMinExponent(int aMinExponent) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    minExponent = aMinExponent;
}

int Mathematics::PrecisionParameters::GetMaxExponent() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return maxExponent;
}

void Mathematics::PrecisionParameters::SetMaxExponent(int aMaxExponent) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    maxExponent = aMaxExponent;
}

int Mathematics::PrecisionParameters::GetMaxBits() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return maxBits;
}

void Mathematics::PrecisionParameters::SetMaxBits(int aMaxBits) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    maxBits = aMaxBits;
}

int Mathematics::PrecisionParameters::GetMaxWords() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return maxWords;
}

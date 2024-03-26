/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/07 16:09)

#include "Mathematics/MathematicsExport.h"

#include "BinaryScientificPrecision.h"
#include "Flags/FloatingPointAnalysisType.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

Mathematics::BinaryScientificPrecision::BinaryScientificPrecision() noexcept
    : bsn{}, bsr{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::BinaryScientificPrecision::BinaryScientificPrecision(int minExponent, int maxExponent, int maxBits) noexcept
    : bsn{ minExponent, maxExponent, maxBits }, bsr{ minExponent, maxExponent, maxBits }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::BinaryScientificPrecision::BinaryScientificPrecision(BinaryScientificPrecisionType type) noexcept
    : bsn{},
      bsr{}
{
    switch (type)
    {
        case BinaryScientificPrecisionType::IsFloat:
            bsn = PrecisionParameters{ -149, 127, 24 };
            break;
        case BinaryScientificPrecisionType::IsDouble:
            bsn = PrecisionParameters{ -1074, 1023, 53 };
            break;
        case BinaryScientificPrecisionType::IsInt32:
            bsn = PrecisionParameters{ 0, 30, 31 };
            break;
        case BinaryScientificPrecisionType::IsInt64:
            bsn = PrecisionParameters{ 0, 62, 63 };
            break;
        case BinaryScientificPrecisionType::IsUInt32:
            bsn = PrecisionParameters{ 0, 31, 32 };
            break;
        case BinaryScientificPrecisionType::IsUInt64:
            bsn = PrecisionParameters{ 0, 63, 64 };
            break;
    }

    bsr = bsn;

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, BinaryScientificPrecision)

Mathematics::PrecisionParameters Mathematics::BinaryScientificPrecision::GetBsn() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return bsn;
}

Mathematics::PrecisionParameters Mathematics::BinaryScientificPrecision::GetBsr() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return bsr;
}

void Mathematics::BinaryScientificPrecision::SetBsn(const PrecisionParameters& aBsn) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    bsn = aBsn;
}

void Mathematics::BinaryScientificPrecision::SetBsr(const PrecisionParameters& aBsr) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    bsr = aBsr;
}

void Mathematics::BinaryScientificPrecision::SetBsn(int minExponent, int maxExponent, int maxBits) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    bsn = PrecisionParameters{ minExponent, maxExponent, maxBits };
}

void Mathematics::BinaryScientificPrecision::SetBsr(int minExponent, int maxExponent, int maxBits) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    bsr = PrecisionParameters{ minExponent, maxExponent, maxBits };
}

Mathematics::BinaryScientificPrecision Mathematics::operator+(const BinaryScientificPrecision& lhs, const BinaryScientificPrecision& rhs) noexcept
{
    BinaryScientificPrecision result{};

    const auto lhsBsn = lhs.GetBsn();
    const auto lhsBsr = lhs.GetBsr();
    const auto rhsBsn = rhs.GetBsn();
    const auto rhsBsr = rhs.GetBsr();

    const auto bsnMinExponent = std::min(lhsBsn.GetMinExponent(), rhsBsn.GetMinExponent());
    if (rhsBsn.GetMaxExponent() <= lhsBsn.GetMaxExponent())
    {
        auto bsnMaxExponent = lhsBsn.GetMaxExponent();
        if (lhsBsn.GetMaxExponent() - lhsBsn.GetMaxBits() + 1 <= rhsBsn.GetMaxExponent())
        {
            ++bsnMaxExponent;
        }

        auto bsnMaxBits = lhsBsn.GetMaxExponent() - rhsBsn.GetMinExponent() + 1;
        if (bsnMaxBits <= lhsBsn.GetMaxBits() + rhsBsn.GetMaxBits() - 1)
        {
            ++bsnMaxBits;
        }

        result.SetBsn(bsnMinExponent, bsnMaxExponent, bsnMaxBits);
    }
    else
    {
        auto bsnMaxExponent = rhsBsn.GetMaxExponent();
        if (rhsBsn.GetMaxExponent() - rhsBsn.GetMaxBits() + 1 <= lhsBsn.GetMaxExponent())
        {
            ++bsnMaxExponent;
        }

        auto bsnMaxBits = rhsBsn.GetMaxExponent() - lhsBsn.GetMinExponent() + 1;
        if (bsnMaxBits <= lhsBsn.GetMaxBits() + rhsBsn.GetMaxBits() - 1)
        {
            ++bsnMaxBits;
        }

        result.SetBsn(bsnMinExponent, bsnMaxExponent, bsnMaxBits);
    }

    /// 加法为n0/d0 + n1/d1 = (n0*d1 + n1*d0)/(d0*d1)。
    /// 假设一个数字的分子和分母具有相同的参数，
    /// 因此对于加法，分子用于参数计算。

    /// 计算乘法运算的参数。
    const auto mulMinExponent = lhsBsr.GetMinExponent() + rhsBsr.GetMinExponent();
    const auto mulMaxExponent = lhsBsr.GetMaxExponent() + rhsBsr.GetMaxExponent() + 1;
    const auto mulMaxBits = lhsBsr.GetMaxBits() + rhsBsr.GetMaxBits();

    /// 计算加法的参数。数字n0*d1和n1*d0在相同的任意精度集中。
    const auto bsrMinExponent = mulMinExponent;
    const auto bsrMaxExponent = mulMaxExponent + 1;  // 总是一个执行。
    auto bsrMaxBits = mulMaxExponent - mulMinExponent + 1;
    if (bsrMaxBits <= 2 * mulMaxBits - 1)
    {
        ++bsrMaxBits;
    }
    result.SetBsr(bsrMinExponent, bsrMaxExponent, bsrMaxBits);

    return result;
}

Mathematics::BinaryScientificPrecision Mathematics::operator-(const BinaryScientificPrecision& lhs, const BinaryScientificPrecision& rhs) noexcept
{
    return lhs + rhs;
}

Mathematics::BinaryScientificPrecision Mathematics::operator*(const BinaryScientificPrecision& lhs, const BinaryScientificPrecision& rhs) noexcept
{
    BinaryScientificPrecision result{};

    const auto lhsBsn = lhs.GetBsn();
    const auto lhsBsr = lhs.GetBsr();
    const auto rhsBsn = rhs.GetBsn();
    const auto rhsBsr = rhs.GetBsr();

    const auto bsnMinExponent = lhsBsn.GetMinExponent() + rhsBsn.GetMinExponent();
    const auto bsnMaxExponent = lhsBsn.GetMaxExponent() + rhsBsn.GetMaxExponent() + 1;
    const auto bsnMaxBits = lhsBsn.GetMaxBits() + rhsBsn.GetMaxBits();
    result.SetBsn(bsnMinExponent, bsnMaxExponent, bsnMaxBits);

    /// 乘法为(n0/d0) * (n1/d1) = (n0 * n1) / (d0 * d1)。
    /// 这些参数与分子/分母的参数相同。
    const auto bsrMinExponent = lhsBsr.GetMinExponent() + rhsBsr.GetMinExponent();
    const auto bsrMaxExponent = lhsBsr.GetMaxExponent() + rhsBsr.GetMaxExponent() + 1;
    const auto bsrMaxBits = lhsBsr.GetMaxBits() + rhsBsr.GetMaxBits();
    result.SetBsr(bsrMinExponent, bsrMaxExponent, bsrMaxBits);

    return result;
}

Mathematics::BinaryScientificPrecision Mathematics::operator/(const BinaryScientificPrecision& lhs, const BinaryScientificPrecision& rhs) noexcept
{
    BinaryScientificPrecision result{};

    const auto lhsBsr = lhs.GetBsr();
    const auto rhsBsr = rhs.GetBsr();

    /// BinaryScientificNumber不支持除法，因此result.bsr的所有成员都设置为零。

    /// 除法为(n0 / d0) / (n1 / d1) = (n0 * d1) / (n1 * d0)。
    /// 参数与乘法相同
    const auto minExponent = lhsBsr.GetMinExponent() + rhsBsr.GetMinExponent();
    const auto maxExponent = lhsBsr.GetMaxExponent() + rhsBsr.GetMaxExponent() + 1;
    const auto maxBits = lhsBsr.GetMaxBits() + rhsBsr.GetMaxBits();
    result.SetBsr(minExponent, maxExponent, maxBits);

    return result;
}

Mathematics::BinaryScientificPrecision Mathematics::operator==(const BinaryScientificPrecision& lhs, const BinaryScientificPrecision& rhs) noexcept
{
    BinaryScientificPrecision result{};

    const auto lhsBsn = lhs.GetBsn();
    const auto lhsBsr = lhs.GetBsr();
    const auto rhsBsn = rhs.GetBsn();
    const auto rhsBsr = rhs.GetBsr();

    const auto bsnMinExponent = std::min(lhsBsn.GetMinExponent(), rhsBsn.GetMinExponent());
    const auto bsnMaxExponent = std::max(lhsBsn.GetMaxExponent(), rhsBsn.GetMaxExponent());
    const auto bsnMaxBits = std::max(lhsBsn.GetMaxBits(), rhsBsn.GetMaxBits());
    result.SetBsn(bsnMinExponent, bsnMaxExponent, bsnMaxBits);

    const auto bsrMinExponent = lhsBsr.GetMinExponent() + rhsBsr.GetMinExponent();
    const auto bsrMaxExponent = lhsBsr.GetMaxExponent() + rhsBsr.GetMaxExponent() + 1;
    const auto bsrMaxBits = lhsBsr.GetMaxBits() + rhsBsr.GetMaxBits();
    result.SetBsr(bsrMinExponent, bsrMaxExponent, bsrMaxBits);

    return result;
}

Mathematics::BinaryScientificPrecision Mathematics::operator!=(const BinaryScientificPrecision& lhs, const BinaryScientificPrecision& rhs) noexcept
{
    return operator==(lhs, rhs);
}

Mathematics::BinaryScientificPrecision Mathematics::operator<(const BinaryScientificPrecision& lhs, const BinaryScientificPrecision& rhs) noexcept
{
    return operator==(lhs, rhs);
}

Mathematics::BinaryScientificPrecision Mathematics::operator<=(const BinaryScientificPrecision& lhs, const BinaryScientificPrecision& rhs) noexcept
{
    return operator==(lhs, rhs);
}

Mathematics::BinaryScientificPrecision Mathematics::operator>(const BinaryScientificPrecision& lhs, const BinaryScientificPrecision& rhs) noexcept
{
    return operator==(lhs, rhs);
}

Mathematics::BinaryScientificPrecision Mathematics::operator>=(const BinaryScientificPrecision& lhs, const BinaryScientificPrecision& rhs) noexcept
{
    return operator==(lhs, rhs);
}

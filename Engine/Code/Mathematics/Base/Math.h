///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/10/30 14:16)

#ifndef MATHEMATICS_BASE_MATH_H
#define MATHEMATICS_BASE_MATH_H

#include "Mathematics/MathematicsDll.h"

#include "Flags/NumericalValueSymbol.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"

#include <limits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Math final
    {
    public:
        using ClassType = Math<Real>;

    public:
        // ��װ���غ�����ʵ�֡�
        // ��ACos��ASin�����нض��������Ϊ[-1,1]���Ա��⵱����Ϊ�Դ���1����С��-1ʱ����NaN�����⡣

        [[nodiscard]] static Real ACos(Real value) noexcept;
        [[nodiscard]] static Real ASin(Real value) noexcept;
        [[nodiscard]] static Real ATan(Real value) noexcept;
        [[nodiscard]] static Real ATan2(Real y, Real x) noexcept;
        [[nodiscard]] static Real Sin(Real value) noexcept;
        [[nodiscard]] static Real Cos(Real value) noexcept;
        [[nodiscard]] static Real Tan(Real value) noexcept;

        [[nodiscard]] static Real Ceil(Real value) noexcept;
        [[nodiscard]] static Real FAbs(Real value) noexcept;
        [[nodiscard]] static Real Floor(Real value) noexcept;
        [[nodiscard]] static Real FMod(Real x, Real y) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        [[nodiscard]] static NumericalValueSymbol Sign(Real value) noexcept;

        [[nodiscard]] static Real Log(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        [[nodiscard]] static Real Log2(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        [[nodiscard]] static Real Log10(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        [[nodiscard]] static Real Exp(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        [[nodiscard]] static Real Pow(Real base, Real exponent) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        [[nodiscard]] static Real Square(Real value) noexcept;

        /// @brief  ���㸡������ƽ������
        /// @pre    value >= 0��
        /// @post   Fabs(result * result - value) <= GetZeroTolerance()��
        [[nodiscard]] static Real Sqrt(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        [[nodiscard]] static Real InvSqrt(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        [[nodiscard]] static Real CubeRoot(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // �ض�����ֵΪ�ض��ķ�Χ[min,max]
        [[nodiscard]] static Real Clamp(Real value, Real minValue, Real maxValue) noexcept;

        // �ض�����ֵΪ[0,1].
        [[nodiscard]] static Real Saturate(Real value) noexcept;

        [[nodiscard]] static bool Approximate(Real lhs, Real rhs, const Real epsilon = GetZeroTolerance()) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // equalDigit��Ҫ�Ƚϵ�β��λ��float���Ϊ23λ��double���Ϊ52λ��
        [[nodiscard]] static bool FloatingPointEqual(Real lhs, Real rhs, int equalDigit) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        [[nodiscard]] static Real GetNumericalRoundOffNonnegative(Real value) noexcept;
        [[nodiscard]] static Real GetNumericalRoundOff(Real value, Real minValue, Real maxValue) noexcept;

    public:
        // ���ó�����
        [[nodiscard]] static Real GetExponent() noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        [[nodiscard]] static Real GetLN2() noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        [[nodiscard]] static Real GetLN10() noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        [[nodiscard]] static Real GetInverseLN2() noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        [[nodiscard]] static Real GetInverseLN10() noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        [[nodiscard]] static Real GetSqrt2() noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        [[nodiscard]] static Real GetInverseSqrt2() noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        [[nodiscard]] static Real GetSqrt3() noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        [[nodiscard]] static Real GetInverseSqrt3() noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        [[nodiscard]] static constexpr Real GetValue(int value) noexcept
        {
            return static_cast<Real>(value);
        }

        [[nodiscard]] static constexpr Real GetRational(int numerator, int denominator) noexcept
        {
            return GetValue(numerator) / GetValue(denominator);
        }

        [[nodiscard]] static constexpr Real GetDegreeToRadian() noexcept
        {
            return GetPI() / GetValue(180);
        }

        [[nodiscard]] static constexpr Real GetRadianToDegree() noexcept
        {
            return GetValue(1) / GetDegreeToRadian();
        }

        static constexpr auto sm_Epsilon = std::numeric_limits<Real>::epsilon();
        static constexpr auto sm_MaxReal = std::numeric_limits<Real>::max();
        static constexpr auto sm_MinReal = std::numeric_limits<Real>::min();

        [[nodiscard]] static constexpr Real GetZeroTolerance() noexcept;
        [[nodiscard]] static constexpr Real GetPI() noexcept;
        [[nodiscard]] static constexpr Real GetTwoPI() noexcept;
        [[nodiscard]] static constexpr Real GetHalfPI() noexcept;
        [[nodiscard]] static constexpr Real GetQuarterPI() noexcept;
        [[nodiscard]] static constexpr Real GetInversePI() noexcept;
        [[nodiscard]] static constexpr Real GetInverseTwoPI() noexcept;
    };

    using FloatMath = Math<float>;
    using DoubleMath = Math<double>;
}

#endif  // MATHEMATICS_BASE_MATH_H

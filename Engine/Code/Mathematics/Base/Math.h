///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/01/28 16:24)

#ifndef MATHEMATICS_BASE_MATH_H
#define MATHEMATICS_BASE_MATH_H

#include "Mathematics/MathematicsDll.h"

#include "Flags/NumericalValueSymbol.h"
#include "System/Helper/PragmaWarning/MathConstants.h"
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

        NODISCARD static Real ACos(Real value) noexcept;
        NODISCARD static Real ASin(Real value) noexcept;
        NODISCARD static Real ATan(Real value) noexcept;
        NODISCARD static Real ATan2(Real y, Real x) noexcept;
        NODISCARD static Real Sin(Real value) noexcept;
        NODISCARD static Real Cos(Real value) noexcept;
        NODISCARD static Real Tan(Real value) noexcept;

        NODISCARD static Real Ceil(Real value) noexcept;
        NODISCARD static Real FAbs(Real value) noexcept;
        NODISCARD static Real Floor(Real value) noexcept;
        NODISCARD static Real FMod(Real x, Real y) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        NODISCARD static NumericalValueSymbol Sign(Real value) noexcept;

        NODISCARD static Real Log(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        NODISCARD static Real Log2(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        NODISCARD static Real Log10(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        NODISCARD static Real Exp(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        NODISCARD static Real Pow(Real base, Real exponent) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        NODISCARD static Real Square(Real value) noexcept;

        /// @brief  ���㸡������ƽ������
        /// @pre    value >= 0��
        /// @post   Fabs(result * result - value) <= GetZeroTolerance()��
        NODISCARD static Real Sqrt(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        NODISCARD static Real InvSqrt(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        NODISCARD static Real CubeRoot(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // �ض�����ֵΪ�ض��ķ�Χ[min,max]
        NODISCARD static Real Clamp(Real value, Real minValue, Real maxValue) noexcept;

        // �ض�����ֵΪ[0,1].
        NODISCARD static Real Saturate(Real value) noexcept;

        NODISCARD static bool Approximate(Real lhs, Real rhs, const Real zeroTolerance = GetZeroTolerance()) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // equalDigit��Ҫ�Ƚϵ�β��λ��float���Ϊ23λ��double���Ϊ52λ��
        NODISCARD static bool FloatingPointEqual(Real lhs, Real rhs, int equalDigit) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        NODISCARD static Real GetNumericalRoundOffNonnegative(Real value) noexcept;
        NODISCARD static Real GetNumericalRoundOff(Real value, Real minValue, Real maxValue) noexcept;

    public:
        // ���ó�����
        NODISCARD static Real GetExponent() noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        NODISCARD static Real GetLN2() noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        NODISCARD static Real GetLN10() noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        NODISCARD static Real GetInverseLN2() noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        NODISCARD static Real GetInverseLN10() noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        NODISCARD static Real GetSqrt2() noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        NODISCARD static Real GetInverseSqrt2() noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        NODISCARD static Real GetSqrt3() noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        NODISCARD static Real GetInverseSqrt3() noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        NODISCARD static constexpr Real GetValue(int value) noexcept
        {
            return static_cast<Real>(value);
        }

        NODISCARD static constexpr Real GetRational(int numerator, int denominator) noexcept
        {
            return GetValue(numerator) / GetValue(denominator);
        }

        NODISCARD static constexpr Real GetDegreeToRadian() noexcept
        {
            return GetPI() / GetValue(180);
        }

        NODISCARD static constexpr Real GetRadianToDegree() noexcept
        {
            return GetValue(1) / GetDegreeToRadian();
        }

        static constexpr auto epsilon = std::numeric_limits<Real>::epsilon();
        static constexpr auto maxReal = std::numeric_limits<Real>::max();
        static constexpr auto minReal = std::numeric_limits<Real>::min();

        NODISCARD static constexpr Real GetZeroTolerance() noexcept
        {
            if constexpr (std::is_same_v<Real, float>)
            {
                return 1e-06f;
            }
            else if constexpr (std::is_same_v<Real, double>)
            {
                return 1e-08;
            }
            else
            {
                return GetValue(0);
            }
        }

        NODISCARD static constexpr Real GetPI() noexcept
        {
            if constexpr (std::is_floating_point_v<Real>)
            {
                return boost::math::constants::pi<Real>();
            }
            else
            {
                return GetValue(3);
            }
        }

        NODISCARD static constexpr Real GetTwoPI() noexcept
        {
            return GetValue(2) * GetPI();
        }

        NODISCARD static constexpr Real GetHalfPI() noexcept
        {
            return GetPI() / GetValue(2);
        }

        NODISCARD static constexpr Real GetQuarterPI() noexcept
        {
            return GetPI() / GetValue(4);
        }

        NODISCARD static constexpr Real GetInversePI() noexcept
        {
            return GetValue(1) / GetPI();
        }

        NODISCARD static constexpr Real GetInverseTwoPI() noexcept
        {
            return GetValue(1) / GetTwoPI();
        }
    };

    using MathF = Math<float>;
    using MathD = Math<double>;
}

#endif  // MATHEMATICS_BASE_MATH_H

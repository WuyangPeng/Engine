///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/03/29 13:51)

#ifndef RENDERING_DATA_TYPES_HALF_FLOAT_H
#define RENDERING_DATA_TYPES_HALF_FLOAT_H

#include "Rendering/RenderingDll.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Rational/IntegerTraits.h"

#include <iosfwd>

namespace Rendering
{
    //  һ��16λ��������1λ�ķ���λ(S)��5λ��ָ��λ(E)��10λ��С��λ(M)��
    //  16λ��������ֵ�����¾�����
    //  (-1)^S * 0.0����� E == 0��M == 0��
    //  (-1)^S * 2^(-14) * (M / 2^10)�����E == 0��M != 0��
    //  (-1)^S * 2^(E - 15) * (1 + M / 2^10)�����0 < E < 31��
    //  (-1)^S * INF�����E == 31��M == 0������
    //  NaN�����E == 31��M != 0��
    //  ����
    //  S = floor((N mod 65536) / 32768)��
    //  E = floor((N mod 32768) / 1024)����
    //  M = N mod 1024��
    //  ������ʵ��ʹ�������κ�������룺
    //  (-1)^S * 0.0�����E == 0��M != 0,
    //  (-1)^S * 2^(E-15) * (1 + M/2^10)�����E == 31��M == 0������
    //  (-1)^S * 2^(E-15) * (1 + M/2^10)�����E == 31��M != 0��
    //
    //  �±�˵����ToHalf��ToFloat�е�ת����
    // ---------------------------
    // bias16  exp32  bias32
    // ---------------------------
    //     0    -127      0 (0x00)
    //     :       :      :
    //     0     -15    112 (0x70)
    // ---------------------------
    //     1     -14    113 (0x71)
    //     :       :      :
    //    15       0    127 (0x7F)
    //     :       :      :
    //    30      15    142 (0x8E)
    // ---------------------------
    //    31      16    143 (0x8F)
    //     :       :      :
    //    31     128    255 (0xFF)
    // ---------------------------

    class RENDERING_DEFAULT_DECLARE HalfFloat : private boost::arithmetic<HalfFloat, boost::totally_ordered<HalfFloat>>
    {
    public:
        using ClassType = HalfFloat;
        using OriginalType = uint16_t;

    public:
        explicit HalfFloat(float value) noexcept;
        explicit HalfFloat(int value);

        explicit constexpr HalfFloat(OriginalType value) noexcept
            : halfFloat{ value }
        {
        }

        CLASS_INVARIANT_DECLARE;

        NODISCARD float ToFloat() const noexcept;
        NODISCARD OriginalType ToOriginalType() const noexcept;

        NODISCARD HalfFloat operator-() const noexcept;

        HalfFloat& operator+=(const HalfFloat& rhs) noexcept;
        HalfFloat& operator-=(const HalfFloat& rhs) noexcept;
        HalfFloat& operator*=(const HalfFloat& rhs) noexcept;
        HalfFloat& operator/=(const HalfFloat& rhs);

    private:
        NODISCARD static OriginalType ConvertHalfFloat(float value) noexcept;

    private:
        using IntegerType = OriginalType;
        static constexpr IntegerType symbol{ 0x8000 };
        static constexpr uint32_t symbolShifting{ 15 };
        static constexpr IntegerType exponent{ 0x7C00 };
        static constexpr uint32_t exponentShifting{ 10 };
        static constexpr uint32_t realExponentDifference{ 0xF };
        static constexpr IntegerType mantissa{ 0x03FF };
        static constexpr IntegerType quietNaN{ 0x0200 };
        static constexpr auto exponentDigits = symbolShifting - exponentShifting;

        using FloatTraitsType = typename Mathematics::IntegerTraits<float>::TraitsType;
        using FloatIntegerType = typename FloatTraitsType::IntegerType;

        static constexpr auto symbolShiftingDifference = FloatTraitsType::symbolShifting - symbolShifting;
        static constexpr auto exponentShiftingDifference = FloatTraitsType::exponentShifting - exponentShifting;
        static constexpr auto exponentDifference = ((1 << FloatTraitsType::exponentDigits) - (1 << exponentDigits)) / 2;

    private:
        OriginalType halfFloat;
    };

    NODISCARD bool RENDERING_DEFAULT_DECLARE operator==(const HalfFloat& lhs, const HalfFloat& rhs) noexcept;
    NODISCARD bool RENDERING_DEFAULT_DECLARE operator<(const HalfFloat& lhs, const HalfFloat& rhs) noexcept;

    NODISCARD bool RENDERING_DEFAULT_DECLARE Approximate(const HalfFloat& lhs, const HalfFloat& rhs, const float epsilon = Mathematics::MathF::GetZeroTolerance()) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

    RENDERING_DEFAULT_DECLARE std::ostream& operator<<(std::ostream& outFile, const HalfFloat& halfFloat);

    NODISCARD float RENDERING_DEFAULT_DECLARE operator*(float lhs, const HalfFloat& rhs) noexcept;
    NODISCARD float RENDERING_DEFAULT_DECLARE operator*(const HalfFloat& lhs, float rhs) noexcept;
    NODISCARD float RENDERING_DEFAULT_DECLARE operator/(float lhs, const HalfFloat& rhs);

    NODISCARD HalfFloat RENDERING_DEFAULT_DECLARE FAbs(const HalfFloat& value) noexcept;
}

#endif  // RENDERING_DATA_TYPES_HALF_FLOAT_H

///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/11 14:58)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DATA_ANALYSIS_H
#define MATHEMATICS_RATIONAL_INTEGER_DATA_ANALYSIS_H

#include "Mathematics/MathematicsDll.h"

#include "RationalFwd.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"

#include <boost/noncopyable.hpp>
#include <iosfwd>
#include <vector>

namespace Mathematics
{
    // N是你想要元整数的32位字节的数目。
    template <int N>
    class IntegerDataAnalysis final : private boost::noncopyable
    {
    public:
        using ClassType = IntegerDataAnalysis<N>;
        using IntegerData = IntegerData<N>;

    public:
        explicit IntegerDataAnalysis(const IntegerData& master) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD IntegerData GetAbsoluteValue() const;

        // 其他实用程序。
        NODISCARD uint32_t ToUnsignedInt(int index) const;
        NODISCARD int ToInt(int index) const;
        NODISCARD uint32_t ToUnsignedInt(int lowerIndex, int highIndex) const;

        NODISCARD int GetLeadingBlock() const;
        NODISCARD int GetTrailingBlock() const;
        NODISCARD int GetLeadingBit(int index) const;  // m_Buffer[i]
        NODISCARD int GetTrailingBit(int index) const;  // m_Buffer[i]
        NODISCARD int GetLeadingBit() const;  // 整个数字
        NODISCARD int GetTrailingBit() const;  // 整个数字

        // 算术运算。
        NODISCARD IntegerData operator-() const;

        NODISCARD IntegerDivisionModulo<N> GetDivisionModulo(const IntegerData& rhs) const;

    private:
        static constexpr auto maskSize = 4;
        static constexpr auto low = 0x0000FFFF;
        static constexpr auto intSize = 2 * N;
        static constexpr auto intLast = intSize - 1;

        using MaskType = std::array<uint16_t, maskSize>;

        // 1111 1111 0000 0000
        // 1111 0000 1111 0000
        // 1100 1100 1100 1100
        // 1010 1010 1010 1010
        static constexpr MaskType leadingMask{ 0xFF00, 0xF0F0, 0xCCCC, 0xAAAA };

        // 0000 0000 1111 1111
        // 0000 1111 0000 1111
        // 0011 0011 0011 0011
        // 0101 0101 0101 0101
        static constexpr MaskType trailingMask{ 0x00FF, 0x0F0F, 0x3333, 0x5555 };

        // 最低位储存在索引0。
        const IntegerData& master;
    };

    template <int N>
    std::ostream& operator<<(std::ostream& os, const IntegerDataAnalysis<N>& integerDataAnalysis);
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_DATA_ANALYSIS_H

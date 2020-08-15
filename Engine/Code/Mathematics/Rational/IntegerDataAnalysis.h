// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.2.5 (2020/03/20 09:47)

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
    class IntegerDataAnalysis : boost::noncopyable
    {
    public:
        using ClassType = IntegerDataAnalysis<N>;
        using IntegerData = IntegerData<N>;

    public:
        explicit IntegerDataAnalysis(const IntegerData& master) noexcept;

        CLASS_INVARIANT_DECLARE;

        const IntegerData GetAbsoluteValue() const;

        // 其他实用程序。
        uint32_t ToUnsignedInt(int index) const;
        int ToInt(int index) const;
        uint32_t ToUnsignedInt(int lowerIndex, int highIndex) const;

        int GetLeadingBlock() const;
        int GetTrailingBlock() const;
        int GetLeadingBit(int index) const;  // m_Buffer[i]
        int GetTrailingBit(int index) const;  // m_Buffer[i]
        int GetLeadingBit() const;  // 整个数字
        int GetTrailingBit() const;  // 整个数字

        // 算术运算。
        const IntegerData operator-() const;

        const IntegerDivisionModulo<N> GetDivisionModulo(const IntegerData& rhs) const;

    private:
        static constexpr int sm_MaskSize{ 4 };
        static const uint16_t sm_LeadingMask[sm_MaskSize];
        static const uint16_t sm_TrailingMask[sm_MaskSize];
        static constexpr uint32_t sm_Low{ 0x0000FFFF };
        static constexpr uint32_t sm_IntSize{ 2 * N };
        static constexpr uint32_t sm_IntLast{ sm_IntSize - 1 };

        // 最低位储存在索引0。
        const IntegerData& m_Master;
    };

    template <int N>
    std::ostream& operator<<(std::ostream& os, const IntegerDataAnalysis<N>& integerDataAnalysis);
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_DATA_ANALYSIS_H

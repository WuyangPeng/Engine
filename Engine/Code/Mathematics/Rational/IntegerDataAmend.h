///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/19 9:59)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DATA_AMEND_H
#define MATHEMATICS_RATIONAL_INTEGER_DATA_AMEND_H

#include "Mathematics/MathematicsDll.h"

#include "RationalFwd.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"

#include <boost/noncopyable.hpp>
#include <vector>

namespace Mathematics
{
    // N是你想要元整数的32位字节的数目。
    template <int N>
    class IntegerDataAmend final : private boost::noncopyable
    {
    public:
        using ClassType = IntegerDataAmend<N>;
        using IntegerData = IntegerData<N>;

    public:
        explicit IntegerDataAmend(IntegerData& master) noexcept;

        CLASS_INVARIANT_DECLARE;

        void Negative();
        void FromUnsignedInt(int index, uint32_t value);
        void SetValue(int beginIndex, int endIndex, uint32_t value);

    private:
        static constexpr auto sm_IntSize = 2 * N;
        static constexpr auto sm_Carry = 0x00010000u;
        static constexpr auto sm_Low = 0x0000FFFFu;

        IntegerData& m_Master;
    };
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_DATA_AMEND_H

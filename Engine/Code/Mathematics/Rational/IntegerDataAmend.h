/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 23:28)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DATA_AMEND_H
#define MATHEMATICS_RATIONAL_INTEGER_DATA_AMEND_H

#include "Mathematics/MathematicsDll.h"

#include "RationalFwd.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"

#include <boost/noncopyable.hpp>

namespace Mathematics
{
    // N������ҪԪ������32λ�ֽڵ���Ŀ��
    template <int N>
    class IntegerDataAmend final : private boost::noncopyable
    {
    public:
        using ClassType = IntegerDataAmend<N>;
        using IntegerDataType = IntegerData<N>;

    public:
        explicit IntegerDataAmend(IntegerDataType& master) noexcept;

        CLASS_INVARIANT_DECLARE;

        void Negative();
        void FromUnsignedInt(int index, uint32_t value);
        void SetValue(int beginIndex, int endIndex, uint32_t value);

    private:
        static constexpr auto intSize = 2 * N;
        static constexpr auto integerCarry = 0x00010000u;
        static constexpr auto low = 0x0000FFFFu;

        IntegerDataType& master;
    };
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_DATA_AMEND_H

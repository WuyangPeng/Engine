///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/19 10:02)

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
    // N������ҪԪ������32λ�ֽڵ���Ŀ��
    template <int N>
    class IntegerDataAnalysis final : private boost::noncopyable
    {
    public:
        using ClassType = IntegerDataAnalysis<N>;
        using IntegerData = IntegerData<N>;

    public:
        explicit IntegerDataAnalysis(const IntegerData& master) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const IntegerData GetAbsoluteValue() const;

        // ����ʵ�ó���
        [[nodiscard]] uint32_t ToUnsignedInt(int index) const;
        [[nodiscard]] int ToInt(int index) const;
        [[nodiscard]] uint32_t ToUnsignedInt(int lowerIndex, int highIndex) const;

        [[nodiscard]] int GetLeadingBlock() const;
        [[nodiscard]] int GetTrailingBlock() const;
        [[nodiscard]] int GetLeadingBit(int index) const;  // m_Buffer[i]
        [[nodiscard]] int GetTrailingBit(int index) const;  // m_Buffer[i]
        [[nodiscard]] int GetLeadingBit() const;  // ��������
        [[nodiscard]] int GetTrailingBit() const;  // ��������

        // �������㡣
        [[nodiscard]] const IntegerData operator-() const;

        [[nodiscard]] const IntegerDivisionModulo<N> GetDivisionModulo(const IntegerData& rhs) const;

    private:
        static constexpr auto sm_MaskSize = 4;
        static constexpr auto sm_Low = 0x0000FFFF;
        static constexpr auto sm_IntSize = 2 * N;
        static constexpr auto sm_IntLast = sm_IntSize - 1;

        using MaskType = std::array<uint16_t, sm_MaskSize>;          

        // 1111 1111 0000 0000
        // 1111 0000 1111 0000
        // 1100 1100 1100 1100
        // 1010 1010 1010 1010
        static constexpr MaskType sm_LeadingMask{ 0xFF00, 0xF0F0, 0xCCCC, 0xAAAA };

        // 0000 0000 1111 1111
        // 0000 1111 0000 1111
        // 0011 0011 0011 0011
        // 0101 0101 0101 0101
        static constexpr MaskType sm_TrailingMask{ 0x00FF, 0x0F0F, 0x3333, 0x5555 };

        // ���λ����������0��
        const IntegerData& m_Master;
    };

    template <int N>
    std::ostream& operator<<(std::ostream& os, const IntegerDataAnalysis<N>& integerDataAnalysis);
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_DATA_ANALYSIS_H

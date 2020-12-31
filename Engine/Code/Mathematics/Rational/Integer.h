///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/18 18:14)

#ifndef MATHEMATICS_RATIONAL_INTEGER_H
#define MATHEMATICS_RATIONAL_INTEGER_H

#include "Mathematics/MathematicsDll.h"

#include "IntegerData.h"
#include "IntegerDivisionModulo.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"

#include <iosfwd>
#include <vector>

// IntegerDataֻ�����ʼ����[]�������
// IntegerDataAmend�����޸�IntegerData�ĺ�����
// IntegerDataAnalysis�������������
// IntegerDataOperator������ѧ�������
// IntegerMultiplication����˷���
// IntegerDivisionModulo������������ࡣ
// Integerֻ������Ҫ���ⲿ�ӿڡ�
namespace Mathematics
{
    // N������ҪԪ������32λ�ֽڵ���Ŀ��
    template <int N>
    class Integer final : private boost::integer_arithmetic<Integer<N>, boost::totally_ordered<Integer<N>, boost::shiftable<Integer<N>>>>
    {
    public:
        static_assert(1 <= N);

        using ClassType = Integer<N>;
        using IntegerDivisionModulo = IntegerDivisionModulo<N>;
        using DataType = std::vector<uint16_t>;
        using IntegerData = IntegerData<N>;

    public:
        Integer() noexcept;
        explicit Integer(const DataType& data);
        explicit Integer(const IntegerData& data) noexcept;

        template <typename T>
        explicit Integer(T value);

        template <int Other>
        explicit Integer(const Integer<Other>& rhs);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] bool IsZero() const noexcept;
        [[nodiscard]] void SetZero();
        [[nodiscard]] NumericalValueSymbol GetSign() const noexcept;

        [[nodiscard]] uint16_t& operator[](int index);
        [[nodiscard]] const uint16_t& operator[](int index) const;

        // �������㡣
        [[nodiscard]] const Integer operator-() const;
        [[nodiscard]] const Integer GetAbsoluteValue() const;

        // �������¡�
        Integer& operator+=(const Integer& rhs);
        Integer& operator-=(const Integer& rhs);
        Integer& operator*=(const Integer& rhs);

        // ���Ҫͬʱ����̺�������ֱ�ӵ���GetDivisionModulo
        [[nodiscard]] const IntegerDivisionModulo GetDivisionModulo(const Integer& rhs) const;
        Integer& operator/=(const Integer& rhs);
        Integer& operator%=(const Integer& rhs);

        // ��λ���¡�
        Integer& operator<<=(int shift);
        Integer& operator>>=(int shift);

        [[nodiscard]] int GetLeadingBlock() const;
        [[nodiscard]] int GetTrailingBlock() const;
        [[nodiscard]] int GetLeadingBit(int index) const;
        [[nodiscard]] int GetTrailingBit(int index) const;
        [[nodiscard]] int GetLeadingBit() const;
        [[nodiscard]] int GetTrailingBit() const;

        void SetBit(int index, bool on);
        [[nodiscard]] bool GetBit(int index) const;

        // �Ƚ�
        [[nodiscard]] bool operator==(const Integer& rhs) const;
        [[nodiscard]] bool operator<(const Integer& rhs) const;

        // ����ֵ�����ضϣ��׳��쳣
        template <typename T>
        [[nodiscard]] T GetValue() const;

        void Print(std::ostream& os) const;

    private:
        IntegerData m_IntegerData;
    };

    template <int N>
    std::ostream& operator<<(std::ostream& os, const Integer<N>& integer);
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_H

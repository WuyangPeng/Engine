///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 20:06)

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
        NODISCARD static Integer<N> CreateOne() noexcept;

        enum class Special
        {
            One = 1,
        };

        explicit Integer(Special special) noexcept;
        Integer() noexcept;
        explicit Integer(const DataType& data);
        explicit Integer(const IntegerData& data) noexcept;

        template <typename T>
        explicit Integer(T value);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsZero() const noexcept;
        NODISCARD void SetZero();
        NODISCARD NumericalValueSymbol GetSign() const noexcept;

        NODISCARD uint16_t& operator[](int index);
        NODISCARD const uint16_t& operator[](int index) const;

        // �������㡣
        NODISCARD Integer operator-() const;
        NODISCARD Integer GetAbsoluteValue() const;

        // �������¡�
        Integer& operator+=(const Integer& rhs);
        Integer& operator-=(const Integer& rhs);
        Integer& operator*=(const Integer& rhs);

        // ���Ҫͬʱ����̺�������ֱ�ӵ���GetDivisionModulo
        NODISCARD IntegerDivisionModulo GetDivisionModulo(const Integer& rhs) const;
        Integer& operator/=(const Integer& rhs);
        Integer& operator%=(const Integer& rhs);

        // ��λ���¡�
        Integer& operator<<=(int shift);
        Integer& operator>>=(int shift);

        NODISCARD int GetLeadingBlock() const;
        NODISCARD int GetTrailingBlock() const;
        NODISCARD int GetLeadingBit(int index) const;
        NODISCARD int GetTrailingBit(int index) const;
        NODISCARD int GetLeadingBit() const;
        NODISCARD int GetTrailingBit() const;

        void SetBit(int index, bool on);
        NODISCARD bool GetBit(int index) const;

        // �Ƚ�
        NODISCARD bool operator==(const Integer& rhs) const;
        NODISCARD bool operator<(const Integer& rhs) const;

        // ����ֵ�����ضϣ��׳��쳣
        template <typename T>
        NODISCARD T GetValue() const;

        void Print(std::ostream& os) const;

    private:
        IntegerData integerData;
    };

    template <int N>
    std::ostream& operator<<(std::ostream& os, const Integer<N>& integer);
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_H

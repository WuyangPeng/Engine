///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/18 18:14)

#ifndef MATHEMATICS_RATIONAL_INTEGER_H
#define MATHEMATICS_RATIONAL_INTEGER_H

#include "Mathematics/MathematicsDll.h"

#include "IntegerData.h"
#include "IntegerDivisionModulo.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"

#include <iosfwd>
#include <vector>

// IntegerData只定义初始化和[]运算符。
// IntegerDataAmend定义修改IntegerData的函数。
// IntegerDataAnalysis定义解析函数。
// IntegerDataOperator定义数学运算符。
// IntegerMultiplication定义乘法。
// IntegerDivisionModulo定义除法和求余。
// Integer只包含必要的外部接口。
namespace Mathematics
{
    // N是你想要元整数的32位字节的数目。
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

        // 算术运算。
        [[nodiscard]] const Integer operator-() const;
        [[nodiscard]] const Integer GetAbsoluteValue() const;

        // 算术更新。
        Integer& operator+=(const Integer& rhs);
        Integer& operator-=(const Integer& rhs);
        Integer& operator*=(const Integer& rhs);

        // 如果要同时求出商和余数，直接调用GetDivisionModulo
        [[nodiscard]] const IntegerDivisionModulo GetDivisionModulo(const Integer& rhs) const;
        Integer& operator/=(const Integer& rhs);
        Integer& operator%=(const Integer& rhs);

        // 移位更新。
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

        // 比较
        [[nodiscard]] bool operator==(const Integer& rhs) const;
        [[nodiscard]] bool operator<(const Integer& rhs) const;

        // 返回值若被截断，抛出异常
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

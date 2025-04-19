/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 23:28)

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

        using IntegerDivisionModuloType = IntegerDivisionModulo<N>;
        using DataType = std::vector<uint16_t>;
        using IntegerDataType = IntegerData<N>;

    public:
        NODISCARD static Integer<N> CreateOne() noexcept;

        enum class Special
        {
            One = 1,
        };

        explicit Integer(Special special) noexcept;
        Integer() noexcept;
        explicit Integer(const DataType& data);
        explicit Integer(const IntegerDataType& data) noexcept;

        template <typename T>
        explicit Integer(T value);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsZero() const noexcept;
        void SetZero();
        NODISCARD NumericalValueSymbol GetSign() const noexcept;

        NODISCARD uint16_t& operator[](int index);
        NODISCARD const uint16_t& operator[](int index) const;

        // 算术运算。
        NODISCARD Integer operator-() const;
        NODISCARD Integer GetAbsoluteValue() const;

        // 算术更新。
        Integer& operator+=(const Integer& rhs);
        Integer& operator-=(const Integer& rhs);
        Integer& operator*=(const Integer& rhs);

        // 如果要同时求出商和余数，直接调用GetDivisionModulo
        NODISCARD IntegerDivisionModuloType GetDivisionModulo(const Integer& rhs) const;
        Integer& operator/=(const Integer& rhs);
        Integer& operator%=(const Integer& rhs);

        // 移位更新。
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

        // 比较
        NODISCARD bool operator==(const Integer& rhs) const;
        NODISCARD bool operator<(const Integer& rhs) const;

        // 返回值若被截断，抛出异常
        template <typename T>
        NODISCARD T GetValue() const;

        void Print(std::ostream& os) const;

    private:
        IntegerDataType integerData;
    };

    template <int N>
    std::ostream& operator<<(std::ostream& os, const Integer<N>& integer);
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_H

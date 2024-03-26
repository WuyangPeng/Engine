/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 19:36)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_U_INTEGER_ARITHMETIC_LOGIC_UNIT_32_H
#define MATHEMATICS_RATIONAL_RATIONAL_U_INTEGER_ARITHMETIC_LOGIC_UNIT_32_H

#include "Mathematics/MathematicsDll.h"

/// 在BSNumber和BSRational中支持无符号整数运算。
/// Curiously Recurring Template Paradigm用于允许UInteger类型在不引入虚拟函数的情况下共享代码。
namespace Mathematics
{
    template <typename UInteger>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE UIntegerArithmeticLogicUnit32
    {
    public:
        using ClassType = UIntegerArithmeticLogicUnit32<UInteger>;

    public:
        UIntegerArithmeticLogicUnit32() noexcept;
        virtual ~UIntegerArithmeticLogicUnit32() noexcept = default;
        UIntegerArithmeticLogicUnit32(const UIntegerArithmeticLogicUnit32& rhs) = default;
        UIntegerArithmeticLogicUnit32& operator=(const UIntegerArithmeticLogicUnit32& rhs) = default;
        UIntegerArithmeticLogicUnit32(UIntegerArithmeticLogicUnit32&& rhs) noexcept = default;
        UIntegerArithmeticLogicUnit32& operator=(UIntegerArithmeticLogicUnit32&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        /// 比较。这些都不是通用的。
        /// 当BSNumber::operatorX()的两个BSNumber参数的形式为1.u*2^p和1.v*2^p时，
        /// 它们依赖于被调用。
        /// 比较适用于作为无符号整数的1.u和1.v，它们的前导1位对齐。
        NODISCARD bool operator==(const UInteger& number) const;
        NODISCARD bool operator!=(const UInteger& number) const;
        NODISCARD bool operator<(const UInteger& number) const;
        NODISCARD bool operator<=(const UInteger& number) const;
        NODISCARD bool operator>(const UInteger& number) const;
        NODISCARD bool operator>=(const UInteger& number) const;

        /// 算术运算。
        /// 这些都是在适当的地方执行的；
        /// 也就是说，结果存储在'this'对象中。
        /// 目标是减少对象副本的数量，
        /// 就像std::move的目标一样。
        /// 子函数要求输入满足n0 > n1。
        void Add(const UInteger& n0, const UInteger& n1);
        void Sub(const UInteger& n0, const UInteger& n1);
        void Mul(const UInteger& n0, const UInteger& n1);

        /// 换挡到位；也就是说，结果存储在'this'对象中。
        void ShiftLeft(const UInteger& number, int shift);

        /// 数字”是偶数和正数。
        /// 它向右移动成为奇数，返回值是移动的量。
        /// 操作执行到位；也就是说，结果存储在'this'对象中。
        NODISCARD int ShiftRightToOdd(const UInteger& number);

        /// 在'this'上加1，这对于BSNumber和BSRational转换中的舍入模式很有用。
        /// 操作执行到位；也就是说，结果存储在'this'对象中。
        /// 返回值是为了获得奇数整数而在相加后偏移的量。
        NODISCARD int RoundUp();

        /// 获取一个以非零数字的前导1位开始的numRequested位块。
        /// 返回的数字的前缀存储在高位。
        /// 附加位被复制并由调用方用于舍入。
        /// 此函数支持从'float'到'double'的转换。
        /// 输入“numRequested”小于64。
        NODISCARD uint64_t GetPrefix(int numRequested) const;

    private:
        NODISCARD virtual const UInteger& GetSelf() const noexcept = 0;
        NODISCARD virtual UInteger& GetSelf() noexcept = 0;
    };
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_U_INTEGER_ARITHMETIC_LOGIC_UNIT_32_H

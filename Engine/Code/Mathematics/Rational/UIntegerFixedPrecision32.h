/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 20:06)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_U_INTEGER_FIXED_PRECISION_32_H
#define MATHEMATICS_RATIONAL_RATIONAL_U_INTEGER_FIXED_PRECISION_32_H

#include "Mathematics/MathematicsDll.h"

#include "UIntegerArithmeticLogicUnit32.h"

#include <array>
#include <iostream>

/// 类UIntegerFP32被设计为支持使用BSNumber和BSRational的固定精度算术。
/// 它不是用于无符号整数算术的通用类。
/// 模板参数N是存储所需计算精度所需的32位字的数量（最大位数为32*N）。
namespace Mathematics
{
    template <int N>
    requires(0 < N)
    class UIntegerFixedPrecision32 final : public UIntegerArithmeticLogicUnit32<UIntegerFixedPrecision32<N>>
    {
    public:
        using ClassType = UIntegerFixedPrecision32<N>;
        using ParentType = UIntegerArithmeticLogicUnit32<UIntegerFixedPrecision32<N>>;

        using BitsType = std::array<uint32_t, N>;

    public:
        NODISCARD static UIntegerFixedPrecision32 CreateZero() noexcept;
        UIntegerFixedPrecision32() noexcept;

        explicit UIntegerFixedPrecision32(uint32_t number);
        explicit UIntegerFixedPrecision32(uint64_t number) requires(2 <= N);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void SetNumBits(int aNumBits);

        NODISCARD int GetNumBits() const noexcept;
        NODISCARD const BitsType& GetBits() const noexcept;
        NODISCARD BitsType& GetBits() noexcept;

        void SetBack(uint32_t value);
        NODISCARD uint32_t GetBack() const;

        NODISCARD int GetSize() const noexcept;
        NODISCARD static int GetMaxSize() noexcept;

        void SetAllBitsToZero();

        /// 从UIntegerFixedPrecision32<NSource>复制到UIntegerFixedPrecision32<N> ，只要NSource <= N。
        template <int NSource>
        void CopyFrom(const UIntegerFixedPrecision32<NSource>& source) requires(NSource <= N);

        /// 磁盘输入/输出。
        /// 应该使用std::ios::binary创建fstream对象。如果操作成功，则返回值为“true”。
        bool Write(std::ostream& output) const;
        bool Read(std::istream& input);

    private:
        NODISCARD const UIntegerFixedPrecision32& GetSelf() const noexcept override;
        NODISCARD UIntegerFixedPrecision32& GetSelf() noexcept override;

    private:
        int numBits;
        int size;
        BitsType bits;
    };
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_U_INTEGER_FIXED_PRECISION_32_H

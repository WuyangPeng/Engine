/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 19:58)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_U_INTEGER_ARBITRARY_PRECISION_32_H
#define MATHEMATICS_RATIONAL_RATIONAL_U_INTEGER_ARBITRARY_PRECISION_32_H

#include "Mathematics/MathematicsDll.h"

#include "UIntegerArithmeticLogicUnit32.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"

#include <vector>

MATHEMATICS_DELAY_COPY_UNSHARED_EXPORT_IMPL(UIntegerArbitraryPrecision32, UIntegerArbitraryPrecision32Impl);

/// 类UIntegerArbitraryPrecision32被设计为支持使用BSNumber和BSRational的任意精度算术。
/// 它不是用于无符号整数算术的通用类。
///
/// 如果数字不是太大，则可以安全地将UIntegerArbitraryPrecision32替换为UIntegerFixedPrecision32，
/// 这会导致代码更快，因为在BSNumber操作期间，std::vector<uint32_t> 不再具有定期发生的动态内存分配和释放。
/// 一个更安全的选择是从数学上论证最大大小以N为界。
/// 这需要分析您执行的计算类型需要多少精度位。
/// 有关允许您计算最大N的代码，请参阅BSPrecision类。
namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE UIntegerArbitraryPrecision32 final : public UIntegerArithmeticLogicUnit32<UIntegerArbitraryPrecision32>
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(UIntegerArbitraryPrecision32);
        using ParentType = UIntegerArithmeticLogicUnit32<UIntegerArbitraryPrecision32>;

        using BitsType = std::vector<uint32_t>;

    public:
        NODISCARD static UIntegerArbitraryPrecision32 CreateZero();
        explicit UIntegerArbitraryPrecision32(uint32_t number);
        explicit UIntegerArbitraryPrecision32(uint64_t number);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void SetNumBits(int numBits);

        NODISCARD int GetNumBits() const noexcept;
        NODISCARD const BitsType& GetBits() const noexcept;
        NODISCARD BitsType& GetBits();

        void SetBack(uint32_t value);
        NODISCARD uint32_t GetBack() const noexcept;

        NODISCARD int GetSize() const;
        NODISCARD static int GetMaxSize() noexcept;

        void SetAllBitsToZero();

        /// 磁盘输入/输出。
        /// 如果操作成功，则返回值为'true'。
        bool Write(std::ostream& output) const;
        bool Read(std::istream& input);

    private:
        explicit UIntegerArbitraryPrecision32(CoreTools::DisableNotThrow disableNotThrow);

        NODISCARD const UIntegerArbitraryPrecision32& GetSelf() const noexcept override;
        NODISCARD UIntegerArbitraryPrecision32& GetSelf() noexcept override;

    private:
        PackageType impl;
    };
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_U_INTEGER_ARBITRARY_PRECISION_32_H

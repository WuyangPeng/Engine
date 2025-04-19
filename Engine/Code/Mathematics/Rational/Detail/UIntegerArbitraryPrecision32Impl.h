/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 11:06)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_U_INTEGER_ARBITRARY_PRECISION_32_IMPL_H
#define MATHEMATICS_RATIONAL_RATIONAL_U_INTEGER_ARBITRARY_PRECISION_32_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include <istream>
#include <vector>
#include <limits>

namespace Mathematics
{
    class MATHEMATICS_HIDDEN_DECLARE UIntegerArbitraryPrecision32Impl
    {
    public:
        using ClassType = UIntegerArbitraryPrecision32Impl;

        using BitsType = std::vector<uint32_t>;

    public:
        UIntegerArbitraryPrecision32Impl() noexcept;

        explicit UIntegerArbitraryPrecision32Impl(uint32_t number);
        explicit UIntegerArbitraryPrecision32Impl(uint64_t number);

        CLASS_INVARIANT_DECLARE;

        void SetNumBits(int aNumBits);

        NODISCARD int GetNumBits() const noexcept;
        NODISCARD const BitsType& GetBits() const noexcept;
        NODISCARD BitsType& GetBits() noexcept;

        void SetBack(uint32_t value) noexcept;
        NODISCARD uint32_t GetBack() const noexcept;

        NODISCARD int GetSize() const;

        NODISCARD static constexpr int GetMaxSize() noexcept
        {
            return std::numeric_limits<int>::max();
        }

        void SetAllBitsToZero();

        bool Write(std::ostream& output) const;
        bool Read(std::istream& input);

    private:
        int numBits;
        BitsType bits;
    };
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_U_INTEGER_ARBITRARY_PRECISION_32_IMPL_H

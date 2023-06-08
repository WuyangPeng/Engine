///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/05/30 14:58)

#ifndef MATHEMATICS_BASE_LOG2_OF_POWER_OF_TWO_H
#define MATHEMATICS_BASE_LOG2_OF_POWER_OF_TWO_H

#include <array>
#include <type_traits>

namespace Mathematics
{
    template <typename T>
    requires std::is_integral_v<T>
    class Log2OfPowerOfTwo final
    {
    public:
        using ClassType = Log2OfPowerOfTwo;
        using UnsignedType = std::make_unsigned_t<T>;
        using CalculateType = std::conditional_t<std::is_same_v<uint64_t, UnsignedType>, uint64_t, uint32_t>;

    public:
        explicit Log2OfPowerOfTwo(T powerOfTwo) noexcept;

        CLASS_INVARIANT_DECLARE;

#ifdef OPEN_CLASS_INVARIANT

        NODISCARD bool IsPowerOfTwoValid() const noexcept;
        NODISCARD bool IsLog2Valid() const noexcept;
        NODISCARD bool IsConvertValid() const noexcept;
        NODISCARD CalculateType GetPowerOfTwoLow() const noexcept;

#endif  // OPEN_CLASS_INVARIANT

        NODISCARD int GetLog2() const;

    private:
        void Convert() noexcept;
        void DetermineWhetherBitExist(int maskIndex, CalculateType mask) noexcept;
        void PowerOfTwoWithMask(int maskIndex, CalculateType mask) noexcept;

    private:
        // 1111 1111 1111 1111 0000 0000 0000 0000
        // 1111 1111 0000 0000 1111 1111 0000 0000
        // 1111 0000 1111 0000 1111 0000 1111 0000
        // 1100 1100 1100 1100 1100 1100 1100 1100
        // 1010 1010 1010 1010 1010 1010 1010 1010
        static constexpr auto maskSize = 5;
        static constexpr std::array<uint32_t, maskSize> maskContainer32{ 0xFFFF0000, 0xFF00FF00, 0xF0F0F0F0, 0xCCCCCCCC, 0xAAAAAAAA };
        static constexpr std::array<uint64_t, maskSize + 1> maskContainer64{ 0xFFFFFFFF00000000ull, 0xFFFF0000FFFF0000ull, 0xFF00FF00FF00FF00ull, 0xF0F0F0F0F0F0F0F0ull, 0xCCCCCCCCCCCCCCCCull, 0xAAAAAAAAAAAAAAAAull };

        T powerOfTwo;
        T powerOfTwoCopy;
        CalculateType log2;
    };
}

#endif  // MATHEMATICS_BASE_LOG2_OF_POWER_OF_TWO_H

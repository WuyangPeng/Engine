///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/01/28 16:07)

#ifndef MATHEMATICS_BASE_LOG2_OF_POWER_OF_TWO_H
#define MATHEMATICS_BASE_LOG2_OF_POWER_OF_TWO_H

#include <array>
#include <type_traits>

namespace Mathematics
{
    template <typename T>
    class Log2OfPowerOfTwo final
    {
    public:
        static_assert(std::is_integral_v<T>, "T must be integral.");

        using ClassType = Log2OfPowerOfTwo;

    public:
        explicit Log2OfPowerOfTwo(T powerOfTwo) noexcept;

        CLASS_INVARIANT_DECLARE;

#ifdef OPEN_CLASS_INVARIANT
        NODISCARD bool IsPowerOfTwoValid() const noexcept;
        NODISCARD bool IsLog2Valid() const noexcept;
        NODISCARD bool IsConvertValid() const noexcept;
        NODISCARD uint32_t GetPowerOfTwoLow() const noexcept;
#endif  // OPEN_CLASS_INVARIANT

        NODISCARD T GetLog2() const;

    private:
        void Convert() noexcept;
        void DetermineWhetherBitExist(int maskIndex, uint32_t mask) noexcept;
        void PowerOfTwoWithMask(int maskIndex, uint32_t mask) noexcept;

    private:
        // 1111 1111 1111 1111 0000 0000 0000 0000
        // 1111 1111 0000 0000 1111 1111 0000 0000
        // 1111 0000 1111 0000 1111 0000 1111 0000
        // 1100 1100 1100 1100 1100 1100 1100 1100
        // 1010 1010 1010 1010 1010 1010 1010 1010
        static constexpr auto maskSize = 5;
        static constexpr std::array<uint32_t, maskSize> maskContainer{ 0xFFFF0000, 0xFF00FF00, 0xF0F0F0F0, 0xCCCCCCCC, 0xAAAAAAAA };

        T powerOfTwo;
        T powerOfTwoCopy;
        uint32_t log2;
    };
}

#endif  // MATHEMATICS_BASE_LOG2_OF_POWER_OF_TWO_H

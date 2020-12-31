///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/10/30 14:15)

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

#ifdef OPEN_CLASS_INVARIANT
        CLASS_INVARIANT_DECLARE;
        [[nodiscard]] bool IsPowerOfTwoValid() const noexcept;
        [[nodiscard]] bool IsLog2Valid() const noexcept;
        [[nodiscard]] bool IsConvertValid() const noexcept;
        [[nodiscard]] uint32_t GetPowerOfTwoLow() const noexcept;
#endif  // OPEN_CLASS_INVARIANT

        [[nodiscard]] T GetLog2() const;

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
        static constexpr auto sm_MaskSize = 5;
        static constexpr std::array<uint32_t, sm_MaskSize> sm_Mask{ 0xFFFF0000, 0xFF00FF00, 0xF0F0F0F0, 0xCCCCCCCC, 0xAAAAAAAA };

        T m_PowerOfTwo;
        T m_PowerOfTwoCopy;
        uint32_t m_Log2;
    };
}

#endif  // MATHEMATICS_BASE_LOG2_OF_POWER_OF_TWO_H

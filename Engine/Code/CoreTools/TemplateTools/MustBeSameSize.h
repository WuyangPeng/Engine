///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/21 14:48)

// 约束：两个类大小必须相等，可能依赖于硬件架构或编译器。
#ifndef CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_SAME_SIZE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_SAME_SIZE_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename T>
    struct SizeOf
    {
        enum
        {
            Value = sizeof(T)
        };
    };

    template <>
    struct SizeOf<void>
    {
        enum
        {
            Value = 0
        };
    };

    template <typename T1, typename T2>
    struct MustBeSameSize
    {
        ~MustBeSameSize()
        {
            MAYBE_UNUSED void (*ptr)() = Constranints;
        }

        MustBeSameSize() noexcept = default;
        MustBeSameSize(const MustBeSameSize& rhs) noexcept = default;
        MustBeSameSize& operator=(const MustBeSameSize& rhs) noexcept = default;
        MustBeSameSize(MustBeSameSize&& rhs) noexcept = default;
        MustBeSameSize& operator=(MustBeSameSize&& rhs) noexcept = default;

    private:
        constexpr static void Constranints() noexcept
        {
            constexpr auto T1NotSameSizeAsT2 = static_cast<uint32_t>(static_cast<int>(SizeOf<T1>::Value) == static_cast<int>(SizeOf<T2>::Value));

            MAYBE_UNUSED const int i[T1NotSameSizeAsT2]{};
        }
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_SAME_SIZE_H

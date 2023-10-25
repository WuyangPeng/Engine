///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 14:47)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_SAME_SIZE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_SAME_SIZE_H

#include "CoreTools/CoreToolsDll.h"

// 约束：两个类大小必须相等，可能依赖于硬件架构或编译器。
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
            constexpr auto t1NotSameSizeAsT2 = static_cast<uint32_t>(static_cast<int>(SizeOf<T1>::Value) == static_cast<int>(SizeOf<T2>::Value));

            MAYBE_UNUSED const int i[t1NotSameSizeAsT2]{};
        }
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_SAME_SIZE_H

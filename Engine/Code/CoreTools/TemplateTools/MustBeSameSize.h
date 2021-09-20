//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/23 15:26)

// 约束：两个类大小必须相等，可能依赖于硬件架构或编译器。
#ifndef CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_SAME_SIZE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_SAME_SIZE_H

#include "CoreTools/CoreToolsDll.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26432)
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
            [[maybe_unused]] void (*ptr)() = Constranints;
        }

    private:
        constexpr static void Constranints() noexcept
        {
            constexpr auto T1NotSameSizeAsT2 = static_cast<uint32_t>(SizeOf<T1>::Value == SizeOf<T2>::Value);

            [[maybe_unused]] const int i[T1NotSameSizeAsT2]{};
        }
    };
}
#include STSTEM_WARNING_POP
#endif  // CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_SAME_SIZE_H

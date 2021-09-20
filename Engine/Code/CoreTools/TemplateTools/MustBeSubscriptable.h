//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/23 15:26)

// 约束：必须可以按下标访问
#ifndef CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_SUBSCRIPTABLE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_SUBSCRIPTABLE_H

#include "CoreTools/CoreToolsDll.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26432)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26440)
namespace CoreTools
{
    template <typename T>
    struct MustBeSubscriptable
    {
        ~MustBeSubscriptable()
        {
            [[maybe_unused]] void (*ptr)(const T&) = Constranints;
        }

    private:
        static void Constranints(const T& TIsNoSubscriptable)   
        {
            [[maybe_unused]] constexpr auto size = sizeof(TIsNoSubscriptable[0]);

            [[maybe_unused]] auto value = TIsNoSubscriptable[0];
        }
    };

    template <typename T>
    struct MustBeSubscriptableAsDecayablePointer
    {
        ~MustBeSubscriptableAsDecayablePointer()
        {
            [[maybe_unused]] void (*ptr)(const T&) = Constranints;
        }

    private:
        static void Constranints(T const& TIsNoSubscriptableAsDecayablePointer) noexcept
        {
            [[maybe_unused]] constexpr auto size = sizeof(0 [TIsNoSubscriptableAsDecayablePointer]);
        }
    };
}
#include STSTEM_WARNING_POP
#endif  // CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_SUBSCRIPTABLE_H

///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/21 14:58)

// 约束：必须可以按下标访问
#ifndef CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_SUBSCRIPTABLE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_SUBSCRIPTABLE_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename T>
    struct MustBeSubscriptable
    {
        MustBeSubscriptable() noexcept = default;
        MustBeSubscriptable(const MustBeSubscriptable& rhs) noexcept = default;
        MustBeSubscriptable& operator=(const MustBeSubscriptable& rhs) noexcept = default;
        MustBeSubscriptable(MustBeSubscriptable&& rhs) noexcept = default;
        MustBeSubscriptable& operator=(MustBeSubscriptable&& rhs) noexcept = default;

        ~MustBeSubscriptable()
        {
            MAYBE_UNUSED void (*ptr)(const T&) = Constranints;
        }

    private:
        static void Constranints(const T& tIsNoSubscriptable) noexcept(noexcept(tIsNoSubscriptable[0]))
        {
            MAYBE_UNUSED constexpr auto size = sizeof(tIsNoSubscriptable[0]);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

            MAYBE_UNUSED auto value = tIsNoSubscriptable[0];

#include STSTEM_WARNING_POP
        }
    };

    template <typename T>
    struct MustBeSubscriptableAsDecayablePointer
    {
        MustBeSubscriptableAsDecayablePointer() noexcept = default;
        MustBeSubscriptableAsDecayablePointer(const MustBeSubscriptableAsDecayablePointer& rhs) noexcept = default;
        MustBeSubscriptableAsDecayablePointer& operator=(const MustBeSubscriptableAsDecayablePointer& rhs) noexcept = default;
        MustBeSubscriptableAsDecayablePointer(MustBeSubscriptableAsDecayablePointer&& rhs) noexcept = default;
        MustBeSubscriptableAsDecayablePointer& operator=(MustBeSubscriptableAsDecayablePointer&& rhs) noexcept = default;

        ~MustBeSubscriptableAsDecayablePointer()
        {
            MAYBE_UNUSED void (*ptr)(const T&) = Constranints;
        }

    private:
        static void Constranints(T const& TIsNoSubscriptableAsDecayablePointer) noexcept
        {
            MAYBE_UNUSED constexpr auto size = sizeof(0 [TIsNoSubscriptableAsDecayablePointer]);
        }
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_SUBSCRIPTABLE_H

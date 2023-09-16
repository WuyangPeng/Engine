///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/03/31 16:10)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_SUBSCRIPTABLE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_SUBSCRIPTABLE_H

#include "CoreTools/CoreToolsDll.h"

// Լ����������԰��±����
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

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

            MAYBE_UNUSED auto value = tIsNoSubscriptable[0];

#include SYSTEM_WARNING_POP
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

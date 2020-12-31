//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/23 15:26)

// Լ����������԰��±����
#ifndef CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_SUBSCRIPTABLE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_SUBSCRIPTABLE_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename T>
    struct MustBeSubscriptable
    {
        ~MustBeSubscriptable()
        {
            void (*ptr)(const T&) = Constranints;
        }

    private:
        static void Constranints(const T& TIsNoSubscriptable)
        {
            auto size = sizeof(TIsNoSubscriptable[0]);

            auto value = TIsNoSubscriptable[0];
        }
    };

    template <typename T>
    struct MustBeSubscriptableAsDecayablePointer
    {
        ~MustBeSubscriptableAsDecayablePointer()
        {
            void (*ptr)(const T&) = Constranints;
        }

    private:
        static void Constranints(T const& TIsNoSubscriptableAsDecayablePointer)
        {
            auto size = sizeof(0 [TIsNoSubscriptableAsDecayablePointer]);
        }
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_SUBSCRIPTABLE_H

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:20)

#ifndef CORE_TOOLS_STATE_MACHINE_TRANSITION_EVENT_H
#define CORE_TOOLS_STATE_MACHINE_TRANSITION_EVENT_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename Transition>
    struct TransitionEvent
    {
        using ClassType = TransitionEvent<Transition>;

        using type = typename Transition::EventType;
    };
}

#endif  //  CORE_TOOLS_STATE_MACHINE_TRANSITION_EVENT_H

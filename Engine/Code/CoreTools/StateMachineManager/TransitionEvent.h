///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/03/31 16:00)

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

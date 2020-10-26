//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 16:01)

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

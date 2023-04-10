///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/03/31 15:53)

#ifndef CORE_TOOLS_STATE_MACHINE_GENERATE_DISPATCHER_H
#define CORE_TOOLS_STATE_MACHINE_GENERATE_DISPATCHER_H

#include "CoreTools/CoreToolsDll.h"

#include "DefaultEventDispatcher.h"
#include "EventDispatcher.h"
#include "TransitionEvent.h"

#include <boost/mpl/filter_view.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/type_traits/is_same.hpp>

namespace CoreTools
{
    template <typename Table, typename Event, typename State = int>
    struct GenerateDispatcher : boost::mpl::fold<boost::mpl::filter_view<Table, boost::is_same<Event, TransitionEvent<boost::mpl::placeholders::_1>>>,
                                                 DefaultEventDispatcher<State>,
                                                 EventDispatcher<boost::mpl::placeholders::_2, boost::mpl::placeholders::_1, State>>
    {
        using StateType = State;
        using TableType = Table;
        using EventType = Event;
        using ClassType = GenerateDispatcher<TableType, EventType, StateType>;
    };
}

#endif  //  CORE_TOOLS_STATE_MACHINE_GENERATE_DISPATCHER_H

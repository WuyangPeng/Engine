/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 10:20)

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

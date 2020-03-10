// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 17:25)

#ifndef CORE_TOOLS_STATE_MACHINE_GENERATE_DISPATCHER_H
#define CORE_TOOLS_STATE_MACHINE_GENERATE_DISPATCHER_H 

#include "CoreTools/CoreToolsDll.h"

#include "TransitionEvent.h"
#include "DefaultEventDispatcher.h"
#include "EventDispatcher.h"

#include <boost/mpl/fold.hpp>
#include <boost/mpl/filter_view.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/mpl/placeholders.hpp>

namespace CoreTools
{
	template<typename Table, typename Event, typename State = uint32_t>
	struct GenerateDispatcher : boost::mpl::fold<boost::mpl::filter_view<Table,
								boost::is_same<Event, TransitionEvent<boost::mpl::placeholders::_1>>>,
								DefaultEventDispatcher<State>,
								EventDispatcher<boost::mpl::placeholders::_2, boost::mpl::placeholders::_1, State>>
	{
		using StateType = State;
		using TableType = Table;
		using EventType = Event;
		using ClassType = GenerateDispatcher<TableType, EventType, StateType>;
	};
}

#endif //  CORE_TOOLS_STATE_MACHINE_GENERATE_DISPATCHER_H


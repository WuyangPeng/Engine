// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 17:24)

#ifndef CORE_TOOLS_STATE_MACHINE_DEFAULT_EVENT_DISPATCHER_H
#define CORE_TOOLS_STATE_MACHINE_DEFAULT_EVENT_DISPATCHER_H 

#include "CoreTools/CoreToolsDll.h"

#include "StateMachineManagerFwd.h"

// 默认事件分派器
namespace CoreTools
{
	template<typename State = uint32_t>
	class DefaultEventDispatcher
	{
	public:
		using StateType = State;
		using ClassType = DefaultEventDispatcher<StateType>;

	public:
		template<typename FsmType, typename EventType>
		static StateType Dispatch(StateMachine<FsmType, StateType>& fsm, StateType state, const EventType& eventType);
	};
}

#endif //  CORE_TOOLS_STATE_MACHINE_DEFAULT_EVENT_DISPATCHER_H


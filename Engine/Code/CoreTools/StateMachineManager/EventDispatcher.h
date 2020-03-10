// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 17:24)

#ifndef CORE_TOOLS_STATE_MACHINE_EVENT_DISPATCHER_H
#define CORE_TOOLS_STATE_MACHINE_EVENT_DISPATCHER_H 

#include "CoreTools/CoreToolsDll.h"

// �¼�������
namespace CoreTools
{
	template<typename Transition, typename Next, typename State = uint32_t>
	class EventDispatcher
	{
	public:	
		using StateType = State;
		using ClassType = EventDispatcher<Transition, Next, StateType>;
		using FsmType = typename Transition::FsmType;
		using EventType = typename Transition::EventType;

	public:
		static StateType Dispatch(FsmType& fsm, StateType state, const EventType& eventType);
	};
}

#endif //  CORE_TOOLS_STATE_MACHINE_EVENT_DISPATCHER_H


// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.2 (2020/01/22 17:27)

#ifndef CORE_TOOLS_STATE_MACHINE_FWD_H
#define CORE_TOOLS_STATE_MACHINE_FWD_H

// ×´Ì¬»ú
namespace CoreTools
{
	template<typename Transition, typename Next, typename State>
	class EventDispatcher;

	template<typename State>
	class DefaultEventDispatcher;

	template<typename Derived, typename State, State CurrentState, typename Event,
			 State NextState, void (Derived::*Action)(const Event&)>
	class StateMachineRow;

	template <typename Transition>
	struct TransitionEvent;

	template<typename Table, typename Event, typename State>
	struct GenerateDispatcher;

	template<typename Derived, typename State>
	class StateMachine;

	template <typename Subclass, typename EventType>
	class StateEntity;

	template <typename EntityType>
	class State;

	template <typename EntityType, typename EventType>
	class StateMachineBase;
}

#endif // CORE_TOOLS_STATE_MACHINE_FWD_H
// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 17:31)

#ifndef CORE_TOOLS_STATE_MACHINE_DEFAULT_STATE_MACHINE_DETAIL_H
#define CORE_TOOLS_STATE_MACHINE_DEFAULT_STATE_MACHINE_DETAIL_H 

#include "StateMachine.h"
#include "GenerateDispatcher.h" 
#include "EventDispatcherDetail.h"
#include "StateMachineRowDetail.h"
#include "DefaultEventDispatcherDetail.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h" 

template<typename Derived, typename State>
CoreTools::StateMachine<Derived, State>
	::StateMachine()
	: m_State{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template<typename Derived, typename State>
CoreTools::StateMachine<Derived, State>
	::~StateMachine()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template<typename Derived, typename State>
bool CoreTools::StateMachine<Derived, State>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template<typename Derived, typename State>
template <typename EventType>
typename CoreTools::StateMachine<Derived, State>::StateType CoreTools::StateMachine<Derived, State>
	::CallNoTransition(StateType state, const EventType& eventType)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return static_cast<Derived*>(this)->NoTransition(state, eventType);
}

template<typename Derived, typename State>
template<typename EventType>
typename CoreTools::StateMachine<Derived, State>::StateType CoreTools::StateMachine<Derived, State>
	::ProcessEvent(const EventType& eventType)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	using Dispatcher = typename GenerateDispatcher<typename Derived::TransitionTable, EventType, StateType>::type;

	m_State = Dispatcher::Dispatch(*static_cast<Derived*>(this), m_State, eventType);

	return m_State;
}

template<typename Derived, typename State>
template<typename EventType>
typename CoreTools::StateMachine<Derived, State>::StateType CoreTools::StateMachine<Derived, State>
	::NoTransition(StateType state, const EventType& eventType)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(eventType);
	SYSTEM_UNUSED_ARG(state);

	return GetStateType();
}

template<typename Derived, typename State>
typename CoreTools::StateMachine<Derived, State>::StateType CoreTools::StateMachine<Derived, State>
	::GetStateType() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_State;
}

template<typename Derived, typename State>
void CoreTools::StateMachine<Derived, State>
	::SetStateType(StateType stateType)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_State = stateType;
}

#endif //  CORE_TOOLS_STATE_MACHINE_DEFAULT_STATE_MACHINE_DETAIL_H


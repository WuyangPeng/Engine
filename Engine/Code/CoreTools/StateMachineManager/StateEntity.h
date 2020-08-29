// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 17:26)

#ifndef CORE_TOOLS_STATE_MACHINE_MANAGER_STATE_ENTITY_H
#define CORE_TOOLS_STATE_MACHINE_MANAGER_STATE_ENTITY_H

#include "CoreTools/CoreToolsDll.h"

#include "StateMachineBase.h"
#include "CoreTools/MessageEvent/EventEntity.h" 

namespace CoreTools
{
	template <typename Subclass, typename EventType = int>
	class StateEntity : public EventEntity<EventType>
	{
	public:
		using ClassType = StateEntity<Subclass, EventType>;
		using ParentType = EventEntity<EventType>;
		using StateMachineBase = StateMachineBase<Subclass, EventType>;
		using State = State<Subclass>;
		using StatePtr = std::shared_ptr<State>;
		using ConstStatePtr = std::shared_ptr<const State>;
		using Telegram = Telegram<EventType>;

	public:
		explicit StateEntity(StatePtr currentState);
		explicit StateEntity(StatePtr currentState, StatePtr globalState);
		virtual ~StateEntity();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		bool EventFunction(const Telegram& telegram);

		void Update(int64_t timeInterval);

		ConstStatePtr GetCurrentState() const;
		ConstStatePtr GetGlobalState() const;
		StatePtr GetPossiblePreviousState();

	private:
		  void DoRegister() override;

	private:
		StateMachineBase m_StateMachineBase;
	};
}

#endif // CORE_TOOLS_STATE_MACHINE_MANAGER_STATE_ENTITY_H
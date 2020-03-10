// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 17:26)

#ifndef CORE_TOOLS_STATE_MACHINE_STATE_MACHINE_BASE_H
#define CORE_TOOLS_STATE_MACHINE_STATE_MACHINE_BASE_H 

#include "CoreTools/CoreToolsDll.h"

#include "State.h"
#include "StateEntity.h"
#include "CoreTools/MessageEvent/Telegram.h"

namespace CoreTools
{
	template <typename EntityType, typename EventType>
	class StateMachineBase
	{
	public:
		using ClassType = StateMachineBase<EntityType, EventType>;
		using EntityTypePtr = std::shared_ptr<EntityType>;
		using EntityEventType = EventType;
		using Telegram = Telegram<EntityEventType>;
		using EntityTypeWeakPtr = std::weak_ptr<EntityType>;
		using State = State<EntityType>;
		using StatePtr = std::shared_ptr<State>;
		using ConstStatePtr = std::shared_ptr<const State>;

	public:
		explicit StateMachineBase(StatePtr currentState);
		StateMachineBase(StatePtr currentState, StatePtr globalState);
		virtual ~StateMachineBase();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		void Register(EntityTypePtr owner);

		void Update(int64_t timeInterval);

		bool HandleMessage(const Telegram& msg);

		bool IsInState(const State& state) const;

		ConstStatePtr GetCurrentState() const;
		ConstStatePtr GetGlobalState() const;
		ConstStatePtr GetPreviousState() const;
		ConstStatePtr GetPossiblePreviousState() const;

		StatePtr GetPossiblePreviousState();

	private:
		void ChangeState(StatePtr newState);

	private:
		StatePtr m_CurrentState;
		StatePtr m_PreviousState;
		StatePtr m_GlobalState;
	};
}

#endif //  CORE_TOOLS_STATE_MACHINE_STATE_MACHINE_BASE_H


// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 17:25)

#ifndef CORE_TOOLS_STATE_MACHINE_MANAGER_STATE_H
#define CORE_TOOLS_STATE_MACHINE_MANAGER_STATE_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/RttiMacro.h"
#include "CoreTools/MessageEvent/EventEntity.h" 

#include <memory>

namespace CoreTools
{
	template <typename EntityType>
	class State : public std::enable_shared_from_this<State<EntityType>>
	{
	public:
		using ClassType = State<EntityType>;
		using EntityTypePtr = std::shared_ptr<EntityType>;
		using EntityEventType = typename EntityType::EntityEventType;
		using Telegram = Telegram<EntityEventType>;
		using EntityTypeWeakPtr = std::weak_ptr<EntityType>;
		using StatePtr = std::shared_ptr<ClassType>;
		using ConstStatePtr = std::shared_ptr<const ClassType>;
		using MessageResult = std::pair<StatePtr, bool>;

	public:
		State();
		virtual ~State();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		void Enter(EntityTypePtr entity);

		virtual StatePtr Execute(int64_t timeInterval) = 0;

		virtual void Exit() = 0;

		virtual MessageResult OnMessage(const Telegram& telegram) = 0;

		template<typename StateType, typename ResultType = StateType, typename... Args>
		static std::shared_ptr<ResultType> MakeState(Args&&... args);

		EntityTypePtr GetOwner();

		bool IsExactly(const Rtti& rtti) const;

		CORE_TOOLS_RTTI_DECLARE;

	protected:
		StatePtr GetPossiblePreviousState();

	private:
		virtual void DoEnter() = 0;

	private:
		EntityTypeWeakPtr m_Entity;
	};
}

#endif // CORE_TOOLS_STATE_MACHINE_MANAGER_STATE_H
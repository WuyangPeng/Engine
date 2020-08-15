// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 17:30)

#ifndef CORE_TOOLS_STATE_MACHINE_MANAGER_STATE_DETAIL_H 
#define CORE_TOOLS_STATE_MACHINE_MANAGER_STATE_DETAIL_H 

#include "State.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename EventType>
CoreTools::State<EventType>
	::State()
	:m_Entity{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename EventType>
CoreTools::State<EventType>
	::~State()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename EventType>
bool CoreTools::State<EventType>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT 

template <typename EntityType>
void CoreTools::State<EntityType>
	::Enter(EntityTypePtr entity)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_Entity = entity;

	DoEnter();
}

template <typename EntityType>
typename CoreTools::State<EntityType>::EntityTypePtr CoreTools::State<EntityType>
	::GetOwner()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	auto lockPtr = m_Entity.lock();

	if (lockPtr)
	{
		return lockPtr;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("实体已释放"s));
	}
}

template <typename EntityType>
typename CoreTools::State<EntityType>::StatePtr CoreTools::State<EntityType>
	::GetPossiblePreviousState()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return GetOwner()->GetPossiblePreviousState();
}

// static
template <typename EventType>
template<typename StateType, typename ResultType, typename... Args>
static std::shared_ptr<ResultType> CoreTools::State<EventType>
	::MakeState(Args&&... args)
{
	auto result = std::make_shared<StateType>(args...);

	return result;
}

template <typename EntityType>
const CoreTools::Rtti& CoreTools::State<EntityType>
	::GetRttiType() const noexcept
{
	return sm_Type;
}

template <typename EntityType>
const CoreTools::Rtti CoreTools::State<EntityType>
	::sm_Type("CoreTools.State<EntityType>", nullptr);

template <typename EntityType>
bool CoreTools::State<EntityType>
	::IsExactly(const Rtti& rtti) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return GetRttiType().IsExactly(rtti);
}

#endif // CORE_TOOLS_STATE_MACHINE_MANAGER_STATE_DETAIL_H
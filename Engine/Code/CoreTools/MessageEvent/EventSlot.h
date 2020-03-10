// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 17:04)

#ifndef CORE_TOOLS_MESSAGE_EVENT_EVENT_SLOT_H
#define CORE_TOOLS_MESSAGE_EVENT_EVENT_SLOT_H

#include "CoreTools/CoreToolsDll.h"

#include "EventInterface.h" 
#include "MessageEventFwd.h"

#include <iosfwd>

namespace CoreTools
{
	template <typename T, typename PriorityType = int>
	class EventSlot
	{
	public:
		using SubclassWeakPointerType = std::weak_ptr<T>;
		using EventSlotPriorityType = PriorityType;
		using SubclassSmartPointerType = std::shared_ptr<T>;
		using SubclassType = T;
		static_assert(std::is_base_of_v<EventInterface, SubclassType>, "SubclassType is base of EventInterface");

		using ClassType = EventSlot<SubclassType, EventSlotPriorityType>;
		using CallbackMemberFunction = typename SubclassType::CallbackMemberFunction;
		using ConstSubclassSmartPointerType = std::shared_ptr<const T>;

	public:
		EventSlot(const SubclassSmartPointerType& smartPointer, PriorityType priority, CallbackMemberFunction callbackMemberFunction);

		CLASS_INVARIANT_DECLARE;

		bool operator()(const CallbackParameters& callbackParameters);
		PriorityType GetPriority() const;

		const ConstSubclassSmartPointerType GetConstSmartPointer() const;

	private:
		SubclassWeakPointerType m_SubclassWeakPointer;
		PriorityType m_Priority;
		CallbackMemberFunction m_CallbackMemberFunction;
	};

	template <typename T, typename PriorityType>
	bool operator<(const EventSlot<T, PriorityType>& lhs, const EventSlot<T, PriorityType>& rhs);

	template <typename T, typename PriorityType>
	std::ostream& operator<<(std::ostream& os, const EventSlot<T, PriorityType>& lhs);
}

#endif // CORE_TOOLS_MESSAGE_EVENT_EVENT_SLOT_H

// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 17:02)

#ifndef CORE_TOOLS_MESSAGE_EVENT_BASE_EVENT_ENTITY_H
#define CORE_TOOLS_MESSAGE_EVENT_BASE_EVENT_ENTITY_H

#include "CoreTools/CoreToolsDll.h"

#include "BaseEntity.h"
#include "TelegramDetail.h"

namespace CoreTools
{
	template <typename EventType = int>
	class EventEntity : public BaseEntity
	{
	public:
		using ClassType = EventEntity<EventType>;
		using ParentType = BaseEntity;
		using Telegram = Telegram<EventType>;
		using EntityEventType = EventType;

	public:
		EventEntity();
		virtual ~EventEntity();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		virtual bool EventFunction(const Telegram& telegram) = 0;
	};
}

#endif // CORE_TOOLS_MESSAGE_EVENT_BASE_EVENT_ENTITY_H
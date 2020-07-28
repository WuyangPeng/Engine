// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.1 (2019/06/28 17:50)

#ifndef CORE_TOOLS_MESSAGE_EVENT_BASE_GAME_ENTITY_H
#define CORE_TOOLS_MESSAGE_EVENT_BASE_GAME_ENTITY_H

#include "CoreTools/CoreToolsDll.h"

#include "MessageEventFwd.h"
#include "CoreTools/Helper/ExportMacro.h"

template class CORE_TOOLS_DEFAULT_DECLARE std::weak_ptr<CoreTools::BaseEntity>;
template class CORE_TOOLS_DEFAULT_DECLARE std::enable_shared_from_this<CoreTools::BaseEntity>;

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE BaseEntity : public std::enable_shared_from_this<BaseEntity>
	{
	public:
		using ClassType = BaseEntity;

	public:
		BaseEntity();
		virtual ~BaseEntity() noexcept = 0;
		BaseEntity(const BaseEntity&) = default;
		BaseEntity& operator= (const BaseEntity&) = default;
		BaseEntity(BaseEntity&&) noexcept = default;
		BaseEntity& operator= (BaseEntity&&) noexcept = default;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		uint64_t GetEntityID() const noexcept;
 
		void Register();

	private:
		virtual void DoRegister();

	private:
		uint64_t m_EntityID;
	};
}

#endif // CORE_TOOLS_MESSAGE_EVENT_BASE_GAME_ENTITY_H
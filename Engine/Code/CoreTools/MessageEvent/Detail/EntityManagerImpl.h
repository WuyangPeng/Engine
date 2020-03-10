// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:55)

#ifndef CORE_TOOLS_MESSAGE_EVENT_ENTITY_MANAGER_IMPL_H
#define CORE_TOOLS_MESSAGE_EVENT_ENTITY_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/MessageEvent/MessageEventFwd.h"

#include <map>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE EntityManagerImpl
	{
	public:
		using ClassType = EntityManagerImpl;
		using EntityPtr = std::shared_ptr<BaseEntity>;
		using EntityWeakPtr = std::weak_ptr<BaseEntity>;

	public:
		EntityManagerImpl();

		CLASS_INVARIANT_DECLARE;

		uint64_t NextUniqueID();

		bool Register(const EntityPtr& entity);
		bool Unregister(uint64_t entityID);

		EntityPtr GetEntity(uint64_t entityID) const;

	private:
		using EntityWeakPtrContainer = std::map<uint64_t, EntityWeakPtr>;

	private:
		EntityWeakPtrContainer m_Container;
	};
}

#endif // CORE_TOOLS_MESSAGE_EVENT_ENTITY_MANAGER_IMPL_H
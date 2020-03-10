// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 17:02)

#ifndef CORE_TOOLS_MESSAGE_EVENT_ENTITY_MANAGER_H
#define CORE_TOOLS_MESSAGE_EVENT_ENTITY_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "MessageEventFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "CoreTools/Base/SingletonDetail.h"
#include "CoreTools/Threading/ThreadingFwd.h"

#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(EntityManagerImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE EntityManager : public CoreTools::Singleton<EntityManager>
	{
	public:
		SINGLETON_INITIALIZE_DECLARE(EntityManager);
		using EntityPtr = std::shared_ptr<BaseEntity>;

	public:
		CLASS_INVARIANT_DECLARE;

	public:
		uint64_t NextUniqueID();
		bool Register(const EntityPtr& entity);
		bool Unregister(uint64_t entityID);
		EntityPtr GetEntity(uint64_t entityID) const;

		template<typename EntityType, typename ResultType = EntityType, typename... Args>
		std::shared_ptr<ResultType> MakeEntity(Args&&... args);

	private:
		SINGLETON_MEMBER_DECLARE(EntityManager);
	};
}

#define ENTITY_MANAGER_SINGLETON CoreTools::EntityManager::GetSingleton()

#endif // CORE_TOOLS_MESSAGE_EVENT_ENTITY_MANAGER_H
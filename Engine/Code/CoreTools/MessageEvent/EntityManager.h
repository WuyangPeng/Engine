//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 15:20)

#ifndef CORE_TOOLS_MESSAGE_EVENT_ENTITY_MANAGER_H
#define CORE_TOOLS_MESSAGE_EVENT_ENTITY_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "MessageEventFwd.h"
#include "CoreTools/Base/SingletonDetail.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "CoreTools/Threading/ThreadingFwd.h"

#include <string>

CORE_TOOLS_EXPORT_UNIQUE_PTR(EntityManager);
CORE_TOOLS_EXPORT_SHARED_PTR(EntityManagerImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE EntityManager final : public CoreTools::Singleton<EntityManager>
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(EntityManager);
        using ParentType = Singleton<EntityManager>;
        using EntitySharedPtr = std::shared_ptr<BaseEntity>;

    private:
        enum class EntityManagerCreate
        {
            Init,
        };

    public:
        explicit EntityManager(EntityManagerCreate entityManagerCreate);

        static void Create();
        static void Destroy() noexcept;

        SINGLETON_GET_PTR_DECLARE(EntityManager);

        CLASS_INVARIANT_DECLARE;

    public:
        [[nodiscard]] bool Register(const EntitySharedPtr& entity);
        [[nodiscard]] bool Unregister(uint64_t entityID);
        [[nodiscard]] EntitySharedPtr GetEntity(uint64_t entityID) const;

        template <typename EntityType, typename ResultType = EntityType, typename... Args>
        [[nodiscard]] std::shared_ptr<ResultType> MakeEntity(Args&&... args);

    private:
        using EntityManagerUniquePtr = std::unique_ptr<EntityManager>;

    private:
        static EntityManagerUniquePtr sm_EntityManager;
        IMPL_TYPE_DECLARE(EntityManager);
    };
}

#define ENTITY_MANAGER_SINGLETON CoreTools::EntityManager::GetSingleton()

#endif  // CORE_TOOLS_MESSAGE_EVENT_ENTITY_MANAGER_H
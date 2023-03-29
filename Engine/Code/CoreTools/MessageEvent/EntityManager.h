///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/29 13:35)

#ifndef CORE_TOOLS_MESSAGE_EVENT_ENTITY_MANAGER_H
#define CORE_TOOLS_MESSAGE_EVENT_ENTITY_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "MessageEventFwd.h"
#include "CoreTools/Base/SingletonDetail.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "CoreTools/Threading/ThreadingFwd.h"

#include <string>

CORE_TOOLS_EXPORT_UNIQUE_PTR(EntityManager);
CORE_TOOLS_NON_COPY_EXPORT_IMPL(EntityManagerImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE EntityManager final : public Singleton<EntityManager>
    {
    public:
        NON_COPY_TYPE_DECLARE(EntityManager);
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

        SINGLETON_GET_PTR_DECLARE(EntityManager)

        CLASS_INVARIANT_DECLARE;

    public:
        NODISCARD bool Register(const EntitySharedPtr& entity);
        NODISCARD bool UnRegister(int64_t entityId);
        NODISCARD EntitySharedPtr GetEntity(int64_t entityId) const;

        template <typename EntityType, typename ResultType = EntityType, typename... Args>
        NODISCARD std::shared_ptr<ResultType> MakeEntity(Args&&... args);

    private:
        using EntityManagerUniquePtr = std::unique_ptr<EntityManager>;

    private:
        static EntityManagerUniquePtr entityManager;
        PackageType impl;
    };
}

#define ENTITY_MANAGER_SINGLETON CoreTools::EntityManager::GetSingleton()

#endif  // CORE_TOOLS_MESSAGE_EVENT_ENTITY_MANAGER_H
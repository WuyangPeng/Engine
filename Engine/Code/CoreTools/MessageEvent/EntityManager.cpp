///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:18)

#include "CoreTools/CoreToolsExport.h"

#include "EntityManager.h"
#include "Detail/EntityManagerImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

SINGLETON_GET_PTR_DEFINE(CoreTools, EntityManager);

CoreTools::EntityManager::EntityManagerUniquePtr CoreTools::EntityManager::entityManager{};

void CoreTools::EntityManager::Create()
{
    entityManager = std::make_unique<CoreTools::EntityManager>(EntityManagerCreate::Init);
}

void CoreTools::EntityManager::Destroy() noexcept
{
    entityManager.reset();
}

CoreTools::EntityManager::EntityManager(EntityManagerCreate entityManagerCreate)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(entityManagerCreate);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, EntityManager)

bool CoreTools::EntityManager::Register(const EntitySharedPtr& entity)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    return impl->Register(entity);
}

bool CoreTools::EntityManager::UnRegister(int64_t entityId)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    return impl->UnRegister(entityId);
}

CoreTools::EntityManager::EntitySharedPtr CoreTools::EntityManager::GetEntity(int64_t entityId) const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetEntity(entityId);
}

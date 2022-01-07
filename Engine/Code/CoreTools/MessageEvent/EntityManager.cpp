///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/26 18:32)

#include "CoreTools/CoreToolsExport.h"

#include "../Contract/Flags/ImplFlags.h"
#include "EntityManager.h"
#include "Detail/EntityManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"

using std::make_shared;
using std::make_unique;

SINGLETON_GET_PTR_DEFINE(CoreTools, EntityManager);

CoreTools::EntityManager::EntityManagerUniquePtr CoreTools::EntityManager::entityManager{};

void CoreTools::EntityManager::Create()
{
    entityManager = make_unique<CoreTools::EntityManager>(EntityManagerCreate::Init);
}

void CoreTools::EntityManager::Destroy() noexcept
{
    entityManager.reset();
}

CoreTools::EntityManager::EntityManager(MAYBE_UNUSED EntityManagerCreate entityManagerCreate)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, EntityManager)

bool CoreTools::EntityManager::Register(const EntitySharedPtr& entity)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    return impl->Register(entity);
}

bool CoreTools::EntityManager::Unregister(uint64_t entityID)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    return impl->Unregister(entityID);
}

CoreTools::EntityManager::EntitySharedPtr CoreTools::EntityManager::GetEntity(uint64_t entityID) const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetEntity(entityID);
}

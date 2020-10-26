//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 15:49)

#include "CoreTools/CoreToolsExport.h"

#include "EntityManager.h"
#include "Detail/EntityManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"

using std::make_shared;
using std::make_unique;

SINGLETON_GET_PTR_DEFINE(CoreTools, EntityManager);

CoreTools::EntityManager::EntityManagerUniquePtr CoreTools::EntityManager::sm_EntityManager{};

void CoreTools::EntityManager::Create()
{
    sm_EntityManager = make_unique<CoreTools::EntityManager>(EntityManagerCreate::Init);
}

void CoreTools::EntityManager::Destroy() noexcept
{
    sm_EntityManager.reset();
}

CoreTools::EntityManager::EntityManager([[maybe_unused]] EntityManagerCreate entityManagerCreate)
    : m_Impl{ make_shared<ImplType>() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, EntityManager)

bool CoreTools::EntityManager::Register(const EntitySharedPtr& entity)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->Register(entity);
}

bool CoreTools::EntityManager::Unregister(uint64_t entityID)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->Unregister(entityID);
}

CoreTools::EntityManager::EntitySharedPtr CoreTools::EntityManager::GetEntity(uint64_t entityID) const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetEntity(entityID);
}

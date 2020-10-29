//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 13:10)

#include "Network/NetworkExport.h"

#include "BaseMainManager.h"
#include "Detail/BaseMainManagerFactory.h"
#include "Detail/BaseMainManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"

using std::make_shared;
using std::make_unique;

SINGLETON_GET_PTR_DEFINE(CoreTools, EntityManager);

Network::BaseMainManager::BaseMainManagerUniquePtr Network::BaseMainManager::sm_BaseMainManager{};

void Network::BaseMainManager::Create(const ConfigurationStrategy& configurationStrategy)
{
    sm_BaseMainManager = make_unique<Network::BaseMainManager>(configurationStrategy, BaseMainManagerCreate::Init);
}

void Network::BaseMainManager::Destroy() noexcept
{
    sm_BaseMainManager.reset();
}

Network::BaseMainManager::BaseMainManager(const ConfigurationStrategy& configurationStrategy, [[maybe_unused]] BaseMainManagerCreate baseMainManagerCreate)
    : m_Impl{ BaseMainManagerFactory::Create(configurationStrategy) }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Network, BaseMainManager)

void Network::BaseMainManager::Run()
{
    // Run调用会阻塞线程，不能加锁。

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    m_Impl->Run();
}

Network::IOContextType& Network::BaseMainManager::GetIOContext()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->GetIOContext();
}

void Network::BaseMainManager::StopContext()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->StopContext();
}

bool Network::BaseMainManager::IsContextStop() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_CONST_1;

    return m_Impl->IsContextStop();
}

void Network::BaseMainManager::RestartContext()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->RestartContext();
}

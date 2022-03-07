///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/21 17:00)

#include "Network/NetworkExport.h"

#include "BaseMainManager.h"
#include "Detail/BaseMainManagerFactory.h"
#include "Detail/BaseMainManagerImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"

using std::make_shared;
using std::make_unique;

SINGLETON_GET_PTR_DEFINE(CoreTools, EntityManager);

Network::BaseMainManager::BaseMainManagerUniquePtr Network::BaseMainManager::baseMainManager{};

void Network::BaseMainManager::Create(const ConfigurationStrategy& configurationStrategy)
{
    baseMainManager = make_unique<BaseMainManager>(configurationStrategy, BaseMainManagerCreate::Init);
}

void Network::BaseMainManager::Destroy() noexcept
{
    baseMainManager.reset();
}

Network::BaseMainManager::BaseMainManager(const ConfigurationStrategy& configurationStrategy, MAYBE_UNUSED BaseMainManagerCreate baseMainManagerCreate)
    : impl{ CoreTools::ImplCreateUseFactory::Default, configurationStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BaseMainManager)

void Network::BaseMainManager::Run()
{
    // Run调用会阻塞线程，不能加锁。

    NETWORK_CLASS_IS_VALID_1;

    impl->Run();
}

Network::IOContextType& Network::BaseMainManager::GetIOContext()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_1;

    return impl->GetIOContext();
}

void Network::BaseMainManager::StopContext()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_1;

    return impl->StopContext();
}

bool Network::BaseMainManager::IsContextStop() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->IsContextStop();
}

void Network::BaseMainManager::RestartContext()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_1;

    return impl->RestartContext();
}

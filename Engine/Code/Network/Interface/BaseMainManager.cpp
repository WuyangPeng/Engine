///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 13:37)

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

SINGLETON_GET_PTR_DEFINE(CoreTools, EntityManager);

Network::BaseMainManager::BaseMainManagerUniquePtr Network::BaseMainManager::baseMainManager{};

void Network::BaseMainManager::Create(const ConfigurationStrategy& configurationStrategy)
{
    baseMainManager = std::make_unique<BaseMainManager>(configurationStrategy, BaseMainManagerCreate::Init);
}

void Network::BaseMainManager::Destroy() noexcept
{
    baseMainManager.reset();
}

Network::BaseMainManager::BaseMainManager(const ConfigurationStrategy& configurationStrategy, BaseMainManagerCreate baseMainManagerCreate)
    : impl{ CoreTools::ImplCreateUseFactory::Default, configurationStrategy }
{
    System::UnusedFunction(baseMainManagerCreate);

    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BaseMainManager)

void Network::BaseMainManager::Run()
{
    // Run调用会阻塞线程，不能加锁。

    NETWORK_CLASS_IS_VALID_1;

    impl->Run();
}

Network::IoContextType& Network::BaseMainManager::GetContext()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    NETWORK_CLASS_IS_VALID_1;

    return impl->GetContext();
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

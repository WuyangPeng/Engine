//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/28 13:10)

#include "Network/NetworkExport.h"

#include "BaseMainManager.h"
#include "Detail/BaseMainManagerFactory.h"
#include "Detail/BaseMainManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"

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
    : impl{ CoreTools::ImplCreateUseFactory::Default, configurationStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BaseMainManager)

void Network::BaseMainManager::Run()
{
    // Run���û������̣߳����ܼ�����

    ;

    impl->Run();
}

Network::IOContextType& Network::BaseMainManager::GetIOContext()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    ;

    return impl->GetIOContext();
}

void Network::BaseMainManager::StopContext()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    ;

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

    ;

    return impl->RestartContext();
}

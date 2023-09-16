///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/15 17:33)

#include "Network/NetworkExport.h"

#include "RouteServiceManager.h"
#include "Detail/RouteServiceManagerImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Threading/Mutex.h"

SINGLETON_GET_PTR_DEFINE(CoreTools, RouteServiceManager);

Network::RouteServiceManager::RouteServiceManagerUniquePtr Network::RouteServiceManager::routeServiceManager{};

void Network::RouteServiceManager::Create(bool useActiveMQ)
{
    routeServiceManager = std::make_unique<RouteServiceManager>(useActiveMQ, RouteServiceManagerCreate::Init);
}

void Network::RouteServiceManager::Destroy() noexcept
{
    routeServiceManager.reset();
}

Network::RouteServiceManager::RouteServiceManager(bool useActiveMQ, RouteServiceManagerCreate routeServiceManagerCreate)
    : impl{ useActiveMQ }
{
    System::UnusedFunction(routeServiceManagerCreate);

    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, RouteServiceManager)

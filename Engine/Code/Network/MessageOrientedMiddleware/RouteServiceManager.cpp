/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:24)

#include "Network/NetworkExport.h"

#include "RouteServiceManager.h"
#include "Detail/RouteServiceManagerImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Threading/Mutex.h"

SINGLETON_GET_PTR_DEFINE(Network, RouteServiceManager);

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
